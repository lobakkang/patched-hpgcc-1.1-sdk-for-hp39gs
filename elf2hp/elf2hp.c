//& ****************************************************************************
//&
//& Copyright (C) 2004 The HP-GCC Team
//&
//& ****************************************************************************
//&
//& This file is part of HP-GCC.
//&
//& HP-GCC is free software; you can redistribute it and/or modify
//& it under the terms of the GNU General Public License as published by
//& the Free Software Foundation; either version 2, or (at your option)
//& any later version.
//& 
//& HP-GCC is distributed in the hope that it will be useful,
//& but WITHOUT ANY WARRANTY; without even the implied warranty of
//& MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//& GNU General Public License for more details.
//& 
//& You should have received a copy of the GNU General Public License
//& along with HP-GCC; see the file COPYING. 
//& 
//& As a special exception, you may use this file as part of a free software
//& library without restriction.  Specifically, if other files instantiate
//& templates or use macros or inline functions from this file, or you compile
//& this file and link it with other files to produce an executable, this
//& file does not by itself cause the resulting executable to be covered by
//& the GNU General Public License.  This exception does not however
//& invalidate any other reasons why the executable file might be covered by
//& the GNU General Public License.
//&
//& ****************************************************************************



//------------------------------------------------------------------
/** elf2hp.c:
 *
 * \author	Maurin Benjamin
 * \date 17/03/05
 * \version 1.5
 * 
 * Log:\n
 * - 17/03/05 Change to libelf for elf i/o, should be better for ARM64
 *
 * - 25/10/04 Default to L3/MMU format (Claudio's mmu), modify the -s switch
 * and look for a const global for sysrpl stack size.
 *
 * - 26/08/04 Endian awareness and L3 linker format by Ingo Blank (ibl)
 *
 * - 25/08/04 Use of ELFIO library, .ini file\n
 * Appened a first try for -shared object files. I explain:
 * you can compile with -shared instead of -static, thus
 * producing a CORRECT plt section and a got section TO PATCH
 * during runtime. By patching, I mean translating the addresses
 * and Filling the missing function adresses (given by elf2hp -v)\n
 *
 * - 30/07/04 First public version
 */

#include                    <ctype.h>
#include                    <fcntl.h>
#include                    <stdio.h>
#include                    <libelf.h>
#include                    <stdlib.h>
#include                    <string.h>
#include                    <unistd.h>




//------------------------------------------------------------------

#define TRUE 1
#define FALSE 0

//------------------------------------------------------------------




// Elf2hp constants for arm-header
#define	OLD_GOT_GLOBALS 0
#define	START_GLOBALS 1
#define	NO_GLOBALS 2
#define	MMU_GLOBALS 3


//! The symbol to look for in the symbols' table
#define STACK_SYMBOL "sys_rpl_mem"


// <ibl ; 2004-11-07>
#define MEMPACKER_RAMBASE 0x09000400
#define RAM_SIGNATURE 0xC00000
unsigned int _ram_signature = RAM_SIGNATURE;
// </ibl>

//------------------------------------------------------------------


//! .ini configuration file
/**
 * This must be a text file that looks like this:\n
 * AS =..\bin\arm-elf-as.exe\n
 * ENTRY =_start\n
 * \n
 * There must be at least ONE SPACE between each KEYWORD and = in 'KEYWORD ='
 */
typedef struct
{
	//! Flag to store the endianess of the host
	int bigendian;
	//! path of the executables
	char AS_path[255];
	char GCC_path[255];
	char LD_path[255];
	//! Entry point value (string)
	char entry_point[255];
	//! Size of the required mem for rpl stuff
	unsigned int rpl_mem_size;
	//! Number of 16-bytes blocks to leave for pushing RPL Pointers
	unsigned int rpl_stack_size;

	//! Value of rpl_mem symbol (position in .rodata)
	unsigned int rpl_mem_pos;
	//! choice of arm exe (1) or lib (2)
	int type;
	//! choice of the global management
	int global;
	//! choice of the output (L3 format or not)
	int L3_style;
	//! Do we add all the functions to the L3 epilog ?
	int L3_full_table;
	//! Verbose flag
	/**
	 * Can be changed with -v option
	 */
	int verbose;
	//! Temporary files flag
	/**
	 * Can be changed with -t option
	 */
	int temp_files;
	//! Help requested
	/**
	 * Can be changed with -h option
	 */
	int help;
	//! Name of the arm-elf source
	/**
	 * First filename given on the command file
	 */
	char source[255];
	//! Name of the hp destination
	/**
	 * second filename given on the command file
	 */
	char destination[255];	
}
Configuration;



//------------------------------------------------------------------


//! Internal structure of an elf file
typedef struct
{
	// File descritor
	int             fd;
	Elf32_Ehdr     *ehdr;
	Elf32_Shdr     *shdr;
	Elf            *elf;
	Elf_Scn        *scn;
	Elf_Data       *data;
} Elf_file;


//! elf ARM symbol entry definition
typedef struct 
{
	unsigned int index;	//!< index
	unsigned int offset;	//!< Offset of symbol
	char name[255];
	unsigned int value;	//!< Value of symbol
	unsigned int size;	//!< Size
	unsigned char bind;	//!<  O= local, 1= global
	int type;		//!< 1: variable 2: fct
	int section;		//! Which section
} elf_Symbol_Table_Entry;


//! elf ARM relocation entry definition, usefull only for Dynamic Elf files
typedef struct 
{
	int type;
	int offset;
	int value;
	char name[255];
} elf_Relocation_Table_Entry;


//! elf ARM section table definition
typedef struct 
{
	unsigned int index;
	char name[20];
	unsigned int type;
	unsigned int address;
	unsigned int size;
	unsigned char entsize;
	unsigned char flags;
	unsigned char link;
	unsigned int info;
	unsigned char align;
	int offset;
} elf_Section_Table_Entry;



// Structure of an HP program object
typedef struct
{
	//! size of the text section to skip (plt+text+rodata)
	int text_size;
	//! size of the data_section to copy in RAM (data+dynamic+got)
	int data_size;
	//! size of the bss_section needed in RAM (bss+heap)
	int bss_size;
	//! position of the got_section relative to begining of text
	int got_pos;
	//! relative position of the entry point from begining of .text
	int entry_pos;
	//! GOT table size
	int	got_size ;
	//! dynamic entry flag
	int	dynamic ;

	//! Symbols Table
	elf_Symbol_Table_Entry		*elf_Symbol_Table;	
	//! Size of Symbols Table
	int	elf_Symbol_Table_size;	

	//! Relocation Table
	elf_Relocation_Table_Entry	*elf_Relocation_Table;
	//! Size of Relocation Table
	int	elf_Relocation_Table_size;	
} HP_armobject;




//------------------------------------------------------------------
// Internal variables
Configuration	config;
HP_armobject	hpobject;



//------------------------------------------------------------------
// Endianess part

//! Definition of a word (4 bytes)
typedef unsigned int USB32;

//! SWAP_B16_IN_B32 - swap 16 bits in 32 bits
/**
 *	dest	- pointer to where the swapped src wil be put
 *	src	- pointer to a 32 bit value to swap
 */
#define SWAP_B16_IN_B32(dest, src) (					\
	*((USB32*)(dest)) =						\
	  (((*((USB32*)(src))) << 16) | ((*((USB32*)(src))) >> 16))	\
)

//! SWAP_B8_IN_B32 - swap 8 & 16 bits in 32 bits
/**
 *	dest	- pointer to where the swapped src wil be put
 *	src	- pointer to a 32 bit value to swap
 *
 * This macro will either switch to the opposite byte sex (Big Endian vs.
 * Little Endian) a 32 bit value.
 */
#define SWAP_B8_IN_B32(dest, src) (					\
	SWAP_B16_IN_B32(dest, src),					\
	(*((USB32*)(dest)) =						\
	  ((((*((USB32*)(dest))) & (USB32)0xff00ff00) >> 8) |		\
	  (((*((USB32*)(dest))) & (USB32)0x00ff00ff) << 8)))		\
)


//! This function checks the endianess of the host
/**
 *
 */
int is_big_endian()
{
	unsigned test = 0xCAFEBABE;
	return( *((unsigned short *) &test) == 0xCAFE);
}


void fwrite_uint32(FILE *fp, USB32 uint32 )
{
	if (config.bigendian) 
		SWAP_B8_IN_B32(&uint32,&uint32);
	fwrite(&uint32,sizeof(unsigned),1,fp);
}

void fwrite_uc8(FILE *fp, unsigned char c)
{
	fwrite(&c,1,1,fp);
	if (config.verbose) printf("%02X ",c);
}



//------------------------------------------------------------------
// general functions


void	libelf_failure()
{
	fprintf(stderr, "elf::%s\n", elf_errmsg(elf_errno()));
	exit(1);
}


void	elf2hp_failure(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

#define verprintf if (config.verbose>0) printf
#define ver1printf if (config.verbose>1) printf
#define ver2printf if (config.verbose>2) printf

void	print_symbol( elf_Symbol_Table_Entry entry )
{
	printf( "0x%08X: %-34.34s %08x %08x %04x %04x %04x\n",
		entry.offset,
		entry.name,
		entry.value,
		entry.size,
		entry.bind,
		entry.type,
		entry.section );
}


void	print_section( elf_Section_Table_Entry entry )
{
	printf("  [%02d] %-20.20s", entry.index, (char *) entry.name);
	printf(" %04x     ",entry.type);
	printf("%08X ",entry.address);
	printf("%08x ",entry.size);
	printf("%02x ",entry.entsize);
	printf("%02x  ",entry.flags);
	printf("%02x ",entry.link);
	printf("%04x ",entry.info);
	printf("%02x ",entry.align);
	printf("\n");
}


//! Returns 1 if not empty
int	Check_Empty_String(char *str)
{
	int r=1;
	while(*str)
	{
		r=r&&(isspace(*str));
		str++;
	}
	return(r);
}

//! append two binary files
int Cat_Binary(char *src_name1, char *src_name2, char *dest_name)
{
	char buffer;
	FILE *fp_src = fopen(src_name1,"rb");
	if (fp_src!=NULL)
	{
		FILE *fp_dest = fopen(dest_name,"wb");
		if (fp_dest!=NULL)
		{
			// Start new file with first file
			while( (!feof(fp_src)) && fread(&buffer,1,1,fp_src))
				fwrite(&buffer,1,1,fp_dest);
			fclose(fp_src);
			// Append second file
			fp_src = fopen(src_name2,"rb");
			if (fp_src!=NULL)
			{
				while( (!feof(fp_src)) && fread(&buffer,1,1,fp_src))
					fwrite(&buffer,1,1,fp_dest);
				fclose(fp_src);
			}
			else
			{
				printf("Read error, Cat_binary can't open %s",src_name2);
				exit(0);
			}
			fclose(fp_dest);
		}
		else
		{
			printf("Write error, Cat_binary can't open %s",dest_name);
			fclose(fp_src);
			exit(0);
		}
	}
	else
	{
		fprintf(stderr, "Read error, Cat_binary can't open %s",src_name1);
		exit(1);
	}
		
	return(1);
}






//------------------------------------------------------------------
// Elf specific part




/**
 *	Verify the Elf header, check if it is ARM ELF32 little endian\n
 *	If any problem, then bails out.
 */
int VerifyHeader(Elf_file  *elf_file)
{
	//Check elf header:
	// See file libelf/elf_repl.h line 175
	
	// Open header
	if ((elf_file->ehdr = elf32_getehdr(elf_file->elf)) == NULL)
		libelf_failure();

	if (config.verbose)
	{
		printf( "\nVerifying ELF header:\n" );
		printf( "---------------------\n" );
		printf( "  Class:      " );
		if (elf_file->ehdr->e_ident[EI_CLASS]==ELFCLASS32)
			printf("Elf32\n");
		else if (elf_file->ehdr->e_ident[EI_CLASS]==ELFCLASS64)
			printf("Elf64\n");
		else if (elf_file->ehdr->e_ident[EI_CLASS]==ELFCLASSNONE)
			printf("None\n");
		else 
			printf("Unknown\n");

		printf("  Encoding:   ");
		if (elf_file->ehdr->e_ident[EI_DATA]==ELFDATA2LSB)
			printf("Little endian\n");
		else if (elf_file->ehdr->e_ident[EI_DATA]==ELFDATA2MSB)
			printf("Big endian\n");
		else if (elf_file->ehdr->e_ident[EI_DATA]==ELFDATANONE)
			printf("None\n");
		else 
			printf("Unknown\n");
	
		printf( "  ELFVersion: %s\n", ( EV_CURRENT ) ? "Current" : "Unknown");

		printf("  Type:       ");
		if (elf_file->ehdr->e_type==ET_EXEC)
			printf("EXEC\n");

		printf( "  Version:    0x%08X\n", elf_file->ehdr->e_version);
		printf( "  Machine:    0x%08X\n", elf_file->ehdr->e_machine);
		printf( "  Entry:      0x%08X\n", elf_file->ehdr->e_entry);
	}
	
	// Check class
	if (elf_file->ehdr->e_ident[EI_CLASS]!=ELFCLASS32)
		elf2hp_failure("Stoping: Bad class value");
	// Check encoding
	if (elf_file->ehdr->e_ident[EI_DATA]!=ELFDATA2LSB)
		elf2hp_failure("Stoping: Bad encoding value");
	// Check type
	if (elf_file->ehdr->e_type!=ET_EXEC)
		elf2hp_failure("Stoping: Bad type value");
	// Check machine compatibility
	if (elf_file->ehdr->e_machine!=0x28)
		elf2hp_failure("Machine type incompatible");
	
	// Fill entry point
	hpobject.entry_pos = elf_file->ehdr->e_entry;

	return(1);
}



/* Given Elf_Scn fill the symbol table 
 */
void fill_symbols( Elf_file  *elf_file)
{
	unsigned int number;
	
	int skip_empty = 1;
	if (skip_empty) verprintf( "Empty name symbols are skipped.\n" );
	
	elf_file->data = 0;
	if ((elf_file->data = elf_getdata( elf_file->scn, elf_file->data )) == 0 || elf_file->data->d_size == 0)
		elf2hp_failure("Section had no data!");
	  
	verprintf( "In Symbol table \n");
	verprintf( "        Id: Name                               Value    Size     Bind Type Sect\n" );
	
	
	// Count symbols in sections
	Elf32_Sym *esym = (Elf32_Sym*)  elf_file->data->d_buf;
	Elf32_Sym *lastsym = (Elf32_Sym*) ((char*)  elf_file->data->d_buf +  elf_file->data->d_size);
	
	for (number = 0; esym < lastsym; esym++, number++)
	{};
	hpobject.elf_Symbol_Table_size = number;
	hpobject.elf_Symbol_Table = (elf_Symbol_Table_Entry*) malloc(sizeof(elf_Symbol_Table_Entry)*number);
	
	
	// now fill the symbols
	esym = (Elf32_Sym*)  elf_file->data->d_buf;
	lastsym = (Elf32_Sym*) ((char*)  elf_file->data->d_buf +  elf_file->data->d_size);
	
	// loop through the symbol table and print it
	for (number = 0; esym < lastsym; esym++, number++)
	{
		strcpy( hpobject.elf_Symbol_Table[number].name ,
				elf_strptr( elf_file->elf, elf_file->shdr->sh_link , (size_t)esym->st_name));
//		printf("ici:%s\n",hpobject.elf_Symbol_Table[number].name );
		
		if (skip_empty&& Check_Empty_String(hpobject.elf_Symbol_Table[number].name) ) 
		{
			number--;
			continue;
		}
		else
		{
		hpobject.elf_Symbol_Table[number].offset = (unsigned long)esym;
		hpobject.elf_Symbol_Table[number].value = esym->st_value;
		hpobject.elf_Symbol_Table[number].size = esym->st_size;
		hpobject.elf_Symbol_Table[number].bind = ELF32_ST_BIND(esym->st_info);
		hpobject.elf_Symbol_Table[number].type = ELF32_ST_TYPE(esym->st_info);
		hpobject.elf_Symbol_Table[number].section = esym->st_shndx;
		
		if (config.verbose)
			print_symbol( hpobject.elf_Symbol_Table[number] );
		}
	}

	verprintf("Found %d symbols\n",number);
	verprintf("\nLooking for entry point %s\n",config.entry_point);
	
	hpobject.entry_pos = -1;
	
	unsigned int i;
	
	// Find functions and entry function
	for( i=0; i<hpobject.elf_Symbol_Table_size; i++)
	{
		if (strcmp(hpobject.elf_Symbol_Table[i].name, config.entry_point)==0)
		{
			if (hpobject.entry_pos != -1) 
			{
				printf("Error: Two or more %s() functions, check if you link"
				" with crt0.o\n", config.entry_point);
				exit(1);
			}
			hpobject.entry_pos = hpobject.elf_Symbol_Table[i].value;
			if (config.verbose)
				printf("%s entry found at offset"
				" %x\n",config.entry_point, hpobject.entry_pos);
		}
		
		if (strcmp(hpobject.elf_Symbol_Table[i].name, STACK_SYMBOL)==0)
		{
			config.rpl_mem_pos = hpobject.elf_Symbol_Table[i].value;
			if (config.verbose)
				printf("Found rpl mem size symbol at: %x\n",config.rpl_mem_pos);
		}
	}
	
	if (hpobject.entry_pos == -1)
	{
		printf("Error: no %s() functions, check if you link with crt0.o\n", 
		config.entry_point);
		exit(1);
	}
}



// Scan sections for Symbols Table, if they exist
int scan_sections_for_symbols(Elf_file  *elf_file)
{
	int cnt;
	
	verprintf( "\nLook for ELF symbol section(s):\n" );
	verprintf( "-------------------------------\n" );
	
	
	elf_file->ehdr = elf32_getehdr(elf_file->elf);
	elf_file->scn = elf_getscn(elf_file->elf, elf_file->ehdr->e_shstrndx);
	
	// Traverse input filename, printing each section 
	for (cnt = 1, elf_file->scn = NULL; (elf_file->scn = elf_nextscn(elf_file->elf, elf_file->scn)); cnt++) 
	{
		elf_file->shdr = elf32_getshdr (elf_file->scn);
		
		// Look if current section if the .symbol table
		if (elf_file->shdr->sh_type == SHT_SYMTAB) 
		{
			// Change SHT_SYMTAB to SHT_DYNSYM
			// to access the dynamic symbol table
			verprintf("Found Symbol Table\n");
			
			// You can use the function given below to print
			// out the symbol table
			fill_symbols(elf_file);
		}
		if (elf_file->shdr->sh_type == SHT_DYNSYM) 
		{
			verprintf("Found Relocation Symbol Table\n");
			//print_symbols(elf_file->elf,section,shdr);
		}
	}
	
	return(1);
}




/**
 * Copy the needed binary sections.
 */
int	Copy_Binary_Word_Aligned_Sections(Elf_file  *elf_file, HP_armobject *hpobject, char *_dest_name)
{
	unsigned int    cnt;
	// Open output binary file
	FILE *fp = fopen(_dest_name,"wb");
	if (fp==NULL)
	{
		printf("Can't create file %s.\n",_dest_name);
		return(0);
	}

	verprintf( "\nCopying binary sections:\n" );
	verprintf( "------------------------\n" );
	verprintf( "Section headers:\n" );
	verprintf( "  [Nr] Name                 Type     Addr     Size     ES Flg Lk Inf  Addr.align\n" );
	
		// Flag to know if we have to append the section to the output
	int _copy_flag;
	// If dynamic, then this variable stores plt_offset
	int plt_offset = 0;
	
	unsigned int i;
	
	// reset size values:
	hpobject->text_size = 0;
	hpobject->data_size = 0;
	hpobject->got_size = 0;
	hpobject->got_pos = -1;

	//Specific elf part
	//Elf32_Shdr *shdr;
	Elf_Scn *section;
	Elf_Data *data;
         
	elf_Section_Table_Entry entry;
	
	elf_file->ehdr = elf32_getehdr(elf_file->elf);
	section = elf_getscn(elf_file->elf, elf_file->ehdr->e_shstrndx);
	data = elf_getdata(section, NULL);
	
	//now scan the sections:
	for (cnt = 1, elf_file->scn = NULL; (elf_file->scn = elf_nextscn(elf_file->elf, elf_file->scn)); cnt++) 
	{
		elf_file->shdr = elf32_getshdr (elf_file->scn);

		if (elf_file->shdr != 0) 
		{
			entry.index=cnt;
			strcpy( entry.name, (char*) data->d_buf + elf_file->shdr->sh_name);
			entry.type = elf_file->shdr->sh_type;
			entry.address = elf_file->shdr->sh_addr;
			entry.size = elf_file->shdr->sh_size;
			entry.entsize = elf_file->shdr->sh_entsize;
			entry.flags = elf_file->shdr->sh_flags;
			entry.link = elf_file->shdr->sh_link;
			entry.info = elf_file->shdr->sh_info;
			entry.align = elf_file->shdr->sh_addralign;

			if (config.verbose)
				print_section( entry );
				
			
			// Now look if we have to add this section to the output file:
			_copy_flag = 0;

			if ((strcmp(entry.name,".plt")==0)&&(hpobject->dynamic==1))
			{
				//this section has to be altered since
				//it points to a constant position of the
				//got table (which will not be the case in the
				//futur)
				hpobject->text_size +=entry.size;
				plt_offset = entry.address;
				hpobject->entry_pos -= plt_offset;
				_copy_flag = 1;
			}

			if (strcmp(entry.name,".text")==0)
			{
				//create the binary files (word aligned)
				hpobject->text_size += entry.size;
				_copy_flag = 1;
			}

			if (strcmp(entry.name,".got")==0)
			{
				hpobject->data_size += entry.size;
				hpobject->got_pos = entry.address;
				hpobject->got_size = entry.size;

				//Required by Claudio's new loader
				if (hpobject->got_pos==MEMPACKER_RAMBASE) 
				{
					if (config.rpl_mem_size==0xfffff)
						config.rpl_mem_size=_ram_signature;
					else
						config.rpl_mem_size+=_ram_signature;

					verprintf("GOT section at %x, use new RPL mem size %x\n",MEMPACKER_RAMBASE, config.rpl_mem_size);
				}



				//LOTS of things to do here !
				if (hpobject->dynamic==1)
				{

					verprintf("Section Patched,%i bytes\n", entry.size);

					//Because it's a dynamic shared object, we
					//build our own got table based on offsets
					//given in relocation table:

					int *_data = (int*) malloc(sizeof(int)*(entry.size/4));
					if (_data==0) exit(0);

					//We write into a temporary buffer (_data)
					//the corrected values of known relocations
					for(i=0;i<(unsigned int)hpobject->elf_Relocation_Table_size; i++)
					{
						int pos_in_got = hpobject->elf_Relocation_Table[i].offset-hpobject->got_pos;
						if (hpobject->elf_Relocation_Table[i].value != 0)
						{
							_data[pos_in_got/4] = hpobject->elf_Relocation_Table[i].value-plt_offset;
						}
						else
							_data[pos_in_got/4] = 0;
	
						verprintf("Symbol %s written with value %08X, at adress"
							"%08Xof got\n",
							hpobject->elf_Relocation_Table[i].name,
							_data[pos_in_got/4],pos_in_got );
					
						if (_data[pos_in_got/4] == 0)
						{
							printf("The symbol '%s'\t written with value %08X,"
							" at offset %08X of GOT:\n"
							"  HAS TO BE RELOCATED AT RUNTIME.\n",
							hpobject->elf_Relocation_Table[i].name,
							_data[pos_in_got/4],pos_in_got );
						}
					}

					//Now we copy the content to the file:
					fwrite(_data,hpobject->got_size,1,fp);

					free(_data);
					hpobject->got_pos-=plt_offset;
				}
				else
					_copy_flag = 1;


			}

			if (strcmp(entry.name,".rodata")==0)
			{			
				//create the binary files (word aligned)
				hpobject->text_size += entry.size;
				
				// Look for a specific value in the section
				if (config.rpl_mem_pos > 0)
				{
					char *_data = (char*) (elf_getdata(elf_file->scn, NULL)->d_buf);
					config.rpl_mem_size = _data[config.rpl_mem_pos- entry.address];

					verprintf("RPL mem size from symbol: %d\n",config.rpl_mem_size);

					if (hpobject->got_pos==MEMPACKER_RAMBASE) 
					{
						if (config.rpl_mem_size==0xfffff)
							config.rpl_mem_size=_ram_signature;
						else
							config.rpl_mem_size+=_ram_signature;
						verprintf("GOT section at %x, use new RPL mem size %x\n",MEMPACKER_RAMBASE, config.rpl_mem_size);
					}
				}
				_copy_flag = 1;
			}

			if (strcmp(entry.name,".data")==0)
			{
				hpobject->data_size += entry.size;
				_copy_flag = 1;
			}

			if ((strcmp(entry.name,".dynamic")==0)&&(hpobject->dynamic==1))
			{
				// This has to be removed once we achieved to
				// alter the .plt section (change the values inside)
				hpobject->data_size += entry.size;
				_copy_flag = 1;
			}

			if (strcmp(entry.name,".bss")==0)
			{

				hpobject->data_size += entry.size;
				if (config.global!=3)
				{
					verprintf("Section created, added %d cleared "
					 "bytes\n",entry.size);
					// Create .bss section:
					for(i=0;i<entry.size;i++)
						fwrite("\0",1,1,fp);
				}
			}
			/*
			if (strcmp(pSec->GetName().c_str(),".stack")==0)
			{
				unsigned int s = _config.mem_size;

				if (s==0) s = pSec->GetSize();

				hpobject->data_size += s;

				// Append .stack section:
				for(i=0;i<s;i++)
					fwrite("\0",1,1,fp);
			}
			*/

			if (_copy_flag)
			{
				verprintf("Section added,%d bytes\n", entry.size);

				char *_data = (char*) (elf_getdata(elf_file->scn, NULL)->d_buf);

				fwrite(_data,entry.size,1,fp);

				// Append a few byte if not word aligned
				if ((entry.size%4)!=0)
				{
					verprintf("Padding %d bytes to section:%s\n",
							(int)(4-(entry.size%4)),
							entry.name);

					for(i=0; i<(4-(entry.size%4)); i++)
						fwrite("\0",1,1,fp);
				}
			}

		}
	}
	fclose(fp);
	return(1);
}





//------------------------------------------------------------------
// Start code part

//! Call the assembler to build the start code that does GOT relocation for globals
/**
 * In this start code, the A>CP (subpl r3,r3,r1,asr #28 instruction)
 * is inserted at the beginning. This code use r2, r3, r4 to compute
 * the relative offset between PC (program counter) and the GOT location.
 * It then stores the result in SL (R10 register) and call the entry point.
 *
 * 
 */
int Build_Start_Code(char *name, HP_armobject *hpobjet)
{
	char buffer[512];
	
	verprintf( "\nBuilding binary loader in tmp_conv_bin.o:\n" );
	verprintf( "-----------------------------------------\n" );
	
	
	if (config.global== OLD_GOT_GLOBALS)
	{
		//Build the start code with old globals management
		// It needs the gnu-as to be used
		FILE *fp_start = fopen("tmp_conv.s","wb");
		fprintf(fp_start,"\t.text\n");
		fprintf(fp_start,"\t.align\t1\n");
		fprintf(fp_start,"\tstmfd\tsp!, {r0, r1, r2, r3,"
		" r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}\n");	//Save flags
		if (hpobjet->got_size>0)
		{
			fprintf(fp_start,"\tldr\tsl, [pc, #4]\n");		// sl=position got
			fprintf(fp_start,"\tldr\tr2, [pc, #4]\n");		// r2=taille got
			fprintf(fp_start,"\tB\t12\n");					// saut des constantes
			fprintf(fp_start,"\t.word\t%d\n",hpobjet->got_pos+4*17);	//Position got
			fprintf(fp_start,"\t.word\t%d\n",hpobjet->got_size-4);	// Taille got
			fprintf(fp_start,"\tadd\tsl, sl, pc\n");		// sl=sl+pc (debut got)
			fprintf(fp_start,"\tsub\tsl, sl, #28\n"); 		// sl=debut got (ajustement)
			fprintf(fp_start,"\tadd\tr3, r2, sl\n"); 		// r3=fin got
			fprintf(fp_start,"\tldr\tr4, [r3]\n");			// repeat: r3=derniere ligne got
			fprintf(fp_start,"\tadd\tr4, r4, pc\n");		// r3=r3+pc
			fprintf(fp_start,"\tadd\tr4, r4, #24\n");		// r3+=24 (ajustement)
			fprintf(fp_start,"\tstr\tr4, [r3]\n");			// stocke r4 en r3
			fprintf(fp_start,"\tsub\tr2, r2, #4\n");		// remonte d'une ligne

			fprintf(fp_start,"\tcmp\tr2, #0\n");			// while(not end of got)
			fprintf(fp_start,"\tbne\t-28\n");				// go back
		}
		fprintf(fp_start,"\tBL\t %d\n",hpobjet->entry_pos+4*2); // Go to entry point
		fprintf(fp_start,"\tldmfd\tsp!, {r0, r1, r2, r3,"
		" r4, r5, r6, r7, r8, r9, r10, r11, r12, pc }\n"); // Restore flags

		fclose(fp_start);

		// Call assembler
		sprintf(buffer, "%s -EL -mcpu=arm920t -mapcs-32 -k tmp_conv.s -o tmp_conv.o ",config.AS_path);
		if (config.verbose)
		{
			printf( "Calling assembler:\n%s\n",buffer);
		}

		FILE *pipe;
		pipe = popen(buffer,"r");
		while( (!feof(pipe)) && (fgets(buffer,255,pipe)))
		{
			printf("%s\n",buffer);
		}
		pclose(pipe);
		
		// Write text section in 'name'
		// Open output binary file
		FILE *fp = fopen(name,"wb");
		if (fp==NULL)
		{
			printf("Can't create file %s.\n",name);
			return(0);
		}

		// Get only the .text section
		// Open the input file 

		int             fd;
		Elf_Data       *data;
		Elf32_Shdr     *shdr;
		Elf32_Ehdr     *ehdr;
		Elf            *elf;
		Elf_Scn        *scn;

		if ((fd = open("tmp_conv.o", O_RDONLY)) == -1)
			elf2hp_failure("Can't open input file tmp_conv.o");
		if ((elf = elf_begin(fd, ELF_C_READ, NULL)) == NULL)
			libelf_failure();

		
		unsigned int i;
		//now scan the sections for .text
	
		ehdr = elf32_getehdr(elf);
		data = elf_getdata(elf_getscn(elf, ehdr->e_shstrndx), NULL);

		//now scan the sections:
		for (i = 1, scn = NULL; (scn = elf_nextscn(elf, scn)); i++) 
		{
			shdr = elf32_getshdr (scn);

			if (shdr != 0) 
			{

				if (strcmp(".text", (char*) data->d_buf + shdr->sh_name)==0)
				{
					//create the binary files (word aligned)
					fwrite((char*)elf_getdata(scn, NULL)->d_buf, shdr->sh_size,1,fp);

					// Append a few byte if not word aligned
					if ((shdr->sh_size%4)!=0)
					{
						for(i=0; i<(4-(shdr->sh_size%4)); i++)
							fwrite("\0",1,1,fp);
					}
				}

			}
		}
		close(fd);
		fclose(fp);

		if (!config.temp_files) unlink("tmp_conv.s");
		if (!config.temp_files) unlink("tmp_conv.o");
	
	}
	else if (config.global==START_GLOBALS)
	{
		//Write text section in 'name'
		// Open output binary file
		FILE *fp = fopen(name,"wb");
		if (fp==NULL)
		{
			printf("Can't create file %s.\n",name);
			return(0);
		}
		// write SAVE REG
		//stmdn		sp!,{r0-r12,lr}
		fwrite_uc8(fp,0xff);
		fwrite_uc8(fp,0x5f);
		fwrite_uc8(fp,0x2d);
		fwrite_uc8(fp,0xe9);

		//write BRANCH main()
		// Compute BL offset:
		int offset =
			(0xffffff+(hpobjet->entry_pos)/4)%0xffffff;
		
		fwrite_uc8(fp,((unsigned char*)&offset)[0]);
		fwrite_uc8(fp,((unsigned char*)&offset)[1]);
		fwrite_uc8(fp,((unsigned char*)&offset)[2]);
		fwrite_uc8(fp,0xeb);
		
		// write RESTORE REGS
		//ldmfd		sp!,{r0r-12,pc}
		fwrite_uc8(fp,0xff);
		fwrite_uc8(fp,0x9f);
		fwrite_uc8(fp,0xbd);
		fwrite_uc8(fp,0xe8);
		if (config.verbose) printf("\n");
		fclose(fp);
	}
	else if (config.global==NO_GLOBALS)
	{
		// No globals management by elf2hp, 
		// write a 
		if (config.verbose)
		{
			printf("No code added, empty file produced.\n");
			if (config.L3_style)
				printf("L3 is chosen, the first entry in the table is the entry point\n");
		}
		FILE *fp = fopen(name,"wb");
		if (fp==NULL)
		{
			printf("Can't create file %s.\n",name);
			return(0);
		}
		fclose(fp);
	}
	else if (config.global==MMU_GLOBALS)
	{
		// start code is provided by Claudio's loader:
		// Write a blank _start code
		FILE *fp = fopen(name,"wb");
		if (fp==NULL)
		{
			printf("Can't create file %s.\n",name);
			return(0);
		}
		fclose(fp);
	}
	else 
	{
		printf("Internal error\n");
	}
	
	return(1);
}




//! Encapsulate an ARM object
/**
 * If -c option is used, then the output is of L3 format.
 * Moreover, if -C is used instead of -c, then the L3 format is filled
 * with a table containing ALL the global functions of the Elf file.
 * Remember that the A>CP code is always put since it is
 * hard-coded inside the start code.
 * \see Build_Start_Code
 */
int Append_Header(char *src_name, char *dest_name,  HP_armobject *hpobject)
{
	if (config.verbose)
	{
		printf( "\nConverting arm binary to required format (A>CP or L3):\n" );
		printf( "--------------------------------------------------------\n" );
	}
	FILE *fp_src;
	fp_src=fopen(src_name,"rb");
	if (fp_src==NULL)
	{
		printf("Cannot open %s file for input\n",src_name);
		return(0);
	}
	FILE *fp_dest;
	fp_dest=fopen(dest_name,"wb");
	if (fp_dest==NULL)
	{
		printf("Cannot open %s file for output\n",dest_name);
		fclose(fp_src);
		return(0);
	}

	unsigned int i;
			
	if (config.L3_style)
	{
		verprintf("L3 chosen: ");
		// (ibl)  Write the L3 magic header (prolog)
		fwrite_uc8(fp_dest, 0x4c);
		fwrite_uc8(fp_dest, 0xb3);
		fwrite_uc8(fp_dest, 0x80);
		verprintf("\n");
	}
	else verprintf("A>CP default.\n");
	
	char * ACP="A>CP";
	// Write A>CP in all cases
	fwrite(ACP,4,1,fp_dest);
	
	// write the ARM binary
	unsigned char c;
	while( (!feof(fp_src)) && (fread(&c,1,1,fp_src)))
		fwrite(&c,1,1,fp_dest);
	
	if (config.L3_style)
	{
		unsigned int nb_fct=0;
		unsigned int offset;
		unsigned int address;

		if (config.global==OLD_GOT_GLOBALS)
			offset = 72; // size of compiled start code
		else if (config.global==START_GLOBALS)
			offset = 12; // size of compiled small start code
		else
			offset = 0;
			
		
		if (config.L3_full_table)
		{
			verprintf("Full table added (Warning, RAM=0 for all).\n");
			// Find functions and append them
			for(i=0; i<hpobject->elf_Symbol_Table_size; i++)
			{
				//Check if symbol is a global function:
				if ((hpobject->elf_Symbol_Table[i].bind==1)&&
					(hpobject->elf_Symbol_Table[i].type==2))
				{
					// amount of ram for this function
					// UNKNOWN ??
					fwrite_uint32(fp_dest, 0);
					// Address of function:
					address = hpobject->elf_Symbol_Table[i].value+offset;
					fwrite_uint32(fp_dest, address);

					verprintf("%-34.34s(%08X) added to L3"
						" table\n",hpobject->elf_Symbol_Table[i].name,address);

					nb_fct++;
				}
			}
		}
		
		verprintf("%d functions added to L3 table\n",nb_fct);
		//Finally, add the entry point end epilog:
		//number of entry points:
		fwrite_uint32(fp_dest, nb_fct);


		// This should be	0x000FFFFF for all RAM (old Claudio's mmu)
		// This should be	0x00400000 for all RAM (new Claudio's mmu)
		
		// Take rpl stack size into account
		config.rpl_mem_size += (config.rpl_stack_size&0xf)<<24;
		if (config.verbose) 
			printf("\nARM Launcher memory information word: %08X\n",config.rpl_mem_size);
		
		fwrite_uint32(fp_dest, config.rpl_mem_size);
		
		unsigned epilog[] = 
		{
			0x00000000,
			0x00000000,
			0x3176B34C
		};
		if (config.global>=2)
		{
			epilog[0] = hpobject->entry_pos;
		}
		int epilog_size = sizeof(epilog)/sizeof(unsigned);

		// (ibl) Write L3 epilog 
		for (i = 0; i < epilog_size; i++) 
			fwrite_uint32(fp_dest, epilog[i]);
	}


	// close files
	fclose(fp_dest);
	fclose(fp_src);
	return(1);
}



//------------------------------------------------------------------
// Conversion to HP string part

//! Encapsulate a binary object into a HP49 string
/**
 * Endianess is used to write the proper size value (IBL).
 */
int Convert_HP49_String(char *src_name, char *dest_name,  HP_armobject *hpobject)
{
	if (config.verbose)
	{
		printf( "\nConverting object to HP49 string:\n" );
		printf( "-----------------------------------\n" );
	}
	FILE *fp_src;
	fp_src=fopen(src_name,"rb");
	if (fp_src==NULL)
	{
		printf("Cannot open %s file for input\n",src_name);
		return(0);
	}
	
	FILE *fp_dest;
	unsigned int size=0;
	unsigned char c;
	char buffer[255];
	
	// Compute the file size to write the HP's string header
	while( (!feof(fp_src)) && (fread(&c,1,1,fp_src)))
		size++;
	rewind(fp_src);
	
	if (config.verbose) printf("Code size:%d\n",size);
	
	fp_dest=fopen(dest_name,"wb");
	if (fp_dest==NULL)
	{
		printf("Cannot open %s file for output\n",dest_name);
		fclose(fp_src);
		return(0);
	}
	
	
	unsigned int octets=0;
	
	// Write HP's string header
	strcpy(buffer,"HPHP49-C");
	fwrite(buffer,strlen(buffer),1,fp_dest);
	fwrite_uc8(fp_dest, 0x2c);
	fwrite_uc8(fp_dest, 0x2a);
	
	// write the string size:
	// 2*size: since 1 char=2 nibbles
	// +5: for string size part (5nibbles)

	unsigned int nibbles, nibbles_ = (2*size+5)<<4;	

	// (ibl) swap words, if necessary
	if (config.bigendian) 
		SWAP_B8_IN_B32(&nibbles,&nibbles_);
	else
		nibbles = nibbles_;

	fwrite_uc8(fp_dest, ((unsigned char*)&nibbles)[0]);
	fwrite_uc8(fp_dest, ((unsigned char*)&nibbles)[1]);
	fwrite_uc8(fp_dest, ((unsigned char*)&nibbles)[2]);
	
	// copy the file, bytes by bytes
	while( (!feof(fp_src)) && (fread(&c,1,1,fp_src)))
	{
		if (config.verbose>1) printf("%02X ",c);
		fwrite(&c,1,1,fp_dest);
		octets++;
		if ((octets%4==0)&&(config.verbose>1)) printf("\t");
		if ((octets%16==0)&&(config.verbose>1)) printf("\n");
	}
	
	// close output file
	fclose(fp_dest);
	if (config.verbose)
		printf("\nConversion successful to %s (%d bytes)\n",
			dest_name,
			octets);
	fclose(fp_src);
	return(1);
}





//! Write the current LD script to be use with elf2hp
/**
 *
 */
void WriteLD_script(void)
{
	FILE *fp = fopen("elf_ld.script","wb");
	if (fp!=NULL)
	{
fprintf(fp,"\n"
"  \n"
);
	}
	fclose(fp);
}






//! Parse command line arguments
/**
 *
 */
void Arg_Check(int argc,char **argv)
{
	int i,j,files=0;
	
	for(i=1; i<argc; i++)
	{
		// printf("%s",argv[i]);
		// Look if we have an option:
		if (argv[i][0]=='-')
		{

			//then which one
			for(j=1;argv[i][j]!='\0';j++)
			{

				switch(argv[i][j])
				{
					case 'v':
						config.verbose = 1;
						if (isdigit(argv[i][j+1]))
							config.verbose = argv[i][j+1]-'0';
						break;
						
					case 't':
						config.temp_files = 1;
						break;
						
					case 'h':
	printf("elf2hp utility v1.5 (The HPGCC-Team 2005): take an elf and convert it to a L3 HP string\n"
	"Usage: elf2hp [-vtlhacmM] [-s<xxx>] [-e<foo>] a.exe a.hp\n\n"
	" Guidelines when compiling:\n"
	" --------------------------\n"
	" 1. use gcc for arm with at least:\n\t-mapcs-32 -fpic -msingle-pic-base"
	" -mpic-register=r10 -mlittle-endian\n"
	" 2. use ld for mmu-arm with at least:\n\t-T ld.script ../lib/crt0.o \n"
	" 3. use elf2hp with:\n\tprog.exe prog.hp\n\n"
	" Options are:\n"
	" -e<foo> force entry point to be <foo>\n"
	" -s<xxx> give SysRPL block size in bytes (default is 0)\n"
	" -d<xx>  Leave room to push xx * 6 pointers on the RPL stack (0-15, defaults to 1)\n"
	" -n Don't use System memory\n"
	" -m use a minimal start code (as required, GOT/globals managed inside the code)\n"
	" -M don't use a start code (no as required, GOT/globals not managed)\n"
	" -c don't use Claudio's ARM Toolbox L3-style (A>CP, output smaller)\n"
	" -a append full functions to the L3 table\n"
	" -v verbose output\n"
	" -t keep tempory files\n"
	" -l to write ld.script in current dir (Warning ld.script subject to modifications)\n"
	" -h show help\n");
						exit(0);
						break;
					case 'l':
						printf("Writing ld.script in current dir...\n");
						WriteLD_script();
						exit(0);
					case 'm':
						config.global = OLD_GOT_GLOBALS;
						break;
					case 'M':
						config.global = NO_GLOBALS;
						break;
					case 'c':
						config.L3_style = FALSE;
						break;
					case 'k':
						break;
					case 'a':
						config.L3_full_table = TRUE;
						break;
					case 'e':
						strcpy(config.entry_point,argv[i]+j+1);
						if (config.verbose)
							printf("Entry point forced to: %s\n",config.entry_point);
						j=strlen(argv[i])-1;
						break;
					case 's':
						config.rpl_mem_size = atoi(argv[i]+j+1);
						if (config.verbose)
							printf("RPL Mem fixed to: %d\n",config.rpl_mem_size);
						j=strlen(argv[i])-1;
						break;
						
					case 'd': //adjust allowed minimum RPL stack depth - Al
						config.rpl_stack_size = atoi(argv[i]+j+1);
						if (config.verbose)
							printf("%d 16-byte blocks left for pushing RPL Pointers\n",config.rpl_stack_size);
						j=strlen(argv[i])-1;
						break;
						
					case 'n':
						//< ibl; 2004-11-07 >
						// Don't use system memory
						_ram_signature &= 0x7FFFFF; // 0xCmmmmm -> 0x4mmmmm
						break;
					
					default:
						printf("Option unknown:%c\n",argv[i][j]);
						break;
				}
			}
		}
		else
		{
			switch(files)
			{
				case 0:
					strcpy(config.source,argv[i]);
					files=1;
					break;
				case 1:
					strcpy(config.destination,argv[i]);
					files=2;
					break;
				default:
					printf("Warning, no more than 2 namefiles should be given\n");
					printf("%s is unused.\n",argv[i]);
			}
		}
	}
	if (files!=2)
	{
		printf("Error, not enough arguments were given. Need 2 filenames.\n");
		printf("Try elf2hp -h.\n");
		exit(0);
	}
}





//!Load configuration file
/**
 *
 */
void Load_Conf_File(void)
{
	char buffer[255],keyword[255], value[255];
	FILE *fp;

	strcpy( config.GCC_path, "");
	strcpy( config.AS_path, "");
	strcpy( config.LD_path, "");
										
	// Look for the configuration file
	fp=fopen("elf2hp.ini", "r");
	if (fp!=NULL)
	{
		while( (!feof(fp)) && (fgets(buffer,255,fp)))
		{
			if (strlen(buffer)!=0)
				if (buffer[0]!='#')
				{
					sscanf(buffer, "%s =%s\n", keyword, value);
					if (Check_Empty_String(keyword)&&Check_Empty_String(value))
					{
						if (strcmp(keyword,"AS")==0)
							strcpy(config.AS_path,value);
						if (strcmp(keyword,"GCC")==0)
							strcpy(config.GCC_path,value);
						if (strcmp(keyword,"LD")==0)
							strcpy(config.LD_path,value);
						if ((strcmp(keyword,"ENTRY")==0) && (strcmp(config.entry_point,"_loader")==0))
							strcpy(config.entry_point, value);
					}
				}
		}
		fclose(fp);
	}
	// Else look for the defaults to use:
	else
	{
		if (config.verbose)
			printf("Initialization file (elf2hp.ini) not found! Defaults are"
			" used.\n");
			
		int asm_found = 0;
		char buffer[255];
		char prefix[255]="arm-elf-";
		char postfix[255]="";
		
		FILE *pipe;
		// try  "arm-elf-as.exe --version"
		pipe = popen("arm-elf-as.exe --version","r");
		while( (!feof(pipe)) && (fgets(buffer,255,pipe)))
		{
			if (strncmp(buffer,"GNU assembler",13)==0)
			{
				strcpy( prefix, "arm-elf-");
				strcpy( postfix, ".exe");
				strcpy( config.AS_path, "arm-elf-as.exe");
				if ( config.verbose ) printf("Found assembler: %s\n",buffer);
				asm_found = 1;
			}
			//if (_config->verbose) printf("%s\n",buffer);
		}
		pclose(pipe);
		
		if (asm_found == 0)
		{
			// try  "arm-elf-as --version"
			pipe = popen("arm-elf-as --version","r");
			while( (!feof(pipe)) && (fgets(buffer,255,pipe)))
			{
				if (strncmp(buffer,"GNU assembler",13)==0)
				{
					strcpy( prefix, "arm-elf-");
					strcpy( postfix, "");
					strcpy( config.AS_path, "arm-elf-as");
					if ( config.verbose ) printf("Found assembler: %s\n",buffer);
					asm_found = 1;
				}
				//if (_config->verbose) printf("%s\n",buffer);
			}
			pclose(pipe);

			if (asm_found == 0)
			{
				// try  "arm-linux-as --version"
				pipe = popen("arm-linux-as --version","r");
				while( (!feof(pipe)) && (fgets(buffer,255,pipe)))
				{
					if (strncmp(buffer,"GNU assembler",13)==0)
					{
						strcpy( prefix, "arm-linux-");
						strcpy( postfix, "");
						strcpy( config.AS_path, "arm-linux-as");
						if ( config.verbose ) printf("Found assembler: %s\n",buffer);
						asm_found = 1;
					}
					//if (_config->verbose) printf("%s\n",buffer);
				}
				pclose(pipe);

				if (asm_found == 0)
				{
					if ( config.verbose )
						printf("No default assembler found, check your installation"
						" of GNU AS or the PATH variable\n");
					// remove next line
					//exit(0);
				}
			}
		}

		if (strlen(config.GCC_path)==0)
		{
			strcpy( config.GCC_path, prefix);
			strcat( config.GCC_path, "gcc");
			strcat( config.GCC_path, postfix);
		}
		if (strlen(config.AS_path)==0)
		{
			strcpy( config.AS_path, prefix);
			strcat( config.AS_path, "as");
			strcat( config.AS_path, postfix);
		}
		if (strlen(config.LD_path)==0)
		{
			strcpy( config.LD_path, prefix);
			strcat( config.LD_path, "ld");
			strcat( config.LD_path, postfix);
		}
	}
	
	if (config.verbose)
	{
		printf("AS =%s\n",config.AS_path);
		printf("LD =%s\n",config.LD_path);
		printf("GCC =%s\n",config.GCC_path);
		printf("ENTRY =%s\n",config.entry_point);
	}
}








int main(int argc, char **argv)
{
	Elf_file	elf_file;

	// Give some defaults:
	config.rpl_mem_size = 0xfffff;
	config.rpl_stack_size = 1; // 16 levels
	config.global = MMU_GLOBALS;
	config.L3_style = TRUE;
	config.L3_full_table = FALSE;
	config.verbose = FALSE;
	config.temp_files = FALSE;
	strcpy(config.entry_point,"_loader");
	config.rpl_mem_pos = 0;
	
	Load_Conf_File();
	Arg_Check(argc,argv);
	
	//config.verbose = TRUE;
	config.bigendian = is_big_endian();
	
	// Check the librayr versionOpen the input file 
	if (elf_version(EV_CURRENT) ==EV_NONE)
		elf2hp_failure("Libelf out of date");

	// Open the input file 
	if ((elf_file.fd = open(config.source, O_RDONLY)) == -1)
		elf2hp_failure("Cannot open file");
	if ((elf_file.elf = elf_begin(elf_file.fd, ELF_C_READ, NULL)) == NULL)
		libelf_failure();

	VerifyHeader(&elf_file);
	
	scan_sections_for_symbols(&elf_file);
	
	// copy the required elf sections
	Copy_Binary_Word_Aligned_Sections(&elf_file, &hpobject, "tmp_conv.armbin");

	Build_Start_Code("tmp_conv.start",&hpobject);

	Cat_Binary("tmp_conv.start","tmp_conv.armbin","tmp_conv.hpbin");
	
	Append_Header("tmp_conv.hpbin", "tmp_conv.hea", &hpobject);
	
	Convert_HP49_String("tmp_conv.hea",config.destination, &hpobject);
	
	if (hpobject.elf_Symbol_Table) free(hpobject.elf_Symbol_Table);
	if (hpobject.elf_Relocation_Table) free(hpobject.elf_Relocation_Table);
	
	if (!config.temp_files) unlink("tmp_conv.start");
	if (!config.temp_files) unlink("tmp_conv.hpbin");
	if (!config.temp_files) unlink("tmp_conv.hea");
	if (!config.temp_files) unlink("tmp_conv.armbin");

	
	close(elf_file.fd);
	return(0);
}				/* end main */

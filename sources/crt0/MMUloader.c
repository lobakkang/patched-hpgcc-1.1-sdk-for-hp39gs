/*
THIS MODULE **MUST** BE COMPILED USING THE FOLLOWING OPTIONS:
arm-elf-gcc 
	-mtune=arm920t -mcpu=arm920t -mapcs-32 -mlittle-endian 
	-fomit-frame-pointer -ffixed-r10 -O3 -fno-inline -c loader.c

IT MUST BE LINKED USING THE ld.script PROVIDED

*/




// GLOBALS GENERATED BY 'LD'
extern unsigned int __data_start,__data_size,__got_start,__got_size,__bss_size;

// GLOBALS GENERATED TO BE USED BY _start

extern unsigned int _code_base,_ram_base,_heap_start;
extern unsigned int _saturn_cpu;


// _start DECLARATION
extern int _start();
extern void _init_globals(int sat_cpu,int rsize,int cbase,int hbase,int nentries);

void c_loader();




// PURE "C" FUNCTION START
// DECLARE THIS FUNCTION HERE SO IT WILL BE THE FIRST FUNCTION IN THE .text SECTION
void c_loader()
{
	
	
	register unsigned int *got_ptr,*ram_ptr asm ("sl"),*new_bss_base;
	register unsigned int code_base, got_size, data_size,bss_size;
	register int f,nitems;
	register int sat_cpu asm("r1");

// GET THE START OF THE .text SECTION
	asm volatile ("adr %0, c_loader" : "=r" (code_base));

//  GET THE NEW RAM ADDRESS
//  NOW THIS IS FIXED AT 0x09000100
 	ram_ptr=(unsigned int *)0x09000400;

//  READ NON-GLOBAL VARIABLES CREATED BY 'ld'
	
	got_ptr= (unsigned int *)((unsigned int)&__got_start+code_base);

	got_size=(unsigned int)&__got_size;
	data_size=(unsigned int)&__data_size;
	bss_size=(unsigned int)&__bss_size;

	new_bss_base=(unsigned int *)((unsigned int) ram_ptr  + got_size + data_size);


//	MOVE .GOT TABLE + DATA

// PATCH .got TABLE FOR PHYSICAL POINTERS

	nitems=got_size>>2;

	for(f=0;f<nitems;++f) {
		if(got_ptr[f]<0x09000000) ram_ptr[f]=got_ptr[f]+code_base;
		else ram_ptr[f]=got_ptr[f];
	}


//  MOVE .data SECTION TO RAM

	nitems=(data_size+got_size+3)>>2;

	for(;f<nitems;++f) ram_ptr[f]=got_ptr[f];





//  INITIALIZE .bss SECTION TO 0

	nitems=(bss_size+3)>>2;
	for(f=0;f<nitems;++f) new_bss_base[f]=0;


//  DONE! GLOBALS ARE WORKING HERE, BUT THIS MODULE WAS COMPILED WITHOUT
//  -fPIC -msingle-pic-base
//  SO WE CANNOT USE THE NEW GLOBALS DIRECTLY YET, PASS AS PARAMETERS TO
//	A FUNCTION THAT WILL THEN SET THE PROPER GLOBALS. THE FUNCTION HAS TO
//  BE IN ANOTHER MODULE COMPILED WITH THE -fPIC SWITCH


_init_globals(sat_cpu,(*( (unsigned int *) (sat_cpu+0x914))-1)<<12,code_base,(unsigned int)new_bss_base+bss_size,*( (unsigned int *) (sat_cpu+0x914)));



// RAM DATA STRUCTURE IS:
// _ram_base: (virtual address = 0x09000000
// .GOT TABLE
// .rodata SECTION (W/CONSTANTS EMBEDDED IN CODE, MOVED TO RAM)
// .data SECTION
// .bss SECTION	
// _heap_start:
// ...free memory...

// stack

}

// CACHE FLUSHING CODE

void _flush_cache() __attribute__ ((naked));

void _flush_cache()
{

asm volatile ("STMFD SP!, {R0-R1, LR}"); //save regs

asm volatile ("mov R0, #0x8000000");
asm volatile ("add R0,R0, #8"); //R0 is a pinter to the int vector
asm volatile ("adr R1, _flush_int_handler");  //R1 is address of new function
asm volatile ("swp R1, R1, [R0]"); // save the new vector
asm volatile ("add lr, pc, #0");
asm volatile ("swi 0"); //call it!
asm volatile ("str R1, [R0]"); // restore the old vector
asm volatile (" LDMFD SP!, {R0-R1, PC}"); //restore regs and return

}

void _flush_int_handler() __attribute__ ((naked));

void _flush_int_handler()
{

asm volatile ("STMFD SP!, {R0,R14}"); //save regs
asm volatile ("mov r0, #0");   // DOCS SAY: IT SHOULD BE ZERO, SO...
// INVALIDATE  D-CACHE
asm volatile ("mcr p15,0,r0,c7,c6,0");
asm volatile("nop");
asm volatile("nop");

// INVALIDATE TLB CACHE
asm volatile ("mcr p15,0,r0,c8,c6,0");
asm volatile("nop");
asm volatile("nop");

asm volatile (" LDMFD SP!, {R0,R14}"); //restore regs                                                                                           mcr     p15,0,r0,cr1,cr0,0      // update CP15 Control Register
asm volatile (" MOVS PC, R14"); //return from SWI  DEBUG!!!

}


// NAKED REQUIRED TO AVOID THE COMPILER PRESERVING THE sp REGISTER

void MMU_map() __attribute__ ((naked));

void MMU_map()
{
// MMU REMAPPING PROCEDURE
// -----------------------
// ENTRY:
// INDICATE A 4KB ALIGNED address IN R0

// EXIT:
// MEMORY STARTING AT address IS MAPPED AT 0x09000000
// A TOTAL OF 256 Kb ARE MAPPED, REGARDLESS OF REAL BLOCK SIZE

	asm volatile ("STMFD SP!, {R0-R3,fp, ip, LR}"); //save regs

	register int _sat_cpu asm("r1");
	register int *a asm("r2") =(int *)0x07f00240 ;
	register int address asm ("r0");

	// GET ADDRESS FROM SATURN REGISTERS
	address=*((int *) (_sat_cpu+0x920));

	// CREATE COARSE PAGE TABLE LEVEL ONE DESCRIPTOR
	*a=address  | 0x11;

	_flush_cache();

	asm volatile ("LDMFD SP!, {R0-R3,fp,ip,PC}"); // RETURN

}

// NAKED REQUIRED TO AVOID THE COMPILER PRESERVING THE sp REGISTER
void MMU_unmap() __attribute__ ((naked));

void MMU_unmap()
{
// MMU UNMAPPING PROCEDURE
// -----------------------
// ENTRY:
// NONE

// EXIT:
// MEMORY AT 0x09000000 IS INVALID

	asm volatile ("STMFD SP!, {R0-R3,fp, ip, LR}"); //save regs

	register int *a  asm ("r0")=(int *)0x07f00240;

	*a=0;

	_flush_cache();
	
	asm volatile ("LDMFD SP!, {R0-R3,fp,ip,PC}"); // RETURN

}


void stack_virt() __attribute__ ((naked));

void stack_virt()
{
	register int _sat_cpu asm("r1");
	register int size asm("r2");
	register int stack asm("sp");

	size=(*((int *)(_sat_cpu+0x914)))<<12;
	size+=0x08FFFFFC;
	*((int *)size)=stack;
	stack=size;

	asm ("mov pc,lr");
}

void stack_phys() __attribute__ ((naked));
void stack_phys()
{
	register int oldst asm("r0");
	register int *stack asm("sp");

	oldst=*stack;
	stack=(int *)oldst;

	asm ("mov pc,lr");
}




// ASSEMBLER SETUP

void _loader() __attribute__ ((naked));
void _loader()
{


asm ("stmfd sp!,{r0-r12,lr}");



MMU_map();

stack_virt();

// MOVE DATA TO NEW MEMORY
	c_loader();

// ALL GLOBALS WORKING FROM HERE ON...

_start();


// MOVE BACK STACK TO ORIGINAL LOCATION
stack_phys();

// ELIMINATE VIRTUAL MEMORY
MMU_unmap();


// FREE SYSTEM MEMORY IF ALLOCATED
asm("ldr r1,[sp,#4]");			// GET SATURN CPU REGISTERS
asm("ldr r1,[r1,#0x918]");		// GET B.HI
asm("tst r1,r1");				// TEST IF NULL
asm("mov r0,#101");
asm("add lr, pc,#0");
asm("swine 0");				// FREE THE BLOCK IF NOT NULL

// 	... AND RETURN
	
asm ("ldmfd sp!,{r0-r12,pc}");

}

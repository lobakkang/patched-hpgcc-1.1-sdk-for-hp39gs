// GENERAL GLOBAL VARIABLES SETUP



unsigned int _saturn_cpu;
unsigned int _ram_base_addr,_code_base_addr,_ram_size,_heap_base_addr,_mmu_table_addr,_mmu_table_entries;
void _init_globals(int sat_cpu,int rsize,int cbase,int hbase,int nentries)
{
	// Purpose is to avoid the relocation bug of ld
	char bug[] __attribute__((unused)) = "BUG";
	register int ramptr asm("sl");

_saturn_cpu=sat_cpu;
_ram_base_addr=ramptr;
_ram_size=rsize;
_heap_base_addr=hbase;
_code_base_addr=cbase;
_mmu_table_addr=0x09000000;
_mmu_table_entries=nentries;
}

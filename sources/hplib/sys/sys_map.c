extern unsigned int *_mmu_table_addr;

int sys_map_v2p(unsigned int vaddr)
{
	//translate virtual -> physical

	// NOT A VIRTUAL ADDRESS
	if( (vaddr>>24)!=0x09) return vaddr;
	return( (_mmu_table_addr[((vaddr&0x000ff000)>>12)]&0xfffff000)+(vaddr&0xfff) );
}

int sys_map_p2v(unsigned int paddr)
{
	//translate physical -> virtual
	int f;

	// ALREADY VIRTUAL ADDRESS
	if( (paddr>>24)==0x09) return paddr;
	
for(f=0;f<256;++f)
{
	if( (_mmu_table_addr[f]&0xfffff000)==(paddr&0xfffff000)) return(0x09000000+(f<<12)+(paddr&0xfff));
}

// ADDRESS IS NOT IN THE VIRTUAL TABLE, RETURN PHYSICAL ADDRESS UNCHANGED
return paddr;
}

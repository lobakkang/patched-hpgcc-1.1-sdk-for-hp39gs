#include <hpgcc49.h>

// Template for RPL stack pop/push usage
// Ingo Blank, 2004-11-24

/*
$Header: /cvsroot/hpgcc/examples/rplstk.c,v 1.4 2005/03/31 10:30:01 alborowski Exp $
*/


int
main()
{
	// argument counter
	int argc = 0;
	
	// Initialize stack access
	unsigned rpl_stack_bias = sat_stack_init();
	
	// Determine number of elements in the stack
	int level = sat_stack_depth();
	
	// Dynamically dimension argument vector just as big as needed
	char *argv[level];
	
	while (sat_stack_depth()) {
		
		SAT_STACK_ELEMENT e;
		SAT_STACK_DATA d;
		
		// Get element at level #1, i.e. stack-top
		sat_get_stack_element(1,&e);
		
		// decode it ...
		sat_decode_stack_element(&d,&e);
		
		// check validity and store in argument vector
		// Note that elements are stored in *reverse* order, since the stack is a LIFO structure
		if (d.type == SAT_DATA_TYPE_STRING)
			// remove single quotes from algebraic objects (if present)
			argv[++argc,--level] = str_unquote(d.sval,'\'');
		else
			; // unsupported data type, error message, bail out, ignore,  whatsoever ...
		
		// pop one element off the stack and continue loop
		sat_stack_drop();
	}
	
	// Now all RPL data is stored in the argv[] vector
	
	// your program here ...
	

	
	// Demo: take two arguments, convert them to integers and apply the 4 basic arithmetic operations to them
	
	if (argc >= 2) {
		int x = atoi(argv[0]);
		int y = atoi(argv[1]);
		char buf[64];
		
		// print the result formatted as an HP list object {,,,}
		sprintf(buf,"{%d %d %d %d}",x+y,x-y,x*y,y ? x/y : 0);
		
		// push the string back to the stack
		// the receiving (User)RPL pogram can convert it with STR-> to a proper list object 
		sat_stack_push_string(buf);
	}
	
	
	// Finalize stack access
	// NEVER forget that, or risk a device crash!
	sat_stack_exit(rpl_stack_bias);
	
	// Since the program does no screen output, skip exit sequence
	
	return 0;
}



#include <hpgcc49.h>
/*
demo of simple RPL stack functionality

$Header: /cvsroot/hpgcc/examples/stack.c,v 1.3 2005/03/31 10:30:01 alborowski Exp $

*/

int main()

{

	

	unsigned rpl_stack_bias = sat_stack_init(); // Initialize RPL stack

	sat_push_zint_llong(sat_pop_zint_llong()*2); //pop off a ZINT, double it, push result

	sat_stack_push_string("Hello, World!"); //push 'hello world' as a string

	sat_push_zint_llong(sat_stack_depth()); //push the stack depth as a ZINT

	sat_stack_exit(rpl_stack_bias); //close it

	return 0;

}





// Eratosthenes Sieve
//
// IBL 2004
//

#include "local_includes.h"

#define bitset(a,i) (a[i >> 5] & (1 << ( i & 31)))
#define bitclear(a,i) a[i >> 5] &= ~(1 << (i & 31))

int
erato(int n, int iter , int dump)
{
	int N,i,k,it,primes;
	unsigned bits[N=(n >> 5)+1];
	
	
	for (it = 0; it < iter ; it ++) {
	
		for(i = 0; i < N; i++)
			bits[i] = 0xFFFFFFFF;
		
		primes = 0;
		
		for(i = 2; i < n; i++)
			if (bitset(bits,i)) {
				primes++;
				if(dump) 
					printf("%d\t",i);
				for (k = i ; k < n; k += i)
					bitclear(bits,k);
			}
	}
		
	return primes;
}

			
	
int 
main()
{
	int i,N,p,iter;
	int t1;
	
	sys_intOff();
	clearScreen();
	
	printf("\020*** Eratosthenes sieve ***\n");
	
	
	N = 1000000;
	iter = 1;
	
	t1 = RTC_seconds();
	
	p = erato(N,iter,0);
	printf("\npix(%d) => %d primes.\n",N,p);
	printf("%d Iterations.\n\n",iter);
	printf("%d primes computed in %d sec.\n\n", p*iter, RTC_seconds()-t1);
	
	
		
	beep();
	
	while (! keyb_isON());
	sys_intOn();
	
	
	return 0;
	
}

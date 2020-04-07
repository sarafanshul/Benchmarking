#include <stdio.h>
#include <time.h>

#define MAXN 31

int nQueens(int n) {
  int q0,q1;
  int cols[MAXN], diagl[MAXN], diagr[MAXN], posibs[MAXN]; // Our backtracking 'stack' 
  int num=0;
  for (q0=0; q0<n-2; q0++) {
	for (q1=q0+2; q1<n; q1++){
	  int bit0 = 1<<q0;
	  int bit1 = 1<<q1;
	  int d=0; // d is our depth in the backtrack stack 
	  cols[0] = bit0 | bit1 | (-1<<n); // The -1 here is used to fill all 'coloumn' bits after n ...
	  diagl[0]= (bit0<<1 | bit1)<<1;
	  diagr[0]= (bit0>>1 | bit1)>>1;
 
	  int posib = ~(cols[0] | diagl[0] | diagr[0]);
 
	  while (d >= 0) {
		while(posib) {
		  int bit = posib & -posib; // The standard trick for getting the rightmost bit in the mask
		  int ncols= cols[d] | bit;
		  int ndiagl = (diagl[d] | bit) << 1;
		  int ndiagr = (diagr[d] | bit) >> 1;
		  int nposib = ~(ncols | ndiagl | ndiagr);
		  posib^=bit; // Eliminate the tried possibility.
		  num += ncols==-1; 
 
		  if (nposib) {
			if (posib) posibs[d++] = posib;
			cols[d] = ncols;
			diagl[d] = ndiagl;
			diagr[d] = ndiagr;
			posib = nposib;
		  }
		}
		posib = posibs[--d]; 
	  }
	}
  }
  return num*2;
}
 
 
int main() {
	double time_spent = 0.0;
    clock_t begin = clock();

    int n = 12;
	printf("%d\n%d\n",n ,nQueens(n));

	clock_t end = clock();
	time_spent += (double)(end - begin);
    printf("Time elpased is %f s", (time_spent*10)/ CLOCKS_PER_SEC);
	return 0;
}
 
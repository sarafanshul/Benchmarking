#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int count = 0;
void solve(int n, int col, int *hist) {
	if (col == n) {
		count++;
		return;
	}
 
#define attack(i, j) (hist[j] == i || abs(hist[j] - i) == col - j)
	for (int i = 0, j = 0; i < n; i++) {
		for (j = 0; j < col && !attack(i, j); j++);
		if (j < col) continue;
 
		hist[col] = i;
		solve(n, col + 1, hist);
	}
}

void nQueens(int n){
	int hist[n];
	solve(n, 0, hist);
	// printf("%d\n", count);
}
 

int main(){
	double time_spent = 0.0;
    clock_t begin = clock();

    int n = 14;
    nQueens(n);
	printf("%d\n%d\n",n ,count);

	clock_t end = clock();
	time_spent += (double)(end - begin);
    printf("Time elpased is %f s", (time_spent*10)/ CLOCKS_PER_SEC);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
 
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
	printf("%d\n", count);
}
 

int main(){
	int n = 13;
	nQueens(n);
	return 0;
}
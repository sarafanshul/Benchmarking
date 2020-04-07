// WA ONLY ONE ANSWER

/* C++ program to solve N Queen Problem using Branch 
   and Bound */
#include<bits/stdc++.h>
#define N 10
using namespace std;

int cnt = 0;

bool isSafe(int row, int col, int slashCode[N][N], 
			int backslashCode[N][N], bool rowLookup[], 
			bool slashCodeLookup[], bool backslashCodeLookup[] ) { 
	if (slashCodeLookup[slashCode[row][col]] || 
		backslashCodeLookup[backslashCode[row][col]] || 
		rowLookup[row]) return false; 
	return true; 
} 

bool solveNQueensUtil(int board[N][N], int col, 
	int slashCode[N][N], int backslashCode[N][N], bool rowLookup[N], 
	bool slashCodeLookup[], bool backslashCodeLookup[] ){ 

	if (col >= N) return true; 

	for (int i = 0; i < N; i++) { 
		if ( isSafe(i, col, slashCode, backslashCode, rowLookup, 
					slashCodeLookup, backslashCodeLookup) ) { 
			board[i][col] = 1; 
			rowLookup[i] = true; 
			slashCodeLookup[slashCode[i][col]] = true; 
			backslashCodeLookup[backslashCode[i][col]] = true; 
  
			if ( solveNQueensUtil(board, col + 1, slashCode, backslashCode, 
					rowLookup, slashCodeLookup, backslashCodeLookup) ) 
				return true; 

			board[i][col] = 0; 
			rowLookup[i] = false; 
			slashCodeLookup[slashCode[i][col]] = false; 
			backslashCodeLookup[backslashCode[i][col]] = false; 
		} 
	} 
	return false; 
} 

bool solveNQueens() { 
	int board[N][N]; 
	memset(board, 0, sizeof board); 
	int slashCode[N][N]; 
	int backslashCode[N][N]; 
	bool rowLookup[N] = {false}; 
  
	bool slashCodeLookup[2*N - 1] = {false}; 
	bool backslashCodeLookup[2*N - 1] = {false}; 
  
	for (int r = 0; r < N; r++) 
		for (int c = 0; c < N; c++){ 
			slashCode[r][c] = r + c;
			backslashCode[r][c] = r - c + 7;} 
  
	if (solveNQueensUtil(board, 0, slashCode, backslashCode, 
	  rowLookup, slashCodeLookup, backslashCodeLookup) == false ) {
		return false; 
	}
	cnt++; 
	return true; 
} 

void nQueens(){
	solveNQueens();
	cout << cnt <<"\n";
}

int main() {
	int n = 10;
	nQueens();
	return 0; 
} 
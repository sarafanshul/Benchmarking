#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <chrono> 
using namespace std::chrono; 
using namespace std;

int position[32];
int cnt = 0;

// Check if a position is safe
bool isSafe(int queen_number, int row_position) {
	// Check each queen before this one
	for (int i = 0; i < queen_number; i++) {
		// Get another queen's row_position
		int other_row_pos = position[i];
		// Now check if they're in the same row or diagonals
		if (other_row_pos == row_position || // Same row
			other_row_pos == row_position - (queen_number - i) || // Same diagonal
			other_row_pos == row_position + (queen_number - i))   // Same diagonal
			return false;
	}
	return true;
}

// Recursively generate a tuple like [0 0 0 0], then [0 0 0 1] then etc...
void solve(int k ,int n){
	if (k == n) cnt++;
	else {
		for (int i = 0; i < n; i++) {
			// Before putting a queen (the k-th queen) into a row, test it for safeness
			if (isSafe(k, i)){
				position[k] = i;
				// Place another queen
				solve(k + 1 ,n);
			}
		}
	}
}

int main(){
	auto start = high_resolution_clock::now();
	int n = 10;
  	solve(0 ,n);
	cout << cnt <<"\n";
  	auto stop = high_resolution_clock::now();
  	auto duration = duration_cast<microseconds>(stop - start);
  	cout << duration.count() << " microseconds" << "\n";
	return 0;
}
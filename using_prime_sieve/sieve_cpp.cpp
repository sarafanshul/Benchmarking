#include <iostream> 
#include <chrono> 

using namespace std; 
using namespace std::chrono; 
  
void SieveOfEratosthenes(int n ,bool prime[]) {
	for (int p=2; p*p<=n; p++) 
	{ 
		if (prime[p] == true) 
		{
			for (int i=p*p; i<=n; i += p) 
				prime[i] = false; 
		} 
	} 
}

int main() { 
	int n = (int)1e7 + 2;
	bool* prime = new bool[n+1];
	memset(prime, true, sizeof(prime));

	auto start = high_resolution_clock::now();
	SieveOfEratosthenes(n , prime);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
	return 0; 
} 

// 1e10 -> 5955683 micro ~ 5.955683sec
// 1e7 -> 50867 microseconds
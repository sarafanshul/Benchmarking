import java.util.*;
import java.lang.*;

class SieveOfEratosthenes 
{
	static int n = (int)1e9 + 2;
	static boolean prime[] = new boolean[n+1];

	static void sieveOfEratosthenes() { 
		for(int p = 2; p*p <=n; p++)
		{
			if(prime[p])
			{ 
				for(int i = p*2; i <= n; i += p) 
					prime[i] = false; 
			}
		}

	}
	public static void main(String args[]) 
	{	
		Arrays.fill(prime, true);
		long startTime = System.nanoTime();
		sieveOfEratosthenes();
		long endTime   = System.nanoTime();
		long totalTime = endTime - startTime;
		System.out.println(totalTime); // 17 sec for 1e9
		double no_of_primes = 0;
		for(long i = 0; i <n ; ++i)
			if(prime[(int)i])
				no_of_primes += 1;
		System.out.println((int)no_of_primes);
	} 
}
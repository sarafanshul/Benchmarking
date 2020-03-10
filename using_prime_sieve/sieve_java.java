import java.util.*;
import java.lang.*;

class SieveOfEratosthenes 
{
	static int n = (int)1e7 + 2;
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
		long _time = 0;
		for (int i = 0 ; i<4 ; ++i){
			Arrays.fill(prime, true);
			long startTime = System.nanoTime();
			sieveOfEratosthenes();
			long endTime   = System.nanoTime();
			_time += endTime - startTime;
			
			Arrays.fill(prime, true);
		}
		System.out.println(_time);
		// double no_of_primes = 0;
		// for(long i = 0; i <n ; ++i)
		// 	if(prime[(int)i])
		// 		no_of_primes += 1;
		// System.out.println((int)no_of_primes);
	} 
}
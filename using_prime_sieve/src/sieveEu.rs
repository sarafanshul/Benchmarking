#![allow(non_snake_case)]
#![allow(non_camel_case_types)]

pub fn prime_sieve(max_number_to_check: usize , prime_mask : &mut Vec<bool>){
    prime_mask[0] = false;
    prime_mask[1] = false;
    let mut p: usize = 2;
    while p*p <= max_number_to_check{
    	if prime_mask[p]{
    	    let mut i = p*p;
    	    while i <= max_number_to_check{
    	    	prime_mask[i] = false;
    	    	i += p;
    	    }
    	}
    	p += 1
    }
}

pub fn sieveEu(N : usize){
    let prime_mask: &mut Vec<bool> = &mut vec![true; N+2];
    prime_sieve(N , prime_mask);
}

// 1e7 in  1.770041056
// 1e8 in  18.258102879
#![allow(non_snake_case)]
#![allow(non_camel_case_types)]
#![allow(warnings)]

extern crate time;
use std::time::{Instant};
mod sieveEu;

fn main() {
    let n: usize = 1e7f64 as i64 as usize;
    let prime_mask: &mut Vec<bool> = &mut vec![true; n+2];
    let now = Instant::now();

    sieveEu::prime_sieve(n , prime_mask);

    println!("Time elapsed = {:?} , N = {} ",now.elapsed() , n);
    // println!("check => SIEVE {:?}", &prime_mask[1..10]);
}

// 1e7 in  1.770041056
// 1e8 in  18.258102879
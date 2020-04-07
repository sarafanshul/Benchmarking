
#![feature(test)]
extern crate test;
extern crate time;

use std::time::{Instant};
use test::Bencher;

mod nQueens;

fn main() {
    let t = 15;
    
    // use this 
    let now = Instant::now();
    let ret = nQueens::parallel_n_queens(t);
    println!("{:?}",ret );
    println!("(P)Time elapsed = {:?}",now.elapsed()); // fastest
    
    let now = Instant::now();
    let ret = nQueens::n_queens(t);
    println!("{:?}",ret );
    println!("(S)Time elapsed = {:?}",now.elapsed());
}

// // Tests

#[test]
fn test_n_queens() {
    let real = vec!(10usize);
    for num in real {
        // assert!(n_queens(num as i32) == real[num]);
        println!("{:?}", nQueens::n_queens(num as i32));
    }
}

#[test]
fn test_parallel_n_queens() {
    let real = vec!(10usize);
    for num in real {
        // assert!(parallel_n_queens(num as i32));
        println!("{:?}", nQueens::parallel_n_queens(num as i32));
    }
}

#[bench]
 fn bench_nonParallel(b: &mut Bencher) {
    // println!("{:?}", n_queens(11));
    b.iter(|| {
        nQueens::n_queens(11);
    });
    }


#[bench]
 fn bench_parallel(b: &mut Bencher) {
        // println!("{:?}", parallel_n_queens(11));
        b.iter(|| {
        nQueens::parallel_n_queens(11);
    });
    }


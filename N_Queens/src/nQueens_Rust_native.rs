// #[cfg(test)] extern crate test;
// #[cfg(test)] use test::Bencher;

// #[cfg(test)]

#![feature(test)]

extern crate test;

extern crate time;
use std::time::{Instant};
use test::Bencher;

use std::thread;
use std::sync::mpsc::channel;
use std::sync::mpsc::{Sender, Receiver};
use std::sync::mpsc;


fn n_queens(n: i32) -> usize {
    return n_queens_helper((1 << n as usize) -1, 0, 0, 0);
}

fn n_queens_helper(all_ones: i32, left_diags: i32, columns: i32, right_diags: i32) -> usize {
 
    let mut solutions = 0;

    let mut valid_spots = !(left_diags | columns | right_diags) & all_ones;

    while valid_spots != 0 {
        let spot = -valid_spots & valid_spots;
        valid_spots = valid_spots ^ spot;
        solutions += n_queens_helper(
            all_ones,
            (left_diags | spot) << 1,
            (columns | spot),
            (right_diags | spot) >> 1);
    }
    return solutions + ((columns == all_ones) as usize)
}

fn parallel_n_queens(n: i32) -> usize {
    let all_ones = (1 << n as usize) - 1;
    let columns = 0;
    let left_diags = 0;
    let right_diags = 0;

    let mut valid_spots = !(left_diags | columns | right_diags) & all_ones;
    let (tx, rx) = channel();
    while valid_spots != 0 {
        let spot = -valid_spots & valid_spots;
        valid_spots = valid_spots ^ spot;
        let tx = tx.clone();
        thread::spawn(move ||{
            tx.send(n_queens_helper(
                all_ones,
                (left_diags | spot) << 1,
                (columns | spot),
                (right_diags | spot) >> 1));
        });
    }

    let mut results = 0;
    for value in rx.iter().take(n as usize) {
        results += value;
    }
    return results + ((columns == all_ones) as usize)
}


fn main() {
    let t = 14;
    let ret = parallel_n_queens(t);
    let now = Instant::now();
    println!("{:?}",ret );
    println!("(P)Time elapsed = {:?}",now.elapsed());
    let ret = n_queens(t);
    let now = Instant::now();
    println!("{:?}",ret );
    println!("(S)Time elapsed = {:?}",now.elapsed());
}

// // Tests

#[test]
fn test_n_queens() {
    let real = vec!(10usize);
    for num in real {
        // assert!(n_queens(num as i32) == real[num]);
        println!("{:?}", n_queens(num as i32));
    }
}

#[test]
fn test_parallel_n_queens() {
    let real = vec!(10usize);
    for num in real {
        // assert!(parallel_n_queens(num as i32));
        println!("{:?}", parallel_n_queens(num as i32));
    }
}

#[bench]
 fn bench_nonParallel(b: &mut Bencher) {
    // println!("{:?}", n_queens(11));
    b.iter(|| {
        n_queens(11);
    });
    }


#[bench]
 fn bench_parallel(b: &mut Bencher) {
        // println!("{:?}", parallel_n_queens(11));
        b.iter(|| {
        parallel_n_queens(11);
    });
    }


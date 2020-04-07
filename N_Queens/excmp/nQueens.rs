use std::thread;
use std::sync::mpsc::channel;
use std::sync::mpsc::{Sender, Receiver};
use std::sync::mpsc;

pub fn n_queens(n: i32) -> usize {
    return n_queens_helper((1 << n as usize) -1, 0, 0, 0);
}

pub fn n_queens_helper(all_ones: i32, left_diags: i32, columns: i32, right_diags: i32) -> usize {
 
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

pub fn parallel_n_queens(n: i32) -> usize {
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


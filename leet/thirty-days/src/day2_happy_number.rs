use std::collections::HashSet;
use std::io;

struct Solution {}

impl Solution {
    pub fn is_happy(mut n: i32) -> bool {
        let mut seen_before = HashSet::new();
        while !seen_before.contains(&n) {
            seen_before.insert(n);
            n = n
                .to_string()
                .chars()
                .map(|c| c.to_digit(10).unwrap().pow(2))
                .sum::<u32>() as i32;
            if n == 1 {
                return true;
            }
        }
        false
    }
}

fn main() {
    let mut line = String::new();
    io::stdin()
        .read_line(&mut line)
        .expect("failed to read input");
    let n: i32 = line.trim().parse::<i32>().expect("failed parsing integer");
    println!("{}", Solution::is_happy(n));
}

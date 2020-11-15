struct Solution {}

impl Solution {
    pub fn get_row(row: i32) -> Vec<i32> {
        let mut memo = vec![vec![0; 34]; 2];
        memo[0][0] = 1;
        memo[1][0] = 1;
        for ii in 1..row + 1 {
            let i = ii as usize;
            // choose 0 is 1
            memo[1][0] = 1;
            for j in 1..i {
                memo[1][j] = memo[0][j] + memo[0][j - 1];
            }
            // choose i is 1
            memo[1][i] = 1;
            // copy
            for i in 0..memo[1].len() {
                memo[0][i] = memo[1][i];
            }
        }
        memo[1][..row as usize + 1].to_vec()
    }
}

fn main() {
    println!("{:?}", Solution::get_row(3));
}

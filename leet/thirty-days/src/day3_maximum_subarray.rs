use std::cmp::max;
use std::io;

struct Solution {}

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let (mut m, mut curr) = (nums[0], nums[0]);
        for i in &nums[1..] {
            curr = max(*i, curr + *i);
            m = max(curr, m);
        }
        m
    }
}

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let ans = Solution::max_sub_array(
        s.trim()
            .split(|c| c == ',' || c == ' ')
            .map(|x| x.parse::<i32>().unwrap())
            .collect(),
    );
    println!("{:?}", ans);
}

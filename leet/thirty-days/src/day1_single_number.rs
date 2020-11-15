fn main() {
    let s = Solution {
        nums: vec![1, 2, 3, 4, 5, 5, 4, 3, 2],
    };
    println!("{}", Solution::single_number(s.nums))
}

struct Solution {
    nums: Vec<i32>,
}

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        nums.iter().fold(0, |x, y| x ^ y)
    }
}

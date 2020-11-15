struct Solution {}

impl Solution {
    pub fn shuffle(nums: Vec<i32>, n: i32) -> Vec<i32> {
        let mut res = nums.clone();
        let (left, right) = res.split_at(n as usize);
        left.iter().zip(right).map(|x| x.iter()).flatten().collect()
    }
}

fn main() {
    println!("{:?}", Solution::shuffle(vec![1, 2, 3, 4, 5, 6], 3))
}

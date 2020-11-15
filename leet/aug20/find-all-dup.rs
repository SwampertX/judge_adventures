struct Solution {}

impl Solution {
    pub fn find_duplicates(nums: Vec<i32>) -> Vec<i32> {
        let mut nums_copy: Vec<i32> = nums.iter().map(|x| x - 1).collect();
        let n = nums_copy.len() as i32;
        let mut ans = Vec::new();
        for i in 0..n {
            let val = nums_copy[i as usize] % n;
            if nums_copy[val as usize] >= n {
                ans.push(val + 1 as i32);
            } else {
                nums_copy[val as usize] += n;
            }
        }
        ans
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::find_duplicates(vec![4, 3, 2, 7, 8, 2, 3, 1])
    );
}

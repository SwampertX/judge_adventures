struct Solution {}

impl Solution {
    pub fn move_zeroes(nums: &mut Vec<i32>) {
        nums.sort_by_key(|x| *x == 0);
    }

    pub fn move_zeroes_bad(nums: &mut Vec<i32>) {
        let mut write_pt = 0;
        for i in 0..nums.len() {
            match nums[i] {
                0 => continue,
                _ => {
                    nums[write_pt] = nums[i];
                    write_pt += 1;
                }
            }
        }
        for i in write_pt..nums.len() {
            nums[i] = 0;
        }
    }
}

fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let mut nums: Vec<i32> = s
        .trim()
        .split(|x| x == ' ' || x == ',')
        .map(|x| x.parse::<i32>().unwrap())
        .collect();
    println!("{:?}", nums);
    Solution::move_zeroes(&mut nums);
    println!("{:?}", nums);
}

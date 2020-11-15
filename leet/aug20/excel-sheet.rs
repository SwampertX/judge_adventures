struct Solution {}

impl Solution {
    pub fn title_to_number(s: String) -> i32 {
        let l = s.len();
        let mut ans = 0;
        for (i, c) in s.chars().enumerate() {
            ans += 26_i32.pow((l - i - 1) as u32) * ((c as u8 - 'A' as u8 + 1) as i32);
        }
        ans
    }
}

fn main() {
    println!("{}", Solution::title_to_number(String::from("ZY")));
}

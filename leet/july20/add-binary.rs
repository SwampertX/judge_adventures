struct Solution {}

impl Solution {
    // target string can be as long as 10000 digits -> around 10^3 digits decimal
    // pub fn add_binary(a: String, b: String) -> String {
    //     let ans = i32::from_str_radix(&a, 2).unwrap() + i32::from_str_radix(&b, 2).unwrap();
    //     format!("{:b}", ans)
    // }
    pub fn add_binary(a: String, b: String) -> String {
        let mut ans = Vec::<u8>::new();
        let mut carry = 0;
        let max_len = usize::max(a.len(), b.len());
        let a_iter = a.bytes().rev().chain(std::iter::repeat(b'0'));
        let b_iter = b.bytes().rev().chain(std::iter::repeat(b'0'));
        for (i, (c, d)) in a_iter.zip(b_iter).enumerate() {
            let sum = c - b'0' + d - b'0' + carry;
            if i >= max_len && sum == 0 {
                break;
            }
            ans.push(sum % 2 + b'0');
            carry = sum / 2;
            // println!("{:?}", ans);
        }
        ans.reverse();
        String::from(std::str::from_utf8(&ans).unwrap())
    }
}

fn main() {
    println!(
        "{}",
        Solution::add_binary(String::from("1010"), String::from("1010"))
    );
}

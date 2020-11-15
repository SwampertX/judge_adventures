struct Solution {}

impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let newlen = s.chars().filter(|x| x.is_ascii_alphanumeric()).count();
        s.chars()
            .filter(|x| x.is_ascii_alphanumeric())
            .take(newlen / 2)
            .map(|x| x.to_ascii_lowercase())
            .eq(s
                .chars()
                .filter(|x| x.is_ascii_alphanumeric())
                .rev()
                .map(|x| x.to_ascii_lowercase())
                .take(newlen / 2))
    }
}

fn main() {
    println!("{}", Solution::is_palindrome(String::from("abcdcba")));
    println!("{}", Solution::is_palindrome(String::from("abccba")));
    println!(
        "{}",
        Solution::is_palindrome(String::from("A man, a plan, a canal: Panama"))
    );
}

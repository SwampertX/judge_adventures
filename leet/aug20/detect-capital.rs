struct Solution {}

impl Solution {
    pub fn detect_capital_use(word: String) -> bool {
        // if first letter is low, make sure rest low
        // if first letter is upper, second is lower, make sure rest low
        // else make sure all upper
        if word.len() == 1 {
            return true;
        }
        let first: char = word.chars().nth(0).unwrap();
        let second: char = word.chars().nth(1).unwrap();
        if first.is_lowercase() {
            return word.chars().all(|x| x.is_lowercase());
        } else if second.is_lowercase() {
            return word.chars().skip(1).all(|x| x.is_lowercase());
        } else {
            return word.chars().all(|x| x.is_uppercase());
        }
    }
}

fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s = s.trim().to_string();
    println!("{}", Solution::detect_capital_use(s));
}

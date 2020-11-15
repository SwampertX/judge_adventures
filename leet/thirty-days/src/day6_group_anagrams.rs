struct Solution {}

impl Solution {
    fn is_anagram_of(str1: &str, str2: &str) -> bool {
        return str1.chars().collect::<Vec<_>>().sort() == str2.chars().collect::<Vec<_>>().sort();
    }

    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut acc: Vec<Vec<String>> = vec![];
        let mut filtered = strs.clone();
        while !filtered.is_empty() {
            let curr = filtered[0].clone();
            acc.push(
                filtered
                    .iter()
                    .filter(|&x| Solution::is_anagram_of(x, &curr))
                    .map(|x| x.to_string())
                    .collect::<Vec<_>>(),
            );
            filtered = filtered
                .iter()
                .filter(|&x| !Solution::is_anagram_of(x, &curr))
                .map(|x| x.to_string())
                .collect();
        }
        acc
    }
}

fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let strs: Vec<String> = s
        .trim()
        .split(", ")
        .map(|x| x.trim_matches('"').to_string())
        .collect();
    println!("{:?}", strs);
    println!("{:?}", Solution::group_anagrams(strs));
    // println!("{:?}", strs);
}

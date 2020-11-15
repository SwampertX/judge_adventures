struct Solution {}

use std::collections::HashMap;
impl Solution {
    pub fn count_sub_trees(n: i32, edges: Vec<Vec<i32>>, labels: String) -> Vec<i32> {
        let mut ans = vec![HashMap::new(); n as usize];
        for (i, map) in ans.iter().enumerate() {
            map.insert(labels[i..i + 1], 1);
        }
        for edge in edges.iter().rev() {
            let s = edge[0] as usize;
            let e = edge[1] as usize;
            // ans[s] += (labels[s..s + 1] == labels[e..e + 1]) as i32 * ans[e];
            // if end child does not have parent's label, skip
            // else ans[s][labels[s]] += ans[e][labels[s]]
            if ans[e].contains_key(labels[s..s + 1]) {
                ans[s][labels[s..s + 1]] += ans[e][labels[s..s + 1]];
            }
        }
        labels
            .as_bytes()
            .iter()
            .map(|b| ans[String::from_utf8(b)])
            .collect()
    }
}

fn main() {}

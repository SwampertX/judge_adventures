use std::collections::HashSet;

struct Solution {}

impl Solution {
    pub fn prison_after_n_days(cells: Vec<i32>, n: i32) -> Vec<i32> {
        let mut days: Vec<Vec<i32>> = Vec::new();
        let mut seen_before = HashSet::new();
        let mut curr = cells.clone();
        let mut next = curr.clone();
        let mut iterate = 1 << 8;
        // for _ in 0..n {
        loop {
            if iterate <= 0 {
                break;
            }
            days.push(curr.clone());
            seen_before.insert(curr.clone());
            for i in 0..8 {
                next[i] = if i == 0 || i == 7 {
                    0
                } else {
                    curr[i - 1] ^ curr[i + 1]
                }
            }
            curr = next.clone();
            iterate -= 1;
        }
        println!("curr {:?}", curr);
        println!("{} entries in days", days.len());
        let loop_start_day = days.iter().position(|x| *x == curr).unwrap();
        let answer_loc = days
            .iter()
            .position(|x| *x == vec![0, 0, 1, 1, 1, 1, 1, 0])
            .unwrap();
        println!(
            "loop starts at {}, answer found at {}",
            loop_start_day, answer_loc
        );
        let period = days.len() - loop_start_day;
        let rem = ((n as usize) - days.len()) % period;
        println!("period is {}, rem is {}", period, rem);
        for i in 0..days.len() {
            println!("{}: {:?}", i, days[i]);
        }
        return days[rem + loop_start_day].clone();

        //     if seen_before.contains(&curr) {
        //         // get the period = days length
        //         // rem = n % period
        //         // return days[rem]
        //         println!("curr {:?}", curr);
        //         println!("{} entries in days", days.len());
        //         let loop_start_day = days.iter().position(|x| *x == curr).unwrap();
        //         let answer_loc = days
        //             .iter()
        //             .position(|x| *x == vec![0, 0, 1, 1, 1, 1, 1, 0])
        //             .unwrap();
        //         println!(
        //             "loop starts at {}, answer found at {}",
        //             loop_start_day, answer_loc
        //         );
        //         let period = days.len() - loop_start_day;
        //         let rem = ((n as usize) - days.len()) % period;
        //         println!("period is {}, rem is {}", period, rem);
        //         for i in 0..days.len() {
        //             println!("{}: {:?}", i, days[i]);
        //         }
        //         return days[rem + loop_start_day].clone();
        //     } else {
        //         days.push(curr.clone());
        //         seen_before.insert(curr.clone());
        //         for i in 0..8 {
        //             next[i] = if i == 0 || i == 7 {
        //                 0
        //             } else {
        //                 curr[i - 1] ^ curr[i + 1]
        //             }
        //         }
        //     }
        //     curr = next.clone();
        // }

        // return curr;
        // }
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::prison_after_n_days([1, 0, 0, 1, 0, 0, 1, 0].to_vec(), 1_000_000_000)
    );
}

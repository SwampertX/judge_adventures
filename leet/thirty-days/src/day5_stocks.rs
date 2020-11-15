struct Solution {}

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut is_looking_for_peak = false;
        let mut valley = prices[0];
        let mut profit = 0;
        for i in 0..prices.len() {
            if !is_looking_for_peak {
                // look for valley
                if (i == 0 || prices[i] < prices[i - 1])
                    && (i == prices.len() - 1 || prices[i + 1] >= prices[i])
                {
                    // is valley
                    valley = prices[i];
                    is_looking_for_peak = true;
                    // println!("valley is {}", valley);
                }
            } else {
                if (i == 0 || prices[i] >= prices[i - 1])
                    && (i == prices.len() - 1 || prices[i + 1] < prices[i])
                {
                    // is peak
                    is_looking_for_peak = false;
                    profit += prices[i] - valley;
                    // println!(
                    //     "peak is {}, profit is {}. Total profit is {}",
                    //     prices[i],
                    //     prices[i] - valley,
                    //     profit
                    // );
                }
            }
        }
        profit
    }
}

fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let v = s
        .trim()
        .split(|c| c == ' ' || c == ',')
        .map(|x| x.parse::<i32>().unwrap())
        .collect();
    println!("{:?}", v);
    println!("{}", Solution::max_profit(v));
}

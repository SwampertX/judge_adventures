struct Solution {}

impl Solution {
    pub fn num_water_bottles(num_bottles: i32, num_exchange: i32) -> i32 {
        let mut drank = num_bottles;
        let mut num_bot;
        let mut empty = num_bottles;
        while empty >= num_exchange {
            num_bot = empty / num_exchange;
            empty = empty % num_exchange;
            drank += num_bot;
            empty += num_bot;
            // println!("empty {} num_bot {} drank {}", empty, num_bot, drank);
        }
        drank
    }
}

fn main() {
    println!("{}", Solution::num_water_bottles(9, 3));
}

use std::io;

struct Solution {}

impl Solution {
    fn digit_square_sum(mut n: i32) -> i32 {
        let mut sum = 0;
        while n != 0 {
            let tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        sum
    }

    pub fn is_happy(n: i32) -> bool {
        let (mut slow, mut fast) = (n, n);
        loop {
            slow = self::Solution::digit_square_sum(slow);
            fast = self::Solution::digit_square_sum(fast);
            fast = self::Solution::digit_square_sum(fast);
            // println!("slow:{}, fast:{}", slow, fast);
            if slow == fast {
                break;
            }
        }
        slow == 1
    }
}

fn main() {
    let mut line = String::new();
    io::stdin()
        .read_line(&mut line)
        .expect("failed to read input");
    let n: i32 = line.trim().parse::<i32>().expect("failed parsing integer");
    println!("{}", Solution::is_happy(n));
}

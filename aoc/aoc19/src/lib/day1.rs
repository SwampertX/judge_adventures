use std::io;

pub fn run() {
    let mut sum = 0;
    loop {
        let mut input = String::new();
        match io::stdin().read_line(&mut input) {
            Ok(_) => {
                let ans = input.trim().parse::<i64>();
                match ans {
                    // part 1
                    // Ok(ans) => sum += ans / 3 - 2,
                    // part 2
                    Ok(ans) => sum += recursive_fuel(ans),
                    Err(_) => break,
                }
            }
            Err(_) => break,
        }
    }
    println!("{}", sum);
}

fn recursive_fuel(fuel: i64) -> i64 {
    let mut sum: i64 = 0;
    let mut fuel = fuel;
    while fuel > 0 && fuel / 3 - 2 > 0 {
        {
            sum += fuel / 3 - 2;
            fuel = fuel / 3 - 2;
        }
    }
    sum
}

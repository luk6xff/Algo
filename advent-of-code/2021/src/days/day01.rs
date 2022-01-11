use super::day::{Day};
use itertools::Itertools;

pub struct Day01 {}

impl Day for Day01 {
    fn day_number(&self) -> &str {
        "01"
    }

    fn part_1(&self) -> String {
        let input: Vec<i32> = self.load_input()
                                .lines()
                                .filter_map(|n| n.parse::<i32>().ok())
                                .collect();
        let mut sum: i32 = 0;
        let mut last_x = input[0];
        for x in input {
            if x > last_x {
                sum += 1;
            }
            last_x = x;
        }

        sum.to_string()
    }

    fn part_2(&self) -> String {
        let input: Vec<i32> = self.load_input()
                                .lines()
                                .filter_map(|n| n.parse::<i32>().ok())
                                .collect();
        let sum = input.into_iter()
                        .tuple_windows::<(_, _, _)>()
                        .tuple_windows()
                        .filter(|((a1, a2, a3), (b1, b2, b3))| (b1 + b2 + b3) > (a1 + a2 + a3))
                        .count();
        sum.to_string()
    }
}

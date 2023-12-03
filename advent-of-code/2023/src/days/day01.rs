use super::day::{Day};

pub struct Day01 {}

impl Day for Day01 {
    fn day_number(&self) -> &str {
        "01"
    }

    fn part_1(&self) -> String {
        let res: u32 = self.load_input()
                                .lines()
                                .map(|line| {
                                    let it = line.chars();
                                    let digits: Vec<char> = it.filter(|c| c.is_digit(10)).collect();
                                    let first = digits.first().cloned().unwrap_or_default();
                                    let second = digits.last().cloned().unwrap_or(first);
                                    let concat_str: String = vec![first, second].iter().collect();
                                    concat_str.parse::<u32>().unwrap_or_default()
                                })
                                .sum::<u32>();
        res.to_string()
    }

    fn part_2(&self) -> String {

        String::from(" ")
    }
}

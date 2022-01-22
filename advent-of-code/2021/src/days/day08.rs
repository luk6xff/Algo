use super::day::{Day};


pub struct Day08 {}

impl Day08 {
    fn parse_input(input: &str) -> Vec<Vec<String>> {
        input.lines()
            .map(|line| line
                .split(" | ")
                .nth(1)
                .unwrap()
                .split(' ')
                .map(String::from)
                .collect::<Vec<String>>()
            ).collect::<Vec<Vec<String>>>()
    }
}

impl Day for Day08 {
    fn day_number(&self) -> &str {
        "08"
    }

    fn part_1(&self) -> String {
        let input = Day08::parse_input(&self.load_input());
        let ret: u64 = input.into_iter()
                            .map(|v| v)
                            .fold(0, |prev, curr|
                                prev + if curr.len() == 2 || curr.len() == 3 || curr.len() == 4 || curr.len() == 7 {1} else {0} as u64
                            );
        println!("RES:{}", ret);
        String::new()
        //res.to_string()
    }

    fn part_2(&self) -> String {
        String::new()
    }
}

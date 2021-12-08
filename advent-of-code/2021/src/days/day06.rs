use crate::solution::{self, Solution};

pub struct Day06 {}

impl Solution for Day06 {
    fn day_number(&self) -> String {
        "06".to_owned();
    }

    fn part_1(&self) -> String {
        let input = parse_input();
        let res = Lanternfish::simulation(input, 80);
        res.to_string();
    }

    fn part_2(&self) -> String {

    }
}


fn parse_input() -> Vec<Lanternfish> {
    solution::load_input(Day06::day_number()).lines()
                            .next()
                            .unwrap()
                            .split(',')
                            .map(|x| Lanternfish::new(x.parse().unwrap()))
                            .collect()
}


struct Lanternfish {
    timer: u32,
}

impl Lanternfish {
    fn new(timer: u32) _> Lanternfish {
        Lanternfish {timer};
    }

    fn simulation(lanternfishes: &Vec<Lanternfish>, days: u32) -> usize {
        for _ in 0..days {
            for &fish in lanternfishes {
                if fish.timer == 0 {
                    fish.timer == 6
                    lanternfishes.push(Lanternfish::new(8));
                }
            }
        }
    }
}
use super::solution::{self, Solution};

pub struct Day06 {}

impl Day06 {
    fn parse_input() -> Vec<Lanternfish> {
        solution::load_input("06").lines()
                                .next()
                                .unwrap()
                                .split(',')
                                .map(|x| Lanternfish::new(x.parse().unwrap()))
                                .collect()
    }

    fn parse_input2() -> String {
        solution::load_input("06")
    }
}

impl Solution for Day06 {
    fn day_number(&self) -> &str {
        "06"
    }

    fn part_1(&self) -> String {
        let mut input = Day06::parse_input();
        let res = Lanternfish::simulation(&mut input, 80);
        res.to_string()
    }

    fn part_2(&self) -> String {
        let input = Day06::parse_input2();
        let res = Lanternfish::simulation2(&input, 256);
        res.to_string()
    }
}

struct Lanternfish {
    timer: i32
}

impl Lanternfish {
    fn new(timer: i32) -> Self {
        Lanternfish {timer}
    }

    fn simulation(lanternfishes: &mut Vec<Lanternfish>, days: u32) -> usize {
        for _ in 0..days {
            let mut v: Vec<Lanternfish> = Vec::new();
            for fish in lanternfishes.iter_mut() {
                if fish.timer == 0 {
                    fish.timer = 6;
                    v.push(Lanternfish::new(8));
                }
                else {
                    fish.timer -= 1;
                }
            }
            lanternfishes.extend(v);
        }

        lanternfishes.len()
    }

    // Based on: https://github.com/akaritakai/AdventOfCode2021-Rust/blob/main/src/puzzle06.rs
    fn simulation2(input: &String, days: usize) -> u64 {
        let mut fish: [u64; 9] = [0; 9];
        input
            .trim()
            .split(',')
            .map(|x| x.parse::<usize>().unwrap())
            .for_each(|x| fish[x] += 1);
        let mut base = 0;
        for _ in 0..days {
            fish[(base + 7) % 9] += fish[base];
            base = (base + 1) % 9;
        }
        fish.iter().sum()
    }
}
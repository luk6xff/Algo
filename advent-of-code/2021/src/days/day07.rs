use super::day::{Day};
use std::fmt;


// CrabSubmarine
struct CrabSubmarine {
    start_pos: u32,
    dest_pos: u32
}

impl CrabSubmarine {

    fn new(start: u32, dest: u32) -> Self {
        CrabSubmarine {
            start_pos: start,
            dest_pos: dest
        }

    }

    fn compute_distance(&self) -> u32 {
        let result: u32;
        if self.start_pos > self.dest_pos {
            result = self.start_pos - self.dest_pos;
        }
        else {
            result = self.dest_pos - self.start_pos;
        }
        result
    }
}



pub struct Day07 {}

impl Day for Day07 {
    fn day_number(&self) -> &str {
        "07"
    }

    fn part_1(&self) -> String {
        let mut input: Vec<u32> = self.load_input()
                        .lines()
                        .next()
                        .unwrap()
                        .split(',')
                        .map(|x| x.parse().unwrap())
                        .collect::<Vec<u32>>();
        input.sort();
        // Compute median
        let med;
        let len = input.len();
        if len % 2 != 0 {
            med = input[len / 2];
        }
        else {
            med = (input[(len - 1) / 2] + input[len / 2]) / 2;
        }
        let fuel: u32 = input.iter()
                            .map(|&x| CrabSubmarine::new(x, med))
                            .collect::<Vec<_>>()
                            .into_iter()
                            .map(|cs| cs.compute_distance())
                            .sum();
        fuel.to_string()
    }

    fn part_2(&self) -> String {
        let mut input: Vec<u32> = self.load_input()
                        .lines()
                        .next()
                        .unwrap()
                        .split(',')
                        .map(|x| x.parse().unwrap())
                        .collect::<Vec<u32>>();
        input.sort();
        // Compute median
        let med;
        let len = input.len();
        if len % 2 != 0 {
            med = input[len / 2];
        }
        else {
            med = (input[(len - 1) / 2] + input[len / 2]) / 2;
        }
        let fuel: u32 = input.iter()
                            .map(|&x| CrabSubmarine::new(x, med))
                            .collect::<Vec<_>>()
                            .into_iter()
                            .map(|cs| cs.compute_distance())
                            .sum();
        println!("Fuel: {}", fuel);
        fuel.to_string()
    }
}

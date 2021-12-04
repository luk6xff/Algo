use std::fs::read_to_string;
use std::path::Path;
use itertools::Itertools;
use lazy_static::lazy_static

lazy_static! {
    static ref REGEXP: Regex = Regex::new(r"(?P<x>\d+)-(?P<y>\d+) (?P<letter>[a-z]): (?P<password>[a-z]+)").unwrap();
}

fn parse_input(input: &str) -> Vec<i32> {
    input.lines()
         .filter_map(|n| n.parse::<i32>().ok())
         .collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    fn common_solution(k_combinations: usize) {
        let input = parse_input(include_str!("../input/day01.txt"));
        match combination_summing_to_n(&input, k_combinations, 2020) {
            Some(s) => println!("Solution: {}", s.iter().product::<i32>()),
            None => println!("No solution found"),
        }
    }

    #[test]
    fn part_1() {
        common_solution(2)
    }

    #[test]
    fn part_2() {
        common_solution(3)
    }
}
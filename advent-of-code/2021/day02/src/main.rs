// Usage: cd 2021/day02 && cargo run

use std::io::{self, Error, ErrorKind, Read, Write};
use std::str::FromStr;


// Command
enum CommandType {
    Forward(u8),
    Down(u8),
    Up(u8)
}

// Submarine
struct Submarine {
    h_pos: u32,
    depth: u32,
    goal: u32
}

impl Submarine {

    fn new() -> Self {
        Submarine {
            h_pos: 0,
            depth: 0,
            goal: 0
        }

    }

    fn process(&mut self, cmds: &[CommandType]) {
        for cmd in cmds {
            match cmd {
                CommandType::Forward(v) => {
                    self.h_pos += *v as u32;
                }
                CommandType::Down(v) => {
                    self.depth += *v as u32;
                }
                CommandType::Up(v) => {
                    self.depth -= *v as u32;
                }
            }
        }
    }
}

use std::num::ParseIntError;

impl FromStr for CommandType {

    fn from_str(line: &str) -> Result<Self, ParseIntError> {
        let mut words = line.split_ascii_whitespace();
        let first = words
                    .next()
                    .ok_or_else(|| Err("Invalid input"));
        let second = words
                    .next()
                    .ok_or_else(|| Err("Invalid input"))?
                    .parse::<u8>()?;
        match first {
            "forward" => Ok(CommandType::Forward(second)),
            "down" => Ok(CommandType::Down(second)),
            "up" => Ok(CommandType::Up(second)),
            _ => Err("Invalid input"),
        }
    }
}

fn parse_input(input: &str) -> Vec<CommandType> {
    input
        .lines()
        .map(|line| CommandType::from_str(line))
        .collect::<std::result::Result<Vec<_>, _>>()?;
}

fn part_1(input: &[CommandType]) {

    //println!("part_1={}", sum);
}

fn part_2(input: &[CommandType]) {

}

fn main() {
    let input = parse_input(include_str!("../input.txt"));
    part_1(&input);
    part_2(input);
}

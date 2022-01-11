use super::day::{Day};
use std::str::FromStr;
use std::num::ParseIntError;
use std::fmt;

// Command
enum CommandType {
    Forward(u8),
    Down(u8),
    Up(u8)
}

impl FromStr for CommandType {
    type Err = ParseIntError;

    fn from_str(line: &str) -> Result<Self, Self::Err> {
        let mut words = line.split_whitespace();
        let option = words.next().unwrap();
        let value: u8 = words.next().unwrap().parse::<u8>().unwrap();
        //println!("--------->Words: {}, {}", option, value);
        match option {
            "forward" => Ok(CommandType::Forward(value)),
            "down" => Ok(CommandType::Down(value)),
            "up" => Ok(CommandType::Up(value)),
            _ => unreachable!(),
        }
    }
}

// Submarine
struct Submarine {
    h_pos: u32,
    depth: u32,
    aim: u32
}

impl Submarine {

    fn new() -> Self {
        Submarine {
            h_pos: 0,
            depth: 0,
            aim: 0
        }

    }

    fn process_1(&mut self, cmds: &[CommandType]) {
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

    fn process_2(&mut self, cmds: &[CommandType]) {
        for cmd in cmds {
            match cmd {
                CommandType::Forward(v) => {
                    self.h_pos += *v as u32;
                    self.depth += self.aim * *v as u32;
                }
                CommandType::Down(v) => {
                    self.aim += *v as u32;
                }
                CommandType::Up(v) => {
                    self.aim -= *v as u32;
                }
            }
        }
    }
}

impl fmt::Display for Submarine {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "({}, {})", self.h_pos, self.depth)
    }
}

pub struct Day02 {}

impl Day02 {
    fn parse_input(input: &str) -> Vec<CommandType> {
        let res = input
                    .lines()
                    .map(|line| CommandType::from_str(line))
                    .collect::<Result<Vec<_>, _>>();
        match res {
            Ok(res) => {
                return res;
            },
            Err(_) => {
                println!("Shit happened!");
                unreachable!();
            }
        }
    }
}

impl Day for Day02 {
    fn day_number(&self) -> &str {
        "02"
    }

    fn part_1(&self) -> String {
        let input = Day02::parse_input(&self.load_input());
        let mut submarine = Submarine::new();
        submarine.process_1(&input);
        (submarine.h_pos * submarine.depth).to_string()
    }

    fn part_2(&self) -> String {
        let input = Day02::parse_input(&self.load_input());
        let mut submarine = Submarine::new();
        submarine.process_2(&input);
        (submarine.h_pos * submarine.depth).to_string()
    }
}

// Usage: cd 2021/day02 && cargo run

use itertools::Itertools;


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

    fn process(&self, cmds: &[CommandType]) {
        
    }


}

fn parse_input(input: &str) -> Vec<i32> {
    input.lines()
         .filter_map(|n| n.parse::<i32>().ok())
         .collect()
}

fn part_1(input: &[i32]) {

    println!("part_1={}", sum);
}

fn part_2(input: Vec<i32>) {

}

fn main() {
    let input = parse_input(include_str!("../input.txt"));
    part_1(&input);
    part_2(input);
}

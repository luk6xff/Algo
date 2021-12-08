use std::fs;
use std::io;


pub trait Solution {
    fn day_number(&self) -> String;
    fn part_1(&self) -> String;
    fn part_2(&self) -> String;
}

pub fn load_input(day_number: &str) -> String {
    let file_path = format!("input/day{}.txt", day_number);
    fs::read_to_string(&file_path).unwrap_or_else(|_| panic!("Error while reading file: {}", file_path));
}
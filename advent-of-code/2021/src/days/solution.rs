use std::fs;
use std::path::Path;

pub trait Solution {
    fn day_number(&self) -> &str;
    fn part_1(&self) -> String;
    fn part_2(&self) -> String;
}

pub fn load_input(day_number: &str) -> String {
    let path = format!("../input/day{}.txt", day_number);
    let file_path = Path::new(&path);
    fs::read_to_string(&file_path).unwrap_or_else(|_| panic!("Error while reading file: {}", file_path.display()))
}
mod days;
mod utils;

struct DaySolutions {
    days: Vec<Box<dyn days::solution::Solution>>,
}

impl DaySolutions {
    fn add(&mut self, day_solution: Box<dyn days::solution::Solution>) {
        self.days.push(day_solution)
    }

    fn run(&self) {
        for day in self.days.iter() {
            println!("Day:{} -> part_1={}", day.day_number(), day.part_1());
            println!("Day:{} -> part_2={}", day.day_number(), day.part_2());
        }
    }
}


fn main() {
    run();
}

fn run() {
    let mut solutions = DaySolutions{days:Vec::new()};
    // Add all the days
    solutions.add(Box::new(days::day06::Day06{}));
    // Run all the soulutions
    solutions.run();
}
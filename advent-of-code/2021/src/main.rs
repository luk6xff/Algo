mod days;
mod utils;

struct DaySolutions {
    days: Vec<Box<dyn days::day::Day>>,
}

impl DaySolutions {
    fn add(&mut self, day_solution: Box<dyn days::day::Day>) {
        self.days.push(day_solution)
    }

    fn run(&self) {
        for day in self.days.iter() {
            let _timer = utils::timer::Timer::new();
            println!("\nDay:{} -> part_1={}", day.day_number(), day.part_1());
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
    solutions.add(Box::new(days::day01::Day01{}));
    solutions.add(Box::new(days::day02::Day02{}));
    solutions.add(Box::new(days::day03::Day03{}));
    solutions.add(Box::new(days::day06::Day06{}));
    // Run all the soulutions
    solutions.run();
}
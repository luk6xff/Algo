mod days;
mod solution;

fn main() {
    run();
}

//println!("part_1={}", submarine.h_pos * submarine.depth);

fn run() {
    let solutions = 25;
    let day = Day06::new();
    println!("part_1={}", day.part_1());
}
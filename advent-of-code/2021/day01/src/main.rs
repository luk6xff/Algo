use itertools::Itertools;

fn parse_input(input: &str) -> Vec<i32> {
    input.lines()
         .filter_map(|n| n.parse::<i32>().ok())
         .collect()
}

fn part_1(input: &[i32]) {
    let mut sum: i32 = 0;
    let mut last_x = input[0];
    for x in input {
        if *x > last_x {
            sum += 1;
        }
        last_x = *x;
    }

    println!("part_1={}", sum);
}

fn part_2(input: Vec<i32>) {
    println!("part_2={}",
    input
    .into_iter()
    .tuple_windows::<(_, _, _)>()
    .tuple_windows()
    .filter(|((a1, a2, a3), (b1, b2, b3))| (b1 + b2 + b3) > (a1 + a2 + a3))
    .count());
}

fn main() {
    let input = parse_input(include_str!("../input.txt"));
    part_1(&input);
    part_2(input);
}

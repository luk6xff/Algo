// Usage: cd 2021/day03 && cargo run

fn parse_input(input: &str) -> Vec<&str> {
    input
        .lines()
        .collect::<Vec<_>>()
}

fn part_1(input: &Vec<&str>) {
    // Create result vector
    let vec_len = input.len();
    let pos_len = input[0].len();
    println!("vec_len={}, pos_len={}", vec_len, pos_len);
    let mut res = vec![0; pos_len];

    let mut gamma_rate: String = String::new();
    let mut epsilon_rate: String = String::new();

    for i in 0..pos_len {
        for val in input {
            let chars: Vec<char> = val.chars().collect();
            if chars[i] == '1' {
                res[i] += 1;
            }
        }

        if res[i] > (vec_len / 2) {
            gamma_rate += "1";
            epsilon_rate += "0";
        } else {
            gamma_rate += "0";
            epsilon_rate += "1";
        }
    }

    println!("part_1={}", usize::from_str_radix(&gamma_rate.to_string(), 2).unwrap() * usize::from_str_radix(&epsilon_rate.to_string(), 2).unwrap());
}

fn part_2(input: &Vec<&str>) {
    // TODO
    println!("part_2={}", 1);
}

fn main() {
    let input = parse_input(include_str!("../input.txt"));
    part_1(&input);
    part_2(&input);
}

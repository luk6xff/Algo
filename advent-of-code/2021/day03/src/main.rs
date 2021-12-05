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


type Matrix<T> = Vec<Vec<T>>;

pub fn generator(input: &str) -> Matrix<char> {
    input
        .lines()
        .map(|line| line.trim())
        .map(|line| line.chars().collect())
        .collect()
}


fn part_2(input: &[Vec<char>]) {
    // let pos_len = input[0].len();
    // let mut oxygen_input = input;
    // let mut oxygen_raw = vec![[0, 0]; pos_len];
    // let mut oxygen_gen = 0;

    // let mut co2_input = oxygen_input.clone();
    // let mut co2_raw = oxygen_raw.clone();
    // let mut co2_scrub = 0;

    // for i in 0..pos_len {
    //     // Filter oxygen
    //     let i_max = get_i_max(&oxygen_raw, i);
    //     oxygen_raw = gen_raw(oxygen_raw, pos_len, &oxygen_input);
    //     oxygen_input = oxygen_input
    //         .iter()
    //         .filter(|x| x.chars().into_iter().nth(i).unwrap() == i_max)
    //         .copied()
    //         .collect();

    //     // Filter Co2
    //     let i_max = get_i_max(&co2_raw, i);
    //     co2_raw = gen_raw(co2_raw, pos_len, &co2_input);
    //     co2_input = co2_input
    //         .iter()
    //         .filter(|x| x.chars().into_iter().nth(i).unwrap() != i_max)
    //         .copied()
    //         .collect();

    //     if oxygen_input.len() == 1 {
    //         oxygen_gen = isize::from_str_radix(oxygen_input.first().unwrap(), 2).unwrap();
    //     }

    //     if co2_input.len() == 1 {
    //         co2_scrub = isize::from_str_radix(co2_input.first().unwrap(), 2).unwrap();
    //     }
    // }

    let num_length = input[0].len(); // yeah, again, super unsafe
    let mut o2_reports = input.to_vec();
    let mut co2_reports = input.to_vec();

    for i in 0..num_length {
        let majority_digit_count = o2_reports
            .iter()
            .map(|line| line[i])
            .fold((0, 0), |acc, d| match d {
                '0' => (acc.0 + 1, acc.1),
                '1' => (acc.0, acc.1 + 1),
                _ => unreachable!(),
            });

        let majority_digit = if majority_digit_count.0 > majority_digit_count.1 {
            '0'
        } else {
            '1'
        };

        o2_reports.retain(|line| line[i] == majority_digit);
        if o2_reports.len() == 1 {
            break;
        }
    }

    for i in 0..num_length {
        let digit_count = co2_reports
            .iter()
            .map(|line| line[i])
            .fold((0, 0), |acc, d| match d {
                '0' => (acc.0 + 1, acc.1),
                '1' => (acc.0, acc.1 + 1),
                _ => unreachable!(),
            });

        let minority_digit = if digit_count.1 < digit_count.0 {
            '1'
        } else {
            '0'
        };

        co2_reports.retain(|line| line[i] == minority_digit);
        if co2_reports.len() == 1 {
            break;
        }
    }

    let o2_rating_string: String = o2_reports[0].iter().collect();
    let co2_rating_string: String = co2_reports[0].iter().collect();

    let o2_rating = u32::from_str_radix(&o2_rating_string, 2).unwrap();
    let co2_rating = u32::from_str_radix(&co2_rating_string, 2).unwrap();

    println!("part_2={}", o2_rating * co2_rating);
    //println!("part_2={}, {}", oxygen_gen, co2_scrub);
}

// Helpers
fn get_i_max(raw: &[[u32; 2]], i: usize) -> char {
    if raw[i][0] > raw[i][1] {
        return '0';
    }
    return '1';
}

fn gen_raw(mut old: Vec<[u32; 2]>, pos_len: usize, input: &[&str]) -> Vec<[u32; 2]> {
    for i in 0..pos_len {
        let mut z = 0;
        let mut o = 0;
        for j in input {
            match j.chars().nth(i).unwrap() {
                '0' => z += 1,
                '1' => o += 1,
                _ => {}
            }
        }
        *old.get_mut(i).unwrap() = [z, o];
    }

    old
}

fn main() {
    let input = parse_input(include_str!("../input.txt"));
    part_1(&input);
    part_2(&generator(include_str!("../input.txt")));
}

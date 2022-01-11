use super::day::{Day};


type Matrix<T> = Vec<Vec<T>>;

pub struct Day03 {}

impl Day03 {
    fn parse_input(input: &str) -> Vec<&str> {
        input.lines()
            .collect::<Vec<_>>()
    }

    fn parse_input2(input: &str) -> Matrix<char> {
        input.lines()
            .map(|line| line.trim())
            .map(|line| line.chars().collect())
            .collect()
    }
}

impl Day for Day03 {
    fn day_number(&self) -> &str {
        "03"
    }

    fn part_1(&self) -> String {
        let data = self.load_input();
        let input = Day03::parse_input(&data);
        let vec_len = input.len();
        let pos_len = input[0].len();
        //println!("vec_len={}, pos_len={}", vec_len, pos_len);
        let mut res = vec![0; pos_len];

        let mut gamma_rate: String = String::new();
        let mut epsilon_rate: String = String::new();

        for i in 0..pos_len {
            for val in &input {
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

        (usize::from_str_radix(&gamma_rate.to_string(), 2).unwrap() * usize::from_str_radix(&epsilon_rate.to_string(), 2).unwrap()).to_string()
    }

    fn part_2(&self) -> String {
        let input = Day03::parse_input2(&self.load_input());
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

        (o2_rating * co2_rating).to_string()
    }
}

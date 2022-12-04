fn main() {

    let file: &str = include_str!("./input.txt");
    let mut lines: Vec<u32> =
        file.split("\n\n")
        .map( |line| line.split("\n")
            .flat_map(|num| num.parse::<u32>())
            .sum::<u32>())
        .collect();
    lines.sort_by(|a, b| b.cmp(a));

    println!("{:?}",lines[0] + lines[1] + lines[2]);

}

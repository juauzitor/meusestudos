
fn main() {
    let mut string = String::new();
    std::io::stdin().read_line(&mut string).unwrap();
    let num = string.trim().parse::<i32>().unwrap();
    for _i in 0..num {
        let mut string = String::new();
        std::io::stdin().read_line(&mut string).unwrap();
        let p = string.trim().parse::<i32>().unwrap();
        if p > 8000 {
            println!("Mais de 8000!");
        } else {
            println!("Inseto!");
        }
    }
}

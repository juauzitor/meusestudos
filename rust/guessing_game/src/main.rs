use std::io; // Biblioteca padrão de in e out put extendida da bibliteca padrão std
use rand::Rng;
use std::cmp::Ordering;

fn main() {
    println!("Guess the number!");
    
    let secret_number = rand::thread_rng().gen_range(1..101); // Gerar o numbero aleatório
    
    println!("The secret number is: {}", secret_number);
    loop {
    
        println!("Please input your number.");

        let mut guess = String::new(); // Let serve para declarar a variavel e mut é para dizer se ela é mutável ou não. String::new é para criar uma nova string vazia

        io::stdin().read_line(&mut guess).expect("Fail to read line");// Chamada da função padrão de entrada, metodo padrão para receber valores, em caso de erro é possivel colocar o expect para avisar.
        
        let guess: u32 = match guess.trim().parse() {Ok(num) => num, Err(_) => continue,};

        println!("Your guessed: {}", guess);

        match guess.cmp(&secret_number){
            Ordering::Less => println!("Too small"),
            Ordering::Greater => println!("Too big"),
            Ordering::Equal => {
                println!("You win");
                break;
            }
            
        }
    }
}

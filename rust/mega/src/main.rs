//use std::io; // Biblioteca padrão de in e out put extendida da bibliteca padrão std
use rand::Rng;

fn main() {
    let mut cont = 0u32;
    loop {
        cont += 1;
        let secret_number = rand::thread_rng().gen_range(1..61); // Gerar o numbero aleatório
        println!("The {} number is: {}", cont, secret_number);
 
        if cont == 6{
            break;
        }
    }
}

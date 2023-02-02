use std::collections::*;

fn main() {

    let mut vec1 = vec![1, 2, 3];
    for x in &vec1 {
        print!("{} ", x);
    }
    
    println!("");

    vec1.push(4);
    let vec2 = Vec::from([1, 2, 3, 4]);

    for x in &vec1 {
        print!("{} ", x);
    }
    // assert_eq!(vec, [7, 1, 2, 3]);

    println!("\nHello, world!");
}

mod lib_1;
use lib_1::service_1::*;

mod lib_2;

fn main() {
    af::f1();
    af::f2();
    bf::f1();
    bf::f3();

    // lib2service_fn_1::f1_lib2service_1();
    // lib2service_fn_1::f2_lib2service_1();

    // let mut vec1 = vec![1, 2, 3];
    // for x in &vec1 {
    //     print!("{} ", x);
    // }

    // println!("");

    // vec1.push(4);
    // let vec2 = Vec::from([1, 2, 3, 4]);

    // for x in &vec1 {
    //     print!("{} ", x);
    // }
    // // assert_eq!(vec, [7, 1, 2, 3]);

    println!("\nHello, world!");
}
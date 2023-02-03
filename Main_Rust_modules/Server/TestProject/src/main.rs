mod lib_1;
mod lib_2;

use lib_1::service_1::*;
use std::fmt::Debug;

trait PrintInOption {
    fn print_in_option(self);
}

// 这里需要一个 `where` 从句，否则就要表达成 `T: Debug`
// 或使用另一种间接的方法。
impl<T> PrintInOption for T where
    Option<T>: Debug {
    // 我们要将 `Option<T>: Debug` 作为限定，因为那是要打印的内容。
    // 不这样做的话，很可能就用到错误的限定。
    fn print_in_option(self) {
        println!("{:?}", Some(self));
    }
}

fn main() {
    let vec = vec![1, 2, 3];
    vec.print_in_option();

    af::f1();
    af::f2();
    bf::f1();
    bf::f3();

    let demo: [&str; 7] = ["Adil"; 7];
    println!("Array {:?}", demo);

    let array: [String; 8] = core::array::from_fn(|_i| { String::from("rust is good!") });
    println!("{:#?}", array);

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
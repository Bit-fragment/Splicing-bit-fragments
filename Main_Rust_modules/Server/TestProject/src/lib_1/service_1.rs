// module_path!("./lib_2");

// #[warn(unused_imports)]
// pub(crate) use lib_2::lib2service::*;
// use crate::lib_2;

pub(crate) mod af {
    use crate::lib_2::lib2service::lib2service_fn_1;
    use crate::lib_1::lib1_1::lib1_1_fn::lib1_1_mod;

    pub fn f1() {
        println!("This is f1() of af.");
        lib2service_fn_1::f1_lib2service_1();
        lib1_1_mod::lib1_1_mod_fn1();
    }

    pub fn f2() {
        println!("This is f2() of af.");
        lib2service_fn_1::f2_lib2service_1();
    }
}

pub(crate) mod bf {
    pub fn f1() {
        println!("This is f1() of bf.")
    }

    pub fn f3() {
        println!("This is f3() of bf.")
    }
}

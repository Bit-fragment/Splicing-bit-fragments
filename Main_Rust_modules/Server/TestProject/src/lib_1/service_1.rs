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

        println!("累加1到100: {}", lib1_1_mod::lib1_1_mod_sum(100));
        print!("排序前: ");
        let mut list: [i32; 5] = [5, 1, 3, 4, 2];
        for x in list {
            print!("{} ", x);
        }
        print!("数组长度为:{}", list.len());
        lib1_1_mod::lib1_1_mod_sort(&mut list);
        print!(" 排序后: ");
        for x in list {
            print!("{} ", x);
        }
        print!("\n");
    }

    pub fn f2() {
        println!("This is f2() of af.");
        lib2service_fn_1::f2_lib2service_1();
        let envelopes: Vec<Vec<i32>> = vec![vec![5, 4], vec![6, 4], vec![6, 7], vec![2, 3]];
        println!("354. 俄罗斯套娃信封问题 https://leetcode.cn/problems/russian-doll-envelopes/");
        let return_var: i32 = lib1_1_mod::max_envelopes(envelopes);
        println!("结果: {}", return_var);
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

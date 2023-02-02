pub(crate) mod lib1_1_mod {
    pub fn lib1_1_mod_fn1() {
        println!("This is lib1_1_mod_fn1() of lib1_1_mod.")
    }

    // 递归累加
    pub fn lib1_1_mod_sum(var: i32) -> i32 {
        if var <= 1 {
            return 1;
        }
        return lib1_1_mod_sum(var - 1) + var;
    }

    // 冒泡排序
    pub fn lib1_1_mod_sort(list: &mut [i32]) {
        let mut _i: usize = 0;
        let mut _y: usize = 0;
        let leng: usize = list.len();
        while _i < leng - 1 {
            _y = _i + 1;
            while _y <= leng - 1 {
                if list[_i] > list[_y] {
                    let var = list[_i];
                    list[_i] = list[_y];
                    list[_y] = var;
                }
                _y = _y + 1;
            }
            _i = _i + 1;
        }
    }

    pub fn max_envelopes(envelopes: Vec<Vec<i32>>) -> i32 {
        let length = envelopes.len();
        println!("envelopes: Vec<Vec<i32>> 的长度为: {}", length);


        return 0;
    }
}
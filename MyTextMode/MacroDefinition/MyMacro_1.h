//
// Created by XMZR on 2022/8/16.
//

#ifndef MYCPPWORLD_MYMACRO_1_H
#define MYCPPWORLD_MYMACRO_1_H{ \
    std::cout << "Macro definition: #define MYCPPWORLD_MYMACRO_1_H" << std::endl;                          \
};
#define hon1{ \
MYCPPWORLD_MYMACRO_1_H              \
};

#define hon2(val){ \
    std::cout<<object::f1(val)<<std::endl; \
    std::cout<<object::f2(val)<<std::endl;\
};

class object {
public:
    int static f1(int value) {
        if (value <= 1) return 1;
        return f1(value - 1) + value;
    }

    static int f2(int value) {
        if (value <= 1) return 1;
        return f1(value - 1) * value;
    }

};

#endif MYCPPWORLD_MYMACRO_1_H

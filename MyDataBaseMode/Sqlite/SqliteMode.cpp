//
// Created by XMZR on 2022/9/21.
//
#include <iostream>
#include "SqliteMode.h"

int main() {
    system("chcp 65001");

    const char *sql1 = "SELECT name, age FROM text1 WHERE age < 30;";
    const char *sql2 = "INSERT INTO text1(name, age) VALUES('小明', 222);";
    SqlActuator sqlActuator;
    std::string value = sqlActuator.WithReturnValue(sql1);
    std::clog << value << std::endl;

    return 0;
}
//
// Created by XMZR on 2022/10/10.
//
#include <iostream>
#include "windows.h"
#include "MyException.h"

using namespace std;

int main() {
    int MyValue = 1;
    while (1) {
        Sleep(500);
        try {
            switch (MyValue) {
                case 1:
                    throw MyException();
                case 2:
                    throw MyException("MyException:My exception description");
                case 3:
                    throw Exception_1();
                case 4:
                    throw Exception_1("Exception_1:My exception description");
                case 5:
                    throw Exception_2("Exception_2:My exception description");
                default:
                    exit(0);
            }
        } catch (Exception_1 &e1) {
            e1.output();
        } catch (MyException &e) {
            e.output();
        } catch (...) {//捕获任何异常
            cout << "Unknown exception" << endl;
        }
        MyValue++;
    }
    return 0;
}
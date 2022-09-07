#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <array>
#include <cstring>
#include "main.h"
#include "mode1/FileUtil.h"
#include "mode1/Object.h"
#include <fstream>
#include "MyTextMode/MyList.h"
#include "windows.h"
#include "MyTextMode/MyException.h"

using namespace std;

void Hello() {
    std::cout << "hello world, I'm a thread!" << std::endl;
}

auto getList1(int size) {
    return vector<int>(size);
}

int *getList2(int size) {
    int *pi = new int[size];
    return pi;
}

struct Ob {
public:
    string email;
    string password;

    string toString() {
        string str;
        str += "{email:" + email + ",password:" + password + "}";
        return str;
    }
};

struct User {//关键字struct表明，这些代码定义的是一个结构的布局。{结构体}
public:
    int age = 0;
    string name;
    double yue = 0;
    Ob ob;

    string toString() {
        string str;
        str += "{age:" + to_string(age) + ",name:" + name + ",yue:" + to_string(yue) + ",ob:" + ob.toString() + "}";
        return str;
    }
};

enum meiju {//枚举类型
    NO1 = 5, NO2 = 3
};

int *getMyList(int size) {
    int *pi = new int[size];
    for (int i = 1; i <= size; ++i) {
        pi[i - 1] = i;
    }
    return pi;
}

template<class T>
void wenhao(T value) {
    cout << typeid(value).name() << endl;
}

void whileRun(long i) {
    AbstractClass *abc = (AbstractClass *) new MyClass_1(to_string(i));
    AbstractClass *abc1 = (AbstractClass *) new MyClass_2(to_string(i));
    abc->star();
    abc1->star();
    delete abc1;
    delete abc;
}

int main() {
    /*Object object;
    FileUtil user;*/

    /*MyList myList;
    for (int i = 0; i < 20; ++i) {
        myList.add(i);
    }
    cout << "myList size:" << myList.getSize() << endl;
    for (int i = 0; i < myList.getSize(); ++i) {
        cout << myList.get(i) << " ";
    }
    try {
        cout << "\nBefore exception" << endl;
        cout << "\n" << myList.get(21) << endl;
        cout << "\nAfter exception" << endl;
    } catch (const char *msg) {
        cout << msg << endl;
    }*/

    /*int a = 1, b = -1;
    while (1) {
        Sleep(1000);
        try {
            if (a + b == 0)throw "Denominator cannot be zero Exception ";
            cout << "Results of normal calculation " << (4 / (a + b)) << endl;
            b < 0 ? b = 1 : b = -1;
        } catch (const char *p) {
            cout << p << b << endl;
            b < 0 ? b = 1 : b = -1;
        }
    }*/

    /*try {
        int b = 2, c = -2;
        if (b + c == 0) {
            throw Object();
        }
        int a = 1 / (b + c);
        cout << "\n" << a << endl;
    } catch (Object &p) {
        cout << "\n" << p.f2(10) << endl;
    }*/

    /*int MyValue = 1;
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
    }*/

    /*MyException *exp = new Exception_2();
    MyException *exp1 = new Exception_1();
    exp->output();
    exp1->output();
    delete exp1;
    delete exp;*/

    /*long i = 0;
    while (1) {
        i++;
        whileRun(i);
//        Sleep(50);
    }*/


    /*int qwe[5];//数组与指针的关系
    int *pio = qwe;
    for (int i = 0; i < 5; ++i) {
        cout << &pio[i] << " ";
    }
    cout << endl;
    cout << "qwe: " << qwe << endl;
    cout << "&qwe: " << &qwe << endl;
    cout << "pio: " << pio << endl;
    //cout << "*pio: " << *pio << endl;
    cout << "&pio: " << &pio << endl;

    cout << endl;
    int *pp = getMyList(5);
    int *po = getMyList(2);

    for (int i = 0; i < 5; ++i) {
        cout << pp[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 2; ++i) {
        cout << po[i] << " ";
    }

    delete[]pp;
    delete[]po;*/

    /*char char_str[] = "wenhao";
    cout << "\nchar_str:" << char_str << ";size:" << strlen(char_str) << endl;
    char *pkl = new char[strlen(char_str) + 1];
    //strcpy()函数接受2个参数。第1个是目标地址，第2个是要复制的 字符串的地址。
    //函数将字符串中剩余的部分复制到数组后面的内存 字节中
    //strcpy(pkl, char_str);
    //strncpy()函数接受3个参数。第1个是目标地址，第2个是要复制的 字符串的地址。第3个参数—要复制的最大字符数
    strncpy(pkl, char_str, strlen(char_str));
    cout << "*pkl:";
    for (char item: char_str) {
        cout << item;
    }
    delete[] pkl;*/

    /*Ob *obpi = new Ob{"wenhao", "password"};
    Ob *obpi1 = new Ob{"1", "2"};
    cout << obpi->email << " " << obpi->password << " obpi:" << &obpi << endl;
    cout << (*obpi1).email << " " << (*obpi1).password << " obpi1:" << &obpi1 << endl;
    delete obpi1;
    delete obpi;*/

    /*tuple<string, vector<int>, int> mydata{"wenhao", {1, 4}, 6};
    auto p1 = get<0>(mydata);
    auto p2 = get<1>(mydata);
    auto p3 = get<2>(mydata);
    cout << p1 << endl;
    cout << "get<1>(mydata):";
    for (auto item: p2) {
        cout << item << " ";
    }
    cout << endl;
    cout << p3 << endl;*/

    /*char char_str11[5];
    cout << "Enter:" << endl;
    cin >> char_str11;
    char *char_list2 = new char[strlen(char_str11) + 1];
    strcpy(char_list2, char_str11);
    cout << "char_list2: " << char_list2 << endl;
    delete[]char_list2;*/

    /*User list[10];//枚举测试
    for (int i = 0; i < 10; ++i) {
        list[i] = {10 + i, "wocao" + to_string(i), 123.123987 + i, {"201067242@qq.com", "42901002wen"}};
    }
    for (int i = 0; i < 10; ++i) {
        cout << list[i].toString() << endl;
    }
    vector<User> userList;
    for (int i = 0; i < 10; ++i) {
        userList.push_back({10 + i, "wocao" + to_string(i), 123.123987 + i, {"201067242@qq.com", "42901002wen"}});
    }
    cout << userList.size() << endl;
    double value = 1.123;
    value += 1;
    cout << value << endl;

    auto mj = meiju(NO1);
    cout << NO2 << "; " << mj << "; " << meiju(1) << "; " << meiju(NO1) << "; " << meiju(2) << endl;

    int list1[] = {1, 2, 3, 4, 5, 6};
    int *p = list1;
    vector<int *> list3;
    list3.push_back(p);

    int *pi = list3[0];
    for (int i = 0; i < 6; ++i) {
        cout << pi[i] << " ";
    }*/

    /*User user2 = {20, "wocao", 123.123987, {"201067242@qq.com", "42901002wen"}};
    cout << user2.toString() << endl;*/

    /*vector<int> list1 = getList1(4);
    int size = 10;
    int *pi = getList2(size);
    for (int i = 0; i < size; ++i) {
        pi[i] = i;
        cout << pi[i] << " ";
    }
    delete pi;
    cout << "\n" << list1.size() << endl;*/

    /*vector<int> list11 = {1, 2};
    cout << list11.begin().base() << endl;
    cout << list11.end().base() << endl;
    int *po = list11.begin().base();
    cout << *po << endl;
    cout << list11.end() - list11.begin() << endl;
    cout << (int *) "hello" << endl;*/

    /*Object ob1;
    ob1.run(1, 2);*/

    /*Object *pp = new Object;
    cout << "pp->f2(100): " << pp->f2(100) << endl;
    delete pp;
    std::shared_ptr<Object> pi = make_shared<Object>();
    cout << "pi->f2(100): " << pi->f2(100) << endl*/;

    /*thread thrd(&Hello);
    thrd.join();*/

    /*vector<int> list = {10, 2, 3, 41, 23, 6};
    for (const auto &item: list) {
        cout << item << " ";
    }
    cout << endl;

    vector<int> list1 = object.f1(list);
    for (const auto &item: list1) {
        cout << item << " ";
    }
    cout << endl;
    std::cout << "Hello, World!" << std::endl;
    cout << object.f2(100) << endl;

    string str = "goodBey";
    cout << "body:" << str << " size():" << str.size() << endl;

    string bodyValue = "Hello world";
    cout << "bodyValue:" << bodyValue << endl;
    cout << "bodyValue(*):" << object.f3(bodyValue) << endl;

    vector<string> charList = {};
    for (int i = 0; i < 10; ++i) {
        charList.push_back(to_string(i));
    }
    cout << charList.size() << endl;
    for (const auto &item: charList)
        cout << item << " ";
    cout << endl;*/

    /*vector<std::string> list2 = user.readFileBody(R"(C:\Users\XMZR\Desktop\test.txt)");
    for (const auto &item: list2)
        cout << item;
    cout << endl;*/

    /*for (int i = 0; i < 10; ++i) {
        string str = "wenhao";
        str += to_string(i) += "\n";//字符串类型拼接
        user1.addFileBody(R"(C:\Users\XMZR\Desktop\wenhao.txt)", str);
    }*/

    return 0;
}
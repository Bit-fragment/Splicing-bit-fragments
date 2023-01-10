#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <cstring>
#include "windows.h"

using namespace std;

void Hello() {
    std::cout << "hello world, I'm a thread!" << std::endl;
}

struct Ob {
public:
    string email;
    string password;

    string toString() const {
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

    string toString() const {
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


int main() {

    int a = 1, b = -1, c = 0;
    while (c < 10) {
        Sleep(1000);
        try {
            if (a + b == 0)throw "Denominator cannot be zero Exception ";
            cout << "Results of normal calculation " << (4 / (a + b)) << endl;
            b < 0 ? b = 1 : b = -1;
        } catch (const char *p) {
            cout << p << b << endl;
            b < 0 ? b = 1 : b = -1;
        }
        c++;
    }

    /*======================================================================*/

    int qwe[5];//数组与指针的关系
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

    /*======================================================================*/

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
    delete[]po;

    /*======================================================================*/

    char char_str[] = "wenhao";
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
    delete[] pkl;

    /*======================================================================*/

    Ob *obpi = new Ob{"wenhao", "password"};
    Ob *obpi1 = new Ob{"1", "2"};
    cout << obpi->email << " " << obpi->password << " obpi:" << &obpi << endl;
    cout << (*obpi1).email << " " << (*obpi1).password << " obpi1:" << &obpi1 << endl;
    delete obpi1;
    delete obpi;

    /*======================================================================*/

    tuple<string, vector<int>, int> mydata{"wenhao", {1, 4}, 6};
    auto p1 = get<0>(mydata);
    auto p2 = get<1>(mydata);
    auto p3 = get<2>(mydata);
    cout << p1 << endl;
    cout << "get<1>(mydata):";
    for (auto item: p2) {
        cout << item << " ";
    }
    cout << endl;
    cout << p3 << endl;

    /*======================================================================*/

    char char_str11[5];
    cout << "Enter:" << endl;
    cin >> char_str11;
    char *char_list2 = new char[strlen(char_str11) + 1];
    strcpy(char_list2, char_str11);
    cout << "char_list2: " << char_list2 << endl;
    delete[]char_list2;

    /*======================================================================*/

    User list[10];//枚举测试
    for (int i = 0; i < 10; ++i) {
        list[i] = {10 + i, "wocao" + to_string(i), 123.123987 + i, {"201067242@qq.com", "42901002wen"}};
    }
    for (const auto &i: list) {
        cout << i.toString() << endl;
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
    }

    /*======================================================================*/

    User user2 = {20, "wocao", 123.123987, {"201067242@qq.com", "qwe123123qwe"}};
    cout << user2.toString() << endl;

    /*======================================================================*/

    thread thrd(&Hello);
    thrd.join();

    return 0;
}
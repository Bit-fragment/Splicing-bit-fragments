//
// Created by XMZR on 2022/9/21.
//

#ifndef BEHAVIORMODE_SQLITEMODE_H
#define BEHAVIORMODE_SQLITEMODE_H
#include <map>
#include <string>
#include "SqliteBin/sqlite3.h"

class SqliteMode {

};

class SqlActuator {
private:
    sqlite3 *sql = nullptr;
public:
    SqlActuator() {
        sqlite3 *sql = NULL; // 一个打开的数据库实例
        const char *path = "../test.db";//某个sql文件的路径
        // 根据文件路径打开数据库连接。如果数据库不存在，则创建。
        // 数据库文件的路径必须以C字符串传入。
        int result = sqlite3_open_v2(
                path, &sql,
                SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE |
                SQLITE_OPEN_NOMUTEX | SQLITE_OPEN_SHAREDCACHE, NULL
        );
        if (result == SQLITE_OK) {
            std::clog << "打开数据库连接成功\n";
        } else {
            std::clog << "打开数据库连接失败\n";
        }
        this->sql = sql;
    };

    ~SqlActuator() {
        //    关闭数据库：sqlite3_close_v2(sqlite3* sql)
        if (sql) {
            sqlite3_close_v2(sql);
            sql = nullptr;
        }
    };

    void NoReturnValue(const char *sqlSentence){
        //      执行不返回数据的SQL语句(增、删、改)。
//      (执行更新、删除语句和执行创表、添加语句基本类似，只需更改sql语句即可。)
//        const char *sqlSentence = "INSERT INTO text1(name, age) VALUES('小明', 222);";//SQL语句
        sqlite3_stmt *stmt = NULL;        //stmt语句句柄

        //进行插入前的准备工作——检查语句合法性
        //-1代表系统会自动计算SQL语句的长度
        int result = sqlite3_prepare_v2(sql, sqlSentence, -1, &stmt, NULL);

        if (result == SQLITE_OK) {
            std::clog << "添加数据语句done\n";
            //执行该语句
            sqlite3_step(stmt);
        } else {
            std::clog << "添加数据语句wrong\n";
        }
        //清理语句句柄，准备执行下一个语句
        sqlite3_finalize(stmt);
    }

    std::string WithReturnValue(const char *sqlSentence){
        std::string str;
        //    执行返回数据的SQL语句(查)。
//        const char *sqlSentence = "SELECT name, age FROM text1 WHERE age < 30;";    //SQL语句
        sqlite3_stmt *stmt = NULL;    // stmt语句句柄
        //进行查询前的准备工作——检查语句合法性
        //-1代表系统会自动计算SQL语句的长度
        int result = sqlite3_prepare_v2(sql, sqlSentence, -1, &stmt, NULL);
        if (result == SQLITE_OK) {
            std::clog << "查询语句done\n";
            // 每调一次sqlite3_step()函数，stmt语句句柄就会指向下一条记录

            while (sqlite3_step(stmt) == SQLITE_ROW) {
                // 取出第0列字段的值
                const unsigned char *name = sqlite3_column_text(stmt, 0);
                // 取出第1列字段的值
                int age = sqlite3_column_int(stmt, 1);
                //输出相关查询的数据
                std::clog << "name = " << name << ", age = " << age;
                str.push_back(*name);
                str.push_back(age);
            }
        } else {
            std::clog << "查询语句wrong\n";
        }
        //清理语句句柄，准备执行下一个语句
        sqlite3_finalize(stmt);
        return str;
    }

};

#endif //BEHAVIORMODE_SQLITEMODE_H

//
// Created by XMZR on 2022/9/21.
//以下代码来自 https://segmentfault.com/a/1190000021141956#:~:text=sqlite3%28%E5%AE%98%E6%96%B9%E6%96%87%E6%A1%A3%29%E6%98%AF%E4%B8%80%E7%A7%8D%E8%BD%BB%E9%87%8F%E7%BA%A7%E4%B8%94%E5%BA%94%E7%94%A8%E5%B9%BF%E6%B3%9B%E7%9A%84%E5%85%B3%E7%B3%BB%E5%9E%8B%E6%95%B0%E6%8D%AE%E5%BA%93%E7%9A%84%E4%B8%80%E7%A7%8D%E3%80%82sqlite3%E6%95%B0%E6%8D%AE%E5%BA%93%E5%8F%AF%E8%BF%90%E8%A1%8C%E5%9C%A8%E7%B1%BBUnix%E5%92%8Cwindow%E7%B3%BB%E7%BB%9F%E4%B9%8B%E4%B8%8A%EF%BC%8C%E5%85%B6%E4%B8%AD%EF%BC%8C%E5%A4%A7%E9%83%A8%E5%88%86%E7%9A%84%E7%B1%BBUnix%E7%B3%BB%E7%BB%9F%28%E5%A6%82Linux%29%E9%83%BD%E9%BB%98%E8%AE%A4%E5%AE%89%E8%A3%85%E4%BA%86sqlite3%E6%95%B0%E6%8D%AE%E5%BA%93%EF%BC%8C%E4%B8%AA%E4%BA%BA%E4%BD%BF%E7%94%A8%E7%9A%84%E7%B3%BB%E7%BB%9F%E4%B8%BAUbuntu,16.04%EF%BC%8C%E9%BB%98%E8%AE%A4%E6%83%85%E5%86%B5%E4%B8%8B%E7%B3%BB%E7%BB%9F%E5%B7%B2%E7%BB%8F%E5%AE%89%E8%A3%85%E4%BA%86sqlite3%20
#include <iostream>
#include <string.h>
#include <string>
#include "SqliteBin/sqlite3.h"
using namespace std;
//创建操作数据库的类

class Data
{
public:
    Data(){
        cout<<"执行构造函数"<<endl;
    };

    ~Data(){
        cout<<"执行析构函数"<<endl;
    }
    //1.创建数据库和数据表
    void createData() ;
    //2.插入数据
    void insertData();
    //3.更新数据（更新第id条记录的第n列字段的值）
    void updateData(const int id,const int n );
    //4.显示开启事物，批量插入数据
    void insertBatch() ;
    //5.选择数据(选择特定行数的数据并打印出来)
    void selectData(const int row,const int offset)  ;
    //6.关闭数据库
    void close(){
        sqlite3_close(conn);
        return ;
    }
    //7.清空数据库表，以便于下次操作测试
    void drop();
private:
    sqlite3 *conn = nullptr;
    int rc;
    int count = 10;
};

void Data::updateData(const int id,const int n){
    const char *field = nullptr;
    const char *update ;
    char str[64] = {0};
    if(1 == n){
        cout<<"约束主键不能修改"<<endl;
        // field = "ID";
        //  update = "update test set ID = %d where ID = %d";
        //  sprintf(str,update,n,id);
    }else if(2 == n){
        field = "name";
        update = "update test set name = '%s' where ID = %d";
        sprintf(str,update,"yxg",id);
    }else{
        field = "width";
        update = "update test set width = %f where ID = %d";
        sprintf(str,update,99.8,id);
    };

    sqlite3_stmt *stmt = nullptr;
    if(sqlite3_prepare_v2(conn,str,strlen(str),&stmt,nullptr) != SQLITE_OK){
        sqlite3_finalize(stmt);
        close();
        return ;
    }
    if(sqlite3_step(stmt)!=SQLITE_DONE){
        sqlite3_finalize(stmt);
        close();
        return;
    }

    sqlite3_finalize(stmt);
}

void Data::selectData(const int row,const int offset) {
    int r = row,o = offset;
    const char * select1 = "select * from test limit %d,%d ";
    char select[64] = {0};
    sprintf(select,select1,row,offset);
    sqlite3_stmt *stmt = nullptr;
    // const char * select = "select * from test limit 1,1";
    if(sqlite3_prepare_v2(conn,select,strlen(select),&stmt,nullptr) != SQLITE_OK){
        cout<<"编译select语句失败"<<endl;
        close();
        sqlite3_finalize(stmt);
        return ;
    }
    if(sqlite3_step(stmt) == SQLITE_ROW){
        // cout<<"查询好了:"<<endl;
        int fieldcount = sqlite3_column_count(stmt);
        cout<<"该表所含字段数量是："<<fieldcount<<endl;

        for(int i = 0;i < fieldcount; ++i){
            int type = sqlite3_column_type(stmt,i);
            if(type == SQLITE_INTEGER){
                int v = sqlite3_column_int(stmt,i);
                cout<<"ID   is:  "<<v<<endl;
            }else if(type == SQLITE_TEXT){
                const char *v=(const char *)sqlite3_column_text(stmt,i);
                string s =  v;
                cout<<"Name is:  "<<s<<endl;
            }else if(type == SQLITE_FLOAT){
                int v = sqlite3_column_int(stmt,i);
                cout<<"Age  is:  "<<v<<endl;
            }else{
                cout<<"The result is nullptr!!"<<endl;
            }

        }
    }
    sqlite3_finalize(stmt);

}

void Data::drop(){

    const char *drop = "drop table test";
    sqlite3_stmt *stmt  = nullptr;
    if(sqlite3_prepare_v2(conn,drop,strlen(drop),&stmt,nullptr ) != SQLITE_OK){
        close();
        sqlite3_finalize(stmt);
        return ;
    }
    if(sqlite3_step(stmt) == SQLITE_DONE){
        cout<<"成功销毁数据表"<<endl;
    }

    sqlite3_finalize(stmt);
    close();

}

void Data::insertBatch(){
    //开启一个事物
    const char *begin = "begin transaction";
    sqlite3_stmt *stmt = nullptr;
    if(sqlite3_prepare_v2(conn,begin,strlen(begin),&stmt,nullptr)!=SQLITE_OK){
        close();
        cout<<"预编译事物失败！！"<<endl;
        return ;
    }
    if(sqlite3_step(stmt) != SQLITE_DONE){
        close();
        cout<<"执行事物失败"<<endl;
        return;
    }
    sqlite3_finalize(stmt);

    //基于绑定变量插入数据
    const char *insert = "insert into test values(?,?,?)";
    sqlite3_stmt *stmt2 = nullptr;
    if(sqlite3_prepare_v2(conn,insert,strlen(insert),&stmt2,nullptr) != SQLITE_OK){
        close();
        return ;
    }
    // char *name = "this is name";
    for(int i = 0; i < count; ++i){
        //数据表最左边的索引为1
        sqlite3_bind_int(stmt2,1,i);
        string name = "this is name ";
        name += to_string(i);
        sqlite3_bind_text(stmt2,2,name.c_str(),sizeof(name),SQLITE_TRANSIENT);
        sqlite3_bind_double(stmt2,3,19.1*i);
        if(sqlite3_step(stmt2)!= SQLITE_DONE){
            close();
            sqlite3_finalize(stmt2);
            return ;
        }
        sqlite3_reset(stmt2);
        cout<<"Insert succeed!"<<endl;
    }
    sqlite3_finalize(stmt2);

    //提交事务
    const char * commit= "commit";
    sqlite3_stmt *stmt3 = nullptr;
    if(sqlite3_prepare_v2(conn,commit,strlen(commit),&stmt3,nullptr)!= SQLITE_OK){
        close();
        sqlite3_finalize(stmt3);
        return;
    }
    if(sqlite3_step(stmt3)!=SQLITE_DONE){

        close();
        sqlite3_finalize(stmt3);
        return;
    }
    sqlite3_finalize(stmt3);


}

void Data::createData()  {
    //在当前目录下打开(或创建)test.db数据库。
    rc = sqlite3_open("test.db",&conn);
    if(rc != SQLITE_OK){
        close();
        cout<<"创建数据库失败！！"<<endl;
        return ;
    }
    //SQL语句
    /*
    const char *createTable = "create table test(" \
        "ID INT PRIMARY KEY NOT NULL,"\
        "name TEXT NOT NULL," \
        "age INT NOT NULL," \
        " );";*/
    const char * createTable = "create table test(ID INT PRIMARY KEY NOT NULL,name TEXT,width REAL)";
    sqlite3_stmt *stmt = nullptr;
    //预编译SQL语句
    if(sqlite3_prepare_v2(conn,createTable,strlen(createTable),&stmt,nullptr) != SQLITE_OK){
        cout<<"预编译失败"<<endl;
        sqlite3_finalize(stmt);
        close();
        return;
    }
    //执行SQL语句
    if(sqlite3_step(stmt) != SQLITE_DONE){
        sqlite3_finalize(stmt);
        cout<<"执行失败"<<endl;
        close();
        return ;
    }
    sqlite3_finalize(stmt);
    cout<<"创建数据库和数据表成功!!"<<endl;

}

int main(int argc, char **argv){
    system("chcp 65001");

    Data *base = new Data;
    base->createData();
    base->insertBatch();
    //打印从第一条记录开始的一条记录(记录索引从0开始)
    base->selectData(1,1);
    base->updateData(1,2);

    base->drop();
    delete base;
    base = nullptr;
    return 0;
}
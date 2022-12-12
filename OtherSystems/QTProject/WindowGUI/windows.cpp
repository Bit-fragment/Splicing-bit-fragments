//
// Created by 20106 on 2022/11/15.
//

#include <QThread>
#include "windows.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent) {
    labl1 = new QLabel(this);
    labl1->setText(tr("请输入圆的半径:"));
    lineEdit = new QLineEdit(this);
    labl2 = new QLabel(this);
    button = new QPushButton(this);
    button->setText(tr("显示对应圆的面积:"));
    auto *mainLayout = new QGridLayout(this);

    mainLayout->addWidget(labl1, 0, 0);
    mainLayout->addWidget(lineEdit, 0, 1);
    mainLayout->addWidget(labl2, 1, 0);
    mainLayout->addWidget(button, 1, 1);
    connect(button, SIGNAL(clicked()), this, SLOT(showArea()));

}

Dialog::~Dialog() noexcept = default;

void Dialog::showArea() {
    bool ok;
    QString tempStr;
    QString valueStr = lineEdit->text();
    int valueInt = valueStr.toInt(&ok);
    double area = valueInt * valueInt * 3.1415;
    labl2->setText(tempStr.setNum(area));
    MyClass mc;
    mc.f1();
}

/*=========Sing in============*/
SinginPage::SinginPage(QWidget *parent) : QDialog(parent) {
    account = new QLabel(this);
    password = new QLabel(this);

    InputAccount = new QLineEdit(this);
    InputPassword = new QLineEdit(this);
    SigninButton = new QPushButton(this);
    LoginButton = new QPushButton(this);

    account->setText(tr("账号:"));
    password->setText(tr("密码:"));

    SigninButton->setText(tr("登录"));
    LoginButton->setText(tr("注册"));

    auto *mainLayout = new QGridLayout(this);

    mainLayout->addWidget(account, 0, 0);
    mainLayout->addWidget(InputAccount, 0, 1);
    mainLayout->addWidget(password, 1, 0);
    mainLayout->addWidget(InputPassword, 1, 1);
    mainLayout->addWidget(SigninButton, 2, 1);
    mainLayout->addWidget(LoginButton, 2, 0);

    connect(SigninButton, SIGNAL(clicked()), this, SLOT(function_singin()));
    connect(LoginButton, SIGNAL(clicked()), this, SLOT(function_login()));

}

SinginPage::~SinginPage() noexcept = default;

void SinginPage::function_singin() {
    QString Account = InputAccount->text();
    QString Password = InputPassword->text();
    qDebug() << "账号: " << Account << "\n密码: " << Password;
}

void SinginPage::function_login() {
    auto f1 = [](){
        LonginPage p;
        p.show();
    };
    //这里有疑问

}

/*=========Log in============*/
LonginPage::LonginPage(QWidget *parent) : QDialog(parent) {
    account = new QLabel(this);
    password_1 = new QLabel(this);
    password_2 = new QLabel(this);

    InputAccount = new QLineEdit(this);
    InputPassword_1 = new QLineEdit(this);
    InputPassword_2 = new QLineEdit(this);
    SubmitButton = new QPushButton(this);

    account->setText(tr("输入账号:"));
    password_1->setText(tr("输入密码:"));
    password_2->setText(tr("确认密码:"));

    SubmitButton->setText(tr("提交"));

    auto *mainLayout = new QGridLayout(this);

    mainLayout->addWidget(account, 0, 0);
    mainLayout->addWidget(InputAccount, 0, 1);
    mainLayout->addWidget(password_1, 1, 0);
    mainLayout->addWidget(InputPassword_1, 1, 1);
    mainLayout->addWidget(password_2, 2, 0);
    mainLayout->addWidget(InputPassword_2, 2, 1);

    mainLayout->addWidget(SubmitButton, 3, 1);

    connect(SubmitButton, SIGNAL(clicked()), this, SLOT(function_Submit()));

}

LonginPage::~LonginPage() noexcept = default;

void LonginPage::function_Submit() {
    QString Account = InputAccount->text();
    QString Password_1 = InputPassword_1->text();
    QString Password_2 = InputPassword_1->text();
    qDebug() << "账号: " << Account << " 密码1:" << Password_1<< " 密码2:" << Password_2;
}


MyClass::MyClass() = default;

MyClass::~MyClass() = default;

void MyClass::f1() {
    QList<int> list = {9, 6, 1, 3, 5, 2, 7};
    qDebug() << "排序之前: " << list;
    for (int i = 0; i < list.size() - 1; i++) {
        for (int j = i + 1; j <= list.size() - 1; j++) {
            if (list[i] > list[j]) {
                int p = list[i];
                list[i] = list[j];
                list[j] = p;
            }
        }
    }
    qDebug() << "排序之后: " << list;
}

void MyClass::f2() {

}

void MyClass::f3() {

}

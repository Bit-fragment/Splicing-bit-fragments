//
// Created by 20106 on 2022/11/15.
//

#ifndef QTPROJECT_WINDOWS_H
#define QTPROJECT_WINDOWS_H

#include <QLabel>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QList>

//class windows {
//
//};

class Dialog : public QDialog {
Q_OBJECT
public:
    explicit Dialog(QWidget *parent = nullptr);

    ~Dialog() override;

private:
    QLabel *labl1, *labl2;
    QLineEdit *lineEdit;
    QPushButton *button;

private slots:

    void showArea();
};

class SinginPage : public QDialog {
Q_OBJECT
public:
    explicit SinginPage(QWidget *parent = nullptr);

    ~SinginPage() override;

private:
    QLabel *account, *password;
    QLineEdit *InputAccount, *InputPassword;
    QPushButton *SigninButton, *LoginButton;

private slots:

    void function_login();

    void function_singin();
};

class LonginPage : public QDialog {
Q_OBJECT
public:
    explicit LonginPage(QWidget *parent = nullptr);

    ~LonginPage() override;

private:
    QLabel *account, *password_1, *password_2;
    QLineEdit *InputAccount, *InputPassword_1, *InputPassword_2;
    QPushButton *SubmitButton;

private slots:

    void function_Submit();
};

class MyClass {
public:
    MyClass();

    ~MyClass();

    void f1();

    void f2();

    void f3();
};


#endif //QTPROJECT_WINDOWS_H

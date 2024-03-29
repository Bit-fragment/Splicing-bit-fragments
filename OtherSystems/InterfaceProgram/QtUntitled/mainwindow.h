//
// Created by XMZR on 2023/3/17.
//

#ifndef QTUNTITLED3_MAINWINDOW_H
#define QTUNTITLED3_MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QList>
#include <QTextEdit>

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
};

class Dialog : public QDialog {
Q_OBJECT
public:
    explicit Dialog(QWidget *parent = nullptr);

    ~Dialog() override = default;

private:
    QLabel *labl1, *labl2;
    QLineEdit *lineEdit;
    QPushButton *button;

private slots:

    void showArea();
};

class Schedule : public QDialog {
Q_OBJECT
public:
    explicit Schedule(QWidget *parent = nullptr);

    ~Schedule() override = default;

private:
    QLabel *startDate, *endDate, *title, *concreteContent,
            *currentState, *completion, *remarks;
    QLineEdit *InputStartDate, *InputEndDate, *InputTitle,
            *InputCurrentState, *InputCompletion, *InputRemarks;
    QPushButton *SubmitButton, *EmptyButton{};
    QTextEdit *InputConcreteContent;



private slots:

    void Submit();
};

class MyClass {
public:
    MyClass() = default;

    ~MyClass() = default;

    void f1();
};

#endif //QTUNTITLED3_MAINWINDOW_H

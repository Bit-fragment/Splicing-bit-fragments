//
// Created by XMZR on 2023/3/17.
//

#include <QPushButton>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
}

MainWindow::~MainWindow() {

}

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

Schedule::Schedule(QWidget *parent) : QDialog(parent) {
    startDate = new QLabel(this);
    endDate = new QLabel(this);
    title = new QLabel(this);
    concreteContent = new QLabel(this);
    currentState = new QLabel(this);
    completion = new QLabel(this);
    remarks = new QLabel(this);


    InputStartDate = new QLineEdit(this);
    InputEndDate = new QLineEdit(this);
    InputTitle = new QLineEdit(this);
    InputConcreteContent = new QTextEdit(this);
    InputCurrentState = new QLineEdit(this);
    InputCompletion = new QLineEdit(this);
    InputRemarks = new QLineEdit(this);
    SubmitButton = new QPushButton(this);
    EmptyButton = new QPushButton(this);

//    InputConcreteContent->resize(320,100);

    startDate->setText(tr("开始日期:"));
    endDate->setText(tr("结束日期:"));
    title->setText(tr("标题:"));
    concreteContent->setText(tr("具体内容:"));
    currentState->setText(tr("当前状态:"));
    completion->setText(tr("完成情况:"));
    remarks->setText(tr("备注:"));
    SubmitButton->setText(tr("提交"));
    EmptyButton->setText(tr("清空"));

    auto *mainLayout = new QGridLayout(this);

    mainLayout->addWidget(startDate, 1, 0);
    mainLayout->addWidget(endDate, 2, 0);
    mainLayout->addWidget(title, 3, 0);
    mainLayout->addWidget(concreteContent, 4, 0);
    mainLayout->addWidget(currentState, 5, 0);
    mainLayout->addWidget(completion, 6, 0);
    mainLayout->addWidget(remarks, 7, 0);
    mainLayout->addWidget(EmptyButton, 8, 0);
    mainLayout->addWidget(SubmitButton, 8, 1);

    mainLayout->addWidget(InputStartDate, 1, 1);
    mainLayout->addWidget(InputEndDate, 2, 1);
    mainLayout->addWidget(InputTitle, 3, 1);
    mainLayout->addWidget(InputConcreteContent, 4, 1);
    mainLayout->addWidget(InputCurrentState, 5, 1);
    mainLayout->addWidget(InputCompletion, 6, 1);
    mainLayout->addWidget(InputRemarks, 7, 1);

    connect(SubmitButton, SIGNAL(clicked()), this, SLOT(Submit()));
}

void Schedule::Submit() {

    QMap<QString,QString> DataMap;
    DataMap.insert("InputStartDate",InputStartDate->text());
    DataMap.insert("InputEndDate",InputEndDate->text());
    DataMap.insert("InputTitle",InputTitle->text());
    DataMap.insert("InputConcreteContent",InputConcreteContent->toPlainText());
    DataMap.insert("InputCurrentState",InputCurrentState->text());
    DataMap.insert("InputCompletion",InputCompletion->text());
    DataMap.insert("InputRemarks",InputRemarks->text());
    qDebug() << "Submit (Map) :" << DataMap;

    QList<QString> DataList;
    DataList.append(InputStartDate->text());
    DataList.append(InputEndDate->text());
    DataList.append(InputTitle->text());
    DataList.append(InputConcreteContent->toPlainText());
    DataList.append(InputCurrentState->text());
    DataList.append(InputCompletion->text());
    DataList.append(InputRemarks->text());
    qDebug() << "Submit (List) :" << DataList;

}

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

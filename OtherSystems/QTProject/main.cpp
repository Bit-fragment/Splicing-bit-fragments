#include <QApplication>
#include <QThread>
#include <QFile>
#include <QDebug>
#include "WindowGUI/windows.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

//    QThread qThread;
//    qThread.

/*    Dialog dialog;
    dialog.show();

    SinginPage singinPage;
    singinPage.show();

    return QApplication::exec();*/


    QFile file("D:/Users/XMZR/CLionProjects/Splicing-bit-fragments/OtherSystems/QTProject/TestFile.txt");
    /*qDebug() << file.exists();
    if (file.open(QIODevice::ReadOnly)) {
        *//*char buffer[2048];
        qint64 lineLen = file.readLine(buffer, sizeof(buffer));
        qDebug() << lineLen;
        if (-1 == lineLen) {
            qDebug() << buffer;
        }*//*
        QByteArray list = file.readAll();
        qDebug() << list.length();
        QString string;
        for (char i: list) {
            string.append(i);
        }
        qDebug() << string;
        file.close();
    }
    file.flush();*/

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return 0;

    while (!file.atEnd()) {
        QByteArray line = file.readAll();
        qDebug() << line.data();
//        process_line(line);
    }


    return 0;
}

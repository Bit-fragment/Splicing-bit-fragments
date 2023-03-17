#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    QFont font("ZYSong18030", 12);
    a.setFont(font);

//    QThread qThread;
//    qThread.

//    Dialog dialog;
//    dialog.show();

    Schedule schedule;
    schedule.show();

    return QApplication::exec();
}

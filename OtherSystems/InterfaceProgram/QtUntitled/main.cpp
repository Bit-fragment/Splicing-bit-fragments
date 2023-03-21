#include <QApplication>
#include <QQueue>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QFont font("ZYSong18030", 12);
    QApplication qApplication(argc, argv);
    qApplication.setFont(font);

//    MainWindow w;
//    w.show();

    Dialog dialog;
    dialog.show();

    Schedule schedule;
    schedule.show();

    return QApplication::exec();

/*    QQueue<int> queue;
    for (int i = 0; i < 5; ++i) {
        queue.enqueue(i);
    }
    while (!queue.isEmpty())
        qDebug() << queue.dequeue();
    qDebug() << Qt::endl;

    return 0;*/
}

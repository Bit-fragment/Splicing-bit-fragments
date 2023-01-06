#include <QApplication>
#include <QThread>
#include <QFile>
#include <QDebug>
#include "WindowGUI/windows.h"

#include <QSplitter>
#include <QTextEdit>
//#include <QTextCodec>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QFont font("ZYSong18030", 12);
    a.setFont(font);

//    QThread qThread;
//    qThread.

//    Dialog dialog;
//    dialog.show();

    Schedule schedule;
    schedule.show();

//    SinginPage singinPage;
//    singinPage.show();


/*    QSplitter *splitterMain = new QSplitter(Qt::Horizontal, 0);

    QTextEdit *textLeft = new QTextEdit(QObject::tr("Left Widget"), splitterMain);
    textLeft->setAlignment(Qt::AlignCenter);

    QSplitter *splitterRight = new QSplitter(Qt::Vertical, splitterMain);
    splitterRight->setOpaqueResize(false);

    QTextEdit *textUp = new QTextEdit(QObject::tr("Top Widget"), splitterRight);
    textUp->setAlignment(Qt::AlignCenter);

    QTextEdit *textButtom = new QTextEdit(QObject::tr("Bottom Widget"), splitterRight);
    textButtom->setAlignment(Qt::AlignCenter);

    splitterMain->setStretchFactor(1, 1);
    splitterMain->setWindowTitle(QObject::tr("Splitter"));
    splitterMain->show();*/

    return QApplication::exec();
}

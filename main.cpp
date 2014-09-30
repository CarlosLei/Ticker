#include "ticker.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ticker w;
    w.setText(QString(QObject::tr("***人的孤独********！")));
    w.show();

    return a.exec();
}

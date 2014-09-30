#include "ticker.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ticker w;
    w.show();

    return a.exec();
}

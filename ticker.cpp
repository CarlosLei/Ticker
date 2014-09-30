#include "ticker.h"
#include <QPainter>
#include <QTimerEvent>

Ticker::Ticker(QWidget *parent)
    : QWidget(parent)
{
    offset = 0;
    myTimerID = 0;
    //setText(QString(tr("Abcdefghijklmnopqrstuvwyz")));
    //setFont(QFont);
}

Ticker::~Ticker()
{

}
void Ticker::setText(const QString &newText)
{
    myText = newText;
    update();
    updateGeometry();
}
QSize Ticker::sizeHint() const
{
    return fontMetrics().size(0,text());
    //窗口的大小是这个 返回文本所需的大小
}

void Ticker::paintEvent(QPaintEvent */*event*/)
{
    QPainter painter(this);
    int textWidth = fontMetrics().width(text());
    if(textWidth < 1)
        return;
    int x = -offset;
    while(x < width())//这个函数会把整个窗口部件绘制填充
    {
        painter.drawText(x, 0,textWidth,height(),
                         Qt::AlignLeft|Qt::AlignVCenter, text());
        x += textWidth;
    }
}
void Ticker::timerEvent(QTimerEvent *event)
//重载定时器事件
{
    if(event->timerId() == myTimerID)
    {
        ++offset;
        if(offset >= fontMetrics().width(text()))
            offset = 0;
        //这个函数重要！
        scroll(-1, 0);
    }
    else
    {
        QWidget::timerEvent(event);
    }
}
void Ticker::showEvent(QShowEvent */*event*/)
{
    myTimerID = startTimer(30);
}
void Ticker::hideEvent(QHideEvent */*event*/)
{
    killTimer(myTimerID);
    myTimerID = 0;
}



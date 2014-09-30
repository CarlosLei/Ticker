#ifndef TICKER_H
#define TICKER_H

#include <QWidget>

class Ticker : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString Text READ Text WRITE setText)

public:
    Ticker(QWidget *parent = 0);
    ~Ticker();

    void setText(const QString &newText);
    QString text() const {return myText;}
    QSize sizeHint() const;
protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);
private:
    QString myText;
    int offset;
    int myTimerID;

};

#endif // TICKER_H



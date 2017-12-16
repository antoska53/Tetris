#ifndef NEXTFIGURE2_H
#define NEXTFIGURE2_H

#include <QWidget>
#include <QDebug>
#include "figure.h"

class NextFigure2 : public QWidget
{
    Q_OBJECT
public:
    explicit NextFigure2(QWidget *parent = nullptr);
    Figure* nextF = nullptr;
    virtual void paintEvent(QPaintEvent *event);
signals:

public slots:
    void slotNextFigure(Figure*);
};

#endif // NEXTFIGURE2_H

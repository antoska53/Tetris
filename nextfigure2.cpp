#include "nextfigure2.h"

NextFigure2::NextFigure2(QWidget *parent) : QWidget(parent)
{

}

void NextFigure2::slotNextFigure(Figure*&  next){
    nextF = next;
}

void NextFigure2::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    qDebug() << nextF->getColorVec();
    //painter.fillRect(40 ,0, 19, 19, nextF->getColorVec()[0]);
    //painter.fillRect(40 ,20, 19, 19, nextF->getColorVec()[1]);
    //painter.fillRect(40 ,40, 19, 19, nextF->getColorVec()[2]);
}

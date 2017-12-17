#include "nextfigure2.h"

NextFigure2::NextFigure2(QWidget *parent) : QWidget(parent)
{

}

void NextFigure2::slotNextFigure(Figure*  next){
    qDebug() << "slot nextfigure";
    qDebug() << next;
    nextF = next;
    qDebug() << nextF;
    qDebug() << nextF->getColorVec();
    repaint();
}

void NextFigure2::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    //painter.fillRect(this->rect(), Qt::gray);
    if(nextF != nullptr){
    qDebug() << "painter" <<  nextF->getColorVec();
    painter.fillRect(40 ,0, 19, 19, nextF->getColorVec()[2]);
    painter.fillRect(40 ,20, 19, 19, nextF->getColorVec()[1]);
    painter.fillRect(40 ,40, 19, 19, nextF->getColorVec()[0]);
    }
}

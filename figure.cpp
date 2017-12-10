#include "figure.h"

Figure::Figure()
{
    vCol.resize(3);
    allColor.push_back(Qt::blue);
    allColor.push_back(Qt::green);
    allColor.push_back(Qt::cyan);
    allColor.push_back(Qt::yellow);
    allColor.push_back(Qt::red);
    allColor.push_back(Qt::magenta);
    allColor.push_back(Qt::darkBlue);
    allColor.push_back(Qt::darkGreen);
    allColor.push_back(Qt::darkCyan);
    allColor.push_back(Qt::darkYellow);
    allColor.push_back(Qt::darkRed);
    allColor.push_back(Qt::darkMagenta);
}

void Figure::setUpCell(int n, int m){
    m_i = n;
    m_j = m;
}

int Figure::getUpCellI(){
    return m_i;
}

int Figure::getUpCellJ(){
    return m_j;
}

void Figure::rotateColors(int n){
    if(n == 0){
    for(int i = 0; i < 2; i++){
    QColor col = vCol[i];
    vCol[i] = vCol[i + 1];
    vCol[i + 1] = col;
    }
    }
    if(n == 1){
        for(int i = 2; i > 0; i--){
        QColor col = vCol[i];
        vCol[i] = vCol[i - 1];
        vCol[i - 1] = col;
        }
    }
}

void Figure::paintFigure(QPainter & painter){
    int x = this->getUpCellI() * 20;
    int y = this->getUpCellJ() * 20;
    painter.fillRect(x, y, 19, 19, this->getColorVec()[0]);
     painter.fillRect(x, y - 20, 19, 19, this->getColorVec()[1]);
      painter.fillRect(x, y - 40, 19, 19, this->getColorVec()[2]);
}
void Figure::makeRandomColors(){
   vCol.replace(0, allColor[rand()%12]);
   vCol.replace(1, allColor[rand()%12]);
   vCol.replace(2, allColor[rand()%12]);

    // vCol.replace(0, QColor(rand() % 255, rand() % 255, rand() % 255));
    //vCol.replace(1, QColor(rand() % 255, rand() % 255, rand() % 255));
    //vCol.replace(2, QColor(rand() % 255, rand() % 255, rand() % 255));
    //qDebug() << vCol[0];
}

QVector<QColor> Figure::getColorVec(){
    return vCol;
}

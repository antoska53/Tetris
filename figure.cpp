#include "figure.h"

Figure::Figure()
{
    vCol.resize(3);
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

void Figure::rotateColors(){

}

void Figure::paintFigure(QPainter & painter){

}
void Figure::makeRandomColors(){
    vCol.push_back(QColor(rand() % 255, rand() % 255, rand() % 255));
    vCol.push_back(QColor(rand() % 255, rand() % 255, rand() % 255));
    vCol.push_back(QColor(rand() % 255, rand() % 255, rand() % 255));

}

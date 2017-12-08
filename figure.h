#ifndef FIGURE_H
#define FIGURE_H
#include <QVector>
#include <QColor>
#include <QPainter>


class Figure
{
    QVector<QColor> vCol;
    int m_i = 0;
    int m_j = 0;
    int m_W = 20;
public:
    Figure();
    void setUpCell(int, int);
    int getUpCellI();
    int getUpCellJ();
    void rotateColors();
    void makeRandomColors();
    void paintFigure(QPainter&);
};

#endif // FIGURE_H

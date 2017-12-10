#ifndef FIGURE_H
#define FIGURE_H
#include <QVector>
#include <QColor>
#include <QPainter>


class Figure
{
    QVector<QColor> vCol;
    QVector<QColor> allColor;
    int m_i = 0;
    int m_j = 0;
    int m_W = 20;
public:
    Figure();
    void setUpCell(int, int);
    int getUpCellI();
    int getUpCellJ();
    void rotateColors(int);
    void makeRandomColors();
    void paintFigure(QPainter&);
    QVector<QColor> getColorVec();
};

#endif // FIGURE_H

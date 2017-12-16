#ifndef GLASS_H
#define GLASS_H

#include <QWidget>
#include <QColor>
#include <QPainter>
#include <QKeyEvent>
#include <QMessageBox>
#include <QDebug>
#include "figure.h"
#define emptyCell QColor(Qt::gray)//серыйцвет

class Glass : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int rows READ rows WRITE setRows)
    Q_PROPERTY(int columns READ columns WRITE setColumns)
    int m_rows = 0;

    int m_columns = 0;
    static const int W = 20;
    int timeInterval = 0;
    bool gameOn = false;
    int score = 0;
   // QColor emptyCell = QColor(Qt::blue); //= new QColor(1, 1, 1, 255);
    QVector<QVector<QColor>> glassArray;
    Figure* cur;
    Figure* next;
    int idTimer;

public:
    explicit Glass(QWidget *parent = nullptr);
    ~Glass();
    // static QColor emptyCell = QColor(Qt::gray);
    virtual void keyPressEvent(QKeyEvent*);
    virtual void timerEvent(QTimerEvent*);

int rows() const
{
    return m_rows;
}

int columns() const
{
    return m_columns;
}
void clearGlass();
void acceptColors(int, int);

virtual void paintEvent(QPaintEvent*event);

signals:
    void signalGlassInit();
    void drawPattern(Figure*);


public slots:
    void slotNewGame();
void setRows(int rows)
{
    m_rows = rows;
}
void setColumns(int columns)
{
    m_columns = columns;
}

void slotGlassInit();
//void clearGlass();
};

#endif // GLASS_H

#include "glass.h"
#include <QDebug>

Glass::Glass(QWidget *parent) : QWidget(parent)
{
   // QPalette pal;
    //pal.setColor(QPalette::Background, Qt::blue);
    //this->setAutoFillBackground(true);
    //this->setPalette(pal);

    connect(this, SIGNAL(signalGlassInit()), this, SLOT(slotGlassInit()), Qt::QueuedConnection);
    emit signalGlassInit();

    cur = new Figure();
    next = new Figure();

}

Glass::~Glass(){
    delete cur;
    delete next;
}

void Glass::slotGlassInit(){\
    qDebug() << m_rows << m_columns;
    glassArray.resize(m_rows);

   // foreach (QVector<QColor> vec, glassArray) {
    //    vec.resize(m_columns);
    //}
    for(int i = 0; i < m_rows; i++){
        glassArray[i].resize(m_columns);
    }
    clearGlass();
    QSize s(m_columns * 20, m_rows * 20);
    this->setFixedSize(s);
    qDebug() << s;
}
void Glass::clearGlass(){
    /*foreach (QVector<QColor> vec, glassArray) {
        //vec.fill(emptyCell);
        vec.fill(Qt::green);
    }
    */
   /* for(int i = 0; i < m_rows; i++){
        QColor qcol(Qt::gray);
        glassArray.value(i).fill(emptyCell);
        qDebug() << qcol;
        qDebug() << emptyCell;
    }
    */
    QColor qc(Qt::blue);
    for(int i = 0; i < m_rows; i++){
        for(int j = 0; j < m_columns; j++){
            glassArray[i].fill(emptyCell);
            qDebug() << glassArray.value(i).value(j);
        }
    }
    for(int i = 0; i < m_rows; i++){
       // QColor qcol(Qt::blue);
        //glassArray.value(i).fill(qcol);
                for(int j = 0; j < m_columns; j++){
        qDebug() << "ПРоверка" << glassArray.value(i).value(j);
                }
    }
}

void Glass::paintEvent(QPaintEvent*event){
    QPainter painter(this);
    int x = 0;
    int y = 0;
    //int count = 0;
    //painter.fillRect(180, 20, 20, 20, glassArray.value(1).value(1));
    for(int i = 0; i < m_rows; i++){
        x = 0;
       for(int j = 0; j < m_columns; j++){
           painter.fillRect(x += 20, y, W - 1, W - 1, glassArray[i][j]);
           //qDebug() << "ПРоверка в рисовании" << glassArray.value(i).value(j);
       }
       y += 20;

    }
}

void Glass::slotNewGame(){
    gameOn = true;
    clearGlass();
    cur->makeRandomColors();
    next->makeRandomColors();
    this->setFocus();
    startTimer(1);
    repaint();
}

void Glass::keyPressEvent(QKeyEvent* event){

    if(gameOn)
    {
    //Если«идет игра»
        int i = 0;
        int j = 0;

    switch(event->key()){//коднажатойклавиши
    case Qt::Key_Left:
    //если есть «куда», перемещаем фигурку влево
        i = cur->getUpCellI();
        j = cur->getUpCellJ();
        cur->setUpCell(i - 20, j);
        break;
    case Qt::Key_Right:
        i = cur->getUpCellI();
        j = cur->getUpCellJ();
        cur->setUpCell(i + 20, j);
        break;
    case Qt::Key_Down:
    //циклически ”переливаем” цвета в фигурке сверху вниз
        break;
    case Qt::Key_Up:
    //циклически ”переливаем” цвета в фигурке снизу вверх
        break;
    case Qt::Key_Space:
    //«роняем» фигурку
        break;
    default:
    QWidget::keyPressEvent(event); //принажатиилюбыхдругихклавишвызываембазовуюобработкусобытия
    }
    }
    else{
    QWidget::keyPressEvent(event);//предоставляемвозможностьбазовому
    //классуобработатьсобытие

    }


}

    void Glass::timerEvent(QTimerEvent* event){
       int i = cur->getUpCellI();
       int j = cur->getUpCellJ();
       cur->setUpCell(i, j + 20);
       repaint();
    }

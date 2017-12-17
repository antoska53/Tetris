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
    //connect()

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
          //  qDebug() << glassArray.value(i).value(j);
        }
    }
    for(int i = 0; i < m_rows; i++){
       // QColor qcol(Qt::blue);
        //glassArray.value(i).fill(qcol);
                for(int j = 0; j < m_columns; j++){
       // qDebug() << "ПРоверка" << glassArray.value(i).value(j);
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
    if(gameOn){
         cur->paintFigure(painter);
        //if(cur->getUpCellJ() == 19 || glassArray[cur->getUpCellJ() + 1][cur->getUpCellI() - 1] != emptyCell){
         // acceptColors(cur->getUpCellI(), cur->getUpCellJ());
        //}

    }
}

void Glass::slotNewGame(){
    qDebug() << "new game";
    if(gameOn){
        killTimer(idTimer);
        gameOn = false;
    }
    gameOn = true;
    score = 0;
    clearGlass();
    cur->makeRandomColors();
    cur->setUpCell(5, 0);
    next->makeRandomColors();
    next->setUpCell(5, 0);
    qDebug() << "sugnal" << next;
    emit drawPattern(next);
    this->setFocus();
    idTimer = startTimer(500);
    repaint();
    qDebug() << cur->getColorVec()[0];
    qDebug() << idTimer;
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
        if(i > 1 && glassArray[j][i - 2] == Qt::gray) cur->setUpCell(i - 1, j);

        break;
    case Qt::Key_Right:
        i = cur->getUpCellI();
        j = cur->getUpCellJ();
        if(i < 9 && glassArray[j][i] == Qt::gray) cur->setUpCell(i + 1, j);
        break;
    case Qt::Key_Down:
    //циклически ”переливаем” цвета в фигурке сверху вниз
        cur->rotateColors(0);
        break;
    case Qt::Key_Up:
    //циклически ”переливаем” цвета в фигурке снизу вверх
        cur->rotateColors(1);
        break;
    case Qt::Key_Space:
    //«роняем» фигурку
        i = cur->getUpCellI();
        j = cur->getUpCellJ();
        while(j < 20 && glassArray[j][i - 1] == Qt::gray){
            //if(j == 19)break;
            j++;

        }
       acceptColors(i, j - 1);
        //cur->setUpCell(i, j);
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
       j++;
       cur->setUpCell(i, j);
        if(cur->getUpCellJ() >= 19 || glassArray[cur->getUpCellJ() + 1][cur->getUpCellI() - 1] != emptyCell){
            if(j < 2){
                QMessageBox::about(this, "game over", "гамовер");
                killTimer(idTimer);
            }
            else {
       glassArray[j].replace(i - 1, cur->getColorVec()[0]);
       glassArray[j - 1].replace(i - 1, cur->getColorVec()[1]);
       glassArray[j - 2].replace(i - 1, cur->getColorVec()[2]);
       this->removeLine();
       Figure* tmp = nullptr;
       tmp = cur;
       cur = next;
       next = tmp;
       tmp = nullptr;
       cur->setUpCell(5, 0);
       next->setUpCell(5, 0);
       next->makeRandomColors();
       emit drawPattern(next);

       }


       }
        repaint();

    }

    void Glass::removeLine(){
        int n = 0;

        for(int i = 0; i < glassArray.count(); i++ ){  //по горизонтали
            for(int j = 0; j < glassArray[i].count() - 1; j++){
                if(glassArray[i][j] == glassArray[i][j + 1] && glassArray[i][j] != emptyCell){
                    n++;
                }
                else if(n >= 2){
                    for(int m = i; m > 0; m--){
                        for(int k = j; k >= j - n; k--){
                        glassArray[m][k] = glassArray[m - 1][k];
                    }

                }
                     score += n + 1;
                    emit setScore(score);
                    n = 0;
                }
                else n = 0;

            }
        }

        n = 0;
        for(int j = 0; j < glassArray[0].count(); j++){        //по вертикали
            for(int i = 0; i < glassArray.count() - 1; i++){
                if(glassArray[i][j] == glassArray[i + 1][j] && glassArray[i][j] != emptyCell){
                    n++;
                }
                else if(n >= 2){
                    for(int m = i; m - n > 0; m--){
                        glassArray[m][j] = glassArray[m - n - 1][j];

                    }
                    score += n + 1;
                    emit setScore(score);
                    n = 0;
                }
                else n = 0;
            }
        }
    }

    void Glass::acceptColors(int i, int j){
        qDebug() << "i = " << i << "j = " << j;

        glassArray[j].replace(i - 1, cur->getColorVec()[0]);
        glassArray[j - 1].replace(i - 1, cur->getColorVec()[1]);
        glassArray[j - 2].replace(i - 1, cur->getColorVec()[2]);
        this->removeLine();
        Figure* tmp;
        tmp = cur;
        cur = next;
        next = tmp;
        tmp = nullptr;
        cur->setUpCell(5, 0);
        next->setUpCell(5, 0);
        next->makeRandomColors();
        emit drawPattern(next);

    }

#ifndef CHESSVIEW_H
#define CHESSVIEW_H

#include <QWidget>
#include "chessdoc.h"
//#include "mainwindow.h"

class ChessView : public QWidget
{
    Q_OBJECT
public:
    explicit ChessView(QWidget *parent = nullptr);
    void drawChessboard(QPainter* p);
    void paintEvent(QPaintEvent*);
    double dim;
    ChessDoc* doc;
    void mouseDoubleClickEvent(QMouseEvent* event);
signals:

private: bool isPainted=false;

};

#endif // CHESSVIEW_H

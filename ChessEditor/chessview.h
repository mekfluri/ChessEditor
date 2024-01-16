#ifndef CHESSVIEW_H
#define CHESSVIEW_H

#include <QWidget>
#include <QPainter>
#include <QFont>
#include "chessdoc.h"

class ChessView : public QWidget
{
    Q_OBJECT
private:
    ChessDoc*  m_chess;
public:
    explicit ChessView(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void drawChessBoard(QPainter* p);
    void setBoard(ChessDoc* chess);
signals:

public slots:
    void on_ChessDataChanged();
};

#endif // CHESSVIEW_H

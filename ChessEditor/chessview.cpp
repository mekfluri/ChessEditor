#include "chessview.h"

ChessView::ChessView(QWidget *parent)
    : QWidget{parent}
{

}

void ChessView::setBoard(ChessDoc* chess){
    m_chess = chess;
    connect(m_chess, &ChessDoc::chessDataChanged, this, &ChessView::on_ChessDataChanged);
}

void ChessView::on_ChessDataChanged(){
    paintEvent(nullptr);
}

QRect figureToRect(int type, int color){
    const int figure_width = 100, figure_height = 100;
    int colorOffset;
    if(color == 0) colorOffset = 1;
    else colorOffset = 0;
    switch(type){
    case 4:
        return QRect(0 * figure_width, colorOffset * figure_height , figure_width, figure_height);
    case 0:
        return QRect(1 * figure_width, colorOffset * figure_height , figure_width, figure_height);
    case 3:
        return QRect(2 * figure_width, colorOffset * figure_height , figure_width, figure_height);
    case 1:
        return QRect(3 * figure_width, colorOffset * figure_height , figure_width, figure_height);
    case 2:
        return QRect(4 * figure_width, colorOffset * figure_height , figure_width, figure_height);
    case 5:
        return QRect(5 * figure_width, colorOffset * figure_height , figure_width, figure_height);
    default: return QRect(0, 0, 0, 0);
    }
}

void ChessView::paintEvent(QPaintEvent *event){
    QPainter p(this);
    drawChessBoard(&p);
}
void ChessView::drawChessBoard(QPainter* p){
    int cellwidth = (width() - width() / 16 )/ 8;
    int cellheight = (height() - height() / 16) / 8;
    QPen blackPen(Qt::black, 2);
    QPen whitePen(Qt::white, 4);
    QFont f("Arial", 15, QFont::Bold);
    char slovce = 'h';
    QImage figure(":/resources/index.png");
    QImage figura;

    p->setBrush(Qt::blue);
    p->drawRect(0, 0, width(), height());
    p->setPen(whitePen);

    p->setFont(f);
    for(int x = 0; x < m_chess->board_size; x++){
        int broj = 8 - x;
        p->drawText(QPoint(x*cellwidth + cellwidth - 1, cellheight / 2), QStringLiteral("%1").arg(broj));
    }

    for(int y = 0; y < m_chess->board_size; y++)
        p->drawText(QPoint(cellwidth / 4, y*cellheight + cellheight - 1), QString(slovce--));

    p->setPen(blackPen);
    p->translate(QPoint(width() / 16, height() / 16));
    for(int y = 0; y < m_chess->board_size; y++){
        for(int x = 0; x < m_chess->board_size; x++){
            QColor brushColor = ChessSquare::fromHextoQColor(m_chess->board[y][x].squareColor());
            QBrush brush = QBrush(brushColor);
            p->setBrush(brush);
            p->drawRect(x * cellwidth, y * cellheight, cellwidth, cellheight);
            if(m_chess->board[y][x].isEmpty()) continue;
            QRect selectionRect = figureToRect(m_chess->board[y][x].figureType(), m_chess->board[y][x].figureColor());
            figura = figure.copy(selectionRect).scaled(cellwidth, cellheight, Qt::AspectRatioMode::IgnoreAspectRatio);
            p->drawImage(x * cellwidth, y * cellheight, figura);
        }
    }
}

#include "chessview.h"
#include <QPainter>
#include "chesssquare.h"
#include "chessdoc.h"
#include <QMouseEvent>
#include "chesssquaredialog.h"

ChessView::ChessView(QWidget *parent) : QWidget(parent)
{
    doc=new ChessDoc();
    connect(doc,SIGNAL(chessDataChanged()),this,SLOT(repaint()));
}

void ChessView::drawChessboard(QPainter *p)
{
    p->setBrush(QColor(46,37,12));
    //dim=width()/10;
    dim=height()/10;
    for(int i=1;i<9;i++)
        for(int j=1;j<9;j++){
        if((j+i)%2==0){
            p->setBrush(QColor("##ff7700"));
        p->drawRect(j*dim,i*dim,dim,dim);
        }
        else{
            p->setBrush(QColor("##0000FF"));
        p->drawRect(j*dim,i*dim,dim,dim);
        }
    }

    ChessSquare sq;
    for(int i=1;i<9;i++)
            for(int j=1;j<9;j++){
            sq=doc->matrica[i-1][j-1];
            if(!sq.isEmpty)
            p->drawImage(QRect(j*dim,i*dim,dim,dim),QImage(":/bitmap.png"),QRect(sq.figureType*200,sq.figureColor*200,200,200));
            }
}

void ChessView::paintEvent(QPaintEvent *ev)
{

    QPainter* p=new QPainter(this);
    drawChessboard(p);
    p->end();

}
void ChessView::mouseDoubleClickEvent(QMouseEvent *event)
{
        double x= event->x();
        int i=(x-dim)/dim;
        double y=event->y();
        int j=(y-dim)/dim;
        if(i<8&&j<8){
        ChessSquare square=doc->matrica[j][i];
        ChessSquareDialog dlg(this,square.figureType,square.figureColor,square.isEmpty);
        if(dlg.exec()==QDialog::Accepted){
            ChessSquare* retSquare=dlg.getValues();
            doc->matrica[j][i].isEmpty=retSquare->isEmpty;
            doc->matrica[j][i].figureColor=retSquare->figureColor;
            doc->matrica[j][i].figureType=retSquare->figureType;
            emit doc->chessDataChanged();
        }
        }
}

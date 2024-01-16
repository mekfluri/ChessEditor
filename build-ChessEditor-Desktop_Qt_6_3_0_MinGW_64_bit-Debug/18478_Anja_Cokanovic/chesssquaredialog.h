#ifndef CHESSSQUAREDIALOG_H
#define CHESSSQUAREDIALOG_H

#include <QDialog>
#include "chesssquare.h"
namespace Ui {
class ChessSquareDialog;
}

class ChessSquareDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChessSquareDialog(QWidget *parent = nullptr,int fType=0,int fColor=0,bool empt=true);
    ~ChessSquareDialog();
    ChessSquare* getValues();
private:
    Ui::ChessSquareDialog *ui;
    int figType;
    int figColor;
    bool empty;
};

#endif // CHESSSQUAREDIALOG_H

#ifndef CHESSEDITDIALOG_H
#define CHESSEDITDIALOG_H

#include <QDialog>
#include "chessdoc.h"

namespace Ui {
class ChessEditDialog;
}

class ChessEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChessEditDialog(QWidget *parent = nullptr);
    ChessEditDialog(ChessDoc* chess, QWidget *parent = nullptr);
    ~ChessEditDialog();

private slots:
    void on_buttonBox_accepted();

private:
    ChessDoc* m_chess;
    Ui::ChessEditDialog *ui;
};

#endif // CHESSEDITDIALOG_H

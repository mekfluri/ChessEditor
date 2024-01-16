#include "chesseditdialog.h"
#include "ui_chesseditdialog.h"

ChessEditDialog::ChessEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChessEditDialog)
{
    ui->setupUi(this);
}

ChessEditDialog::ChessEditDialog(ChessDoc* chess, QWidget *parent): QDialog(parent), ui(new Ui::ChessEditDialog){
    ui->setupUi(this);
    m_chess = chess;
    ui->textEdit->setText(m_chess->toString());
}

ChessEditDialog::~ChessEditDialog()
{
    delete ui;
}

void ChessEditDialog::on_buttonBox_accepted()
{
    QString data = ui->textEdit->toPlainText();
    QStringList lines = data.split('\n');
    int figureColor;

    for(int i = 0; i < m_chess->board_size; i++){
        QStringList tokens = lines[i].split(',');
        for(int j = 0; j < tokens.length(); j++){
            if(tokens[j][0] == '-'){
                m_chess->board[i][j].setFigureColor(-1);
            }
            else {
                figureColor = tokens[j][0] == 'W' ? 1 : 0;
                m_chess->board[i][j].setFigureColor(figureColor);
                switch(tokens[j][1].toLatin1()){
                case 'K':
                    m_chess->board[i][j].setFigureType(0);
                    break;
                case 'Q':
                    m_chess->board[i][j].setFigureType(1);
                    break;
                case 'R':
                    m_chess->board[i][j].setFigureType(4);
                    break;
                case 'B':
                    m_chess->board[i][j].setFigureType(2);
                    break;
                case 'N':
                    m_chess->board[i][j].setFigureType(3);
                    break;
                case 'P':
                    m_chess->board[i][j].setFigureType(5);
                    break;
                }
            }
        }
    }
    emit m_chess->chessDataChanged();
}


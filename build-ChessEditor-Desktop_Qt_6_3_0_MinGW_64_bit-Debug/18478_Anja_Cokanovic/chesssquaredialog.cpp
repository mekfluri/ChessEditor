#include "chesssquaredialog.h"
#include "ui_chesssquaredialog.h"

ChessSquareDialog::ChessSquareDialog(QWidget *parent, int fType, int fColor, bool empt) :
    QDialog(parent),
    ui(new Ui::ChessSquareDialog)
{
    figColor=fColor;
    figType=fType;
    empty=empt;
    ui->setupUi(this);
    if (empty) {
        ui->checkBox->setChecked(true);
        ui->comboBox->setCurrentText(" ");
        ui->comboBox_2->setCurrentText(" ");
    }
    else
        ui->checkBox->setChecked(false);
    if(figColor==0)
        ui->comboBox->setCurrentText("Black");
    else
        ui->comboBox->setCurrentText("White");

    if(figType==0)
        ui->comboBox_2->setCurrentText("King");
    else if(figType==1)
        ui->comboBox_2->setCurrentText("Queen");
    else if(figType==2)
        ui->comboBox_2->setCurrentText("Bishop");
    else if(figType==3)
        ui->comboBox_2->setCurrentText("Knight");
    else if(figType==4)
        ui->comboBox_2->setCurrentText("Rook");
    else if(figType==5)
        ui->comboBox_2->setCurrentText("Pawn");


}

ChessSquareDialog::~ChessSquareDialog()
{
    delete ui;
}

ChessSquare *ChessSquareDialog::getValues()
{
    int c;
    bool e=ui->checkBox->isChecked();
    if(ui->comboBox->currentText()=="Black")
         c=0;
    else  c=1;

    int type=0;

    if(ui->comboBox_2->currentText()=="King")
        type=0;
    else if(ui->comboBox_2->currentText()=="Queen")
            type=1;
    else if(ui->comboBox_2->currentText()=="Bishop")
            type=2;
    else if(ui->comboBox_2->currentText()=="Knight")
            type=3;
    else if(ui->comboBox_2->currentText()=="Rook")
            type=4;
    else if(ui->comboBox_2->currentText()=="Pawn")
            type=5;

    ChessSquare* sq=new ChessSquare(e,0,type,c);
    return sq;
}

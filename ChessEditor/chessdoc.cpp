#include "chessdoc.h"
#include <QCoreApplication>
ChessDoc::ChessDoc(QObject *parent)
    : QObject{parent}
{
    init_board();
}

void ChessDoc::init_board(){
    int red = 0;
    QString color1 = "#ff00ff";
    QString color2 = "#ff7700";
    board = new ChessSquare*[board_size];
    for(int i = 0; i < board_size; i++)
        board[i] = new ChessSquare[board_size];
    while(red < board_size){
        for(int i = 0, j = 1; i < board_size || j < board_size; i += 2, j += 2){
            board[red][i].setSquareColor(color1);
            board[red][j].setSquareColor(color2);
        }
        QString tmp = color1;
        color1 = color2;
        color2 = tmp;
        red++;
    }
}

ChessDoc::~ChessDoc(){
    for(int i = 0; i < board_size; i++)
        delete[] board[i];
    delete[] board;
}

void ChessDoc::load(QString filename){
    QFile file(filename);
    int figureColor;

    if(!file.open(QIODevice::ReadOnly))
        qFatal("Failed opening file for reading");

    for(int i = 0; !file.atEnd(); i++){
        QString line = file.readLine();
        QStringList tokens = line.split(',');
        for(int j = 0; j < tokens.length(); j++){
            if(tokens[j][0] == '-'){
                board[i][j].setFigureColor(-1); // da bi isEmpty bilo true
            }
            else {
                figureColor = tokens[j][0] == 'W' ? 1 : 0;

                board[i][j].setFigureColor(figureColor);
                switch(tokens[j][1].toLatin1()){//toLatin da se dobije ascii znak, ovako je QCharRef neki djavo
                case 'K':
                    board[i][j].setFigureType(0);
                    break;
                case 'Q':
                    board[i][j].setFigureType(1);
                    break;
                case 'R':
                    board[i][j].setFigureType(4);
                    break;
                case 'B':
                    board[i][j].setFigureType(2);
                    break;
                case 'N':
                    board[i][j].setFigureType(3);
                    break;
                case 'P':
                    board[i][j].setFigureType(5);
                    break;
                }
            }
        }
    }
    file.close();
    emit chessDataChanged();
}

QString ChessDoc::toString(){
    QString polje;
    for(int i = 0; i < board_size; i++){
        for(int j = 0; j < board_size; j++){
            if(board[i][j].isEmpty()){
                polje += '-';
                if(j != board_size - 1)
                    polje += ',';
                continue;
            }
            char boja = board[i][j].figureColor() == 1 ? 'W' : 'B';
            char tip = '?';
            switch(board[i][j].figureType()){
            case 0:
                tip = 'K';
                break;
            case 1:
                tip = 'Q';
                break;
            case 2:
                tip = 'B';
                break;
            case 3:
                tip = 'N';
                break;
            case 4:
                tip = 'R';
                break;
            case 5:
                tip = 'P';
                break;
            }
            polje += boja;
            polje += tip;
            if(j != board_size - 1) polje += ',';
        }
        polje += '\n';
    }
    return polje;
}

void ChessDoc::save(QString filename){
    QFile file(filename);
    QString polje;

    if(!file.open(QIODevice::WriteOnly))
        qFatal("failed opening file for writing");

    polje = toString();

    file.write(polje.toLocal8Bit());
    file.close();
}

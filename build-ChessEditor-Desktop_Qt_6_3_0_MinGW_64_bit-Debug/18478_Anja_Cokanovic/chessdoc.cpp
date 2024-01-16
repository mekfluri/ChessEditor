#include "chessdoc.h"
#include <QFile>

ChessDoc::ChessDoc(QObject *parent) : QObject(parent)
{
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            matrica[i][j]=ChessSquare();


    int i=1;
    for(int j=0;j<8;j++)
        matrica[i][j]=ChessSquare(false,0,5,1);

    i=6;
    for (int j = 0; j < 8; j++)
        matrica[i][j] = ChessSquare(false, 0, 5, 0);

    for(int i=2;i<6;i++)
        for(int j=0;j<8;j++)
            matrica[i][j]=ChessSquare(true,0,0,0);

    matrica[0][0]=ChessSquare(false,0,4,1);
    matrica[0][7]=ChessSquare(false,0,4,1);

    matrica[0][1]=ChessSquare(false,0,3,1);
    matrica[0][6]=ChessSquare(false,0,3,1);

    matrica[0][2]=ChessSquare(false,0,2,1);
    matrica[0][5]=ChessSquare(false,0,2,1);

    matrica[0][3]=ChessSquare(false,0,1,1);
    matrica[0][4]=ChessSquare(false,0,0,1);



    matrica[7][0]=ChessSquare(false,0,4,0);
    matrica[7][7]=ChessSquare(false,0,4,0);

    matrica[7][1]=ChessSquare(false,0,3,0);
    matrica[7][6]=ChessSquare(false,0,3,0);

    matrica[7][2]=ChessSquare(false,0,2,0);
    matrica[7][5]=ChessSquare(false,0,2,0);

    matrica[7][3]=ChessSquare(false,0,1,0);
    matrica[7][4]=ChessSquare(false,0,0,0);
}

void ChessDoc::Load(QString file)
{
    QFile f(file);

    if(!f.open(QIODevice::ReadOnly))
        qFatal("Could not open file!");
    QByteArray data=f.readAll();
    QString dataString=QString(data);
    int k=0;
    QChar slovo;
    for(int i=0;i<8;i++){
        int j=0;
        while(j<8)
            {
               slovo=dataString[k];
               if(slovo==',')
                   k++;
               else if(slovo=='-'){
                    matrica[i][j].isEmpty=true;
                    k+=1;
                    j++;
               }
               else if(slovo=='B'||slovo=='W'){
                   if(slovo=='B')
                       matrica[i][j].figureColor=0;
                   else if(slovo=='W')
                       matrica[i][j].figureColor=1;
                   k++;
                   slovo=dataString[k];

                   if(slovo=='K')
                       matrica[i][j].figureType=0;
                   else if(slovo=='Q')
                       matrica[i][j].figureType=1;
                   else if(slovo=='R')
                       matrica[i][j].figureType=4;
                   else if(slovo=='B')
                       matrica[i][j].figureType=2;
                   else if(slovo=='N')
                       matrica[i][j].figureType=3;
                   else if(slovo=='P')
                       matrica[i][j].figureType=5;
                   matrica[i][j].isEmpty=false;
                   j++;
                   k++;
               }
               else k++;
            }
}
    f.close();
    emit chessDataChanged();
}

void ChessDoc::Save(QString file)
{
    QFile f(file);
    if(!f.open(QIODevice::WriteOnly))
        qFatal("Could not open file!");
    QString text("");
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(matrica[i][j].isEmpty)
                text+="-";
            else{
                if(matrica[i][j].figureColor==0)
                    text+="B";
                else
                    text+="W";
                if(matrica[i][j].figureType==0)
                    text+="K";
                else if(matrica[i][j].figureType==1)
                    text+="Q";
                else if(matrica[i][j].figureType==2)
                    text+="B";
                else if(matrica[i][j].figureType==3)
                    text+="N";
                else if(matrica[i][j].figureType==4)
                    text+="R";
                else if(matrica[i][j].figureType==5)
                    text+="P";
            }
            if(j<7)
            text+=",";
        }
        text+="\n";
    }
    f.write(text.toUtf8());
    f.close();
}


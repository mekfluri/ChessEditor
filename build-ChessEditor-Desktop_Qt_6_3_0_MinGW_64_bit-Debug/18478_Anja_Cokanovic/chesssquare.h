#ifndef CHESSSQUARE_H
#define CHESSSQUARE_H


class ChessSquare
{
public:
    ChessSquare();
    ChessSquare(bool empty,int sqColor,int fType,int FColor);

    bool isEmpty;
    int squareColor;
    int figureType;
    int figureColor;

};

#endif // CHESSSQUARE_H

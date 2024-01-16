#include "chesssquare.h"

ChessSquare::ChessSquare()
{

}

ChessSquare::ChessSquare(bool empty, int sqColor, int fType, int FColor)
{
    isEmpty=empty;
    squareColor=sqColor;
    figureType=fType;
    figureColor = FColor;
}

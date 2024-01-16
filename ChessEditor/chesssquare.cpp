#include "chesssquare.h"

ChessSquare::ChessSquare()
{
    setFigureType(-1);
    setFigureColor(-1);
    setSquareColor("");
}

ChessSquare::ChessSquare(int type, int color, QString sColor):
    m_figureType(type),
    m_figureColor(color),
    m_squareColor(sColor)

{
}

void ChessSquare::setFigureType(int type) {
    m_figureType = type;
    m_isEmpty = m_figureType == -1 ? true : false;
}
void ChessSquare::setFigureColor(int color){
    m_figureColor = color;
    m_isEmpty = m_figureType == -1 ? true : false;
}
void ChessSquare::setSquareColor(QString color){
    m_squareColor = color;
}

QColor ChessSquare::fromHextoQColor(QString color){
    //#ff00ff
    QString c = color.mid(1, 6);
    unsigned int broj;
    int r, g, b;
    broj = c.toUInt(nullptr, 16);
    b = broj & 0xFF;
    broj >>= 8;
    g = broj & 0xFF;
    broj >>= 8;
    r = broj & 0xFF;
    return QColor(r, g, b);
}

#ifndef CHESSSQUARE_H
#define CHESSSQUARE_H

#include <QString>
#include <QColor>

class ChessSquare
{
private:
    bool m_isEmpty;
    int m_figureType;
    int m_figureColor;
    QString m_squareColor;
public:
    ChessSquare();
    ChessSquare(int,int,QString);
    inline bool isEmpty() { return m_isEmpty; }
    inline int figureType() { return m_figureType; }
    inline int figureColor() { return m_figureColor; }
    inline QString squareColor() { return m_squareColor; }
    void setFigureType(int);
    void setFigureColor(int);
    void setSquareColor(QString);
    static QColor fromHextoQColor(QString);
};

#endif // CHESSSQUARE_H

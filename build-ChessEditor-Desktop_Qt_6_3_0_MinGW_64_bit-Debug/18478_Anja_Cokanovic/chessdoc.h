#ifndef CHESSDOC_H
#define CHESSDOC_H

#include <QObject>
#include "chesssquare.h"
//#include "chessview.h"
class ChessDoc : public QObject
{
    Q_OBJECT
public:
    explicit ChessDoc(QObject *parent = nullptr);
    ChessSquare matrica[8][8];
    void Load(QString file);
    void Save(QString file);
signals:
    void chessDataChanged();
};

#endif // CHESSDOC_H

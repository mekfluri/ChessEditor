#ifndef CHESSDOC_H
#define CHESSDOC_H

#include <QObject>
#include <QFile>
#include "chesssquare.h"

class ChessDoc : public QObject
{
    Q_OBJECT
private:
    QString filename;
    void init_board();
public:
    ChessSquare** board;
    static const int board_size = 8;
public:
    explicit ChessDoc(QObject *parent = nullptr);
    void load(QString filename);
    void save(QString filename);
    QString toString();
    ~ChessDoc();

signals:
void chessDataChanged();
};

#endif // CHESSDOC_H

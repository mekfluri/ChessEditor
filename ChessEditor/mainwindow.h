#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "chessdoc.h"
#include "chesseditdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionLoad_Chessboard_triggered();
    void dibagovanje();

    void on_actionEdit_Chess_Dialog_triggered();

    void on_actionsave_file_triggered();

private:
    ChessEditDialog* m_dialog;
    ChessDoc* m_chess;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

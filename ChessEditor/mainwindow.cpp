#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_chess = new ChessDoc();
    ui->centralwidget->setBoard(m_chess);
    this->setWindowTitle("Chess Editor");
    connect(ui->actionSave_Chessboard, &QAction::triggered, this, &MainWindow::on_actionsave_file_triggered);
    connect(ui->actionopen_file, &QAction::triggered, this, &MainWindow::on_actionLoad_Chessboard_triggered);
}

MainWindow::~MainWindow()
{
    delete m_dialog;
    delete m_chess;
    delete ui;
}

void MainWindow::dibagovanje(){
    QString polje;
    for(int i = 0; i < m_chess->board_size; i++){
        for(int j = 0; j < m_chess->board_size; j++){
            if(m_chess->board[i][j].isEmpty()){
                polje += '-';
                if(j != m_chess->board_size - 1)
                    polje += ',';
                continue;
            }
            char boja = m_chess->board[i][j].figureColor() == 1 ? 'W' : 'B';
            char tip = '?';
            switch(m_chess->board[i][j].figureType()){
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
        }
        polje += '\n';
    }
}

void MainWindow::on_actionLoad_Chessboard_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Chessboard fajl", QDir::currentPath(), "*.txt");
    m_chess->load(filename);
}


void MainWindow::on_actionEdit_Chess_Dialog_triggered()
{
    m_dialog = new ChessEditDialog(m_chess);
    m_dialog->setModal(true);
    m_dialog->exec();
    delete m_dialog;
}


void MainWindow::on_actionsave_file_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save file", QDir::homePath(), "*.txt");
    m_chess->save(filename);
}


#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <QMessageBox>
#include "ConfigurationDialog.h"
#include <QAction>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->startNewGame, &QAction::triggered,
            this, &MainWindow::startNewGame);
    connect(ui->gameBoard, &TicTacToeWidget::currentPlayerChanged,
            this, &MainWindow::updateNameLabel);
    connect(ui->gameBoard, &TicTacToeWidget::gameOver,
            this, &MainWindow::handelGameOver);
    connect(ui->quit, &QAction::triggered, qApp, &QApplication::quit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startNewGame()
{
    ConfigurationDialog dialog(this);
    if(dialog.exec() == QDialog::Rejected)
    {
        return;
    }
    ui->playerName->setText(dialog.player1Name());
    ui->player2Name->setText(dialog.player2Name());
    ui->gameBoard->initNewGame();
}

void MainWindow::updateNameLabel()
{
    setLabelBold(ui->playerName,
                 ui->gameBoard->currentPlayer()
                 == TicTacToeWidget::Player::Player1);

    setLabelBold(ui->player2Name,
                 ui->gameBoard->currentPlayer()
                 == TicTacToeWidget::Player::Player2);
}

void MainWindow::setLabelBold(QLabel *label, bool isBold)
{
    QFont f = label->font();
    f.setBold(isBold);
    label->setFont(f);
}

void MainWindow::handelGameOver(TicTacToeWidget::Player winner)
{
    QString message;
    if(winner == TicTacToeWidget::Player::Draw)
    {
        message = tr("Game ended with a draw");
    }
    else
    {
        QString winnerName = winner == TicTacToeWidget::Player::Player1 ?
                    ui->playerName->text() : ui->player2Name->text();
        message = tr("%1 wins").arg(winnerName);
    }

    QMessageBox::information(this, tr("Info"), message);
}

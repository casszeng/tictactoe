#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include "TicTacToeWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setLabelBold(QLabel *label, bool isBold);

private slots:
    void startNewGame();
    void updateNameLabel();

    void handelGameOver(TicTacToeWidget::Player winner);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

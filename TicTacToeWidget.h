#ifndef TICTACTOEWIDGET_H
#define TICTACTOEWIDGET_H

#include <QPushButton>
#include <QWidget>

class TicTacToeWidget : public QWidget
{
    Q_OBJECT

public:
    enum class Player
    {
        Invalid, Player1, Player2, Draw
    };
    Q_ENUM(Player);
    explicit TicTacToeWidget(QWidget *parent = nullptr);
    //~TicTacToeWidget();
    Player currentPlayer() const;
    void setCurrentPlayer(Player p);
    void initNewGame();
signals:
    void currentPlayerChanged(Player);
    void gameOver(Player);

private slots:
    void handleButtonClick(int index);

private:
    Player checkWinCondition();
    Player checkDraw();
    Player checkWins();

private:
    QVector<QPushButton*> m_board;
    Player m_currentPlayer;

};

#endif // TICTACTOEWIDGET_H

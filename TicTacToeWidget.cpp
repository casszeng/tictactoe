#include "TicTacToeWidget.h"

#include <QGridLayout>
#include <QSignalMapper>

TicTacToeWidget::TicTacToeWidget(QWidget *parent) :
    QWidget(parent),
    m_currentPlayer(Player::Invalid)

{
    QGridLayout *gridLayout = new QGridLayout(this);
    QSignalMapper *mapper = new QSignalMapper(this);
    for(int row = 0; row < 3; ++row)
    {
        for (int column = 0; column < 3; ++column)
        {
            QPushButton *button = new QPushButton(" ");
            button->setSizePolicy(QSizePolicy::Preferred,
                                  QSizePolicy::Preferred);
            button->setEnabled(false);
            gridLayout->addWidget(button, row, column);
            m_board.append(button);
            mapper->setMapping(button, m_board.count() - 1);
            connect(button, SIGNAL(clicked()), mapper, SLOT(map()));

        }
    }

    connect(mapper, SIGNAL(mapped(int)),
            this, SLOT(handleButtonClick(int)));
}

TicTacToeWidget::Player TicTacToeWidget::currentPlayer() const
{
    return m_currentPlayer;
}

void TicTacToeWidget::setCurrentPlayer(Player p)
{
    if(m_currentPlayer == p)
    {
        return;
    }
    m_currentPlayer = p;
    emit currentPlayerChanged(p);
}

void TicTacToeWidget::handleButtonClick(int index)
{
    if(m_currentPlayer == Player::Invalid)
    {
        return;
    }

    if(index < 0 || index >= m_board.size())
    {
        return;
    }
    QPushButton *button = m_board[index];
    if(button->text() != " ")
    {
        return;
    }
    button->setText(currentPlayer() == Player::Player1 ? "X" : "O");
    Player winner = checkWinCondition();
    if(winner == Player::Invalid)
    {
        setCurrentPlayer(currentPlayer() == Player::Player1 ? Player::Player2 : Player::Player1);
        return;
    }
    else
    {
        for(QPushButton* b : m_board)
        {
            b->setEnabled(false);
        }
        emit gameOver(winner);
    }
}

void TicTacToeWidget::initNewGame()
{
    for (QPushButton* button : m_board)
    {
        button->setText(" ");
        button->setEnabled(true);
    }

    setCurrentPlayer(Player::Player1);
}

TicTacToeWidget::Player TicTacToeWidget::checkWinCondition()
{
    Player winner = checkWins();

    if(winner == Player::Invalid)
    {
        winner = checkDraw();
    }
    return winner;

}

TicTacToeWidget::Player TicTacToeWidget::checkWins()
{
    QString player1 = "X";
    QString player2 = "O";

    QString firstPiece = m_board[0]->text();
    QString secPiece = m_board[1]->text();
    QString thirPiece = m_board[2]->text();
    if( QString::compare(firstPiece, secPiece, Qt::CaseInsensitive) == 0
            && QString::compare(thirPiece, secPiece, Qt::CaseInsensitive) == 0 )
    {
        if(QString::compare(firstPiece, player1, Qt::CaseInsensitive) == 0)
        {
            return Player::Player1;
        }
        else if(QString::compare(firstPiece, player2, Qt::CaseInsensitive) == 0)
        {
            return Player::Player2;
        }
    }

    player1 = "X";
    player2 = "O";

    firstPiece = m_board[3]->text();
    secPiece = m_board[4]->text();
    thirPiece = m_board[5]->text();
    if( QString::compare(firstPiece, secPiece, Qt::CaseInsensitive) == 0
            && QString::compare(thirPiece, secPiece, Qt::CaseInsensitive) == 0 )
    {
        if(QString::compare(firstPiece, player1, Qt::CaseInsensitive) == 0)
        {
            return Player::Player1;
        }
        else if(QString::compare(firstPiece, player2, Qt::CaseInsensitive) == 0)
        {
            return Player::Player2;
        }
    }

    player1 = "X";
    player2 = "O";

    firstPiece = m_board[6]->text();
    secPiece = m_board[7]->text();
    thirPiece = m_board[8]->text();
    if( QString::compare(firstPiece, secPiece, Qt::CaseInsensitive) == 0
            && QString::compare(thirPiece, secPiece, Qt::CaseInsensitive) == 0 )
    {
        if(QString::compare(firstPiece, player1, Qt::CaseInsensitive) == 0)
        {
            return Player::Player1;
        }
        else if(QString::compare(firstPiece, player2, Qt::CaseInsensitive) == 0)
        {
            return Player::Player2;
        }
    }

    player1 = "X";
    player2 = "O";

    firstPiece = m_board[0]->text();
    secPiece = m_board[4]->text();
    thirPiece = m_board[8]->text();
    if( QString::compare(firstPiece, secPiece, Qt::CaseInsensitive) == 0
            && QString::compare(thirPiece, secPiece, Qt::CaseInsensitive) == 0 )
    {
        if(QString::compare(firstPiece, player1, Qt::CaseInsensitive) == 0)
        {
            return Player::Player1;
        }
        else if(QString::compare(firstPiece, player2, Qt::CaseInsensitive) == 0)
        {
            return Player::Player2;
        }
    }

    player1 = "X";
    player2 = "O";

    firstPiece = m_board[2]->text();
    secPiece = m_board[4]->text();
    thirPiece = m_board[6]->text();
    if( QString::compare(firstPiece, secPiece, Qt::CaseInsensitive) == 0
            && QString::compare(thirPiece, secPiece, Qt::CaseInsensitive) == 0 )
    {
        if(QString::compare(firstPiece, player1, Qt::CaseInsensitive) == 0)
        {
            return Player::Player1;
        }
        else if(QString::compare(firstPiece, player2, Qt::CaseInsensitive) == 0)
        {
            return Player::Player2;
        }
    }

    return Player::Invalid;
}

TicTacToeWidget::Player TicTacToeWidget::checkDraw()
{
    QString player = " ";

    for (QPushButton* button : m_board)
    {
        QString firstPiece = button->text();
        if(QString::compare(firstPiece, player, Qt::CaseInsensitive) == 0)
        {
            return Player::Invalid;
        }
    }

    return Player::Draw;
}


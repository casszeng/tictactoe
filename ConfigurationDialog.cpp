#include "ConfigurationDialog.h"
#include "ui_ConfigurationDialog.h"

#include <QPushButton>

ConfigurationDialog::ConfigurationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigurationDialog)
{
    ui->setupUi(this);
    connect(ui->player1Name, &QLineEdit::textChanged,
            this, &ConfigurationDialog::updateOkButtonState);
    connect(ui->player2Name, &QLineEdit::textChanged,
            this, &ConfigurationDialog::updateOkButtonState);
    updateOkButtonState();
}

ConfigurationDialog::~ConfigurationDialog()
{
    delete ui;
}

void ConfigurationDialog::setPlayer1Name(const QString &p1name)
{
    ui->player1Name->setText(p1name);
}

void ConfigurationDialog::setPlayer2Name(const QString &p1name)
{
    ui->player2Name->setText(p1name);
}

QString ConfigurationDialog::player2Name() const
{
    return ui->player2Name->text();
}

void ConfigurationDialog::updateOkButtonState()
{
    QPushButton *okButton = ui->buttonBox->button(QDialogButtonBox::Ok);
    okButton->setEnabled(!ui->player1Name->text().isEmpty() &&
                         !ui->player2Name->text().isEmpty());

}

QString ConfigurationDialog::player1Name() const
{
    return ui->player1Name->text();
}

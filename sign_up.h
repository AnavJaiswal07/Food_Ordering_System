#ifndef SIGN_UP_H
#define SIGN_UP_H

#include <QDialog>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include<mainwindow.h>

namespace Ui {
class Sign_up;
}

class Sign_up : public QDialog
{
    Q_OBJECT

public:
    explicit Sign_up(QWidget *parent = nullptr);
    ~Sign_up();
    QString pass_value();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Sign_up *ui;
    QSqlDatabase mydb;

};

#endif // SIGN_UP_H

#ifndef ORDER_SYSTEM_H
#define ORDER_SYSTEM_H

#include <QDialog>
#include<sign_up.h>
#include<mainwindow.h>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
namespace Ui {
class order_System;
}

class order_System : public QDialog
{
    Q_OBJECT

public:
    explicit order_System(QWidget *parent = nullptr);
    ~order_System();
    Sign_up sign;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::order_System *ui;
    QSqlDatabase mydb;
};

#endif // ORDER_SYSTEM_H

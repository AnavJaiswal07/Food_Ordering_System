#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"sign_up.h"
#include"order_system.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1200,800);
    ui->lineEdit->setPlaceholderText("Username");
    ui->lineEdit_2->setPlaceholderText("Password");
    ui->label->setAlignment(Qt::AlignHCenter);
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("c:/sqlite/first.db");
    if(!mydb.open())
        ui->label->setText("Database failed connection");
    else
        ui->label->setText("Database connected...!");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    this->destroy();
    this->hide();
    Sign_up sign;
    sign.setModal(true);
    sign.exec();
}
void MainWindow::on_pushButton_2_clicked()
{
    QString username,password;
     QSqlQuery qry;
    username = ui->lineEdit->text();
    password = ui->lineEdit_2->text();
    if(!mydb.isOpen()){
        qDebug()<<"Database failed...!";
        return;
    }
    if(qry.exec("select * from first where username = '"+username+"'and password = '"+password+"'")){
        int count =0;
        while(qry.next()){
            count++;
        }
        if(count==1){
            ui->label->setText("Signed in sucessfully..!");
            this->destroy();
            this->hide();
            class order_System order;
            order.setModal(true);
            order.exec();
        }
        if(count<1){
            ui->label->setText("Username or password not correct !");
        }
    }

}



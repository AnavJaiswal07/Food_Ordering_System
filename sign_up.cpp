#include "sign_up.h"
#include "ui_sign_up.h"
#include"order_system.h"
Sign_up::Sign_up(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sign_up)
{
    ui->setupUi(this);
    this->setFixedSize(1200,800);
    ui->lineEdit->setPlaceholderText("Name");
    ui->lineEdit_2->setPlaceholderText("Email Address");
    ui->lineEdit_3->setPlaceholderText("Phone Number");
    ui->lineEdit_4->setPlaceholderText("Username");
    ui->lineEdit_5->setPlaceholderText("Password");
    ui->label->setAlignment(Qt::AlignHCenter);
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("c:/sqlite/first.db");
    if(!mydb.open())
        ui->label->setText("Database failed connection");
    else
        ui->label->setText("Database connected...!");
}

Sign_up::~Sign_up()
{
    delete ui;
}

void Sign_up::on_pushButton_clicked()
{
    this->destroy();
    this->hide();
    order_System order;
    order.setModal(true);
    order.exec();
}


void Sign_up::on_pushButton_2_clicked()
{
    QString name,email,phone,username,password;
    QSqlQuery qry1,qry;
    name = ui->lineEdit->text();
    email=ui->lineEdit_2->text();
    phone=ui->lineEdit_3->text();
    username=ui->lineEdit_4->text();
    password=ui->lineEdit_5->text();
    if(!mydb.isOpen()){
                qDebug()<<"Database failed ";
            }
             if(qry1.exec("select * from first where username = '"+username+"'")){
                int count =0;
                while(qry1.next()){
                    count++;
                    }
                if(count==1){
                    ui->label->setText("Username already exists..!");
                }
                if(count<1){
                    if(qry.exec("insert into first (name,email,phone,username,password)values('"+name+"','"+email+"','"+phone+"','"+username+"','"+password+"')")){
                      ui->label->setText("Data entered move to login page...!");
                      this->destroy();
                      this->hide();
                      class order_System order;
                      order.setModal(true);
                      order.exec();
                   }
                }
            }
}



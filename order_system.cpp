#include "order_system.h"
#include "ui_order_system.h"
#include"sign_up.h"
#include<QMessageBox>
order_System::order_System(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::order_System)
{
    ui->setupUi(this);
    this->setFixedSize(1200,800);
    ui->label->setAlignment(Qt::AlignHCenter);
    ui->label_2->setAlignment(Qt::AlignHCenter);
    ui->lineEdit->setAlignment(Qt::AlignHCenter);
    ui->lineEdit_2->setAlignment(Qt::AlignHCenter);
    ui->lineEdit_3->setAlignment(Qt::AlignHCenter);
    ui->lineEdit_4->setAlignment(Qt::AlignHCenter);
    ui->lineEdit_5->setAlignment(Qt::AlignHCenter);
    ui->label->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->label->setOpenExternalLinks(true);
    ui->label->setTextFormat(Qt::RichText);
    ui->label->setText("<a href=\"http://www.paytm.com\">Paytm</a>");
    ui->lineEdit->setPlaceholderText("Enter Quantity");
    ui->lineEdit_2->setPlaceholderText("Enter Quantity");
    ui->lineEdit_3->setPlaceholderText("Enter Quantity");
    ui->lineEdit_4->setPlaceholderText("Enter Quantity");
    ui->lineEdit_5->setPlaceholderText("Enter Quantity");
    ui->lineEdit_6->setPlaceholderText("Username");
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("c:/sqlite/second.db");
    if(!mydb.open()){

    }
    else{

    }



}

order_System::~order_System()
{
    delete ui;
}

void order_System::on_pushButton_clicked()
{
    this->destroy();
    this->hide();
    Sign_up sign;
    sign.setModal(true);
    sign.exec();
}

QString username;
bool check=false;
void order_System::on_pushButton_2_clicked()
{
    QSqlQuery qry1,qry;
    int no1= 0,no2=0,no3=0,no4=0,no5=0,c=0;
    QString str = ui->lineEdit->text();
     no1 = str.toInt();
     no1 = no1*5;
    QString str1 = ui->lineEdit_2->text();
    no2 = str1.toInt();
    no2 = no2 *3;
   QString str2 = ui->lineEdit_3->text();
   no3 = str2.toInt();
   no3 = no3*2;
   QString str3 = ui->lineEdit_4->text();
   no4 = str3.toInt();
   no4= no4*1;
   QString str4 = ui->lineEdit_5->text();
   no5 =str4.toInt();
   no5 = no5*3;
    c = no1 + no2+no3+no4+no5;
   QString output = QString::number(c);
  ui->label_2->setText(" Total : $"+ output);

  username = ui->lineEdit_6->text();
  QString pizza="0",burger="0",coldDrinks="0",fries="0",momos="0",totalPrice="0";
  pizza = ui->lineEdit->text();
  burger = ui->lineEdit_2->text();
  coldDrinks = ui->lineEdit_3->text();
  fries = ui->lineEdit_4->text();
  momos = ui->lineEdit_5->text();
  totalPrice = output;
  QMessageBox msgbox;
  if(username==0){
      msgbox.setText("Enter your username first...!");
      msgbox.exec();
  }
  else{
  if(!mydb.isOpen()){
              qDebug()<<"Database failed ";
          }
           if(qry1.exec("select * from second where username = '"+username+"'")){
              int count =0;
              while(qry1.next()){
                  count++;
                  }
              if(count==1){
                  msgbox.setText("username already exist...!");
                  msgbox.exec();
              }
              if(count<1){
                  if(qry.exec("insert into second (username,pizza,burger,coldDrinks,fries,momos,totalPrice)values('"+username+"','"+pizza+"','"+burger+"','"+coldDrinks+"','"+fries+"','"+momos+"','"+totalPrice+"')")){
                      msgbox.setText("Your order submiteed sucessfully...!");
                      check = true;
                      msgbox.exec();
                 }
              }
          }
  }
}

void order_System::on_pushButton_3_clicked()
{
    QMessageBox mess;

    if(check ==false){
       mess.setText("Enter username correctly...!");
       mess.exec();
     }
   else if(check ==true){
        QSqlQuery qry1;
        qry1.prepare( "delete from second where username = '"+username+"'");
          if( qry1.exec()){
              mess.setText("Order cancelled sucessfully...!");
              mess.exec();}
          else{
              mess.setText("Please try again...!");
              mess.exec();
          }

      }

}


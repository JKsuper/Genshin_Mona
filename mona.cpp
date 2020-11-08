#include "mona.h"
#include "ui_mona.h"
#include <QString>

mona::mona(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mona)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(caldmg()));
}

mona::~mona()
{
    delete ui;
}

int add(int a,int b){
   return a+b;
}

void mona::caldmg(){
    QString atk = ui->atk->text();
    int add1=atk.toInt();
    QString cri = ui->cri->text();
    int add2=cri.toInt();
    int sum=add(add1,add2);
    ui->textBrowser->setText(QString::number(sum));
}

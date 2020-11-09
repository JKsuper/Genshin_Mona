#include "mona.h"
#include "ui_mona.h"
#include <QString>

mona::mona(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mona)
{
    ui->setupUi(this);
    ui->bannite->setEnabled(false);
    ui->bannitejiashang->setEnabled(false);
    ui->jiankang->setEnabled(false);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(caldmg()));
    connect(ui->checkBox,SIGNAL(clicked(bool)),ui->bannite,SLOT(setEnable(bool)));
    connect(ui->checkBox,SIGNAL(clicked(bool)),ui->bannitejiashang,SLOT(setEnable(bool)));
    connect(ui->checkBox_2,SIGNAL(clicked(bool)),ui->jiankang,SLOT(setEnabled(bool)));

}

mona::~mona()
{
    delete ui;
}

double add(double a,double b,double c,double d,double e,double f){
   return (a*b)*(1+c)*(1+d)*2*(1+e)*f;
}

void mona::caldmg(){
    QString atk = ui->atk->text();
    int gongjili=atk.toInt();
    QString jineng = ui->jineng->text();
    double beilv=jineng.toDouble()/100;

    QString bannite=ui->bannite->text();
    int banniteatk=bannite.toInt();
    QString bannitejiashang=ui->bannitejiashang->text();
    double bannitebuff=bannitejiashang.toDouble()/100;

    if(ui->checkBox->isChecked()==true){
        double ewaigongji=banniteatk*bannitebuff;
        gongjili=gongjili+static_cast<int>(ewaigongji);
    }

    QString baojilv=ui->baoji->text();
    double add3=baojilv.toDouble()/100;
    QString baojishanghai=ui->baojishanghai->text();
    double add4=baojishanghai.toDouble()/100;
    double baojiyuqi=add3*add4;

    QString yuansujiacheng=ui->yuansu->text();
    double add5=yuansujiacheng.toDouble()/100;
    QString dazhao=ui->dazhaojiashang->text();
    double add6=dazhao.toDouble()/100;
    QString liaoli=ui->liaoli->text();
    double add7=liaoli.toDouble()/100;
    double jiashangyuqi=add5+add6+add7;

    QString jingtong=ui->jingtong->text();
    double fanyingyuqi=(6.665-9340/(jingtong.toDouble()+1401))/2.4;

    QString renwu=ui->renwudengji->text();
    QString guaiwu=ui->guaiwudengji->text();
    int renwulv=renwu.toInt();
    int guaiwulv=guaiwu.toInt();

    double mianshang;
    if(renwulv!=guaiwulv){
        mianshang=0.45-(guaiwulv-renwulv)*0.0015;
    }else {
        mianshang=0.45;
    }

    double sum=add(gongjili,beilv,baojiyuqi,jiashangyuqi,fanyingyuqi,mianshang);
    double kangxing=add(gongjili,beilv,add4,jiashangyuqi,fanyingyuqi,mianshang);
    double wubaoji=add(gongjili,beilv,0,jiashangyuqi,fanyingyuqi,mianshang);


    if(ui->checkBox_2->isChecked()==true){
        double kangxingjiacheng = 0.0;
        QString jiankang=ui->jiankang->text();
        double jiankangbili=jiankang.toDouble()/100;
        if(jiankangbili<=0.1){
            kangxingjiacheng=(jiankangbili/(1-0.1))+1;
        }else if(jiankangbili>0.1){
            kangxingjiacheng=((0.1+jiankangbili)/2*(1-0.1))+1;
        }
        sum=sum*kangxingjiacheng;
        kangxing=kangxing*kangxingjiacheng;
        wubaoji=wubaoji*kangxingjiacheng;
    }

    ui->textBrowser->setText(QString::number(static_cast<int>(sum)));
    ui->textBrowser_2->setText(QString::number(static_cast<int>(kangxing)));
    ui->textBrowser_3->setText(QString::number(static_cast<int>(wubaoji)));
}

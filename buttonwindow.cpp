#include "buttonwindow.h"
#include "ui_buttonwindow.h"

buttonWindow::buttonWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::buttonWindow)
{
    ui->setupUi(this);
    flag_v1=0;
    flag_v2=0;
    a.clear();
    b.clear();

    //connect(this,SIGNAL(),this,SLOT(on_pushButton_zero_clicked()));


}

buttonWindow::~buttonWindow()
{
    delete ui;
}
//数字键

void buttonWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_0)
    {
        on_pushButton_zero_clicked();
    }
    else if(e->key()==Qt::Key_1)
    {
        on_pushButton_clicked();
    }
    else if(e->key()==Qt::Key_2)
    {
        on_pushButton_2_clicked();
    }
    else if(e->key()==Qt::Key_3)
    {
        on_pushButton_3_clicked();
    }
    else if(e->key()==Qt::Key_4)
    {
        on_pushButton_4_clicked();
    }
    else if(e->key()==Qt::Key_5)
    {
        on_pushButton_5_clicked();
    }
    else if(e->key()==Qt::Key_6)
    {
        on_pushButton_6_clicked();
    }
    else if(e->key()==Qt::Key_7)
    {
        on_pushButton_7_clicked();
    }
    else if(e->key()==Qt::Key_8)
    {
        on_pushButton_8_clicked();
    }
    else if(e->key()==Qt::Key_9)
    {
        on_pushButton_9_clicked();
    }
    else if(e->key()==Qt::Key_Period)
    {
        on_pushButton_point_clicked();
    }
    else if(e->key()==Qt::Key_Plus)
    {
        on_pushButton_plug_clicked();
    }
    else if(e->key()==Qt::Key_Minus)
    {
        on_pushButton_minus_clicked();
    }
    else if(e->key()==Qt::Key_Asterisk)
    {
        on_pushButton_multiply_clicked();
    }
    else if(e->key()==Qt::Key_Slash)
    {
        on_pushButton_divide_clicked();
    }
    else if(e->key()==Qt::Key_Backspace)
    {
        on_pushButton_retreat_clicked();
    }
    else if(e->key()==Qt::Key_Enter)
    {
        on_pushButton_result_clicked();
    }
    else if(e->key()==Qt::Key_Return)
    {
        on_pushButton_result_clicked();
    }
}
void buttonWindow::on_pushButton_zero_clicked()
{
    a+="0";
    ui->lineEdit->setText(a);
}

void buttonWindow::on_pushButton_clicked()
{
    a+="1";
    ui->lineEdit->setText(a);
}

void buttonWindow::on_pushButton_2_clicked()
{
    a+="2";
    ui->lineEdit->setText(a);
}

void buttonWindow::on_pushButton_3_clicked()
{
    a+="3";
    ui->lineEdit->setText(a);
}

void buttonWindow::on_pushButton_4_clicked()
{
    a+="4";
    ui->lineEdit->setText(a);
}

void buttonWindow::on_pushButton_5_clicked()
{
    a+="5";
    ui->lineEdit->setText(a);
}

void buttonWindow::on_pushButton_6_clicked()
{
    a+="6";
    ui->lineEdit->setText(a);
}

void buttonWindow::on_pushButton_7_clicked()
{
    a+="7";
    ui->lineEdit->setText(a);
}

void buttonWindow::on_pushButton_8_clicked()
{
    a+="8";
    ui->lineEdit->setText(a);
}

void buttonWindow::on_pushButton_9_clicked()
{
    a+="9";
    ui->lineEdit->setText(a);
}

void buttonWindow::on_pushButton_PI_clicked()
{
    a=QString::number(M_PI);
    ui->lineEdit->setText(a);
}

//point
void buttonWindow::on_pushButton_point_clicked()
{
    a+=".";
    ui->lineEdit->setText(a);
}

//加减乘除
void buttonWindow::on_pushButton_plug_clicked()
{
    if(b.isEmpty())
    {
         b.insert(0,a);
    }
    else
    {
         b.insert(1,"+");
    }
    a.clear();
    b.insert(1,"+");
    ui->lineEdit->setText(a);
}

void buttonWindow::on_pushButton_minus_clicked()
{
    if(b.isEmpty())
    {
        if(a=="")
        {
            a="-";
        }
        else
        {
            b.insert(0,a);
            b.insert(1,"-");
            a.clear();
        }
    }
    else
    {
        if(a=="")
        {
            a="-";
        }
        else
        {
            b.insert(1,"-");
            a.clear();
        }
    }
    ui->lineEdit->setText(a);
}

void buttonWindow::on_pushButton_multiply_clicked()
{
    if(b.isEmpty())
    {
        b.insert(0,a);
    }
    else
    {
        b.insert(1,"*");
    }
    a.clear();
    b.insert(1,"*");
    ui->lineEdit->setText(a);
}

void buttonWindow::on_pushButton_divide_clicked()
{
    if(b.isEmpty())
    {
        b.insert(0,a);
    }
    else
    {
        b.insert(1,"/");
    }
    a.clear();
    b.insert(1,"/");
    ui->lineEdit->setText(a);
}
//取余
void buttonWindow::on_pushButton_mode_clicked()
{
    if(b.isEmpty())
    {
        b.insert(0,a);
    }
    else
    {
        b.insert(1,"%");
    }
    a.clear();
    b.insert(1,"%");
    ui->lineEdit->setText(a);
}


//结果键
void buttonWindow::on_pushButton_result_clicked()
{
    if(b.count()>=2)
    {
        b.insert(2,a);
        QString a1=b.at(0),a2=b.at(2);
        flag_v1=1;
        flag_v2=1;
        if(a1.contains("-"))
        {
            a1.remove("-");
            flag_v1=-1;
        }
        if(a2.contains("-"))
        {
            a2.remove("-");
            flag_v2=-1;
        }
        v1=a1.toDouble();
        v2=a2.toDouble();
        v1=v1*flag_v1;
        v2=v2*flag_v2;
        if(b.at(1)=="+")
        {
           v3=v1+v2;
           a.clear();
           a=QString::number(v3);
           ui->lineEdit->setText(a);
        }
       else if(b.at(1)=="-")
        {
            v3=v1-v2;
            a.clear();
            a=QString::number(v3);
            ui->lineEdit->setText(a);
        }
        else if(b.at(1)=="*")
        {
           v3= v1*v2;
           a.clear();
           a=QString::number(v3);
           ui->lineEdit->setText(a);
        }
        else if(b.at(1)=="/")
        {
           v3= v1/v2;
           a.clear();
           a=QString::number(v3);
           ui->lineEdit->setText(a);
        }
       else if(b.at(1)=="%")
        {
           int u3=QString(b.at(0)).toInt() % QString(b.at(2)).toInt();
           a.clear();
           a=QString::number(u3);
           ui->lineEdit->setText(a);
        }
        b.clear();
        b.insert(0,a);

    }
    else
    {
        a.clear();
        b.clear();
    }
}






//退格键和清除键

void buttonWindow::on_pushButton_retreat_clicked()
{
    a.chop(1);
    ui->lineEdit->setText(a);
}

void buttonWindow::on_pushButton_clear_clicked()
{
    a.clear();
    b.clear();
    ui->lineEdit->setText(a);
}



//取倒数
void buttonWindow::on_pushButton_reciprocal_clicked()
{
    double w3=QString(a).toDouble();
    w3=1/w3;
    a=QString::number(w3);
    ui->lineEdit->setText(a);
    b.insert(0,a);
}
//平方
void buttonWindow::on_pushButton_square_clicked()
{
    double w3=QString(a).toDouble();
    w3=w3*w3;
    a=QString::number(w3);
    ui->lineEdit->setText(a);
    b.insert(0,a);
}

//开方
void buttonWindow::on_pushButton_rooting_clicked()
{
    if(a.contains("-"))
    {
        QDialog dialog;
        dialog.setWindowTitle(QObject::tr("ERRO"));
        dialog.resize(250,75);
        QLabel label(&dialog);
        QFont ft;
        ft.setPointSize(15);
        label.setFont(ft);
        label.setText(QObject::tr("被开方数不能为负数!!!"));
        dialog.exec();


    }
    else
    {
        double w3=QString(a).toDouble();
        w3=sqrt(w3);
        a=QString::number(w3);
        ui->lineEdit->setText(a);
        b.insert(0,a);
    }
}
//三角函数
void buttonWindow::on_pushButton_sin_clicked()
{
    double w3=QString(a).toDouble();
    w3=sin(w3);
    a=QString::number(w3);
    ui->lineEdit->setText(a);
    b.insert(0,a);
}

void buttonWindow::on_pushButton_cos_clicked()
{
    double w3=QString(a).toDouble();
    w3=cos(w3);
    a=QString::number(w3);
    ui->lineEdit->setText(a);
    b.insert(0,a);
}

void buttonWindow::on_pushButton_tan_clicked()
{
    double w3=QString(a).toDouble();
    w3=tan(w3);
    a=QString::number(w3);
    ui->lineEdit->setText(a);
    b.insert(0,a);
}





#include "mainwindow.h"
#include "ui_mainwindow.h"

double result = 0.0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btn_div->setCheckable(true);
    ui->btn_mult->setCheckable(true);
    ui->btn_minus->setCheckable(true);
    ui->btn_pl->setCheckable(true);
    connect(ui->btn0,SIGNAL(clicked()),this,SLOT(btn_slot()));
    connect(ui->btn1,SIGNAL(clicked()),this,SLOT(btn_slot()));
    connect(ui->btn2,SIGNAL(clicked()),this,SLOT(btn_slot()));
    connect(ui->btn3,SIGNAL(clicked()),this,SLOT(btn_slot()));
    connect(ui->btn4,SIGNAL(clicked()),this,SLOT(btn_slot()));
    connect(ui->btn5,SIGNAL(clicked()),this,SLOT(btn_slot()));
    connect(ui->btn6,SIGNAL(clicked()),this,SLOT(btn_slot()));
    connect(ui->btn7,SIGNAL(clicked()),this,SLOT(btn_slot()));
    connect(ui->btn8,SIGNAL(clicked()),this,SLOT(btn_slot()));
    connect(ui->btn9,SIGNAL(clicked()),this,SLOT(btn_slot()));
    connect(ui->btn_div,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->btn_mult,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->btn_pl,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->btn_minus,SIGNAL(clicked()),this,SLOT(operations()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btn_slot()
{
    QPushButton *btn = (QPushButton *)sender();
    QString res;
    double num = (ui->disp->text()+btn->text()).toDouble();
    res = QString :: number(num,'g',10);
    ui->disp->setText(res);
}

void MainWindow::on_btn_ac_clicked()
{
    ui->disp->clear();
    ui->disp->insert(ui->btn0->text());
    result=0;
}

void MainWindow::on_btn_com_clicked()
{
    if(!(ui->disp->text().contains('.'))){
        ui->disp->setText(ui->disp->text()+ '.');
    }
}

void MainWindow::on_btn_sign_clicked()
{
    QString res;
    double num = (ui->disp->text()).toDouble();
    res = QString :: number(num *(-1),'g',10);
    ui->disp->setText(res);
}

void MainWindow::on_btn_prc_clicked()
{
    QString res;
    double num = (ui->disp->text()).toDouble();
    res = QString :: number(num * 0.01,'g',10);
    ui->disp->setText(res);
}

void MainWindow::operations()
{
    if(ui->btn_div->isChecked()==0 || ui->btn_minus->isChecked()==0
            || ui->btn_mult->isChecked()==0 || ui->btn_pl->isChecked()==0)
    {
        on_btn_eql_clicked();
    }
    QPushButton *btn = (QPushButton *)sender();
    result =(ui->disp->text()).toDouble();
    btn->setChecked(true);
    ui->disp->clear();
}


void MainWindow::on_btn_eql_clicked()
{
    double num = (ui->disp->text()).toDouble();
    if(ui->btn_div->isChecked()){
        result= result/num;
        ui->btn_div->setChecked(false);
    }
    if(ui->btn_mult->isChecked()){
        result= result*num;
        ui->btn_mult->setChecked(false);
    }
    if(ui->btn_pl->isChecked()){
        result = result+num;
        ui->btn_pl->setChecked(false);
    }
    if(ui->btn_minus->isChecked()){
        result = result - num;
        ui->btn_minus->setChecked(false);
    }
    QString res = QString::number(result);
    ui->disp->setText(res);
}

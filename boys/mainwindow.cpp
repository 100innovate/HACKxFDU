﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QWidget>
#include<QGroupBox>

int MainWindow::getLocal()
{
    hub.run(1000 / 15);
    collector.print();
    return collector.loc();
}

void MainWindow::up()
{
    ui->label_2->setText(QString::number(getLocal()));
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    hub("com.example.hello-myo")
{
    ui->setupUi(this);
    ms.resize(3);
    this->resize(800,600);
    this->setMaximumSize(800,600);
    this->setMinimumSize(800,600);
    hub.addListener(&collector);
    this->setStyleSheet("background-image:url(:/index/index);");
    ui->pushButton->setGeometry(0,0,0,0);
    choice1=new QPushButton(this);
    choice2= new QPushButton(this);
    choice1->setGeometry(35,180,205,260);
    choice2->setGeometry(580,180,205,260);
    choice1->setStyleSheet("background: rgba(97%,80%,9%,0%)");
    choice2->setStyleSheet("background: rgba(97%,80%,9%,0%)");
    connect(choice1,&QPushButton::clicked,this,&MainWindow::playgame1);
    connect(choice2,&QPushButton::clicked,this,&MainWindow::playgame2);
    gameBackground=new QGroupBox(this);
    gameBackground->hide();

    restart=new QPushButton(this);
    restart->setGeometry(300,500,200,50);
    restart->setText("重新开始");
    restart->setStyleSheet("background:#acdcfc;color:#5aa6ea;");
    restart->hide();
    connect(restart,&QPushButton::clicked,this,&MainWindow::reGame);

    grade=new QLabel(this);
    grade->setGeometry(210,150,400,50);
    grade->hide();
    grade->setText("您的最终得分:");
    grade->setStyleSheet("font-size:35px;font-family:STHUPO;color:#000000;border:0px groove gray;background: rgba(97%,80%,9%,0%);");

    rank1=new QLabel(this);
    rank2=new QLabel(this);
    rank3=new QLabel(this);

    rank1->hide();
    rank2->hide();
    rank3->hide();

    rank1->setText("100");
    rank2->setText("200");
    rank3->setText("300");

    rank1->setStyleSheet("font-size:30px;font-family:STHUPO;color:#000000;border:0px groove gray;background: rgba(97%,80%,9%,0%);");
    rank2->setStyleSheet("font-size:30px;font-family:STHUPO;color:#000000;border:0px groove gray;background: rgba(97%,80%,9%,0%);");
    rank3->setStyleSheet("font-size:30px;font-family:STHUPO;color:#000000;border:0px groove gray;background: rgba(97%,80%,9%,0%);");

    rank1->setGeometry(320,250,400,30);
    rank2->setGeometry(320,290,400,30);
    rank3->setGeometry(320,330,400,30);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    thisgame.beginGame();
    while(1){
        int i=thisgame.run(getLocal());
        if(i!=-1)
            ui->label_2->setText(QString::number(i));
        else break;
        QApplication::processEvents();
    }
}

void MainWindow::playgame1()
{
    choice1->hide();
    choice2->hide();
    this->setStyleSheet("background:#7ac6fa;");
    gameBackground->show();
    gameBackground->setGeometry(150,50,500,500);
    gameBackground->setStyleSheet("background-image:url(:/index/245);border:0px;");

    thisgame.beginGame();
    int now(0);
    while(1){
        int i=thisgame.run(getLocal());
        if(i!=-1){
            if(i==1){
                now++;
                gameBackground->setStyleSheet("background-image:url(:/index/26);border:0px;");
            }
            else if(i==2){
                now++;
                gameBackground->setStyleSheet("background-image:url(:/index/235);border:0px;");
            }
            ui->label_2->setText(QString::number(now));
        }
        else break;
        QApplication::processEvents();
    }
    gameBackground->hide();
    this->setStyleSheet("background-image:url(:/index/rank);border:0px;");
    restart->show();

    grade->show();
    grade->setText("您的最终成绩:    "+QString::number(now));

    for(int i(0);i<3;i++){
        if(now>ms[i]){
            if(i==0){
                ms[2]=ms[1];
                ms[1]=ms[0];
            }
            if(i==1){
                ms[2]=ms[1];
            }
            ms[i]=now;
            break;
        }
    }

    rank1->setText("第一名:"+QString::number(ms[0]));
    rank2->setText("第二名:"+QString::number(ms[1]));
    rank3->setText("第三名:"+QString::number(ms[2]));

    rank1->show();
    rank2->show();
    rank3->show();
}

void MainWindow::playgame2()
{
    choice1->hide();
    choice2->hide();
    this->setStyleSheet("background:#7ac6fa;");
    gameBackground->show();
    gameBackground->setGeometry(150,50,500,500);
    gameBackground->setStyleSheet("background-image:url(:/index/135);border:0px;");

    thisgame.beginGame();
    int now(0);
    while(1){
        int i=thisgame.run(getLocal());
        if(i!=-1){
            if(i==1){
                now++;
                gameBackground->setStyleSheet("background-image:url(:/index/145);border:0px;");
            }
            else if(i==2){
                now++;
                gameBackground->setStyleSheet("background-image:url(:/index/125);border:0px;");
            }
            ui->label_2->setText(QString::number(now));
        }
        else break;
        QApplication::processEvents();
    }
    gameBackground->hide();
    this->setStyleSheet("background-image:url(:/index/rank);border:0px;");
    restart->show();

    grade->show();
    grade->setText("您的最终成绩:    "+QString::number(now));

    for(int i(0);i<3;i++){
        if(now>ms[i]){
            if(i==0){
                ms[2]=ms[1];
                ms[1]=ms[0];
            }
            if(i==1){
                ms[2]=ms[1];
            }
            ms[i]=now;
            break;
        }
    }

    rank1->setText("第一名:"+QString::number(ms[0]));
    rank2->setText("第二名:"+QString::number(ms[1]));
    rank3->setText("第三名:"+QString::number(ms[2]));

    rank1->show();
    rank2->show();
    rank3->show();

    QApplication::processEvents();
}

void MainWindow::reGame()
{
    this->setStyleSheet("background-image:url(:/index/index);");
    choice1->show();
    choice2->show();

    grade->hide();
    restart->hide();

    rank1->hide();
    rank2->hide();
    rank3->hide();

    ui->label_2->setText("0");
}

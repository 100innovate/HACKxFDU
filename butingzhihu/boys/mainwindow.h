﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"datacollector.h"
#include"game.h"
#include<QPushButton>
#include<QGroupBox>
#include<QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int getLocal();
    void up();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void playgame1();
    void playgame2();
    void reGame();

private:
    Ui::MainWindow *ui;
    myo::Hub hub;
    DataCollector collector;
    game thisgame;
    QPushButton *choice1;
    QPushButton *choice2;

    QPushButton *restart;

    QGroupBox *gameBackground;

    QLabel *grade;
};

#endif // MAINWINDOW_H

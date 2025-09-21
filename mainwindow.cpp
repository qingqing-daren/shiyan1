#include "mainwindow.h"
#include "ui_mainwindow.h"

//垂直布局
#include<QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置窗口标题
    setWindowTitle("五子棋");
    //设置窗口大小
    setFixedSize(1300,1000);
    //创建棋盘对象
    qipan1=new qipan(this);
    //设置布局
    QWidget *centerWidget =new QWidget(this);
    setCentralWidget(centerWidget);
    QVBoxLayout *layout =new QVBoxLayout(centerWidget);
    layout->addWidget(qipan1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


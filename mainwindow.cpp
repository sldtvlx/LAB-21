#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myglwidget.h"
#include <QPainter>
#include <QGridLayout>
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myGLWidget *openGLW=new myGLWidget(this);
    QGridLayout *grid=new QGridLayout();
    QPushButton *btn=new QPushButton();
    grid->addWidget(openGLW,0,0);
    grid->addWidget(btn,1,0);
    ui->centralwidget->setLayout(grid);
    connect(btn,&QPushButton::clicked,openGLW,&myGLWidget::redraw);
}
MainWindow::~MainWindow()
{
    delete ui;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1350,800);
    mapView = new MyGraphicView(this);
    ui->map_layout->addWidget(mapView);
//    ui->centralwidget->addWidget(mapView);
    mm = A_Map(std::string("C:/Users/Artem/Documents/test/map_1.json"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


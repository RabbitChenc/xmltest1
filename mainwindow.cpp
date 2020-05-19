#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "./Proj/hfbutton_facade_attrs.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    HFButtonFacadeAttrs * fbtn = new HFButtonFacadeAttrs;
}

MainWindow::~MainWindow()
{
    delete ui;
}


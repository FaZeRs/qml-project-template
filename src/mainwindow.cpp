#include "mainwindow.h"

#include <QDebug>

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  qDebug() << "Hello World!";
}

MainWindow::~MainWindow() { delete ui; }

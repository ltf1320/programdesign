#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(800,600);
    imageWidget=new ImageWidget(this);
    imageWidget->setFocus();
    setCentralWidget(imageWidget);
    initConnections();
    imageWidget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initConnections()
{
  //  connect(choseAndMove,SIGNAL(tr))
 //   connect(save,SIGNAL(trigged()),imageWidget,SLOT(save()));
}

void MainWindow::on_choseAndMove_triggered()
{
    imageWidget->changeState(ImageWidget::St_ChoseAndMove);
}

void MainWindow::on_drawLine_triggered()
{
    imageWidget->changeState(ImageWidget::St_DrawLine);
}


void MainWindow::on_drawRec_triggered()
{
    imageWidget->changeState(ImageWidget::St_DrawRec);
}

void MainWindow::on_drawEllipse_triggered()
{
    imageWidget->changeState(ImageWidget::St_DrawEllipse);
}


void MainWindow::on_combine_triggered()
{
    imageWidget->combine();
}

void MainWindow::on_split_triggered()
{
    imageWidget->split();
}

void MainWindow::on_save_triggered()
{
    imageWidget->save();
}

void MainWindow::on_open_triggered()
{
    imageWidget->read();
}

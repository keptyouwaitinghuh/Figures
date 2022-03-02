#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Circle.h"
#include "Rhomb.h"
#include "RightPol.h"
#include "Star.h"
#include "Rect.h"
#include "Square.h"
#include <QGraphicsSceneMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(ui->graphicView);
    scene->setSceneRect(0,0,780,580);
    ui->graphicView->setScene(scene);
    currentItem=nullptr;

    ui->horizontalSlider->setMaximum(180);
    ui->horizontalSlider->setMinimum(-180);
    ui->horizontalSlider->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void QGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   addRect(10,20,800,400);
}

void QGraphicsScene:: keyPressEvent(QKeyEvent *keyEvent)
{
    addRect(30,30,30,30);
}

void MainWindow::on_radioEllipse_clicked(bool checked)
{
        if(currentItem!=nullptr)
        {
            scene->removeItem(currentItem);
            delete currentItem;
        }
        currentItem = new Circle(100);
        currentItem->setRotation(ui->horizontalSlider->value());
        scene->addItem(currentItem);
}


void MainWindow::on_radioTriangle_clicked(bool checked)
{
    if(currentItem!=nullptr)
    {
        scene->removeItem(currentItem);
        delete currentItem;
    }
        currentItem = new RightPol(3);
        currentItem->setRotation(ui->horizontalSlider->value());
        scene->addItem(currentItem);
}


void MainWindow::on_radioStar6_clicked(bool checked)
{

    if(currentItem!=nullptr)
    {
        scene->removeItem(currentItem);
        delete currentItem;
    }
        currentItem = new Star(6);
        currentItem->setRotation(ui->horizontalSlider->value());
        scene->addItem(currentItem);

}


void MainWindow::on_radioStar8_clicked(bool checked)
{


    if(currentItem!=nullptr)
    {
        scene->removeItem(currentItem);
        delete currentItem;
    }
        currentItem = new Star(8);
        currentItem->setRotation(ui->horizontalSlider->value());
        scene->addItem(currentItem);


}


void MainWindow::on_radioStar5_clicked(bool checked)
{

    if(currentItem!=nullptr)
    {
        scene->removeItem(currentItem);
        delete currentItem;
    }
        currentItem = new Star(5);
        currentItem->setRotation(ui->horizontalSlider->value());
        scene->addItem(currentItem);

}


void MainWindow::on_radioRect_clicked(bool checked)
{

    if(currentItem!=nullptr)
    {
        scene->removeItem(currentItem);
        delete currentItem;
    }
        currentItem = new Rect(400,300);
        currentItem->setRotation(ui->horizontalSlider->value());
        scene->addItem(currentItem);

}


void MainWindow::on_radioSquare_clicked(bool checked)
{
    if(currentItem!=nullptr)
    {
        scene->removeItem(currentItem);
        delete currentItem;
    }
        currentItem = new Square(350);
        currentItem->setRotation(ui->horizontalSlider->value());
        scene->addItem(currentItem);


}


void MainWindow::on_radioRhomb_clicked(bool checked)
{

        if(currentItem!=nullptr)
        {
            scene->removeItem(currentItem);
            delete currentItem;
        }
        currentItem = new Rhomb(200,400);
        currentItem->setRotation(ui->horizontalSlider->value());
        scene->addItem(currentItem);
}


void MainWindow::on_radioHex_clicked(bool checked)
{

        if(currentItem!=nullptr)
        {
            scene->removeItem(currentItem);
            delete currentItem;
        }
        currentItem = new RightPol(6);
        currentItem->setRotation(ui->horizontalSlider->value());
        scene->addItem(currentItem);
}



void MainWindow::on_pushUp_pressed()
{
     currentItem->moveBy(0, -10);
}


void MainWindow::on_pushLeft_pressed()
{
        currentItem->moveBy(-10, 0);
}


void MainWindow::on_pushRight_pressed()
{
        currentItem->moveBy(10, 0);
}


void MainWindow::on_pushDown_pressed()
{

        currentItem->moveBy(0, 10);

}


void MainWindow::on_pushScale_clicked()
{
    qreal scale = ui->lineScale->text().toDouble();
    currentItem->setScale(scale);
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    if(currentItem!=nullptr)
    {
        QPointF origin(ui->lineX->text().toDouble(), ui->lineY->text().toDouble());
        currentItem->setTransformOriginPoint(origin);
         currentItem->setRotation(value);
    }
}


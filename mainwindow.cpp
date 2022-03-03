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

    scene = new BetterScene(ui->graphicView);
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

BetterScene::BetterScene(QObject *parent): QGraphicsScene(parent), canva(0), figure(new QGraphicsItemGroup)
{

}


void BetterScene::setFigure(QGraphicsItemGroup *newFigure)
{
    figure = newFigure;
}

void BetterScene::clearPoints()  { points.clear(); }

QGraphicsItemGroup *BetterScene::getFigure() { return figure; }

void BetterScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(canva)
    {
        points.append(event->scenePos());
        int d=points.length();
        if(points.length()>1) figure->addToGroup(new QGraphicsLineItem(points[d-1].x(),points[d-1].y()
                ,points[d-2].x(),points[d-2].y()));
    }
    else
    {
        if( !(items().isEmpty()) )items().first()->setTransformOriginPoint(event->scenePos());
    }
}

void BetterScene::keyPressEvent(QKeyEvent *event)
{
    canva=0;
    figure->addToGroup(new QGraphicsLineItem(points[points.length()-1].x(),points[points.length()-1].y(),
            points[0].x(),points[0].y()));
    clearPoints();

}


void MainWindow::on_radioEllipse_clicked()
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


void MainWindow::on_radioTriangle_clicked()
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





void MainWindow::on_radioRect_clicked()
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


void MainWindow::on_radioSquare_clicked()
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


void MainWindow::on_radioRhomb_clicked()
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


void MainWindow::on_radioPolygon_clicked()
{
    int n = ui->linePolygon->text().toInt();
    if (n >= 2)
    {
        if(currentItem!=nullptr)
        {
            scene->removeItem(currentItem);
            delete currentItem;
        }
        currentItem = new RightPol(n);
        currentItem->setRotation(ui->horizontalSlider->value());
        scene->addItem(currentItem);
    }
}



void MainWindow::on_pushUp_pressed()
{
     currentItem->moveBy(0, -10);
     massCent = QPointF(massCent.x(), massCent.y() - 10);
     QString massCenter = "(" + QString::number(massCent.x()) + ";" +
             QString::number(massCent.y()) + ")";
     ui->labelMassCenter->setText(massCenter);
}


void MainWindow::on_pushLeft_pressed()
{
        currentItem->moveBy(-10, 0);
        massCent = QPointF(massCent.x() - 10, massCent.y());
        QString massCenter = "(" + QString::number(massCent.x()) + ";" +
                QString::number(massCent.y()) + ")";
        ui->labelMassCenter->setText(massCenter);
}


void MainWindow::on_pushRight_pressed()
{
        currentItem->moveBy(10, 0);
        massCent = QPointF(massCent.x() + 10, massCent.y());
        QString massCenter = "(" + QString::number(massCent.x()) + ";" +
                QString::number(massCent.y()) + ")";
        ui->labelMassCenter->setText(massCenter);
}


void MainWindow::on_pushDown_pressed()
{
        currentItem->moveBy(0, 10);
        massCent = QPointF(massCent.x(), massCent.y() + 10);
        QString massCenter = "(" + QString::number(massCent.x()) + ";" +
                QString::number(massCent.y()) + ")";
        ui->labelMassCenter->setText(massCenter);
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
        if (ui->lineX->text().toInt() != 0 && ui->lineY->text().toInt() != 0){
        QPointF origin(ui->lineX->text().toInt(), ui->lineY->text().toInt());
        currentItem->setTransformOriginPoint(origin);}
        currentItem->setRotation(value);
    }
}


void MainWindow::on_radioStar_clicked()
{
    int n = ui->lineStar->text().toInt();
    if (n >= 5)
    {
        if(currentItem!=nullptr)
        {
            scene->removeItem(currentItem);
            delete currentItem;
        }
            currentItem = new Star(n);
            Star* star = new Star(n);
            star->findSquare();
            QString square = QString::number(star->getSquare());
            ui->labelSquare->setText(square);
            star->findPerimeter();
            QString perimeter = QString::number(star->getPerimeter());
            ui->labelPerimeter->setText(perimeter);
            QString massCenter = "(" + QString::number(star->getMassCenter().x()) + ";" +
                    QString::number(star->getMassCenter().y()) + ")";
            massCent = star->getMassCenter();
            ui->labelMassCenter->setText(massCenter);
            currentItem->setRotation(ui->horizontalSlider->value());
            scene->addItem(currentItem);
    }
}


void MainWindow::on_radioCanva_clicked(bool checked)
{
    if(currentItem != nullptr )
    {
        scene->removeItem(currentItem);
        delete currentItem;
    }

    scene->setFigure(new QGraphicsItemGroup());
    currentItem=scene->getFigure();
    scene->addItem(currentItem);

    scene->changeCanva(1);
}


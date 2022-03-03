#pragma once

#include <QMainWindow>
#include <QMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class BetterScene: public QGraphicsScene
{
    bool canva;
    QVector<QPointF> points;
    QGraphicsItemGroup *figure;


public:
    void clearPoints();

    void changeCanva(bool value){ canva = value; };

    BetterScene(QObject *parent=0);

    QGraphicsItemGroup *getFigure() ;


    void setFigure(QGraphicsItemGroup *newFigure);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
};






class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QGraphicsScene* getScene() { return scene; }

    void rotateItem(int angle);
private slots:

    void on_radioEllipse_clicked();

    void on_radioTriangle_clicked();

    void on_radioRect_clicked();

    void on_radioSquare_clicked();

    void on_radioRhomb_clicked();

    void on_radioPolygon_clicked();

    void on_pushUp_pressed();

    void on_pushLeft_pressed();

    void on_pushRight_pressed();

    void on_pushDown_pressed();

    void on_pushScale_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_radioStar_clicked();

    void on_radioCanva_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    BetterScene *scene;
    QGraphicsItem *currentItem;
    QPointF massCent;
};

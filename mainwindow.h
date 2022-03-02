#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QGraphicsScene* getScene() { return scene; }

    void rotateItem(int angle);
private slots:

    void on_radioEllipse_clicked(bool checked);

    void on_radioTriangle_clicked(bool checked);

    void on_radioStar6_clicked(bool checked);

    void on_radioStar8_clicked(bool checked);

    void on_radioStar5_clicked(bool checked);

    void on_radioRect_clicked(bool checked);

    void on_radioSquare_clicked(bool checked);

    void on_radioRhomb_clicked(bool checked);

    void on_radioHex_clicked(bool checked);

    void on_pushUp_pressed();

    void on_pushLeft_pressed();

    void on_pushRight_pressed();

    void on_pushDown_pressed();

    void on_pushScale_clicked();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsItem *currentItem;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_go_to_basket_clicked();

    void on_back_button_clicked();

    void on_pay_button_clicked();

    void on_aproove_button_clicked();

    void on_again_button_clicked();

    void on_add_cola_clicked();

    void on_add_pepsi_clicked();

    void on_add_sprite_clicked();

    void on_add_ice_tea_clicked();

    void on_add_americano_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <vector>
#include <string>
#include <QString>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


struct itemPrice
{
    std::string itemName;
    int itemPrice;
};

std::vector<itemPrice> v;
int total = 0;


void MainWindow::on_go_to_basket_clicked()
{
    std::string str;

    ui->stackedWidget->setCurrentIndex(2);

    for(int i = 0 ; i < v.size() ; i++){
        str = v[i].itemName + "\t\t" + std::to_string(v[i].itemPrice);
        ui->bascet_list->addItem(str.c_str());
        total += v[i].itemPrice;
    }
    str = std::to_string(total);
    ui->total_price->setText(str.c_str());

}


void MainWindow::on_back_button_clicked()
{
    v.clear();
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pay_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    std::string str;
    str = std::to_string(total);
    ui->pay_total_price->setText(str.c_str());
}




struct customerInfo{
    int receiptNum;
    QString customerName , cardNum;
};

void MainWindow::on_aproove_button_clicked()
{
    std::ofstream outputFile;
    ui->stackedWidget->setCurrentIndex(3);

    customerInfo ci;
    ci.receiptNum = rand()%(1000 - 1 + 1) + 1;
    ci.customerName = ui->text_name->toPlainText();
    ci.cardNum = ui->text_card_num->toPlainText();

    outputFile.open("Customer info.txt" , std::ios::app);
    if(outputFile){
        outputFile <<"çek nömrəsi " << ci.receiptNum << "\n";
        outputFile <<"müştəri adı " << ci.customerName.toStdString() << "\n";
        outputFile <<"müştəri kart nömrəsi" << ci.cardNum.toStdString() << "\n";
        outputFile <<"----------alınan mehsullar---------" << "\n";
        outputFile <<"məhsul------------------qiymət" << "\n";
        for(int i = 0; i < v.size() ; i++ ){
            outputFile <<v[i].itemName <<"\t\t";
            outputFile <<v[i].itemPrice << "\n";
        }
        outputFile <<"CƏM" << "\t\t" << total<< "\n";
        outputFile <<"---------çek sonu---------" << "\n\n\n\n\n\n";
    }
}


void MainWindow::on_again_button_clicked()
{
    ui->bascet_list->clear();
    v.clear();
    total = 0;
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_add_cola_clicked()
{
    itemPrice item;
    item.itemName = "coca-cola";
    item.itemPrice = 8;

    v.push_back(item);

    ui->empty->setText(v[0].itemName.c_str());
}


void MainWindow::on_add_pepsi_clicked()
{
    itemPrice item;
    item.itemName = "pepsi";
    item.itemPrice = 6;
    v.push_back(item);
    ui->empty->setText(v[0].itemName.c_str());
}


void MainWindow::on_add_sprite_clicked()
{
    itemPrice item;
    item.itemName = "sprite";
    item.itemPrice = 5;
    v.push_back(item);

    ui->empty->setText(v[0].itemName.c_str());

}


void MainWindow::on_add_ice_tea_clicked()
{
    itemPrice item;
    item.itemName = "ice tea";
    item.itemPrice = 2;

    v.push_back(item);

    ui->empty->setText(v[0].itemName.c_str());
}


void MainWindow::on_add_americano_clicked()
{
    itemPrice item;
    item.itemName = "americano";
    item.itemPrice = 9;
    v.push_back(item);

    ui->empty->setText(v[0].itemName.c_str());
}


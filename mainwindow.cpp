#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText("");

    connect(this, SIGNAL(sig_show_img()), this, SLOT(show_img()));
}

void MainWindow::show_img()
{
    // qDebug() << "show_img";
    if (_img.isNull())
    {
        QMessageBox::warning(this, "warning", "Plense input image!");
        return;
    }
//    ui->label->setPixmap(_img);
    QPixmap dest = _img.scaled(ui->label->size(), Qt::KeepAspectRatio);
    ui->label->setPixmap(dest);

    ui->label->show();
    return;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_file_clicked()
{
    QString file_path = QFileDialog::getOpenFileName(
        this,
        tr("select a file."),
        ".",// D:/
        tr("images(*.png *jpeg *bmp *jpg);;All files(*.*)"));
    if (file_path.isEmpty())
    {
        QMessageBox::warning(this, "Warning!", "Failed to select the image!");
        return;
    }
    _img_path = file_path;
    bool status = _img.load(_img_path);
    if (!status)
    {
        QMessageBox::warning(this, "Error!", "Failed to load the image!");
        return;
    }
    emit sig_show_img();
}

void MainWindow::on_pushButton_copy_clicked()
{
}

void MainWindow::on_pushButton_screen_clicked()
{
}

void MainWindow::on_pushButton_ocr_clicked()
{

}

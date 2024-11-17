#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QPixmap>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

// 自定义信号
signals:
    // 信号没有返回值，可以有参数,信号函数不需要定义，只需要声明
    void sig_show_img();

// 自定义槽函数
public slots:
    void show_img();

private slots:
    void on_pushButton_file_clicked();

    void on_pushButton_copy_clicked();

    void on_pushButton_screen_clicked();

    void on_pushButton_ocr_clicked();

private:
    Ui::MainWindow *ui;
    QString _img_path;
    QPixmap _img;
};
#endif // MAINWINDOW_H

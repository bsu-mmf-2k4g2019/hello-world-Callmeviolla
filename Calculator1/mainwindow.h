#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void btn_slot();

private slots:
    void on_btn_ac_clicked();

    void on_btn_com_clicked();

    void on_btn_sign_clicked();

    void on_btn_prc_clicked();

    void operations();

    void on_btn_eql_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

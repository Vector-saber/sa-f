#ifndef BUTTONWINDOW_H
#define BUTTONWINDOW_H
#include <QMainWindow>
#include<QDialog>
#include<QLabel>
#include<QtMath>
#include<QKeyEvent>
namespace Ui {
class buttonWindow;
}

class buttonWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit buttonWindow(QWidget *parent = 0);
    ~buttonWindow();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_plug_clicked();

    void on_pushButton_result_clicked();

    void on_pushButton_zero_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_minus_clicked();

    void on_pushButton_multiply_clicked();

    void on_pushButton_divide_clicked();


    void on_pushButton_retreat_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_mode_clicked();

    void on_pushButton_point_clicked();

    void on_pushButton_reciprocal_clicked();

    void on_pushButton_square_clicked();


    void on_pushButton_rooting_clicked();

    void on_pushButton_sin_clicked();

    void on_pushButton_cos_clicked();

    void on_pushButton_tan_clicked();


    void on_pushButton_PI_clicked();
    void keyPressEvent(QKeyEvent *e);

private:
    Ui::buttonWindow *ui;

    QString a;
    QStringList b;
    double v1,v2,v3;
    int flag_v1,flag_v2;


};

#endif // BUTTONWINDOW_H

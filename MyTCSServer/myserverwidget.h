#ifndef MYSERVERWIDGET_H
#define MYSERVERWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class MyServerWidget;
}
QT_END_NAMESPACE

class MyServerWidget : public QWidget
{
    Q_OBJECT

public:
    MyServerWidget(QWidget *parent = nullptr);
    ~MyServerWidget();

private slots:
    void on_pb_start_clicked();

    void on_pb_close_clicked();

    void connectionRecieved();

    void readData();

    void on_lineEdit_returnPressed();

private:
    Ui::MyServerWidget *ui;

    QTcpServer *m_server;
    QTcpSocket *m_cliSocket;
};
#endif // MYSERVERWIDGET_H

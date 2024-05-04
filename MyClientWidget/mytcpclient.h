#ifndef MYTCPCLIENT_H
#define MYTCPCLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MyTcpClient;
}
QT_END_NAMESPACE

class MyTcpClient : public QWidget
{
    Q_OBJECT

public:
    MyTcpClient(QWidget *parent = nullptr);
    ~MyTcpClient();

private slots:
    void on_lineEdit_returnPressed();

    void on_pb_connect_clicked();

    void on_pb_send_clicked();

    void on_pb_clear_clicked();

    void readData();

private:
    Ui::MyTcpClient *ui;
    QTcpSocket *m_clientSocket;
};
#endif // MYTCPCLIENT_H

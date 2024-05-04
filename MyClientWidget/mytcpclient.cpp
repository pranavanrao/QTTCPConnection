#include "mytcpclient.h"
#include "ui_mytcpclient.h"

MyTcpClient::MyTcpClient(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyTcpClient)
{
    ui->setupUi(this);
    m_clientSocket = new QTcpSocket;
    connect(m_clientSocket,
            SIGNAL(readyRead()),
            this,
            SLOT(readData()));
}

MyTcpClient::~MyTcpClient()
{
    delete ui;
}

void MyTcpClient::on_lineEdit_returnPressed()
{
    QString data = ui->lineEdit->text();
    qDebug() << Q_FUNC_INFO << data << Qt::endl;
    m_clientSocket->write(data.toStdString().c_str());
}


void MyTcpClient::on_pb_connect_clicked()
{
    m_clientSocket->connectToHost("localhost",8001);
}


void MyTcpClient::on_pb_send_clicked()
{

}

void MyTcpClient::on_pb_clear_clicked()
{

}

void MyTcpClient::readData()
{
    qDebug() << "Reading Data" << Qt::endl;
    QString data = m_clientSocket->readAll();
    ui->textEdit->setPlainText(data);
}


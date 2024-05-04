#include "myserverwidget.h"
#include "ui_myserverwidget.h"

#include <QDebug>

MyServerWidget::MyServerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyServerWidget)
{
    ui->setupUi(this);
    qDebug() << Q_FUNC_INFO << Qt::endl;
    m_server = new QTcpServer;
    connect(m_server,
            &QTcpServer::newConnection,
            this,
            &MyServerWidget::connectionRecieved);
}

MyServerWidget::~MyServerWidget()
{
    delete ui;
}

void MyServerWidget::on_pb_start_clicked()
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
    m_server->listen(QHostAddress::Any, 8001);
}

void MyServerWidget::on_pb_close_clicked()
{
    qDebug() << Q_FUNC_INFO << Qt::endl;
}

void MyServerWidget::connectionRecieved()
{
    qDebug() << "New connection arrived" << Qt::endl;
    this->m_cliSocket = m_server->nextPendingConnection();
    connect(m_cliSocket,
            SIGNAL(readyRead()),
            this,
            SLOT(readData()));
}

void MyServerWidget::readData()
{
    qDebug() << "Reading the data" << Qt::endl;
    QString data = m_cliSocket->readAll();
    ui->textEdit->setPlainText(data);
}


void MyServerWidget::on_lineEdit_returnPressed()
{
    const char* data = this->ui->lineEdit->text().toStdString().c_str();
    m_cliSocket->write(data);
}


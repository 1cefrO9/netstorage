#include "tcpclient.h"

#include <QByteArray>
#include <QDebug>
#include <QHostAddress>
#include <QMessageBox>

#include "ui_tcpclient.h"

TcpClient::TcpClient(QWidget *parent) : QWidget(parent), ui(new Ui::TcpClient) {
  ui->setupUi(this);
  loadConfig();
  connect(&m_tcpSocket, SIGNAL(connected()), this, SLOT(showConnect()));
  // 连接服务器
  m_tcpSocket.connectToHost(QHostAddress(m_strIP), m_usPort);
}

TcpClient::~TcpClient() { delete ui; }

void TcpClient::loadConfig() {
  QFile file(":/clinet.config");
  if (file.open(QIODevice::ReadOnly)) {
    QByteArray baData = file.readAll();
    QString strData = baData.toStdString().c_str();
    strData.replace("\r\n", " ");
    QStringList strList = strData.split(" ");
    m_strIP = strList.at(0);
    m_usPort = strList.at(1).toUShort();
    qDebug() << "IP地址为：" << m_strIP << "端口为：" << m_usPort;
    file.close();
  } else {
    QMessageBox::critical(this, "open config", "open config failed");
  }
}

// 获取和服务器连接结果
void TcpClient::showConnect() {
  QMessageBox::information(this, "连接服务器", "连接服务器成功");
}

// void TcpClient::on_send_pd_clicked() {
//   QString strMsg = ui->lineEdit->text();
//   strMsg = "hello world";
//   qDebug() << strMsg;
//   if (!strMsg.isEmpty()) {
//     PDU *pdu = mkPDU(strMsg.size());
//     pdu->uiMsgType = 8888;
//     memcpy(pdu->caMsg, strMsg.toStdString().c_str(), strMsg.size());
//     m_tcpSocket.write((char *)pdu, pdu->uiPDULen);
//     free(pdu);
//     pdu = NULL;
//   } else {
//     QMessageBox::warning(this, "信息发送", "发送的信息不能为空");
//   }
// }
void TcpClient::on_send_pd_clicked() {
  QString strMsg = ui->lineEdit->text();
  // strMsg = "hello world";  // 测试用固定字符串，实际可删除此行
  qDebug() << "准备发送消息：" << strMsg;

  if (!strMsg.isEmpty()) {
    // 1. 创建协议数据单元
    PDU *pdu = mkPDU(strMsg.size());
    pdu->uiMsgType = 8888;

    // 2. 安全拷贝字符串（确保 caMsg 是 char[]）
    memcpy(pdu->caMsg, strMsg.toStdString().c_str(), strMsg.size());

    // 3. 发送数据并检查结果
    qint64 bytesWritten = m_tcpSocket.write((char *)pdu, pdu->uiPDULen);
    if (bytesWritten == -1) {
      qDebug() << "发送失败：" << m_tcpSocket.errorString();
    } else {
      qDebug() << "发送成功，字节数：" << bytesWritten;
      m_tcpSocket.flush();  // 立即发送缓冲区数据
    }

    // 4. 释放内存（确保数据已写入缓冲区后再释放）
    free(pdu);
  } else {
    QMessageBox::warning(this, "信息发送", "发送的信息不能为空");
  }
}

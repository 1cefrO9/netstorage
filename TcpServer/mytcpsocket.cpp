#include <QDebug>

#include "mytcpsocket.h"

MyTcpSocket::MyTcpSocket() {
  connect(this, SIGNAL(readyRead()), this, SLOT(recvMsg()));
}

// 接收来自客户端的消息
void MyTcpSocket::recvMsg() {
  qDebug() << this->bytesAvailable();
  uint uiPDULen = 0;
  this->read((char *)&uiPDULen, sizeof(uint));
  uint uiMsgLen = uiPDULen - sizeof(PDU);
  PDU *pdu = mkPDU(uiMsgLen);
  this->read((char *)pdu + sizeof(uint), uiPDULen - sizeof(uint));
  qDebug() << pdu->uiMsgType << pdu->caMsg;
}

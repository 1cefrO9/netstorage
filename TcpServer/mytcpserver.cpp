#include "mytcpserver.h"

#include <QDebug>

MyTcpServer::MyTcpServer() {}

MyTcpServer &MyTcpServer::getInstance() {
  static MyTcpServer instance;
  return instance;
}

void MyTcpServer::incomingConnection(qintptr handle) {
  // 派生QTcpSocket，然后对Socket进行绑定相应的槽函数，这样就可以不同客户端由不同MyTcpSocket进行处理
  // 从而可以实现客户端连接和对应数据收发的socket的关联
  qDebug() << "new client connected";
  MyTcpSocket *pTcpSocket = new MyTcpSocket;  // 建立新的socket连接
  pTcpSocket->setSocketDescriptor(
      handle);  // 设置其Socket描述符，不同描述符指示不同客户端
  m_tcpSocketList.append(pTcpSocket);
  connect(pTcpSocket, SIGNAL(offline(MyTcpSocket *)), this,
          SLOT(deleteSocket(MyTcpSocket *)));
}

void MyTcpServer::resend(const char *pername, PDU *pdu) {
  if (NULL == pername || NULL == pdu) {
    return;
  }
  QString strName = pername;
  for (int i = 0; i < m_tcpSocketList.size(); i++) {
    if (strName == m_tcpSocketList.at(i)->getName()) {
      m_tcpSocketList.at(i)->write((char *)pdu, pdu->uiPDULen);
      break;
    }
  }
}

void MyTcpServer::deleteSocket(MyTcpSocket *mysocket) {
  QList<MyTcpSocket *>::iterator iter = m_tcpSocketList.begin();
  for (; iter != m_tcpSocketList.end(); iter++) {
    if (mysocket == *iter)  // 异常原因发生在这里！！！
    {
      // error
      // delete *iter;  // 释放空间
      (*iter)->deleteLater();  // 延迟释放空间
      *iter = NULL;
      // error end
      m_tcpSocketList.erase(iter);  // 删除列表中指针
      break;
    }
  }
}

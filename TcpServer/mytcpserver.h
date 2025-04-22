#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QList>
#include <QTcpServer>

#include "mytcpsocket.h"

class MyTcpServer : public QTcpServer {
  Q_OBJECT
 public:
  MyTcpServer();
  static MyTcpServer &getInstance();  // 实现单例模式获取静态对象的引用
  void incomingConnection(
      qintptr handle) override;  // 判断何时有客户端接入并处理

 private:
  QList<MyTcpSocket *> m_tcpSocketList;  // 存储服务器所有已经建立的Socket连接

 public slots:
  void deleteSocket(MyTcpSocket *mysocket);
};

#endif  // MYTCPSERVER_H

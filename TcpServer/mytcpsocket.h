#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H
#include <QTcpSocket>

#include "opedb.h"
#include "protocol.h"

class MyTcpSocket : public QTcpSocket {
  Q_OBJECT

 public:
  MyTcpSocket();
 public slots:
  void recvMsg();  // 槽函数，按照协议形式处理传输过来的数据
  void clientOffline();
  QString getName();

 private:
  QString m_strName;
 signals:
  void offline(MyTcpSocket *mysocket);
};

#endif  // MYTCPSOCKET_H

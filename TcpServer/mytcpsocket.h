#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H
#include <QDir>
#include <QFile>
#include <QFileInfoList>
#include <QTcpSocket>
#include <QTimer>

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
  void sendFileToClient();
  void copyDir(QString strSrcDir, QString strDestDir);

 private:
  QString m_strName;

  QFile m_file;
  qint64 m_iTotal;
  qint64 m_iRecved;
  bool m_bUpload;
  QTimer *m_pTimer;
 signals:
  void offline(MyTcpSocket *mysocket);
};

#endif  // MYTCPSOCKET_H

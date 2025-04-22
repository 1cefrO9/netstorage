#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QFile>
#include <QTcpSocket>
#include <QWidget>

#include "operatewidget.h"
#include "protocol.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class TcpClient;
}
QT_END_NAMESPACE

class TcpClient : public QWidget {
  Q_OBJECT

 public:
  TcpClient(QWidget *parent = nullptr);
  ~TcpClient();
  void loadConfig();
  static TcpClient &getInstance();
  QTcpSocket &getTcpSocket();

 public slots:
  void showConnect();
  void receiveMsg();

 private slots:
  // void on_send_pd_clicked();

  void on_login_pb_clicked();

  void on_regist_pb_clicked();

  void on_cancel_pb_clicked();

 private:
  Ui::TcpClient *ui;
  QString m_strIP;
  quint16 m_usPort;
  // 连接服务器 和服务器进行数据交互
  QTcpSocket m_tcpSocket;
};
#endif  // TCPCLIENT_H

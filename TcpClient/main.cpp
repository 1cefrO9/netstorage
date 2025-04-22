#include <QApplication>

#include "friend.h"
#include "online.h"
#include "operatewidget.h"
#include "tcpclient.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  // TcpClient w;
  // w.show();
  // Friend w;
  // Online w;
  // OperateWidget w;
  TcpClient::getInstance().show();
  // w.show();
  return a.exec();
}

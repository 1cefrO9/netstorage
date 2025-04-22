#include <QApplication>

#include "OpeDB.h"
#include "tcpserver.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  OpeDB::getInstance().init();
  TcpServer w;
  w.show();
  return a.exec();
}

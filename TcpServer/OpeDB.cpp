#include "opedb.h"

#include <QDebug>
#include <QMessageBox>

OpeDB::OpeDB(QObject *parent) : QObject(parent) {
  m_db = QSqlDatabase::addDatabase("QSQLITE");
}

// 生成实例
OpeDB &OpeDB::getInstance() {
  static OpeDB instance;
  return instance;
}

// 数据库连接初始化
void OpeDB::init() {
  m_db.setHostName("localhost");
  // 不同的数据库存放的位置，要更改为对应的位置
  m_db.setDatabaseName("J:\\cloudsotrage\\TcpServer\\cloud.db");
  if (m_db.open()) {
    QSqlQuery query;
    query.exec("select * from userInfo");
    while (query.next()) {
      QString data = QString("%1,%2,%3")
                         .arg(query.value(0).toString())
                         .arg(query.value(1).toString())
                         .arg(query.value(2).toString());
      qDebug() << data;
    }
  } else {
    QMessageBox::critical(NULL, "打开数据库", "打开数据库失败");
  }
}

// 析构函数用来关闭数据库连接
OpeDB::~OpeDB() { m_db.close(); }

// 处理客户端的用户注册信息
bool OpeDB::handleRegist(const char *name, const char *pwd) {
  if (NULL == name || NULL == pwd) {
    return false;
  }
  QString data = QString("insert into userInfo(name,pwd) values(\'%1\',\'%2\')")
                     .arg(name)
                     .arg(pwd);
  QSqlQuery query;
  return query.exec(data);
}

bool OpeDB::handleLogin(const char *name, const char *pwd) {
  // 考虑极端情况
  if (NULL == name || NULL == pwd) {
    return false;
  }
  // 数据库查询
  QString strQuery =
      QString(
          "select * from userInfo where name = \'%1\' and pwd = \'%2\' "
          "and online = 0")
          .arg(name)
          .arg(pwd);  // online = 0 可以判定用户是否未登录，不允许重复登陆
  QSqlQuery query;

  qDebug() << strQuery;
  query.exec(strQuery);

  if (query
          .next())  // 每次调用next都会读取一条数据，并将结果放入query中，返回值为true，无数据则返回false
  {
    // 如果登录成功，需要设置online = 1，并返回true
    strQuery = QString(
                   "update userInfo set online = 1 where name = \'%1\' and pwd "
                   "= \'%2\' ")
                   .arg(name)
                   .arg(pwd);
    return query.exec(strQuery);
  } else {
    return false;
  }
}

void OpeDB::handleOffline(const char *name) {
  if (NULL == name) {
    return;
  }
  QString data =
      QString("update userInfo set online = 0 where name = \'%1\'").arg(name);
  QSqlQuery query;
  query.exec(data);
}

QStringList OpeDB::handleAllOnline() {
  QString data = QString("select name from userInfo where online = 1");
  QSqlQuery query;
  qDebug() << data;
  query.exec(data);
  QStringList result;
  result.clear();
  while (query.next()) {
    result.append(query.value(0).toString());
  }
  return result;
}

int OpeDB::handleSearchUsr(const char *name) {
  if (NULL == name) {
    return -1;
  }
  QString data =
      QString("select online from userInfo where name = \'%1\'").arg(name);
  QSqlQuery query;
  query.exec(data);
  if (query.next()) {
    int res = query.value(0).toInt();
    if (1 == res) {
      return 1;
    } else if (0 == res) {
      return 0;
    }
  } else {
    return -1;
  }
}

int OpeDB::handleAddFriend(const char *pername, const char *name) {
  if (NULL == pername || NULL == name) {
    return -1;
  }
  QString data =
      QString(
          "select * from friend where (id = (select id from userInfo where "
          "name=\'%1\') and friendId = (select id from userInfo where "
          "name=\'%2\')) or (id = (select id from userInfo where name=\'%3\') "
          "and friendId = (select id from userInfo where name=\'%4\'))")
          .arg(pername)
          .arg(name)
          .arg(name)
          .arg(pername);
  qDebug() << data;
  QSqlQuery query;
  query.exec(data);
  if (query.next()) {
    return 0;
  } else {
    QString data =
        QString("select online from userInfo where name = \'%1\'").arg(pername);
    QSqlQuery query;
    query.exec(data);
    if (query.next()) {
      int res = query.value(0).toInt();
      if (1 == res) {
        return 1;
      } else if (0 == res) {
        return 2;
      }
    } else {
      return 3;
    }
  }
}

void OpeDB::handleAgreeAddFriend(const char *pername, const char *name) {
  if (NULL == pername || NULL == name) {
    return;
  }
  QString data =
      QString(
          "insert into friend(id, friendId) values((select id from userInfo "
          "where name=\'%1\'), (select id from userInfo where name=\'%2\'))")
          .arg(pername)
          .arg(name);
  QSqlQuery query;
  query.exec(data);
}

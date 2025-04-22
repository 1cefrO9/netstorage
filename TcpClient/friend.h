#ifndef FRIEND_H
#define FRIEND_H

#include <QHBoxLayout>
#include <QInputDialog>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

#include "online.h"
#include "protocol.h"

// 好友展示界面
class Friend : public QWidget {
  Q_OBJECT
 public:
  explicit Friend(QWidget *parent = 0);
  // 显示所有在线用户
  void showAllOnlineUsr(PDU *pdu);
  QString m_strSearchName;

 signals:

 public slots:
  // 切换在线用户显示/隐藏状态
  void showOnline();
  // 查询用户
  void searchUsr();

 private:
  QTextEdit *m_pShowMsgTE;           //显示信息
  QListWidget *m_pFriendListWidget;  //好友列表
  QLineEdit *m_pInputMsgLE;          //内容输入框
  QPushButton *m_pDelFriendPB;       //删除用户按钮
  QPushButton *m_pFlushFriendPB;     //刷新好友用户按钮
  QPushButton *m_pShowOnlineUserPB;  //查看在线用户
  QPushButton *m_pSearchUserPB;      //搜素用户
  QPushButton *m_pMsgSendPB;         //信息发送
  QPushButton *m_pPrivateChatPB;     //私聊

  Online *m_pOnline;  //在线用户
};

#endif  // FRIEND_H

#include "friend.h"

#include "protocol.h"
#include "tcpclient.h"

Friend::Friend(QWidget *parent) : QWidget(parent) {
  m_pShowMsgTE = new QTextEdit;
  m_pFriendListWidget = new QListWidget;
  m_pInputMsgLE = new QLineEdit;
  m_pDelFriendPB = new QPushButton("删除好友");
  m_pFlushFriendPB = new QPushButton("刷新好友");
  m_pShowOnlineUserPB = new QPushButton("显示在线用户");
  m_pSearchUserPB = new QPushButton("查找用户");
  m_pMsgSendPB = new QPushButton("信息发送");
  m_pPrivateChatPB = new QPushButton("私聊");
  m_pOnline = new Online;

  QVBoxLayout *pRightPBVBL = new QVBoxLayout;
  pRightPBVBL->addWidget(m_pDelFriendPB);
  pRightPBVBL->addWidget(m_pFlushFriendPB);
  pRightPBVBL->addWidget(m_pShowOnlineUserPB);
  pRightPBVBL->addWidget(m_pSearchUserPB);
  pRightPBVBL->addWidget(m_pPrivateChatPB);

  QHBoxLayout *pTopHBL = new QHBoxLayout;
  pTopHBL->addWidget(m_pShowMsgTE);
  pTopHBL->addWidget(m_pFriendListWidget);
  pTopHBL->addLayout(pRightPBVBL);

  QHBoxLayout *pMsgHBL = new QHBoxLayout;
  pMsgHBL->addWidget(m_pInputMsgLE);
  pMsgHBL->addWidget(m_pMsgSendPB);

  QVBoxLayout *pMain = new QVBoxLayout;
  pMain->addLayout(pTopHBL);
  pMain->addLayout(pMsgHBL);
  pMain->addWidget(m_pOnline);
  // 默认隐藏在线用户
  m_pOnline->hide();
  // 显示该布局
  setLayout(pMain);
  // 创建信号链接
  // 点击按钮事件
  connect(m_pShowOnlineUserPB, SIGNAL(clicked(bool)), this, SLOT(showOnline()));
}

void Friend::showAllOnlineUsr(PDU *pdu) {
  if (NULL == pdu) {
    return;
  }
  m_pOnline->showUsr(pdu);
}

void Friend::showOnline() {
  if (m_pOnline->isHidden()) {
    m_pOnline->show();
    PDU *pdu = mkPDU(0);
    pdu->uiMsgType = ENUM_MSG_TYPE_ALL_ONLINE_REQUEST;
    TcpClient::getInstance().getTcpSocket().write((char *)pdu, pdu->uiPDULen);
    free(pdu);
    pdu = NULL;
  } else {
    m_pOnline->hide();
  }
}

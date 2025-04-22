#include "mytcpsocket.h"

#include <QDebug>

#include "mytcpserver.h"

MyTcpSocket::MyTcpSocket() {
  connect(this, SIGNAL(readyRead()), this, SLOT(recvMsg()));
  connect(this, SIGNAL(disconnected()), this, SLOT(clientOffline()));
}

// 接收来自客户端的消息
void MyTcpSocket::recvMsg() {
  // qDebug() << this->bytesAvailable();  // 获取接收到的数据大小
  // uint uiPDULen = 0;
  // this->read((char *)&uiPDULen,
  //            sizeof(uint));  // 先读取uint大小的数据，首个uint正是总数据大小
  // uint uiMsgLen =
  //     uiPDULen -
  //     sizeof(
  //         PDU);  //
  //         实际消息大小，sizeof(PDU)只会计算结构体大小，而不是分配的大小
  // PDU *pdu = mkPDU(uiMsgLen);
  // this->read((char *)pdu + sizeof(uint),
  //            uiPDULen - sizeof(uint));  //
  //            接收剩余部分数据（第一个uint已读取）
  // qDebug() << pdu->uiMsgType << ' ' << (char *)pdu->caMsg;  // 输出
  // // 中文字符会乱码
  qDebug() << this->bytesAvailable();
  uint uiPDULen = 0;
  this->read((char *)&uiPDULen, sizeof(uint));
  uint uiMsgLen = uiPDULen - sizeof(PDU);
  PDU *pdu = mkPDU(uiMsgLen);
  this->read((char *)pdu + sizeof(uint), uiPDULen - sizeof(uint));
  switch (pdu->uiMsgType) {
    // 注册请求
    case ENUM_MSG_TYPE_REGIST_REQUEST: {
      char caName[32] = {'\0'};
      char caPwd[32] = {'\0'};
      strncpy(caName, pdu->caData, 32);
      strncpy(caPwd, pdu->caData + 32, 32);
      bool res = OpeDB::getInstance().handleRegist(caName, caPwd);
      PDU *respdu = mkPDU(0);
      respdu->uiMsgType = ENUM_MSG_TYPE_REGIST_RESPOND;
      if (res) {
        strcpy(respdu->caData, REGIST_OK);
      } else {
        strcpy(respdu->caData, REGIST_FAILED);
      }
      write((char *)respdu, respdu->uiPDULen);
      free(respdu);
      respdu = NULL;
      break;
    }

      // 登录请求
    case ENUM_MSG_TYPE_LOGIN_REQUEST: {
      char caName[32] = {'\0'};
      char caPwd[32] = {'\0'};
      strncpy(caName, pdu->caData, 32);
      strncpy(caPwd, pdu->caData + 32, 32);
      bool res = OpeDB::getInstance().handleLogin(caName, caPwd);
      PDU *respdu = mkPDU(0);
      respdu->uiMsgType = ENUM_MSG_TYPE_LOGIN_RESPOND;
      if (res) {
        strcpy(respdu->caData, LOGIN_OK);
        m_strName = caName;
      } else {
        strcpy(respdu->caData, LOGIN_FAILED);
      }
      write((char *)respdu, respdu->uiPDULen);
      free(respdu);
      respdu = NULL;
      break;
    }

    // 查看在线用户请求
    case ENUM_MSG_TYPE_ALL_ONLINE_REQUEST: {
      QStringList res = OpeDB::getInstance().handleAllOnline();
      uint uiMsgLen = res.size() * 32;
      PDU *resPdu = mkPDU(uiMsgLen);
      resPdu->uiMsgType = ENUM_MSG_TYPE_ALL_ONLINE_RESPOND;
      qDebug() << "在线用户数：" << res.size();
      for (int i = 0; i < res.size(); i++) {
        memcpy((char *)(resPdu->caMsg) + i * 32,
               res.at(i).toStdString().c_str(), res.at(i).size());
        qDebug() << "所有在线用户有：" << (char *)(resPdu->caMsg) + 32 * i;
      }
      write((char *)resPdu, resPdu->uiPDULen);
      free(resPdu);
      resPdu = NULL;
      break;
    }
    // 查看查找用户请求
    case ENUM_MSG_TYPE_SEARCH_USR_REQUEST: {
      int res = OpeDB::getInstance().handleSearchUsr(pdu->caData);
      PDU *resPdu = mkPDU(0);
      resPdu->uiMsgType = ENUM_MSG_TYPE_SEARCH_USR_RESPOND;
      if (-1 == res) {
        strcpy(resPdu->caData, SEARCH_USR_NO);
      } else if (1 == res) {
        strcpy(resPdu->caData, SEARCH_USR_ONLINE);
      } else if (0 == res) {
        strcpy(resPdu->caData, SEARCH_USR_OFFLINE);
      }
      write((char *)resPdu, resPdu->uiPDULen);
      free(resPdu);
      resPdu = NULL;
      break;
    }

    // 查看添加好友请求
    case ENUM_MSG_TYPE_ADD_FRIEND_REQUEST: {
      char caPerName[32] = {'\0'};
      char caName[32] = {'\0'};
      strncpy(caPerName, pdu->caData, 32);
      strncpy(caName, pdu->caData + 32, 32);
      int res = OpeDB::getInstance().handleAddFriend(caPerName, caName);
      PDU *respdu = NULL;
      if (-1 == res) {
        respdu = mkPDU(0);
        respdu->uiMsgType = ENUM_MSG_TYPE_ADD_FRIEND_RESPOND;
        strcpy(respdu->caData, UNKNOW_ERROR);
        write((char *)respdu, respdu->uiPDULen);
        free(respdu);
        respdu = NULL;
      } else if (0 == res) {
        respdu = mkPDU(0);
        respdu->uiMsgType = ENUM_MSG_TYPE_ADD_FRIEND_RESPOND;
        strcpy(respdu->caData, EXISTED_FRIEND);
        write((char *)respdu, respdu->uiPDULen);
        free(respdu);
        respdu = NULL;
      } else if (1 == res) {
        MyTcpServer::getInstance().resend(caPerName, pdu);
      } else if (2 == res) {
        respdu = mkPDU(0);
        respdu->uiMsgType = ENUM_MSG_TYPE_ADD_FRIEND_RESPOND;
        strcpy(respdu->caData, ADD_FRIEND_OFFLINE);
        write((char *)respdu, respdu->uiPDULen);
        free(respdu);
        respdu = NULL;
      } else if (3 == res) {
        respdu = mkPDU(0);
        respdu->uiMsgType = ENUM_MSG_TYPE_ADD_FRIEND_RESPOND;
        strcpy(respdu->caData, ADD_FRIEND_NO_EXIST);
        write((char *)respdu, respdu->uiPDULen);
        free(respdu);
        respdu = NULL;
      }
      break;
    }

    case ENUM_MSG_TYPE_ADD_FRIEND_AGGREE: {
      char caPerName[32] = {'\0'};
      char caName[32] = {'\0'};
      strncpy(caPerName, pdu->caData, 32);
      strncpy(caName, pdu->caData + 32, 32);
      OpeDB::getInstance().handleAgreeAddFriend(caPerName, caName);
      MyTcpServer::getInstance().resend(caName, pdu);
      break;
    }
    case ENUM_MSG_TYPE_ADD_FRIEND_REFUSE: {
      char caName[32] = {'\0'};
      strncpy(caName, pdu->caData + 32, 32);
      MyTcpServer::getInstance().resend(caName, pdu);
      break;
    }

    default: {
      break;
    }
  }
  free(pdu);
  pdu = NULL;
}

void MyTcpSocket::clientOffline() {
  OpeDB::getInstance().handleOffline(m_strName.toStdString().c_str());
  emit offline(this);
}

QString MyTcpSocket::getName() { return m_strName; }

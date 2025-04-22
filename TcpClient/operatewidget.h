#ifndef OPERATEWIDGET_H
#define OPERATEWIDGET_H

#include <QListWidget>
#include <QStackedWidget>
#include <QWidget>

#include "book.h"
#include "friend.h"

class OperateWidget : public QWidget {
  Q_OBJECT
 public:
  explicit OperateWidget(QWidget *parent = nullptr);
  static OperateWidget &getInstance();
  Friend *getFriend();

 private:
  QListWidget *m_pListW;  // 组织主页面左侧常用功能（好友、文件按钮等）
  Friend *m_pFriend;      // 好友页面
  Book *m_pBook;          // 文件页面
  QStackedWidget *m_pSW;  // 容器，每次显示一个页面（好友or文件）

 signals:
};

#endif  // OPERATEWIDGET_H

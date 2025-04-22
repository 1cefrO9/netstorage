#include "operatewidget.h"

OperateWidget::OperateWidget(QWidget *parent) : QWidget{parent} {
  m_pListW = new QListWidget(this);  // 参数指示QWidget *parent
  m_pListW->addItem("好友");
  m_pListW->addItem("图书");

  m_pFriend = new Friend;
  m_pBook = new Book;

  m_pSW = new QStackedWidget;
  m_pSW->addWidget(m_pFriend);  // 如果没有设置，默认显示第一个页面
  m_pSW->addWidget(m_pBook);

  QHBoxLayout *pMain = new QHBoxLayout;
  pMain->addWidget(m_pListW);
  pMain->addWidget(m_pSW);

  setLayout(pMain);

  // 将m_pListWidget的行号变化信号与m_pSW的设置当前页面槽函数关联
  connect(m_pListW, SIGNAL(currentRowChanged(int)), m_pSW,
          SLOT(setCurrentIndex(int)));
}

OperateWidget &OperateWidget::getInstance() {
  static OperateWidget instance;
  return instance;
}

Friend *OperateWidget::getFriend() { return m_pFriend; }

#ifndef SHAREFILE_H
#define SHAREFILE_H

#include <QButtonGroup>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

class ShareFile : public QWidget {
  Q_OBJECT
 public:
  explicit ShareFile(QWidget *parent = nullptr);
  static ShareFile &getInstance();
  void updateFriend(QListWidget *pFriendList);

 signals:

 public slots:
  void cancelSelect();
  void selectAll();
  void okShare();
  void cancelShare();

 private:
  QPushButton *m_pSelectAllPB;
  QPushButton *m_pCancelSelectPB;
  QPushButton *m_pOKPB;
  QPushButton *m_pCancelPB;
  QScrollArea *m_pSA;
  QWidget *m_pFriendW;
  QVBoxLayout *m_pFriendWVBL;
  QButtonGroup *m_pButtonGroup;
};

#endif  // SHAREFILE_H

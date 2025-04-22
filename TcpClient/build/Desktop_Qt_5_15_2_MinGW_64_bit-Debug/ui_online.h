/********************************************************************************
** Form generated from reading UI file 'online.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONLINE_H
#define UI_ONLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Online
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QListWidget *online_lw;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *addFriend_pb;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Online)
    {
        if (Online->objectName().isEmpty())
            Online->setObjectName(QString::fromUtf8("Online"));
        Online->resize(400, 300);
        widget = new QWidget(Online);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 401, 301));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        online_lw = new QListWidget(widget);
        new QListWidgetItem(online_lw);
        new QListWidgetItem(online_lw);
        new QListWidgetItem(online_lw);
        online_lw->setObjectName(QString::fromUtf8("online_lw"));

        horizontalLayout->addWidget(online_lw);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 88, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        addFriend_pb = new QPushButton(widget);
        addFriend_pb->setObjectName(QString::fromUtf8("addFriend_pb"));
        addFriend_pb->setMinimumSize(QSize(0, 30));
        addFriend_pb->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("JetBrainsMono NF"));
        font.setPointSize(13);
        addFriend_pb->setFont(font);

        verticalLayout->addWidget(addFriend_pb);

        verticalSpacer_2 = new QSpacerItem(20, 88, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Online);

        QMetaObject::connectSlotsByName(Online);
    } // setupUi

    void retranslateUi(QWidget *Online)
    {
        Online->setWindowTitle(QCoreApplication::translate("Online", "Form", nullptr));

        const bool __sortingEnabled = online_lw->isSortingEnabled();
        online_lw->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = online_lw->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("Online", "1111", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = online_lw->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("Online", "2222", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = online_lw->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("Online", "3333", nullptr));
        online_lw->setSortingEnabled(__sortingEnabled);

        addFriend_pb->setText(QCoreApplication::translate("Online", "\345\212\240\345\245\275\345\217\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Online: public Ui_Online {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONLINE_H

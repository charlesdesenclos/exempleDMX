/********************************************************************************
** Form generated from reading UI file 'serverWebSocket.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWEBSOCKET_H
#define UI_SERVERWEBSOCKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serverWebSocketClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *serverWebSocketClass)
    {
        if (serverWebSocketClass->objectName().isEmpty())
            serverWebSocketClass->setObjectName(QString::fromUtf8("serverWebSocketClass"));
        serverWebSocketClass->resize(600, 400);
        menuBar = new QMenuBar(serverWebSocketClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        serverWebSocketClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(serverWebSocketClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        serverWebSocketClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(serverWebSocketClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        serverWebSocketClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(serverWebSocketClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        serverWebSocketClass->setStatusBar(statusBar);

        retranslateUi(serverWebSocketClass);

        QMetaObject::connectSlotsByName(serverWebSocketClass);
    } // setupUi

    void retranslateUi(QMainWindow *serverWebSocketClass)
    {
        serverWebSocketClass->setWindowTitle(QCoreApplication::translate("serverWebSocketClass", "serverWebSocket", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serverWebSocketClass: public Ui_serverWebSocketClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWEBSOCKET_H

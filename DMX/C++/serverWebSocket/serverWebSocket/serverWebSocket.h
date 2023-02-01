#pragma once
#include <iostream>
#include <memory>

#include <QDebug>
#include <QObject>
#include <QList>
#include <QWebSocket>
#include <QWebSocketServer>
#include <Windows.h>
#include "bddserver.h"
#include "DMX32.h"

class QtserverTCP;

class QtserverWebSocket;

typedef std::shared_ptr<QWebSocketServer> QWebSocketServerPtr;
typedef std::shared_ptr<QWebSocket> QWebSocketPtr;
typedef std::shared_ptr<QtserverWebSocket> QtserverWebSocketPtr;

class QtserverWebSocket : public QObject
{
	Q_OBJECT
		QWebSocketServerPtr websocketServer;
		QList<QWebSocket*> wsclients;
		QMap<QWebSocket*, QString> wsocketToUsername;
		bddserver *bdd;

private:
	QWebSocket * socket;
	QtserverTCP * tcpServer;
	DMX32 * dmx = new DMX32();

public:
	QtserverWebSocket(bddserver *bdd, uint16_t port);
	void setTcpServer(QtserverTCP * server);
	QMap<QWebSocket*, QString> & getSockets() {
		return wsocketToUsername;
	}

public slots:
	//Connexion du serveur WS
	void onNewConnection();

	//Message
	void processTextMessage( QString message );
	
	//Déconnexion du serveur WS
	void socketDisconnected();

signals:
	void closed();
};

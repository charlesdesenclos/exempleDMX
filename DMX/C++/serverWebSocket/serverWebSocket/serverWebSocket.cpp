#include "serverWebSocket.h"
#include "DMX32.h"

QtserverWebSocket::QtserverWebSocket(bddserver *bdd, uint16_t port )
	: websocketServer(new QWebSocketServer(QStringLiteral("Server WebSocket"), QWebSocketServer::NonSecureMode))
{
	this->bdd = bdd;
	if (this->websocketServer->listen(QHostAddress::AnyIPv4, port)) {
		qInfo() << "Server WebSocket: Nouvelle connexion";
		QObject::connect(websocketServer.get(), SIGNAL(newConnection()), this, SLOT(onNewConnection()));
	}
	else{
		qInfo() << "Server WebSocket: Erreur d'ecoute IP ou Port";
	}
}

void QtserverWebSocket::setTcpServer(QtserverTCP * server)
{
	this->tcpServer = server;
}

void QtserverWebSocket::onNewConnection(){
	QWebSocket * socket = this->websocketServer->nextPendingConnection();
	QTcpSocket::connect(socket, &QWebSocket::textMessageReceived, this, &QtserverWebSocket::processTextMessage);

	QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));

	this->wsclients.push_back(socket);
	qDebug() << "ok";
}

void QtserverWebSocket::processTextMessage(const QString message) {

	//Récupère les messages envoyé par le client
	QSqlQuery query;

	//Authentification de l'utilisateur
	if (message.startsWith("SLIDER :: ") == true) {

		// N° SLIDER :
		QString data1 = QStringRef(&message, 4, message.length() - 4).toString();
		QString Num = data1.section(" :: ", 1, 1);

		// VALUE SLIDER :
		QString data2 = QStringRef(&message, 4, message.length() - 4).toString();
		QString Value = data2.section(" :: ", 2, 2);

		// LOG CONSOLE
		qDebug().nospace() << "Default : " << QString(message);
		qDebug().nospace() << "Value : " << QString(Value).toInt() << " Numero : " << QString(Num).toInt();

		// Changement Color
		if (QString(Num).toInt() == 0) {
			dmx->changeCaneau1(QString(Value).toInt());
			qDebug().nospace() << "Change : 0";
		}
		if (QString(Num).toInt() == 1) {
			dmx->changeCaneau2(QString(Value).toInt());
			qDebug().nospace() << "Change : 1";
		}
		if (QString(Num).toInt() == 2) {
			dmx->changeCaneau3(QString(Value).toInt());
			qDebug().nospace() << "Change : 2";
		}
		if (QString(Num).toInt() == 3) {
			dmx->changeCaneau4(QString(Value).toInt());
			qDebug().nospace() << "Change : 3";
		};
		if (QString(Num).toInt() == 4) {
			dmx->changeCaneau5(QString(Value).toInt());
			qDebug().nospace() << "Change : 4";
		}
		if (QString(Num).toInt() == 5) {
			dmx->changeCaneau6(QString(Value).toInt());
			qDebug().nospace() << "Change : 5";
		}
		if (QString(Num).toInt() == 6) {
			dmx->changeCaneau7(QString(Value).toInt());
			qDebug().nospace() << "Change : 6";
		}
		if (QString(Num).toInt() == 7) {
			dmx->changeCaneau8(QString(Value).toInt());
			qDebug().nospace() << "Change : 7";
		}
		if (QString(Num).toInt() == 8) {
			dmx->changeCaneau9(QString(Value).toInt());
			qDebug().nospace() << "Change : 8";
		}
		if (QString(Num).toInt() == 9) {
			dmx->changeCaneau10(QString(Value).toInt());
			qDebug().nospace() << "Change : 9";
		}
		if (QString(Num).toInt() == 10) {
			dmx->changeCaneau11(QString(Value).toInt());
			qDebug().nospace() << "Change : 10";
		}
		if (QString(Num).toInt() == 11) {
			dmx->changeCaneau12(QString(Value).toInt());
			qDebug().nospace() << "Change : 11";
		}
	}
	// Request Reset All Value.
	if (message.startsWith("RESET ALL") == true) {
		dmx->reset0();
		qDebug().nospace() << "Reset : ALL";
	}
	if (message.startsWith("RANDOM START") == true) {
		dmx->ActiveColorRand();
		qDebug().nospace() << "Random : START";
	}
	if (message.startsWith("RANDOM STOP") == true) {
		dmx->StopColorRand();
		qDebug().nospace() << "Random : STOP";
	}
	// Request Allume All Value.
	if (message.startsWith("ALLUME ALL") == true) {
		dmx->activate_all();
		qDebug().nospace() << "ALLUME : ALL";
	}
	// Request Lampes
	if (message.startsWith("RESET LAMPE 1") == true) {
		dmx->reset1();
		qDebug().nospace() << "RESET LAMPE : 1";
	}
	if (message.startsWith("RESET LAMPE 2") == true) {
		dmx->reset2();
		qDebug().nospace() << "RESET LAMPE : 2";
	}
	if (message.startsWith("RESET LAMPE 3") == true) {
		dmx->reset3();
		qDebug().nospace() << "RESET LAMPE : 3";
	}
	if (message.startsWith("ALLUME LAMPE 1") == true) {
		dmx->allumage1();
		qDebug().nospace() << "ALLUME LAMPE : 1";
	}
	if (message.startsWith("ALLUME LAMPE 2") == true) {
		dmx->allumage2();
		qDebug().nospace() << "ALLUME LAMPE : 2";
	}
	if (message.startsWith("ALLUME LAMPE 3") == true) {
		dmx->allumage3();
		qDebug().nospace() << "ALLUME LAMPE : 3";
	}
	// Request Color Allume
	if (message.startsWith("ALLUME COLOR ROUGE") == true) {
		dmx->activate_r();
		qDebug().nospace() << "ALLUME COLOR : ROUGE";
	}
	if (message.startsWith("ALLUME COLOR VERT") == true) {
		dmx->activate_v();
		qDebug().nospace() << "ALLUME COLOR : VERT";
	}
	if (message.startsWith("ALLUME COLOR BLEU") == true) {
		dmx->activate_b();
		qDebug().nospace() << "ALLUME COLOR : BLEU";
	}
	if (message.startsWith("ALLUME COLOR BLANC") == true) {
		dmx->activate_w();
		qDebug().nospace() << "ALLUME COLOR : BLANC";
	}

	// Request Color Reset
	if (message.startsWith("RESET COLOR ROUGE") == true) {
		dmx->desactivate_r();
		qDebug().nospace() << "RESET COLOR : ROUGE";
	}
	if (message.startsWith("RESET COLOR VERT") == true) {
		dmx->desactivate_v();
		qDebug().nospace() << "RESET COLOR : VERT";
	}
	if (message.startsWith("RESET COLOR BLEU") == true) {
		dmx->desactivate_b();
		qDebug().nospace() << "RESET COLOR : BLEU";
	}
	if (message.startsWith("RESET COLOR BLANC") == true) {
		dmx->desactivate_w();
		qDebug().nospace() << "RESET COLOR : BLANC";
	}
	// Request Specifiques
	if (message.startsWith("ALLUME FRANCE") == true) {
		dmx->France();
		qDebug().nospace() << "ALLUME : FRANCE";
	}
	else
	{
		qDebug().nospace() << "Default : " << QString(message);
	}
}

//Déconnexion du server WS
void QtserverWebSocket::socketDisconnected(){
	QWebSocket * ws = qobject_cast<QWebSocket*>(sender());
	qInfo() << "Server WebSocket: Deconnexion";
	this->wsclients.removeAll(ws);
}
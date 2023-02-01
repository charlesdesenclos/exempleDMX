#include <QtCore/QCoreApplication>
#include <QSettings>
#include <QStringList>
#include "serverWebSocket.h"
#include "DMX32.h"
#include "serverWebSocket.h"
#include "DasHard.h"


int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	//récupération des informations de configuration dans le fichier .ini
	QSettings *settings = new QSettings("config.ini", QSettings::IniFormat);
	QStringList l = settings->allKeys();
	if(!settings->contains("BDD/ipbdd")
		||
		!settings->contains("BDD/nameBdd")
		||
		!settings->contains("BDD/loginUserBdd")
		||
		!settings->contains("BDD/passUserBdd")
		||
		!settings->contains("WS/ipWS")
		||!settings->contains("WS/port")
		){
		settings->beginGroup("BDD");
		settings->setValue("ipbdd", "192.168.65.219");
		settings->setValue("nameBdd", "DMX");
		settings->setValue("loginUserBdd", "admin");
		settings->setValue("passUserBdd", "admin");
		settings->endGroup();
		settings->beginGroup("WS");
		settings->setValue("port", "1234");
		settings->endGroup();
		settings->sync();
	}


	QString ipbdd = settings->value("BDD/ipbdd", "config").toString();
	QString loginUserbdd = settings->value("BDD/loginUserbdd", "config").toString();
	QString passUserbdd = settings->value("BDD/passUserbdd", "config").toString();
	QString nameBdd = settings->value("BDD/nameBdd", "config").toString();
	int port = settings->value("WS/port", "config").toInt();
	// Connexion à la BDD
	bddserver *bdd = new bddserver();
	// Protocole, IP, Nom BDD, User, Password
	bdd->bddInit("QMYSQL", ipbdd, nameBdd, loginUserbdd, passUserbdd);

	// Appel du server WS
	QtserverWebSocket serverWebSocket(bdd, port);

	return a.exec();
}

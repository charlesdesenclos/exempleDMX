#include <QDebug>
#include "bddserver.h"

//Initialisation de le BDD
void bddserver::bddInit(QString level, QString date_creation, QString ID, QString login, QString mdp) {
	QSqlDatabase bdd = QSqlDatabase::addDatabase(level);	
	bdd.setHostName(date_creation);
	bdd.setDatabaseName(ID);
	bdd.setUserName(login);
	bdd.setPassword(mdp);

	bddConnect(bdd);
}

//Vérification de la connexion à la BDD
void bddserver::bddConnect(QSqlDatabase bdd) {
	bool ok = bdd.open();
	if (ok == true) {
		qInfo() << "BDD:";
	}
	else {
		qInfo() << "BDD: Erreur de connexion";
	}
}

//Fonction de connexion de l'utilisateur
QString bddserver::connexion(QString login, QString mdp) {
	QSqlQuery query;
	QString pseudo = "";
	query.exec("SELECT * FROM `user` WHERE `login`='"+login+"' AND `mdp`='"+mdp+"'");
	if (query.next()) {
		QString logid = query.value(0).toString();
		QString loglogin = query.value(1).toString();
		QString logmdp = query.value(2).toString();

		if (loglogin == login && logmdp == mdp) {
			qInfo() << login+" s'est connecte";
			pseudo = login;
		}
	}
	return pseudo;
}

//Fonction d'inscription de l'utilisateur
QString bddserver::inscription(QString login, QString mdp) {
	QSqlQuery query;
	QString pseudo = login;
	query.exec("INSERT INTO `user`(`login`, `mdp`) VALUES('"+login+"', '"+mdp+"')");
	query.next();
	qInfo() << login + " à creer un compte";
	qInfo() << login + " s'est connecte";
	return pseudo;
}


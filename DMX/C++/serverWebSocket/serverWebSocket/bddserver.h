#pragma once
#include <QObject>
#include <QtSql>
#include <QSqlDatabase>
#include <qstring.h>

class bddserver {
private :
	bddserver *bdd;
public :
	//Initialisation de le BDD
	void bddInit(QString level, QString date_creation, QString ID, QString login, QString mdp);
	
	//Vérification de la connexion à la BDD
	void bddConnect(QSqlDatabase bdd);
	
	//Fonction de connexion de l'utilisateur
	QString connexion(QString login, QString mdp);
	
	//Fonction d'inscription de l'utilisateur
	QString inscription(QString login, QString mdp);
};
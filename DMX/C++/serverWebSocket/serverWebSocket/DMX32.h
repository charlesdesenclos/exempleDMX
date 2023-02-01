#pragma once

#include <Windows.h>
#include "DasHard.h"
#include <QTimer>
#include <QDebug>
#include <QObject>
#include <QList>
#include <QTcpSocket>
#include <QTcpServer>
#include "bddserver.h"

#define DMX_MAXCHANNEL 512

class DMX32 : public QObject
{
	Q_OBJECT

public:
	DMX32(QWidget *parent = Q_NULLPTR);
	HINSTANCE g_dasusbdll;
	typedef int(*DASHARDCOMMAND)(int, int, unsigned char*);
	DASHARDCOMMAND DasUsbCommand;
	int interface_open;
	unsigned char dmxBlock[512];	
	QTimer *timer;

public slots:

	// Système Slider
	void changeCaneau1(int Value);
	void changeCaneau2(int Value);
	void changeCaneau3(int Value);
	void changeCaneau4(int Value);
	void changeCaneau5(int Value);
	void changeCaneau6(int Value);
	void changeCaneau7(int Value);
	void changeCaneau8(int Value);
	void changeCaneau9(int Value);
	void changeCaneau10(int Value);
	void changeCaneau11(int Value);
	void changeCaneau12(int Value);

	// Reset DMX
	void reset0();
	void reset1();
	void reset2();
	void reset3();

	//Allumage DMX
	void allumage1();
	void allumage2();
	void allumage3();

	// Activate / Désactivate Color
	void activate_all();

	void activate_w();
	void activate_r();
	void activate_v();
	void activate_b();

	void desactivate_w();
	void desactivate_r();
	void desactivate_v();
	void desactivate_b();

	// Couleur Aléatoire / Autres
	void ActiveColorRand();
	void ColorRand();
	void StopColorRand();
	void ActiveColorPrimRand();
	void ColorPrimRand();
	void France();
};

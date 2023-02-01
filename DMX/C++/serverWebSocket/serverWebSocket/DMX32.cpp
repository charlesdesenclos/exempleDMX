#include "DMX32.h"
#include <Windows.h>


DMX32::DMX32(QWidget *parent)
{
	g_dasusbdll = LoadLibrary(L"DasHard2006.dll");

	if (g_dasusbdll) {
		DasUsbCommand = (DASHARDCOMMAND)::GetProcAddress((HMODULE)g_dasusbdll, "DasUsbCommand");
	}

	interface_open = DasUsbCommand(DHC_INIT, 0, NULL);
	interface_open = DasUsbCommand(DHC_OPEN, 0, 0);

	if (interface_open > 0)
	{
		for (int i = 0; i < DMX_MAXCHANNEL + 1; i++) {
			dmxBlock[i] = 0;
		}
		DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
	}
}


// Changement Slide

void DMX32::changeCaneau1(int Value)
{
	dmxBlock[0] = Value;
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}

void DMX32::changeCaneau2(int Value)
{
	dmxBlock[1] = Value;
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}

void DMX32::changeCaneau3(int Value)
{
	dmxBlock[2] = Value;
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}

void DMX32::changeCaneau4(int Value)
{
	dmxBlock[3] = Value;
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}

void DMX32::changeCaneau5(int Value)
{
	dmxBlock[4] = Value;
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}

void DMX32::changeCaneau6(int Value)
{
	dmxBlock[5] = Value;
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}

void DMX32::changeCaneau7(int Value)
{
	dmxBlock[6] = Value;
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}

void DMX32::changeCaneau8(int Value)
{
	dmxBlock[7] = Value;
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}

void DMX32::changeCaneau9(int Value)
{
	dmxBlock[8] = Value;
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}

void DMX32::changeCaneau10(int Value)
{
	dmxBlock[9] = Value;
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}

void DMX32::changeCaneau11(int Value)
{
	dmxBlock[10] = Value;
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}

void DMX32::changeCaneau12(int Value)
{
	dmxBlock[11] = Value;
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}

// Changement Reset DMX

void DMX32::reset0()
{
	for (int nb1 = 0; nb1 < 12; nb1++) {
		dmxBlock[nb1] = 0;
	}
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
	qDebug() << "RESET : 0";
}

void DMX32::reset1()
{
	for (int nb1 = 0; nb1 < 4; nb1++) {
		QString nb2 = QString::number(0);
		dmxBlock[nb1] = 0;
	}
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
	qDebug() << "RESET : 1";
}

void DMX32::reset2()
{
	for (int nb1 = 4; nb1 < 8; nb1++) {
		QString nb2 = QString::number(0);
		dmxBlock[nb1] = 0;
	}
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
	qDebug() << "RESET : 2";
}

void DMX32::reset3()
{
	for (int nb1 = 8; nb1 < 12; nb1++) {
		QString nb2 = QString::number(0);
		dmxBlock[nb1] = 0;
	}
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
	qDebug() << "RESET : 3";
}

// Changement Allumage DMX

void DMX32::allumage1()
{
	for (int nb1 = 0; nb1 < 4; nb1++) {
		QString nb2 = QString::number(0);
		dmxBlock[nb1] = 255;
	}
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
	qDebug() << "ALLUMAGE : 1";
}

void DMX32::allumage2()
{
	for (int nb1 = 4; nb1 < 8; nb1++) {
		QString nb2 = QString::number(0);
		dmxBlock[nb1] = 255;
	}
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
	qDebug() << "ALLUMAGE : 2";
}

void DMX32::allumage3()
{
	for (int nb1 = 8; nb1 < 12; nb1++) {
		QString nb2 = QString::number(0);
		dmxBlock[nb1] = 255;
	}
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
	qDebug() << "ALLUMAGE : 3";
}

// Changement Activate Color

void DMX32::activate_all()
{
	for (int nb1 = 0; nb1 < DMX_MAXCHANNEL + 1; nb1++) {
		dmxBlock[nb1] = 255;
	}
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
	qDebug() << "RESET : ALL";
}

void DMX32::activate_r()
{
	QString nb2 = QString::number(255);
	dmxBlock[0] = 255;
	dmxBlock[4] = 255;
	dmxBlock[8] = 255;
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}

void DMX32::activate_v()
{
	QString nb2 = QString::number(255);
	dmxBlock[1] = 255;
	dmxBlock[5] = 255;
	dmxBlock[9] = 255;
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}

void DMX32::activate_b()
{
	QString nb2 = QString::number(255);
	dmxBlock[2] = 255;
	dmxBlock[6] = 255;
	dmxBlock[10] = 255;
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}

void DMX32::activate_w()
{
	QString nb2 = QString::number(255);
	dmxBlock[3] = 255;
	dmxBlock[7] = 255;
	dmxBlock[11] = 255;
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}

// Changement Désactivate Color

void DMX32::desactivate_r()
{
	QString nb2 = QString::number(0);
	dmxBlock[0] = 0;
	dmxBlock[4] = 0;
	dmxBlock[8] = 0;
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}

void DMX32::desactivate_v()
{
	QString nb2 = QString::number(0);
	dmxBlock[1] = 0;
	dmxBlock[5] = 0;
	dmxBlock[9] = 0;
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}

void DMX32::desactivate_b()
{
	QString nb2 = QString::number(0);
	dmxBlock[2] = 0;
	dmxBlock[6] = 0;
	dmxBlock[10] = 0;
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}

void DMX32::desactivate_w()
{
	QString nb2 = QString::number(0);
	dmxBlock[3] = 0;
	dmxBlock[7] = 0;
	dmxBlock[11] = 0;
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}

// Système Aléatoire

void DMX32::ActiveColorRand()
{
	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &DMX32::ColorRand);
	timer->start(10);
}

void DMX32::ColorRand()
{
	int channel1 = rand() % 11;
	int channel2 = rand() % 11;
	int value1 = rand() % 255 + 1;
	int value2 = rand() % 255 + 1;
	dmxBlock[channel1] = value1;
	dmxBlock[channel2] = value2;
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}

void DMX32::StopColorRand()
{

	if ( timer->isActive( ) ) { 

		timer->stop();
		DMX32::reset0();
	}
}

void DMX32::ActiveColorPrimRand()
{
	//timer = new QTimer(this);
	//connect(timer, &QTimer::timeout, this, &DMX32::ColorPrimRand);
	//timer->start(50);
}

void DMX32::ColorPrimRand()
{
	int randChannel[8] = { 0, 1, 2, 4, 6, 8, 9, 10 };
	int channel1 = randChannel[rand() % 8];
	int channel2 = randChannel[rand() % 8];
	int channel3 = randChannel[rand() % 8];
	int channel4 = randChannel[rand() % 8];
	int channel5 = randChannel[rand() % 8];
	int colorValue[5] = { 0, 0, 62, 186, 255 };
	int value = colorValue[rand() % 5];
	dmxBlock[channel1] = value;
	dmxBlock[channel2] = value;
	dmxBlock[channel3] = value;
	dmxBlock[channel4] = value;
	dmxBlock[channel5] = value;
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}

// Paterne Bleu Blanc Rouge
void DMX32::France()
{
	QString nb2 = QString::number(255);
	dmxBlock[2] = 255;
	dmxBlock[7] = 255;
	dmxBlock[8] = 255;
	DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}
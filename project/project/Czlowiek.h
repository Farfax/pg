#ifndef CZLOWIEK_H
#define CZLOWIEK_H

#include <conio.h>
#include "Zwierze.h"

class Czlowiek : public Zwierze {
public:
	Czlowiek(Swiat& sw) : Zwierze(5, 4, 254, 12, 0, "CZLOWIEK", sw) {};
	void kolizja() {};
	void akcja();
};

//
//void Czlowiek::kolizja() {
//
//};

void Czlowiek::akcja() {
	unsigned char znak = getch();
	
	switch (znak)
	{
	case 0: //klawisze specjalne
	case 224: //klawisze specjalne
		znak = getch();
		switch (znak)
		{
		case 72: //strza�ka w g�r�
			if (pos.y - 1 > 0)//swiat.HEIGHT)
			pos.y--;
			break;
		case 80: //strza�ka w d�
			if (pos.y + 1 <= 20)//swiat.HEIGHT)
			pos.y++;
			break;
		case 75: //strza�ka w lewo
			if (pos.x - 1 > 0)//swiat.WIDTH)
			pos.x--;
			break;
		case 77: //strza�ka w prawo
			if (pos.x + 1 <= 40)//swiat.WIDTH)
			pos.x++;
			break;
		case 112: //specjalna umiejetnosc 'p'
		default:
			break;
		}
		znak = 0;
		break;
	}
}

#endif
#include "Barszcz.h"
#include "Swiat.h"

Barszcz::Barszcz(Swiat& sw) : Roslina(99, 0, 'B', 11, 0, "BARSZCZ", sw) {
	maxZakresLosowania = 300;
	allocate();
};

Barszcz::Barszcz(Swiat& sw, int x, int y) : Roslina(99, 0, 'B', 11, 0, "BARSZCZ", sw) {
	maxZakresLosowania = 300;
	this->pos.x = x;
	this->pos.y = y;
	allocate();
}

void Barszcz::rozmnazanie() {
	Organizm *child = new Barszcz(swiat, pos.x, pos.y);
	swiat.lista.push_back(child);
	swiat.sortujInicjatywa();
}

void Barszcz::kolizja(Organizm& other) {
	if (this->getRodzaj() != "CYBER-OWCA") {
		swiat.komentuj(" + " + other.getRodzaj() + " ginie otruty przez " + rodzaj + "! + ");
		swiat.world[other.getOldPosy()][other.getOldPosx()] = NULL;
		other.die();
		swiat.world[pos.y][pos.x] = NULL;
		this->die();
	}
}

void Barszcz::akcja() {
	Roslina::akcja();
	Organizm* tmp;
	if (pos.y - 1 < swiat.HEIGHT - 1 && pos.y - 1 > 1) {
		tmp = swiat.world[pos.y - 1][pos.x];
		if (tmp != NULL && dynamic_cast<Zwierze*>(tmp)) {
			swiat.komentuj(" + " + tmp->getRodzaj() + " ginie przez trujace opary BARSZCZU! + ");
			tmp->die();
			swiat.world[pos.y - 1][pos.x] = NULL;
			Util::gotoxy(pos.y - 1, pos.x);
			putchar(' ');
		}
	}

	if (pos.y + 1 < swiat.HEIGHT - 1 && pos.y + 1 > 1) {
		tmp = swiat.world[pos.y + 1][pos.x];
		if (tmp != NULL && dynamic_cast<Zwierze*>(tmp)) {
			swiat.komentuj(" + " + tmp->getRodzaj() + " ginie przez trujace opary BARSZCZU! + ");
			tmp->die();
			swiat.world[pos.y + 1][pos.x] = NULL;
			Util::gotoxy(pos.y + 1, pos.x);
			putchar(' ');
		}
	}

	if (pos.x + 1 < swiat.WIDTH - 1 && pos.x + 1 > 1) {
		tmp = swiat.world[pos.y][pos.x + 1];
		if (tmp != NULL && dynamic_cast<Zwierze*>(tmp)) {
			swiat.komentuj(" + " + tmp->getRodzaj() + " ginie przez trujace opary BARSZCZU! + ");
			tmp->die();
			swiat.world[pos.y][pos.x+1] = NULL;
			Util::gotoxy(pos.y, pos.x + 1);
			putchar(' ');
		}
	}

	if (pos.x - 1 < swiat.WIDTH - 1 && pos.x - 1 > 1) {
		tmp = swiat.world[pos.y][pos.x - 1];
		if (tmp != NULL && dynamic_cast<Zwierze*>(tmp)) {
			swiat.komentuj(" + " + tmp->getRodzaj() + " ginie przez trujace opary BARSZCZU! + ");
			tmp->die();
			swiat.world[pos.y][pos.x - 1] = NULL;
			Util::gotoxy(pos.y, pos.x - 1);
			putchar(' ');
		}
	}
}
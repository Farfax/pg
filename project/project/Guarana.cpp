#include "Trawa.h"
#include "Swiat.h"

Trawa::Trawa(Swiat& sw) : Roslina(0, 0, 176, 10, 0, "TRAWA", sw) {
	if (swiat.world[pos.y][pos.x] == NULL)
		swiat.world[pos.y][pos.x] = this;
	else {
		reallocate();
	}
};

Trawa::Trawa(Swiat& sw, int x, int y) : Roslina(0, 0, 176, 10, 0, "TRAWA", sw) {
	this->pos.x = x;
	this->pos.y = y;

	if (swiat.world[pos.y][pos.x] == NULL)
		swiat.world[pos.y][pos.x] = this;
	else {
		reallocate();
	}
}

void Trawa::rozmnazanie() {
	Organizm *child = new Trawa(swiat, pos.x, pos.y);
	swiat.lista.push_back(child);
	swiat.sortujInicjatywa();
}

void Trawa::kolizja(Organizm& other) {

}

void Trawa::akcja() {
	grow();
	if (this->wiek == 100) {
		this->color = 2;
		this->symbol = 177;
	}
	if (this->wiek == 200) {
		this->color = 6;
		this->symbol = 178;
	}
	if ((validPosY(pos.y - 1) && validPosX(pos.x) && swiat.world[pos.y - 1][pos.x] != NULL) &&
		(validPosY(pos.y + 1) && validPosX(pos.x) && swiat.world[pos.y + 1][pos.x] != NULL) &&
		(validPosY(pos.y) && validPosX(pos.x - 1) && swiat.world[pos.y][pos.x - 1] != NULL) &&
		(validPosY(pos.y) && validPosX(pos.x + 1) && swiat.world[pos.y][pos.x + 1] != NULL))
		return;
	else
	if (swiat.losuj(1, 80) == swiat.losuj(1, 80))
		rozmnazanie();
}
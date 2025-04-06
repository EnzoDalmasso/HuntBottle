#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

using namespace std;

class Blancos
{
private:
	
	Texture text_botella[4];
	Sprite* spr_botella[4];
	int botella_elegida;
	Vector2f pos_bote[3];
	Vector2f velocidad;
	Vector2f aceleracion;
	Clock* reloj2;
	Time* time2;
	float tiempo3;

public:
	Blancos();
	void copia_vent1(RenderWindow *ventana);
	void reiniciartiempo();
	void pos_botellas();
	void botella_al(Vector2f al_azar);
	void actualizar(float delta_t);
	void eliminarbote(int tiempo);
	bool generarboteal(int tiempo);
	void reiniciarbotellas(int tiempo);
	void chaubote(int botelladada);
	Sprite devolver_spr1() { return *spr_botella[0]; };
	Sprite devolver_spr2() { return *spr_botella[1]; };
	Sprite devolver_spr3() { return *spr_botella[2]; };
	Sprite devolver_spr4() { return *spr_botella[3]; };
};

Blancos::Blancos() 
{
	for (int i = 0; i < 4; i++)
	{
		spr_botella[i] = new Sprite;
	}
	text_botella[0].loadFromFile("botellamarron.png");
	spr_botella[0]->setTexture(text_botella[0]);
	spr_botella[0]->setOrigin(text_botella[0].getSize().x / 2.f, text_botella[0].getSize().y / 2.f);
	spr_botella[0]->setScale(0.05f, 0.05f);

	text_botella[1].loadFromFile("botellanegra.png");
	spr_botella[1]->setTexture(text_botella[1]);
	spr_botella[1]->setOrigin(text_botella[1].getSize().x / 2.f, text_botella[1].getSize().y / 2.f);
	spr_botella[1]->setScale(0.08f, 0.08f);

	text_botella[2].loadFromFile("botellaverde.png");
	spr_botella[2]->setTexture(text_botella[2]);
	spr_botella[2]->setOrigin(text_botella[2].getSize().x / 2.f, text_botella[2].getSize().y / 2.f);
	spr_botella[2]->setScale(0.02f, 0.02f);

	text_botella[3].loadFromFile("Molo.png");
	spr_botella[3]->setTexture(text_botella[3]);
	spr_botella[3]->setOrigin(text_botella[3].getSize().x / 2.f, text_botella[3].getSize().y / 2.f);
	spr_botella[3]->setScale(0.045f, 0.045f);

	
	pos_bote[0] = { -60,320 };
	pos_bote[1] = { -60,380 };
	pos_bote[2] = { -60,450 };
	srand(time(NULL));

	
	velocidad.x = 6;
	velocidad.y = -6.5;

	aceleracion.x = -0.003;
	aceleracion.y = 0.1;
	
	
	reloj2 = new Clock();
	time2 = new Time();
	tiempo3 = 0;
}

void Blancos::copia_vent1(RenderWindow* ventana)
{
	*time2 = reloj2->getElapsedTime();
	if (time2->asSeconds() > tiempo3 + 1 / 60)
	{
		tiempo3 = time2->asSeconds();
		actualizar(tiempo3);

		if (spr_botella[botella_elegida])
		{
			switch (botella_elegida)
			{
			case 0:
				ventana->draw(*spr_botella[0]);
				break;
			case 1:
				ventana->draw(*spr_botella[1]);
				break;
			case 2:
				ventana->draw(*spr_botella[2]);
				break;
			case 3:
				ventana->draw(*spr_botella[3]);
				break;
			}
		}
	}
		
}

void Blancos::pos_botellas()
{
	int aux;
	aux= rand() % 3;
	switch (aux)
	{
	case 0:
		botella_al(pos_bote[0]);
		break;
	case 1:
		botella_al(pos_bote[1]);
		break;
	case 2:
		botella_al(pos_bote[2]);
		break;
	}
}
void Blancos::botella_al(Vector2f al_azar)
{

	botella_elegida = rand() % 4;
	switch (botella_elegida)
	{
	case 0:
		spr_botella[0]->setPosition(al_azar);
		break;
	case 1:
		spr_botella[1]->setPosition(al_azar);
		break;
	case 2:
		spr_botella[2]->setPosition(al_azar);
		break;
	case 3:
		spr_botella[3]->setPosition(al_azar);
		break;

	}
}

void Blancos::actualizar(float delta_t)
{
	if (spr_botella[botella_elegida])
	{
		delta_t / 10000000;
		velocidad.x += aceleracion.x * delta_t;
		velocidad.y += aceleracion.y * delta_t;

		spr_botella[botella_elegida]->setRotation(spr_botella[botella_elegida]->getRotation() + 5);
		spr_botella[botella_elegida]->setPosition(spr_botella[botella_elegida]->getPosition().x + velocidad.x * delta_t, spr_botella[botella_elegida]->getPosition().y + velocidad.y * delta_t);
	}
	
}
void Blancos::eliminarbote(int tiempo)
{
	if (spr_botella[botella_elegida] && spr_botella[botella_elegida]->getPosition().y >= 450)

	{
		spr_botella[botella_elegida] = NULL;
		reiniciarbotellas(tiempo);
		
	}
}

bool Blancos::generarboteal(int tiempo)
{
	if ((spr_botella[botella_elegida] == NULL) || tiempo%5==0)
	{
		switch (botella_elegida)
		{
		case 0:
			spr_botella[0] = new Sprite(text_botella[0]);
			spr_botella[0]->setOrigin(text_botella[0].getSize().x / 2.f, text_botella[0].getSize().y / 2.f);
			spr_botella[0]->setScale(0.05f, 0.05f);
			break;
		case 1:
			spr_botella[1] = new Sprite(text_botella[1]);
			spr_botella[1]->setOrigin(text_botella[1].getSize().x / 2.f, text_botella[1].getSize().y / 2.f);
			spr_botella[1]->setScale(0.08f, 0.08f);
			break;
		case 2:
			spr_botella[2] = new Sprite(text_botella[2]);
			spr_botella[2]->setOrigin(text_botella[2].getSize().x / 2.f, text_botella[2].getSize().y / 2.f);
			spr_botella[2]->setScale(0.02f, 0.02f);
			break;
		case 3:
			spr_botella[3] = new Sprite(text_botella[3]);
			spr_botella[3]->setOrigin(text_botella[3].getSize().x / 2.f, text_botella[3].getSize().y / 2.f);
			spr_botella[3]->setScale(0.045f, 0.045f);
			break;
		}
		velocidad.x = 6;
		velocidad.y = -6.5;
		pos_botellas();
		return true;
	}
	return false;
}
void Blancos::reiniciarbotellas(int tiempo)
{
	if (generarboteal(tiempo))
	{
		tiempo3 = 0;
		reloj2->restart();
	}
}
void Blancos::chaubote(int botelladada)
{
	spr_botella[botelladada] = NULL;
	botella_elegida = botelladada;
	tiempo3 = 0;
	reloj2->restart();
}
void Blancos::reiniciartiempo()
{
	tiempo3 = 0;
	reloj2->restart();
}
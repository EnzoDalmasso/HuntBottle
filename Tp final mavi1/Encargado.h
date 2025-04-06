#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include "Jugador1.h"
#include "Blancos.h"

using namespace sf;

using namespace std;

class Encargado
{
private:
	
	RenderWindow* ventana;
	int fps;
	Texture fondo_pant;
	Sprite fondo_pantalla;
	int vida_pj = 3;
	int puntaje;
	Clock* reloj1;
	Time* tiempo1;
	float tiempo2;
	int convertir_tiempo;
	Jugador1 j1;
	Blancos b1;
	Event mouse;
	Vector2f pos_mouse;
	Font * fuente1;
	Text * txt_vidas[7];
	Music musica;
	
public:
	Encargado();
	void imp_pant();
	void finjuego();
	void eventos();
	void act_tiempo();
	void sumatoria_puntos();
	void menos_vida();
	void detectarbote();
	void iniciar_botellas();
	int disparo();
	void reinicio_juego();
	
};

Encargado::Encargado() {
fondo_pant.loadFromFile("fondo tpfinal.jpg");
fondo_pantalla.setTexture(fondo_pant);
fondo_pantalla.setOrigin(fondo_pant.getSize().x/2.f,fondo_pant.getSize().y/2.f);
fondo_pantalla.setPosition(390, 300);
fondo_pantalla.setScale(2.7f, 5.8f);
ventana = new RenderWindow(VideoMode(800, 600, 32), "Ventana 1");
ventana->setMouseCursorVisible(false);
fps = 30;
ventana->setFramerateLimit(fps);

puntaje = 0;
reloj1 = new Clock();
tiempo1 = new Time();
tiempo2 = 0;
convertir_tiempo = tiempo2;

iniciar_botellas();

fuente1 = new Font();
fuente1->loadFromFile("Texto.ttf");

for (int i = 0; i < 7; i++)
{
	txt_vidas[i] = new Text();
	txt_vidas[i]->setFont(*fuente1);
	txt_vidas[i]->setFillColor(Color::Black);
	txt_vidas[i]->setOrigin(txt_vidas[i]->getGlobalBounds().width / 2, txt_vidas[i]->getGlobalBounds().height / 2);
	txt_vidas[i]->setCharacterSize(20);
}

txt_vidas[0]->setString("Puntaje:");
txt_vidas[0]->setPosition(645, 20);

txt_vidas[1]->setString(to_string(puntaje));
txt_vidas[1]->setPosition(750, 20);

txt_vidas[2]->setString(to_string(vida_pj));
txt_vidas[2]->setPosition(380, 20);

txt_vidas[3]->setString("Vidas:");
txt_vidas[3]->setPosition(310, 20);

txt_vidas[4]->setString("Tiempo:");
txt_vidas[4]->setPosition(0, 20);

txt_vidas[5]->setString(to_string(convertir_tiempo));
txt_vidas[5]->setPosition(85, 20);

txt_vidas[6]->setString("Fin de juego, R para reiniciar");
txt_vidas[6]->setPosition(260,300);


if (!musica.openFromFile("musica.ogg"))
{
	cout << "no se pudo cargar la musica" << endl;
	musica.setLoop(true);
	
}

}

void Encargado::imp_pant()
{
	
	while (ventana->isOpen())
	{
		
		musica.setVolume(5);
		musica.play();
		while (convertir_tiempo<=60 && vida_pj>0)
		{
			*tiempo1 = reloj1->getElapsedTime();
			if (tiempo1->asSeconds() > tiempo2 + 1 / 60)
			{
				tiempo2 = tiempo1->asSeconds();
				
				ventana->clear();
				ventana->draw(fondo_pantalla); 
				for (int i = 0; i < 6; i++)
				{
					ventana->draw(*txt_vidas[i]);
				}
				j1.copia_vent(ventana);
				b1.copia_vent1(ventana);
				b1.eliminarbote(tiempo2);
				ventana->display();
				eventos();
				act_tiempo();
				convertir_tiempo = tiempo2;
			}
		}
		eventos();
		finjuego();
		
	}
	

}
void Encargado::eventos() 
{
	while (ventana->pollEvent(mouse)) {
		switch (mouse.type)
		{
			if (convertir_tiempo<=60)
			{
		case Event::MouseMoved:
			pos_mouse = ((Vector2f)Mouse::getPosition(*ventana));
			j1.mover_mira(pos_mouse);
			break;
		case Event::MouseButtonPressed:
			detectarbote();
			j1.traspdisp();
			break;
			}
		
		case Event::Closed:
			exit(1);
			break;
			if (convertir_tiempo == 60)
			{
		case Event::KeyPressed:
			if(Keyboard::isKeyPressed(Keyboard::R))
			{
				reinicio_juego();
				break;
			}

			}
		}
	}
}

void Encargado::iniciar_botellas()
{
	b1.pos_botellas();
}

int Encargado::disparo()
{
	int boteaux=-1;

	//Tamaño del sprite
	float anchoSprite = b1.devolver_spr1().getTexture()->getSize().x*0.05f;
	float xmaximo = b1.devolver_spr1().getPosition().x + anchoSprite / 2.0f;
	float xminimo = b1.devolver_spr1().getPosition().x - anchoSprite / 2.0f;

	if (pos_mouse.x < xmaximo && pos_mouse.x > xminimo)
	{
		//Para la altura del sprite
		float altoSprite = b1.devolver_spr1().getTexture()->getSize().y*0.05f;
		float ymaximo = b1.devolver_spr1().getPosition().y + altoSprite / 2.0f;
		float yminimo = b1.devolver_spr1().getPosition().y - altoSprite / 2.0f;
		if (pos_mouse.y < ymaximo && pos_mouse.y > yminimo)
		boteaux = 0;
		
		b1.chaubote(boteaux);
		b1.generarboteal(tiempo2);
			return 1;
	}

	float anchoSprite2 = b1.devolver_spr2().getTexture()->getSize().x*0.08f;
	float xmaximo2 = b1.devolver_spr2().getPosition().x + anchoSprite2 / 2.0f;
	float xminimo2 = b1.devolver_spr2().getPosition().x - anchoSprite2 / 2.0f;

	if (pos_mouse.x < xmaximo2 && pos_mouse.x > xminimo2)
	{
		float altoSprite2 = b1.devolver_spr2().getTexture()->getSize().y * 0.08f;
		float ymaximo2 = b1.devolver_spr2().getPosition().y + altoSprite2 / 2.0f;
		float yminimo2 = b1.devolver_spr2().getPosition().y - altoSprite2 / 2.0f;
		if (pos_mouse.y < ymaximo2 && pos_mouse.y > yminimo2)
			boteaux = 1;
		b1.chaubote(boteaux);
		b1.generarboteal(tiempo2);
			return 2;
	}

	float anchoSprite3 = b1.devolver_spr3().getTexture()->getSize().x * 0.02f;;
	float xmaximo3 = b1.devolver_spr3().getPosition().x + anchoSprite3 / 2.0f;
	float xminimo3= b1.devolver_spr3().getPosition().x - anchoSprite3 / 2.0f;

	if (pos_mouse.x < xmaximo3 && pos_mouse.x > xminimo3)
	{
		float altoSprite3 = b1.devolver_spr3().getTexture()->getSize().y * 0.02f;
		float ymaximo3 = b1.devolver_spr3().getPosition().y + altoSprite3 / 2.0f;
		float yminimo3 = b1.devolver_spr3().getPosition().y - altoSprite3 / 2.0f;
		if (pos_mouse.y < ymaximo3 && pos_mouse.y > yminimo3)
		boteaux = 2;
		b1.chaubote(boteaux);
		b1.generarboteal(tiempo2);
		return 3;
	}

	float anchoSprite4 = b1.devolver_spr4().getTexture()->getSize().x * 0.045f;;
	float xmaximo4 = b1.devolver_spr4().getPosition().x + anchoSprite4 / 2.0f;
	float xminimo4 = b1.devolver_spr4().getPosition().x - anchoSprite4 / 2.0f;

	if (pos_mouse.x < xmaximo4 && pos_mouse.x > xminimo4)
	{
		float altoSprite4 = b1.devolver_spr4().getTexture()->getSize().y * 0.045f;
		float ymaximo4 = b1.devolver_spr4().getPosition().y + altoSprite4 / 2.0f;
		float yminimo4 = b1.devolver_spr4().getPosition().y - altoSprite4 / 2.0f;
		if (pos_mouse.y < ymaximo4 && pos_mouse.y > yminimo4)
		boteaux = 3;
		b1.chaubote(boteaux); 
		b1.generarboteal(tiempo2);
		return 4;
	}
	
	boteaux=-1;
	return false;
}

void Encargado::act_tiempo()
{
	txt_vidas[5]->setString(to_string(convertir_tiempo));
}
void Encargado::reinicio_juego()
{
	tiempo2 = 0;
	vida_pj = 3;
	puntaje = 0;
	convertir_tiempo = 0;

	reloj1->restart();
	menos_vida();
	b1.reiniciartiempo();

}

void Encargado::detectarbote()
{
	int aux;

	aux = disparo();
	switch (aux)
	{
	case 1:
		puntaje += 100;
		break;
	case 2:
		puntaje += 50;
		break;
	case 3:
		puntaje += 200;
		break;
	case 4:
		vida_pj--;
		break;
	}
	sumatoria_puntos();
	menos_vida();
	
}

void Encargado::sumatoria_puntos()
{
	txt_vidas[1]->setString(to_string(puntaje));
}
void Encargado::menos_vida()
{
	txt_vidas[2]->setString(to_string(vida_pj));
}

void Encargado::finjuego()
{
	ventana->clear();
	ventana->draw(fondo_pantalla);
	ventana->draw(*txt_vidas[6]);
	ventana->draw(*txt_vidas[2]);
	ventana->draw(*txt_vidas[3]);
	ventana->draw(*txt_vidas[0]);
	ventana->draw(*txt_vidas[1]);
	ventana->display();
}
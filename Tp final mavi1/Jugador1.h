
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

using namespace std;
class Jugador1
{
private:
	Texture mira;
	Sprite mira_s;
	SoundBuffer buffer;
	Sound sonido;


public:
	Jugador1();
	void copia_vent(RenderWindow *ventana);
	void mover_mira(Vector2f movimiento);
	void traspdisp();
};

Jugador1::Jugador1(){
	mira.loadFromFile("mira.png");
	mira_s.setTexture(mira);
	mira_s.setOrigin(mira.getSize().x / 2.f, mira.getSize().y / 2.f);
	mira_s.setPosition(400, 300);
	mira_s.setScale(0.1f, 0.1f);
	buffer.loadFromFile("disparo.wav");
	sonido.setBuffer(buffer);

	
}
void Jugador1::copia_vent(RenderWindow *ventana) 
{
	
	ventana->draw(mira_s);

}
void Jugador1::mover_mira(Vector2f movimiento) 
{
	mira_s.setPosition(movimiento);
}
void Jugador1::traspdisp()
{
	sonido.setVolume(40);
	sonido.play();
}
#ifndef GAME_H
#define GAME_H

namespace Game
{
	enum Estado
	{
		juego,
		menu,
		creditos

	};

	extern int screenWidth;
	extern int screenHeight;

	void ejecutarJuego();
}

#endif

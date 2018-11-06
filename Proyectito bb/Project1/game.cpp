#include "game.h"

#include "raylib.h"
#include "gameplay.h"

namespace Game
{
	bool inGame;

	Estado estado = juego;
	Estado estadoA = juego;

	int screenWidth = 900;
	int screenHeight = 600;

	void cambiarEstado()
	{
		if (estado != estadoA)
		{
			estadoA = estado;
		}
	}

	void chequearInputJuego()
	{
		switch (estado)
		{
		case juego:
			Gameplay::chequearInputGP();
			break;
		case menu:
			break;
		case creditos:
			break;
		default:
			break;
		}
	}

	void actualizarJuego()
	{
		switch (estado)
		{
		case juego:
			if (estado != estadoA)
			{
				//Gameplay::inicializarGameplay();
			}
			Gameplay::actualizarGP();
			break;
		}
	}

	void dibujarJuego()
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		switch (estado)
		{
		case juego:
			Gameplay::dibujarGP();
			break;
		}
		EndDrawing();
	}

	void inicializarJuego()
	{
		inGame = true;
		InitWindow(screenWidth, screenHeight, "Algebra");
		SetExitKey(KEY_ESCAPE);
		Gameplay::inicializarGameplay();
	}

	void finalizarJuego()
	{
		CloseWindow();
	}

	void ejecutarJuego()
	{
		inicializarJuego();

		while (inGame)
		{
			cambiarEstado();
			chequearInputJuego();
			actualizarJuego();
			dibujarJuego();

			if (WindowShouldClose())
			{
				inGame = false;
			}
		}

		finalizarJuego();
	}
}
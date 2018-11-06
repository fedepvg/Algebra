#include "gameplay.h"

#include "raylib.h"
#include "game.h"

namespace Game
{
	namespace Gameplay
	{
		struct Personaje
		{
			Rectangle sprite;
			Rectangle colliders[4];
		};

		const int cantRecs = 4;
		Personaje rec[cantRecs];
		Rectangle enemigo;
		bool puedeMoverse;
		static bool permitirMovimiento();

		void inicializarGameplay()
		{
			for (int i = 0; i < cantRecs; i++)
			{
				rec[i].sprite.width = 40;
				rec[i].sprite.height = 40;
				if (i > 0)
				{
					rec[i].sprite.x = screenWidth / 2 - rec[i].sprite.width / 2+i*80;
					rec[i].sprite.y = screenHeight / 2 - rec[i].sprite.height / 2;
				}
				else
				{
					rec[i].sprite.x = screenWidth / 2 - rec[i].sprite.width / 2 ;
					rec[i].sprite.y = screenHeight / 2 - rec[i].sprite.height / 2 ;
				}


			}

			enemigo.height = 40;
			enemigo.width = 40;
			enemigo.x = screenWidth / 2 - enemigo.width / 2;
			enemigo.y = screenHeight / 3;

			puedeMoverse = true;
		}

		void chequearInputGP()
		{
			float vel = 400.0f;
			if (permitirMovimiento())
			{
				for (int i = 0; i < cantRecs; i++)
				{
					if (IsKeyDown(KEY_UP))
					{
						rec[i].sprite.y -= vel * GetFrameTime();
					}
					if (IsKeyDown(KEY_DOWN))
					{
						rec[i].sprite.y += vel * GetFrameTime();
					}
					if (IsKeyDown(KEY_RIGHT))
					{
						rec[i].sprite.x += vel * GetFrameTime();
					}
					if (IsKeyDown(KEY_LEFT))
					{
						rec[i].sprite.x -= vel * GetFrameTime();
					}
				}
			}
		}

		static Rectangle dondeColisiono()
		{
			for (int i = 0; i < cantRecs; i++)
			{
				for (int j = 0; j < cantRecs; j++)
				{
					if (CheckCollisionRecs(rec[i].colliders[j], enemigo))
					{
						return rec[i].colliders[j];
					}
				}
			}
		}

		static bool permitirMovimiento()
		{
			
			return puedeMoverse;
		}

		void actualizarGP()
		{
			permitirMovimiento();
		}

		void dibujarGP()
		{
			for (int i = 0; i < cantRecs; i++)
			{
				DrawRectangleRec(rec[i].sprite, DARKGREEN);
			}
			DrawRectangleRec(enemigo, BLACK);
		}
	}
}
#include <iostream>
#include "../SDL/include/SDL.h"
#pragma comment(lib, "../SDL/libx86/SDL2.lib")
#pragma comment(lib, "../SDL/libx86/SDL2main.lib")

using namespace std;
int main(int argv, char *argc[])
{
	int op1 = 0, op2 = 0;
	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "Video initialization error." << SDL_GetError() << endl;
		return 1;
	}
	else
	{
		window = SDL_CreateWindow("Red Square", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
		if (window == nullptr)
		{
			cout << "Window creation error." << SDL_GetError() << endl;
			return 1;
		}
		else
		{
			SDL_Rect rectangle;
			rectangle.x = 100;
			rectangle.y = 100;
			rectangle.w = 120;
			rectangle.h = 120;
			SDL_Rect bullet;
			bullet.x = rectangle.x + 120;
			bullet.y = rectangle.y - 60;
			bullet.w = 35;
			bullet.h = 10;

			renderer = SDL_CreateRenderer(window, -1, 0);
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
			SDL_RenderClear(renderer);

			bool loop = true;
			bool bulletaux = NULL;
			while (loop)
			{
				SDL_Event event;
				if (SDL_PollEvent(&event) != 0)
				{
					switch (event.type)
					{
					case SDL_QUIT:
						loop = false;
						break;
					case SDL_KEYDOWN:
						switch (event.key.keysym.sym) {
						case SDLK_SPACE:
							bulletaux = true;
							bullet.x = rectangle.x + 120;
							bullet.y = rectangle.y +50;
							break;
						case SDLK_UP:
							rectangle.y -= 11;
							break;
						case SDLK_DOWN:
							rectangle.y += 11;
							break;
						case SDLK_RIGHT:
							rectangle.x += 11;
							break;
						case SDLK_LEFT:
							rectangle.x -= 11;
							break;

						}
					}

				}
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
				SDL_RenderFillRect(renderer, &rectangle);
				SDL_RenderPresent(renderer);
				if (bulletaux) {
					SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
					SDL_RenderFillRect(renderer, &bullet);
					SDL_RenderPresent(renderer);
					bullet.x += 10;
					if (bullet.x >= 640) {
						bulletaux = false;
					}
					SDL_Delay(2);
				}
				SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
				SDL_RenderClear(renderer);

				
			}
		}
	}
	return 0;
}
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

			SDL_Rect bullet[5];
			for (int i = 0; i < 5; i++) {
				bullet[i].x = NULL;
				bullet[i].y = NULL;
				bullet[i].w = NULL;
				bullet[i].h = NULL;
			}
			renderer = SDL_CreateRenderer(window, -1, 0);
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
			SDL_RenderClear(renderer);

			int bulletnum = 0;
			bool loop = true;
			bool bulletaux = false;
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
							switch (bulletnum) {
							case 0:
								bullet[0].x = rectangle.x + 120;
								bullet[0].y = rectangle.y +50;
								bullet[0].w = 35;
								bullet[0].h = 10;
								bulletnum++;
								break;
							case 1:
								bullet[1].x = rectangle.x + 120;
								bullet[1].y = rectangle.y + 50;
								bullet[1].w = 35;
								bullet[1].h = 10;
								bulletnum++;
								break;
							case 2:
								bullet[2].x = rectangle.x + 120;
								bullet[2].y = rectangle.y + 50;
								bullet[2].w = 35;
								bullet[2].h = 10;
								bulletnum++;
								break;
							case 3:
								bullet[3].x = rectangle.x + 120;
								bullet[3].y = rectangle.y + 50;
								bullet[3].w = 35;
								bullet[3].h = 10;
								bulletnum++;
								break;
							case 4:
								bullet[4].x = rectangle.x + 120;
								bullet[4].y = rectangle.y + 50;
								bullet[4].w = 35;
								bullet[4].h = 10;
								bulletnum=0;
								break;
						}
							break;
						case SDLK_UP:
							rectangle.y -= 11;
							if (rectangle.y <= 0) {
								rectangle.y = 0;
							}
							break;
						case SDLK_DOWN:
							rectangle.y += 11;
							if (rectangle.y > 360) {
								rectangle.y = 360;
							}	
							break;
						case SDLK_RIGHT:
							rectangle.x += 11;
							if (rectangle.x > 520) {
								rectangle.x = 520;
							}
							break;
						case SDLK_LEFT:
							rectangle.x -= 11;
							if (rectangle.x < 0) {
								rectangle.x = 0;
							}
							break;
							

						}
					}

				}
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
				SDL_RenderFillRect(renderer, &rectangle);
				SDL_RenderPresent(renderer);

				if (bulletaux) {
					for (int i = 0; i < 5; i++) {
						SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
						SDL_RenderFillRect(renderer, &bullet[i]);
						SDL_RenderPresent(renderer);
						bullet[i].x += 10;
					}
					SDL_Delay(10);
				}
				
				SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
				SDL_RenderClear(renderer);

				
			}
		}
	}
	return 0;
}
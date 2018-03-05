#include <iostream>
#include "../SDL/include/SDL.h"
#include "../SDL_Image/include/SDL_image.h"
#pragma comment(lib, "../SDL/libx86/SDL2.lib")
#pragma comment(lib, "../SDL/libx86/SDL2main.lib")
#pragma comment(lib, "../SDL_image/libx86/SDL2_image.lib")
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

using namespace std;
int main(int argv, char *argc[])
{
	int op1 = 0, op2 = 0, i = 0;
	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;
	SDL_Init(SDL_INIT_VIDEO);

	int imgFlags = IMG_INIT_PNG;

	window = SDL_CreateWindow("Red Square", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
		
			SDL_Rect rectangle;
			rectangle.x = 100;
			rectangle.y = 100;
			rectangle.w = 70;
			rectangle.h = 70;

			SDL_Rect bullet[5];
			for (int i = 0; i < 5; i++) {
				bullet[i].x;
				bullet[i].y;
				bullet[i].w = 15;
				bullet[i].h = 8;
			}

			renderer = SDL_CreateRenderer(window, -1, 0);
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
			SDL_RenderClear(renderer);

			int bulletnum = 0;
			bool loop = true;
			bool bulletaux = false;
			bool Moveup = false;
			bool Movedown = false;
			bool Moveright = false;
			bool Moveleft = false;

			while (loop)
			{
				SDL_Event event;
				if (SDL_PollEvent(&event) != 0)
				{
					if (event.type == SDL_QUIT) {
						loop = false;
					}

					if (event.type == SDL_KEYDOWN) {

						if (event.key.keysym.sym == SDLK_SPACE) {
							bulletaux = true;
							bullet[bulletnum].x = (rectangle.x) + (rectangle.w);
							bullet[bulletnum].y = (rectangle.y) + ((rectangle.h) / 2 - bullet->h);
							bulletnum++;
							if (bulletnum == 5) {
								bulletnum = 0;
							}
						}

						if (event.key.keysym.sym == SDLK_UP) {
							Moveup = true;
						}
						if (event.key.keysym.sym == SDLK_DOWN) {
							Movedown = true;
						}
						if (event.key.keysym.sym == SDLK_RIGHT) {
							Moveright = true;
						}
						if (event.key.keysym.sym == SDLK_LEFT) {
							Moveleft = true;
						}
					}

					if (event.key.keysym.sym == SDLK_ESCAPE) {
						loop = false;
					}


					if (event.type == SDL_KEYUP) {

						if (event.key.keysym.sym == SDLK_UP) {
							Moveup = false;
						}
						if (event.key.keysym.sym == SDLK_DOWN) {
							Movedown = false;
						}
						if (event.key.keysym.sym == SDLK_RIGHT) {
							Moveright = false;
						}
						if (event.key.keysym.sym == SDLK_LEFT) {
							Moveleft = false;
						}
					}
				}
					

					//definir bordes
					if (rectangle.x > WINDOW_WIDTH - rectangle.w) {
						rectangle.x = WINDOW_WIDTH - rectangle.w;
					}
					if (rectangle.x < 0) {
						rectangle.x = 0;
					}
					if (rectangle.y > WINDOW_HEIGHT - rectangle.h) {
						rectangle.y = WINDOW_HEIGHT - rectangle.h;
					}
					if (rectangle.y < 0) {
						rectangle.y = 0;
					}


				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
				SDL_RenderFillRect(renderer, &rectangle);
				if (bulletaux) {
					for (int i = 0; i < 5; i++) {
						SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
						SDL_RenderFillRect(renderer, &bullet[i]);
						bullet[i].x += 20;
					}
				}		
					
				if (Moveup == true) {
					rectangle.y -= 11;
				}
				if (Movedown == true) {
					rectangle.y = rectangle.y + 11;
				}
				if (Moveright == true) {
					rectangle.x = rectangle.x + 11;
				}
				if (Moveleft == true) {
					rectangle.x = rectangle.x - 11;
				}
				SDL_RenderPresent(renderer);
				SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
				SDL_RenderClear(renderer);

				SDL_Delay(20);
			}

			SDL_DestroyWindow(window);

	return 0;
}
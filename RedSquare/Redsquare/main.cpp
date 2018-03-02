#include <iostream>
#include "../SDL/include/SDL.h"
#pragma comment(lib, "../SDL/libx86/SDL2.lib")
#pragma comment(lib, "../SDL/libx86/SDL2main.lib")

using namespace std;
int main(int argv, char *argc[])
{
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
			rectangle.x = 240;
			rectangle.y = 180;
			rectangle.w = 120;
			rectangle.h = 120;

			renderer = SDL_CreateRenderer(window, -1, 0);
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
			SDL_RenderClear(renderer);
			bool loop = true;

			while (loop)
			{
				SDL_Event event;
				if (SDL_PollEvent(&event) != 0)
				{
					switch (event.type)
					{
					case SDL_QUIT:
						loop = false;
					}
				}
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
				SDL_RenderFillRect(renderer, &rectangle);
				SDL_RenderPresent(renderer);

				SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
				SDL_RenderClear(renderer);
				if (rectangle.x <= 360) {
					rectangle.x++;
					if (rectangle.x == 360) {
						rectangle.x = 0;
					}
				}
				SDL_Delay(5);
			}
		}
	}
	return 0;
}
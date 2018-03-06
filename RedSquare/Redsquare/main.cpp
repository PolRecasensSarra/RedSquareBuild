#include <iostream>
#include "../SDL/include/SDL.h"
#include "../SDL_Image/include/SDL_image.h"
#include "../SDL_Mixer/include/SDL_mixer.h"
#pragma comment(lib, "../SDL/libx86/SDL2.lib")
#pragma comment(lib, "../SDL/libx86/SDL2main.lib")
#pragma comment(lib, "../SDL_image/libx86/SDL2_image.lib")
#pragma comment(lib, "../SDL_Mixer/libx86/SDL2_mixer.lib")
const int WINDOW_WIDTH = 1040;
const int WINDOW_HEIGHT = 680;

SDL_Texture* loadTexture(std::string path);
SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;
SDL_Texture* background;
SDL_Texture* meliodas;
SDL_Texture* fullcounter;

SDL_Texture* loadTexture(std::string path) {
	SDL_Texture* newTexture;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);
	return newTexture;
}











int main(int argv, char *argc[])
{
	int op1 = 0, op2 = 0, i = 0, volum = 64;
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
	window = SDL_CreateWindow("Red Square", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1040, 680, SDL_WINDOW_SHOWN);
	int imgFlags = IMG_INIT_PNG;
	Mix_Init(MIX_INIT_OGG);
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048);
	Mix_VolumeMusic(15);
	Mix_Music* bgMusic;
	Mix_Chunk* fullcounterFx;

	SDL_Rect* rectangle = new SDL_Rect;
			rectangle->x = 100;
			rectangle->y = 100;
			rectangle->w = 150;
			rectangle->h = 130;

			SDL_Rect* bullet[5];
			for (int i = 0; i < 5; i++) {
				bullet[i]= new SDL_Rect;
				bullet[i]->x= (rectangle->x) + (rectangle->w)-60;
				bullet[i]->y= (rectangle->y)-(rectangle->h/3);
				bullet[i]->w = 200;
				bullet[i]->h = 100;
			}

			renderer = SDL_CreateRenderer(window, -1, 0);

			int bulletnum = 0;
			bool loop = true;
			bool bulletaux = false;
			bool Moveup = false;
			bool Movedown = false;
			bool Moveright = false;
			bool Moveleft = false;

			background = loadTexture("../Game/Background1.png");
			meliodas = loadTexture("../Game/meliodas.png");
			fullcounter = loadTexture("../Game/fullcounter.png");
			bgMusic = Mix_LoadMUS("../Game/bgMusic.ogg");
			fullcounterFx = Mix_LoadWAV("../Game/fullcounterFx.ogg");
			Mix_VolumeChunk(fullcounterFx, volum);
			
			Mix_PlayMusic(bgMusic, 1);

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
							
								bullet[bulletnum]->x = (rectangle->x) + (rectangle->w)-60;
								bullet[bulletnum]->y = (rectangle->y) - (rectangle->h / 3);
								bulletnum++;
								bulletaux = true;
								Mix_PlayChannel(-1, fullcounterFx, 0);
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
					
					if (rectangle->x > WINDOW_WIDTH - rectangle->w) {
						rectangle->x = WINDOW_WIDTH - rectangle->w;
					}
					if (rectangle->x < 0) {
						rectangle->x = 0;
					}
					if (rectangle->y > WINDOW_HEIGHT - rectangle->h) {
						rectangle->y = WINDOW_HEIGHT - rectangle->h;
					}
					if (rectangle->y < 0) {
						rectangle->y = 0;
					}

				SDL_RenderCopy(renderer, background, 0, 0);
				SDL_RenderCopy(renderer, meliodas, 0, rectangle);
				if (bulletaux) {
					for (int i = 0; i < 5; i++) {
						SDL_RenderCopy(renderer, fullcounter, 0, bullet[i]);
						bullet[i]->x += 20;
					}                                                               
				}
				if (Moveup == true) {
					rectangle->y -= 7;
				}
				if (Movedown == true) {
					rectangle->y = rectangle->y + 7;
				}
				if (Moveright == true) {
					rectangle->x = rectangle->x + 7;
				}
				if (Moveleft == true) {
					rectangle->x = rectangle->x - 7;
				}

				SDL_RenderPresent(renderer);
			
				
				

				SDL_Delay(25);
			}
			SDL_Quit();
			IMG_Quit();
			Mix_Quit();
			SDL_DestroyWindow(window);
	return 0;
}
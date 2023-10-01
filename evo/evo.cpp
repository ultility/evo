// evo.cpp : Defines the entry point for the application.
//

#include "evo.h"
#define MSG(x) std::cout << x << std::endl;

SDL_Window* window;
SDL_Renderer* renderer;
int main(int argc, char* argv[])
{
	/*if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		MSG("error: " << SDL_GetError() << "at line " << __LINE__);
		exit(1);
	}
	window = SDL_CreateWindow("evo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
	if (window == NULL)
	{
		MSG("error: " << SDL_GetError() << "at line " << __LINE__);
		exit(1);
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		MSG("error: " << SDL_GetError() << "at line " << __LINE__);
		exit(1);
	}
	bool run = true;
	SDL_Event event;
	while (run)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			switch (event.type)
			{
			case SDL_QUIT:
				run = false;
				break;
			}
		}
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();*/

	DNA d(50);
	MSG(d.GetSequence());
	for (int i = 0; i < 10; i++)
	{
		MSG(i)
		Sequence test;
		test.length = d.GetLength();
		test.Sequence = d.GetSequence();
		DNA::MutateSequence(test);
		d = DNA(test.Sequence, test.Sequence.length());
		MSG(d.GetSequence());
	}
	return 0;
}

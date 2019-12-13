#include <iostream>
#include <string>
#include "shapes.h"
#include <vector>
#include "SDL.h"
#undef main
#include <stdlib.h>
#include <time.h>

using namespace std;

void testRendering(vector<shape*> shapes,SDL_Renderer* renderer) {
	int size, count=0;
	size = shapes.size();
	while (size > count) {
		shapes[count]->render(renderer);
		count++;
	}
}

/*
int main() {
	rectangle rec(0, 0, 0, 0, 0, 0, 0, 0);
	triangle tri(0, 0, 0, 0, 0, 0, 0, 0);
	circle cir(0, 0, 0, 0, 0, 0, 0);
	vector<shape*> shapes;
	shapes.resize(3);
	shapes[0] = &rec;
	shapes[1] = &tri;
	shapes[2] = &cir;
	testRendering(shapes);
	system("pause");
	return 0;
}
*/

int main() {
	float x_pos, y_pos;
	double radius, base, height, width;
	int red, green, blue, alpha;
	char input_char=0;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Rendering", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	srand(time(0));
	SDL_Delay(5000);

	vector<shape*> shapes;
	
	while (1) {
		cout << "\n\n+--------+\n|  MENU  |\n+--------+\n\nc : Circle\nr : Rectangle\nt : Triangle\nx : Remove all shapes\nq : Quit\n\n";
		cin >> input_char;
		x_pos = rand() % 400 + 50;
		y_pos = rand() % 250 + 50;
		radius = rand() % 49 + 1;
		base = rand() % 99 + 1;
		height = rand() % 49 + 1;
		width = rand() % 99 + 1;
		red = rand() % 256;
		green = rand() % 256;
		blue = rand() % 256;
		alpha = rand() % 256;
		switch (input_char) {
		case 'c':
			shapes.push_back(&circle(x_pos, y_pos, red, green, blue, alpha, radius));
			break;
		case 'r':
			shapes.push_back(&rectangle(x_pos, y_pos, red, green, blue, alpha, width, height));
			break;
		case 't':
			shapes.push_back(&triangle(x_pos, y_pos, red, green, blue, alpha, base, height));
			break;
		case 'x':
			shapes.resize(0);
			break;
		case'q':
			return 0;
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		
		testRendering(shapes, renderer);
		SDL_RenderPresent(renderer);
		SDL_Delay(1000);

	}
}
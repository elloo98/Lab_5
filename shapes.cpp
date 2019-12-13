#include <iostream>
#include <string>
#include "shapes.h"
#include "SDL.h"

//Point2D
Point2D::Point2D() {
	x = 0;
	y = 0;
}

Point2D::Point2D(float nx, float ny) {
	x = nx;
	y = ny;
}

void Point2D::setx(float set_x) {
	x = set_x;
}

void Point2D::sety(float set_y) {
	y = set_y;
}

float Point2D::getx() {
	return x;
}

float Point2D::gety() {
	return y;
}

string Point2D::toString() {
	string output = "[";
	output = output + to_string(x) + "," + to_string(y) + "]\n";
	return output;
}

float Point2D::distanceBetween(Point2D otherPoint) {
	//Chosen because of pythagoran theorem
	float A = x - otherPoint.x;
	float B = y - otherPoint.y;
	float C;
	C = sqrt(pow(A, 2) + pow(B, 2));
	return C;
}


//Shape
shape::shape() {
	Point2D point;
	RGBA[0] = RGBA[1] = RGBA[2] = RGBA[3] = 0;
	point.setx(0);
	point.sety(0);
}

shape::shape(float x_pos, float y_pos, int red, int green, int blue, int alpha) {
	if (red < 256 && 0 <= red && green < 256 && 0 <= green && blue < 256 && 0 <= blue && alpha < 256 && 0 <= alpha) {
		RGBA[0] = red;
		RGBA[1] = green;
		RGBA[2] = blue;
		RGBA[3] = alpha;
		position.setx(x_pos);
		position.sety(y_pos);
	}
}

void shape::render(SDL_Renderer* renderer) {
	cout << "draws a generic shape\n";
}


//Rectangle
rectangle::rectangle(float pos_x, float pos_y, int red, int green, int blue, int alpha, double width, double height) :shape(pos_x, pos_y, red, green, blue, alpha), width(width), height(height) {

}

float rectangle::getWidth() {
	return width;
}

float rectangle::getHeight() {
	return height;
}

void rectangle::setWidth(float nw) {
	width = nw;
}

void rectangle::setHeight(float nh) {
	height = nh;
}

void rectangle::render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
	SDL_RenderDrawLine(renderer, shape::position.getx(), shape::position.gety(), shape::position.getx() + width, shape::position.gety());
	SDL_RenderDrawLine(renderer, shape::position.getx()+width, shape::position.gety(), shape::position.getx() + width, shape::position.gety()+height);
	SDL_RenderDrawLine(renderer, shape::position.getx()+width, shape::position.gety()+height, shape::position.getx(), shape::position.gety()+height);
	SDL_RenderDrawLine(renderer, shape::position.getx(), shape::position.gety()+height, shape::position.getx(), shape::position.gety());
	
	
}


//Triangle
triangle::triangle(float pos_x, float pos_y, int red, int green, int blue, int alpha, double base, double height) :shape(pos_x, pos_y, red, green, blue, alpha), base(base), height(height) {

}

float triangle::getBase() {
	return base;
}

float triangle::getHeight() {
	return height;
}

void triangle::setBase(float nb) {
	base = nb;
}

void triangle::setHeight(float nh) {
	height = nh;
}

void triangle::render(SDL_Renderer* renderer) {
	int x = shape::position.getx();
	int y = shape::position.gety();
	SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
	SDL_RenderDrawLine(renderer, shape::position.getx()+base/2, shape::position.gety(), shape::position.getx() + base, shape::position.gety()+height);
	SDL_RenderDrawLine(renderer, shape::position.getx() + base, shape::position.gety()+height, shape::position.getx(), shape::position.gety()+height);
	SDL_RenderDrawLine(renderer, shape::position.getx(), shape::position.gety()+height, shape::position.getx() + base/2, shape::position.gety());
}


//Circle
circle::circle(float pos_x, float pos_y, int red, int green, int blue, int alpha, double radius) :shape(pos_x, pos_y, red, green, blue, alpha), radius(radius) {

}

float circle::getRadius() {
	return radius;
}

void circle::setRadius(float nr) {
	radius = nr;
}

void circle::render(SDL_Renderer* renderer) {
	int theta = 1;
	int h = shape::position.getx();
	int k = shape::position.gety();
	int oldx = h + radius;
	int oldy = k;
	int x;
	int y;
	while (theta <= 360) {
		x = h + radius * cos(theta);
		y = k + radius * sin(theta);
		SDL_RenderDrawLine(renderer, oldx, oldy, x, y);
		oldx = x;
		oldy = y;
		theta++;
	}
}
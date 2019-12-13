#pragma once
#pragma once
#pragma once
#include <iostream>
#include <string>
#include "SDL.h"

using namespace std;

class Point2D {
public:
	Point2D();
	Point2D(float nx, float ny);
	float distanceBetween(Point2D otherPoint);
	float getx();
	float gety();
	void setx(float set);
	void sety(float set);
	string toString();

private:
	float x;
	float y;
};


class shape {
public:
	Point2D position;
	int RGBA[4];
	shape();
	shape(float pos_x, float pos_y, int red, int green, int blue, int alpha);
	virtual void render(SDL_Renderer* render);
};


class rectangle : public shape {
private:
	float width;
	float height;
	int red;
	int green;
	int blue;
	int alpha;
public:
	rectangle(float pos_x, float pos_y, int red, int green, int blue, int alpha, double width, double height);
	float getWidth();
	float getHeight();
	void setWidth(float n_width);
	void setHeight(float n_height);
	void render(SDL_Renderer* renderer);
};


class triangle : public shape {
private:
	float base;
	float height;
	int red;
	int green;
	int blue;
	int alpha;
public:
	triangle(float pos_x, float pos_y, int red, int green, int blue, int alpha, double base, double height);
	float getBase();
	float getHeight();
	void setBase(float n_base);
	void setHeight(float n_height);
	void render(SDL_Renderer* renderer);
};


class circle : public shape {
private:
	float radius;
	int red;
	int green;
	int blue;
	int alpha;
public:
	circle(float pos_x, float pos_y, int red, int green, int blue, int alpha, double radius);
	float getRadius();
	void setRadius(float n_rad);
	void render(SDL_Renderer* renderer);
};
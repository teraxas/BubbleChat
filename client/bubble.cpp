#include "bubble.h"
#include <iostream>

Bubble::Bubble() {
}

Point Bubble::getPos() const {
	return pos;
}

void Bubble::setPos(Point _pos) {
	pos = _pos;	
}

int Bubble::getID()
{
	return id;
}

void Bubble::setID(int _id)
{
	id = _id;
}

void Bubble::setName(std::string name) {
	this->name = name;
}

std::string Bubble::getName()
{
	return this->name;
}

void Bubble::setDir(Point dir) {
	this->dir = dir;
}

Point Bubble::getDir(){
	return this->dir;
}

void Bubble::progress(int time) {
	pos.x += SPEED * time * dir.x / 1000;
	const int MAX_W = 640-64, MAX_H = 480-64;
	pos.x = (pos.x < 0 ? 0 : pos.x > MAX_W ? MAX_W : pos.x);
	pos.y += SPEED * time * dir.y / 1000;
	pos.y = (pos.y < 0 ? 0 : pos.y > MAX_H ? MAX_H : pos.y);
}

void Bubble::say(std::string message) {
	std::cout << name << ": " << message << std::endl;
}

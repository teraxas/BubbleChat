#include "display.h"

#include "world.h"//TODO: move loading

void Display::init(bool fullscreen, int width, int height) {
	SDL_Init(SDL_INIT_VIDEO);
	Uint32 flags = SDL_DOUBLEBUF;//SDL_SWSURFACE | SDL_DOUBLEBUF;
	if (fullscreen)
		flags |= SDL_FULLSCREEN;
	if (width == -1 || height == -1) {
		const SDL_VideoInfo *info = SDL_GetVideoInfo();
		width = info->current_w;
		height = info->current_h;
	} 
	screenSurface = SDL_SetVideoMode(width, height, 32, flags);

	bubbleSurface = SDL_LoadBMP("data/bubble.bmp");
	World world;
	worldSurface = world.getSurface();
	SDL_Rect rect;
	rect.x = rect.y = 0;;
	rect.w = screenSurface->w;
	rect.h = screenSurface->h;
	clean(rect);
}

void Display::draw(SDL_Surface *image, Sint16 x, Sint16 y) {
	SDL_Rect rSrc, rDst;
	rSrc.w = rDst.w = image->w;
	rSrc.h = rDst.h = image->h;
	rSrc.x = rSrc.y = 0;
	rDst.x = x;
	rDst.y = y;
	SDL_BlitSurface(image, &rSrc, screenSurface, &rDst);
}

void Display::draw(SDL_Surface *image, Point p) {
	draw(image, p.x, p.y);
}

void Display::clean(SDL_Rect &rect) {
	SDL_BlitSurface(worldSurface, &rect, screenSurface, &rect);
}

void Display::cleanBubble(const Bubble &bubble) {
	SDL_Rect rect;
	Point pos = bubble.getPos();
	rect.x = pos.x;
	rect.y = pos.y;
	rect.w = bubbleSurface->w;
	rect.h = bubbleSurface->h;
	clean(rect);
}

void Display::drawBubble(const Bubble &bubble) {
	draw(bubbleSurface, bubble.getPos());
}

void Display::progress() {
	SDL_Flip(screenSurface);
}
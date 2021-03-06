#include <stdlib.h>
#include <SDL2/SDL.h>

#include "canvas.h"
#include "types.h"
#include "vector.h"

Canvas *canvas_init(uint width, uint height, uint viewport_width, uint viewport_height)
{
    Canvas *canvas = malloc(sizeof(Canvas));
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
    canvas->window = window;
    canvas->renderer = renderer;
    canvas->width = width;
    canvas->height = height;
    canvas->viewport_width = viewport_width;
    canvas->viewport_height = viewport_height;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    return canvas;
}

void *canvas_destroy(Canvas *self)
{
    SDL_DestroyRenderer(self->renderer);
    SDL_DestroyWindow(self->window);
    free(self);
}

void *canvas_draw(Canvas *self, uint x, uint y, byte r, byte g, byte b)
{
    SDL_SetRenderDrawColor(self->renderer, r, g, b, 255);
    SDL_RenderDrawPoint(self->renderer, x, y);
}

void *canvas_display(Canvas *self)
{
    SDL_RenderPresent(self->renderer);
}

Vector *canvas_to_viewport(Canvas *self, int canvas_x, int canvas_y, int distance)
{
    canvas_x -= self->width / 2;
    canvas_y -= self->height / 2;
    double viewport_x = (double) canvas_x * self->viewport_width / self->width;
    double viewport_y = (double) canvas_y * self->viewport_height / self->height;
    return vector_init(viewport_x, viewport_y, distance);
}

#include <SDL2/SDL.h>

#include "types.h"
#include "vector.h"

typedef struct
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    uint width;
    uint height;
    uint viewport_width;
    uint viewport_height;
} Canvas;

Canvas *canvas_init(uint width, uint height, uint viewport_width, uint viewport_height);
void *canvas_destroy(Canvas *self);
void *canvas_draw(Canvas *self, uint x, uint y, byte r, byte g, byte b);
void *canvas_display(Canvas *self);
Vector *canvas_to_viewport(Canvas *self, int canvas_x, int canvas_y, int distance);

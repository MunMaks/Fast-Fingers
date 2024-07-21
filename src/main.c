#include <SDL2/SDL.h>
// #include <MLV/all.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO); // Initialize SDL2

    SDL_Window *window = SDL_CreateWindow("SDL2 Example",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          640, 480, 0);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Set draw color to red
    SDL_RenderClear(renderer); // Clear the window with the current draw color

    SDL_RenderPresent(renderer); // Update the window

    SDL_Delay(3000); // Wait for 3 seconds

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

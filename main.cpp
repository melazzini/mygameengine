#include <iostream>
#include "include/ImagePrimitiveSdl.hpp"
#include "include/Image.hpp"
#include "include/Renderer.hpp"
#include <SDL2/SDL.h>

using namespace std;

int main(int argc, char *argv[])
{
    ImagePrimitiveSdl imagePrimitive;
    RenderEngine renderEngine;
    Renderer r{&renderEngine};
    ImageLoader loader{&r};

    Image image{&imagePrimitive, loader, boost::uuids::uuid()};

    image.setImage("/home/francisco/Projects/gameEngines/mygameengine/assets/images/rock-big-3.png");

    auto renderer = r.engine()->backendEngine();

    SDL_Rect rect;
    rect.h = 40;
    rect.w = 40;
    rect.x = rect.y = 30;

    auto isRunning = true;
    while (isRunning)
    {
        SDL_Event evt;
        while (SDL_PollEvent(&evt))
        {
            if (evt.type == SDL_KEYDOWN && evt.key.keysym.sym == SDLK_ESCAPE)
            {
                isRunning = false;
            }
            else if (evt.type == SDL_WINDOWEVENT && evt.window.event == SDL_WINDOWEVENT_CLOSE)
            {
                isRunning = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 101, 101, 130, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 200, 201, 10, 255);
        SDL_RenderFillRect(renderer, &rect);

        r.render(&image);

        SDL_RenderPresent(renderer);
    }

    cout << "Hello world!" << endl;

    return 0;
}
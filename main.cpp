#include <iostream>
#include <SDL2/SDL.h>

#include "include/ImagePrimitiveSdl.hpp"
#include "include/Image.hpp"
#include "include/Renderer.hpp"
#include "include/Window.hpp"
#include "include/WindowPrimitiveSdl.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    WindowPrimitiveSdl wndPrimitive;
    ImagePrimitiveSdl imagePrimitive;
    RenderEngine renderEngine;
    Renderer r{&renderEngine};
    Window wnd{&wndPrimitive};
    ImageLoader loader{&r};

    Image image{&imagePrimitive, loader, boost::uuids::uuid(), Position{300, 100}};

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
            else if (evt.type == SDL_KEYDOWN && evt.key.keysym.sym == SDLK_RIGHT)
            {
                image.setPosition(image.position() + Position{10, 0});
            }
            else if (evt.type == SDL_KEYDOWN && evt.key.keysym.sym == SDLK_LEFT)
            {
                image.setPosition(image.position() + Position{-10, 0});
            }
            else if (evt.type == SDL_KEYDOWN && evt.key.keysym.sym == SDLK_UP)
            {
                image.setPosition(image.position() + Position{0, -10});
            }
            else if (evt.type == SDL_KEYDOWN && evt.key.keysym.sym == SDLK_DOWN)
            {
                image.setPosition(image.position() + Position{0, 10});
            }
        }

        r.clearWindow(&wnd, {200,110,10,200});

        SDL_SetRenderDrawColor(renderer, 210, 201, 10, 255);
        SDL_RenderFillRect(renderer, &rect);

        r.render(&image);

        r.present();
    }

    cout << "Hello world!" << endl;

    return 0;
}
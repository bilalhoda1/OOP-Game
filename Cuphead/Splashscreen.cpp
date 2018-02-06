#include "Splashscreen.h"

Splashscreen::Splashscreen()
{
    cout<<"splash ctor"<<endl;

}

void Splashscreen::Render(SDL_Renderer*r,LTexture*L)
{
    int c=255;//initialize the color
    cout<<"Render splash"<<endl;

    while (c>0)//Ensures the color gradually reaches black and fades away.
    {
        SDL_SetRenderDrawColor(r,0,0,0,0);
        SDL_RenderClear(r);//clear up screen
        L->SetColor(c,c,c);
        L->Render(0,0,NULL,0.0,NULL,SDL_FLIP_NONE,r);
        SDL_Delay(50);//a delay for one drop in color level
        c=c-6.375;//each time the color is reduced by 6.375 and multiplied over the image.
        SDL_RenderPresent(r);//Updates screen

    }


    //SDL_Delay(2000);

}
Splashscreen::~Splashscreen()
{
    cout<<"splash dtor"<<endl;
}

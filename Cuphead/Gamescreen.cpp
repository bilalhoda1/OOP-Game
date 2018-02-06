#include "Gamescreen.h"
Gamescreen::Gamescreen(LTexture*f,LTexture*bg)
{
    font=f;
    background=bg;
    pause=new button(&pauserect,"PAUSE",font,780,600,5);//dynamically creates the pause button

    cout<<"gamescreen ctor"<<endl;
}
Gamescreen::~Gamescreen()
{
    delete pause;
    cout<<"gamescreen dtor"<<endl;
}
void Gamescreen::Render_horizontal(SDL_Renderer*r,int scrollingOffset)
{
    //renders same texture twice but diff starting and end points as to give the illusion of moving bg.
    //cout<<"Scrolling offset here is: "<<scrollingOffset<<endl;

    SDL_SetRenderDrawColor( r, 0, 0, 0, 0 );
    SDL_RenderClear( r );
    background->Render( scrollingOffset, 0,NULL,0.0,NULL,SDL_FLIP_NONE, r );
    background->Render( scrollingOffset + background->GetWidth(), 0,NULL,0.0,NULL,SDL_FLIP_NONE,r );
    pause->Render(r);

    //SDL_RenderPresent(r);
}


void Gamescreen::Render_vertical(SDL_Renderer*r,LTexture*L,int scrollingOffset)
{
    SDL_SetRenderDrawColor( r, 0, 0, 0, 0 );
    SDL_RenderClear( r );

    L->Render( 0,scrollingOffset,NULL,0.0,NULL,SDL_FLIP_NONE, r );
    L->Render( 0,scrollingOffset + L->GetHeight(),NULL,0.0,NULL,SDL_FLIP_NONE,r );
     pause->Render(r);

     SDL_RenderPresent(r);
}
string Gamescreen::game_button_select(int x,int y)//links to the button check bounds as to allow checking which button is pressed.
{
    if(pause->checkbounds(x,y)==true)
    {
        return "pause";
    }
    else
    {
        return "";
    }
}

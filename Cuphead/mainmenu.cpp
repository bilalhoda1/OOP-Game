#include "mainmenu.h"

mainmenu::mainmenu(LTexture*BG,LTexture*Fonts)
{
    menu=BG;
    font=Fonts;
    play=new button(&playrect,"PLAY",font,450,320,4);
    load=new button(&loadrect,"LOAD",font,450,390,4);
    exit=new button(&exitrect,"EXIT",font,450,450,4);


    cout<<"Main screen ctor"<<endl;
}
void mainmenu::Render(SDL_Renderer*r)
{
    SDL_SetRenderDrawColor(r,0,0,0,0);
    SDL_RenderClear(r);
   menu->Render(0,0,NULL,0.0,NULL,SDL_FLIP_NONE,r);
   play->Render(r);
   load->Render(r);
   exit->Render(r);

}

mainmenu::~mainmenu()
{
    delete play;
    delete load;
    delete exit;
    cout<<"Main screen dtor"<<endl;
}

string mainmenu::menu_button_select(int x,int y)//links to the button check bounds as to allow checking which button is pressed.
{
    if (play->checkbounds(x,y)==true)
    {
        return "play";
    }
    else if (load->checkbounds(x,y)==true)
    {
        return "load";
    }
    else if(exit->checkbounds(x,y)==true)
    {
        return "exit";
    }
    else
    {
        return "";
    }
}

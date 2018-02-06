#include"Pausemenu.h"
Pausemenu::Pausemenu(LTexture*f)
{
    font=f;
    cout<<"pause menu ctor"<<endl;
    resume=new button(&resumerect,"RESUME",font,30,220,6);
    exit_pause=new button(&exitPauserect,"EXIT",font,820,220,4);
    return_menu=new button(&returnrect,"RETURN",font,30,320,6);
    save=new button(&saverect,"SAVE",font,820,320,4);

}

Pausemenu::~Pausemenu()
{
    delete resume;
    delete exit_pause;
    delete return_menu;
    delete save;
    cout<<"pause menu dtor"<<endl;
}

void Pausemenu::Render(SDL_Renderer*r,LTexture*L)
{
    SDL_SetRenderDrawColor(r,0,0,0,0);
    SDL_RenderClear(r);
    L->Render(0,0,NULL,0.0,NULL,SDL_FLIP_NONE,r);
    resume->Render(r);
    exit_pause->Render(r);
    return_menu->Render(r);
    save->Render(r);
    SDL_RenderPresent(r);
}
string Pausemenu::pause_button_select(int x,int y)//links to the button check bounds as to allow checking which button is pressed.

{
    if (save->checkbounds(x,y)==true)
    {
        return "save";
    }
    else if (return_menu->checkbounds(x,y)==true)
    {
        return "return";
    }
    else if(exit_pause->checkbounds(x,y)==true)
    {
        return "exit_pause";
    }
    else if(resume->checkbounds(x,y)==true)
    {
        return "resume";
    }
    else
    {
        return "";
    }
}

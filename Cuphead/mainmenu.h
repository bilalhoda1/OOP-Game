#ifndef MAINMENU_H
#define MAINMENU_H
#include<SDL.h>


#include"LTexture.h"
#include<iostream>
#include"button.h"

using namespace std;
class mainmenu
{
    public:
        ~mainmenu();
        mainmenu(LTexture*,LTexture*);
        void Render(SDL_Renderer*);
        string menu_button_select(int,int);

    protected:

    private:
        LTexture*menu;
        LTexture*font;
        SDL_Rect playrect={421,303,168,50};
        SDL_Rect loadrect={421,366,168,47};
        SDL_Rect exitrect={421,433,168,47};
        button*play;
        button*load;
        button*exit;


};

#endif // MAINMENU_H

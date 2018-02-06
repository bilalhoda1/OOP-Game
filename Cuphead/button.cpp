#include "button.h"


button::button(SDL_Rect* rect,string S,LTexture*fonts,int myx, int myy,int wordsize)
{
    cout<<"Button created"<<endl;
    x=myx;
    y=myy;
    this->button_rect = rect;
    button_word=new Word(wordsize,S,fonts,x,y);
}


//Render image
void button::Render(SDL_Renderer* gRenderer)
{
    SDL_RenderFillRect(gRenderer,button_rect);
    button_word->Render(gRenderer);
}


bool button::checkbounds(int xstate,int ystate)
{
    int x=button_rect->x;
    int y=button_rect->y;
    int w=button_rect->w;
    int h=button_rect->h;

    if((x<xstate)&&(xstate<(x+w))&&(ystate>y)&&(ystate<(y+h)))
    {
        return true;
    }
    else
    {
        return false;
    }
}
button::~button()
{
    delete button_word;
    cout<<"Button deleted"<<endl;
}

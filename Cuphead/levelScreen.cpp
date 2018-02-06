#include"levelScreen.h"
levelScreen::levelScreen(string levelname,int wordlength,LTexture*f)
{
    font=f;
    name_of_level=levelname;
    displaylevel=new Word(wordlength,levelname,font,350,300);
    cout<<"Level screen generated"<<endl;
}
levelScreen::~levelScreen()
{
    delete displaylevel;
    cout<<"level screen destroyed"<<endl;
}
void levelScreen::Render(SDL_Renderer*r)
{

    SDL_SetRenderDrawColor(r,0,0,0,0);
    SDL_RenderClear(r);
    SDL_SetRenderDrawColor(r,0,0,0,0);
    SDL_RenderDrawRect(r,&screensize);
    displaylevel->Render(r);
    SDL_RenderPresent(r);
    SDL_Delay(2000);

}

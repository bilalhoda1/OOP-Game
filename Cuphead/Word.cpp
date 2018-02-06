#include "Word.h"

Word::Word(int len,string S,LTexture*image,float x,float y)
{
    this->spritesFont=image;

    cout<<"Word created"<<endl;
    no_of_letters=len;
    word=new Character[no_of_letters];//dynamically created array of characters
    for(int i=0;i<no_of_letters;i++)//for each letter
    {
        char c=S[i];
        word[i]=Character(spritesFont,(x+(44*i)),y,c);//each letter is separated by 44, we could reduce it to make the letters closer.
        //y is constant as to get the letters on one line.

    }

}

void Word::Render(SDL_Renderer*r)
{

    for(int i=0;i<no_of_letters;i++)
    {
        word[i].Render(r,false);//renders each letter
    }

}

Word::~Word()
{
    delete word;
    cout<<"Word destroyed"<<endl;
}

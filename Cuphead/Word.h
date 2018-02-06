#ifndef WORD_H
#define WORD_H
#include<string.h>
#include<stdio.h>
#include<iostream>
#include"Character.h"

using namespace std;
class Word
{
    public:
        Word(int,string,LTexture*,float,float);
        ~Word();
        void Render(SDL_Renderer*);


    protected:

    private:
        int no_of_letters;
        Character*word;
        LTexture*spritesFont;

};

#endif // WORD_H

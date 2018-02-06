#include"Character.h"
#include<iostream>

Character::Character()
{
    width = 44;
    height = 48;
    character_value = 0;
}

Character::Character(LTexture* image, float x, float y,char text)
{
    spriteSheetTexture = image;//will read the sprite sheet

    spriteClips.w = 44;//w and h will not vary from char to char
    spriteClips.h = 48;
    int capital=toupper(text);//capital gives the ASCII value of the letter.
    character_value = capital-65;//this will lead to the start of the font texture sheet.
    if ((0<=character_value)&&(character_value<=10))
    {
        spriteClips.x=44*character_value;
        spriteClips.y=0;
    }
    else if((character_value>10)&&(character_value<=22))
    {
        spriteClips.x=44*(character_value%11);
        spriteClips.y=48*1;
    }
    else if((character_value>22)&&(character_value<=26))//only uppercase letters
    {
        spriteClips.x=44*(character_value%11);//for each 11 letters in one row
        spriteClips.y=48*2;
    }
    //Frame 0
    position.x = x;
    position.y = y;

    this->width = spriteClips.w;
    this->height = spriteClips.h;
}

Character::~Character()
{
    char n = character_value + 65;
    //cout<<"\nCharacter "<<n<<" Destroyed";
}

void Character::Render(SDL_Renderer* gRenderer, bool debug)
{

    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &spriteClips, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x - width/2, position.y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}

void Character::SetPosition(Point& position)
{
    this->position.x = position.x - width/2;
    this->position.y = position.y - height/2;
}

void Character::SetPosition(int x, int y)
{
    this->position.x = x - width/2;
    this->position.y = y - height/2;
}

int Character::GetFrameWidth()
{
    return width;
}
int Character::GetFrameHeight()
{
    return height;
}


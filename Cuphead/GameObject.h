#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Point.h"

using namespace std;

class Vector2;
class GameObject
{
protected:
    LTexture* spriteSheetTexture; //The pointer to use our texture class
    float x,y,width,height;  // Gives us the x and y values of our object along with its area
    int currentFrame;      // Tells us which frame the sprite is at
    int typeId;          // A unique identifier to tell us what type of child object is being used
    int ScreenWidth;
    int ScreenHeight;
    int lives;

public:
    SDL_Rect cRectangle;  // This is the intersection rectanlge we are making
    GameObject();
    virtual void Move();   // The move function
    virtual void Move(int direction);  //The move function in which direction
    virtual void Render(SDL_Renderer* gRenderer);    //The render function to draw
    virtual void Render(SDL_Renderer* gRenderer,int dir);   //The render function to draw with a direction
    virtual void SetFrame(int frame);          //Sets frame of the object
    virtual float Getx();        //Gets the x position
    virtual float Gety();        //Gets the y position
    virtual void SetType(int);   //Sets the type of object
    virtual int GetType();
    virtual  void Shooting(Vector2*);
    virtual int GetLives();
    virtual void SetLives(int);

           //Gets the type of the object
};

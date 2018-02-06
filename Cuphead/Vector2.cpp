#include "Vector2.h"

Vector2::Vector2()
{
    //ctor
}
Vector2::~Vector2()
{
    o.clear();
}


void Vector2::Render(SDL_Renderer* gRenderer,int dir)
{
    for (int j = 0; j < o.size(); j++ )
    {
        o[j]->Render(gRenderer,dir);

    }

}


void Vector2::Deallocate(int h,int w)
{
    if ((o.empty()==0&& o[0]->Gety()<-50) ||( o.empty()==0&&o[0]->Getx()>w) || (o.empty()==0&&o[0]->Getx()<-50) || (o.empty()==0&&o[0]->Gety()>h))
    {   cout<<"Deallocate"<<endl;
        o.erase(o.begin());
    }


}

void Vector2::Move()
{
    for (int j = 0; j < o.size(); j++ )
    {
        o[j]->Move();
    }
}

bool Vector2::Collision2(const SDL_Rect* a,const SDL_Rect *b)
{
    bool intersect;

	intersect=SDL_HasIntersection(a,b);


    return intersect;
}



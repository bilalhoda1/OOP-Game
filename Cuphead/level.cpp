#include "level.h"

Level::Level()
{
  //level_num=1;
}

Level::~Level()
{
    delete block;
    delete ghost;
    delete Minions;
    delete Minions1;
    delete Minions2;
    delete Minions3;
    delete Minions4;
    block=NULL;
    ghost=NULL;
    Minions=NULL;
    Minions1=NULL;
    Minions2=NULL;
    Minions3=NULL;
    Minions4=NULL;

}

Level::Level(Vector2* vectors,int level_num,LTexture* image,int w,int h )
{

    if (level_num==1)
    {   Boss* ghost= new Boss(image, float(275), float(150), w, h); //set
        Minion* Minions=new Minion(image, float(620),float(598),w,h); //set
        Minion* Minions1=new Minion(image, float(230),float(598),w,h); //set
        Minion* Minions2=new Minion(image, float(125),float(333),w,h); //set
        Minion* Minions3=new Minion(image, float(150),float(525),w,h);//set
        Minion* Minions4=new Minion(image, float(325),float(455),w,h);//set
        vectors->o.push_back(ghost);
        vectors->o.push_back(Minions);
        vectors->o.push_back(Minions1);
        vectors->o.push_back(Minions2);
        vectors->o.push_back(Minions3);
        vectors->o.push_back(Minions4);



         for(int i=10;i<990;i=i+30)
            {
                Platform* block = new Platform(image, float (i), float (625));
			    vectors->o.push_back(block);
            }
            for(int i=100;i<250;i=i+30)
            {
               Platform* block = new Platform(image, float (i), float (550));
			   vectors->o.push_back(block);
            }

            for(int i=290;i<490;i=i+30)
            {
                Platform* block = new Platform(image, float (i), float (480));
			    vectors->o.push_back(block);
            }
            for(int i=15;i<290;i=i+30)
            {
                Platform* block = new Platform(image, float (i), float (358));
			    vectors->o.push_back(block);
            }
             for(int i=800;i<990;i=i+30)
            {
               Platform* block = new Platform(image, float (i), float (527));
			   vectors->o.push_back(block);
            }
            for(int i=560;i<660;i=i+30)
            {
                Platform* block = new Platform(image, float (i), float (400));
			    vectors->o.push_back(block);
            }
            for(int i=730;i<820;i=i+30)
            {
                Platform* block = new Platform(image, float (i), float (310));
			    vectors->o.push_back(block);
            }

        cout<<"lol5"<<endl;
    }
    cout<<"lol6"<<endl;
    if (level_num==2)
    {
        block->SetFrame(1);
      Platform* block = new Platform(image, float (500), float (310));
    }
}


int Level::GetLevel()
{
    return this->level_num;
}

void Level::SetLevel(int level)
{
    this->level_num=level;
}

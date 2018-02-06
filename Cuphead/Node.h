#pragma once
#include"GameObject.h"

struct Node
{
    GameObject* unit;
    Node* next;
    Node* prev;

    ~Node()
    {
        delete unit;
    }
};

#pragma once


#include <list>
#include <stdlib.h>
//#include "game_state.h"
#include <cstdlib>
#include <iostream>


using namespace std;

typedef enum {
    WEREWOLF, VAMPIRE, AVATAR, TREE, WATER, EARTH
} GraphicType;


class graphics {
    //static unsigned num_ofgraphics;
    unsigned short int x;
    unsigned short int y;
    GraphicType type;
public:
    graphics() {
        this->x = 0;
        this->y = 0;
        this->type = EARTH;
    }
    graphics(unsigned short int x_, int y_, GraphicType type_ = EARTH) {
        this->x = x_;
        this->y = y_;
        this->type = type_;
    };
    virtual int move();
    void set_type(GraphicType type_) { this->type = type_; };
    GraphicType get_type() { return this->type; };
    void set_x(unsigned short int i) { this->x = i; };
    void set_y(unsigned short int i) { this->y = i; };
    //static unsigned get_num_of_graphics() { return num_of_graphics; };
    unsigned short int get_y() { return y; };
    unsigned short int get_x() { return x; };
    GraphicType get_id(graphics example) { return example.type; };
    virtual int getpower() const { return NULL; }
    virtual int getdefense()const { return NULL; }
    virtual int gethealth()const { return NULL; }
    virtual void health_decrease(int);
    virtual void health_increase(int);
    virtual int get_potions() { return NULL; }
    //void update_charactes(graphics example, unsigned short int map_x, unsigned short int mapy);
};



class vampires : public graphics {
    unsigned short int power, defense, health,potions;
public:
    vampires() {
        this->power = rand() % 4;
        this->defense = rand() % 3;
        this->health = 10;
        this->potions = rand() % 2;
    };
    int move();
    int getpower() const { return this->power; }
    int getdefense()const { return this->defense; }
    int gethealth()const { return this->health; }
    void printstats()const;
    void health_decrease(int);
    int get_potions ()const{ return this->potions; }
    void health_increase(int);

};


   
class werewolves : public graphics {
    unsigned short int power, defense, health,potions;
public:
    werewolves() {
        this->power = rand() % 4;
        this->defense = rand() % 3;
        this->health = 10;
        this->potions = rand() % 2;
    };
    int getpower() const { return this->power; }
    int getdefense()const { return this->defense; }
    int gethealth()const { return this->health; }
    int get_potions()const { return this->potions; }
    void printstats_w()const;
    void health_decrease(int );
    void health_increase(int);
};

   


class avatars : public graphics {
    int potions;
public:
    avatars () {
        potions = rand() % 2;
    }
    int input(); // the user moves the avatar
};
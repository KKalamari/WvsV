#include <iostream>
#include"graphics.h"
#include <cstdlib> // in order to use srand and rand 
#include<windows.h>
#include"game_state.h"

using namespace std;


int graphics::move() {
    switch (1 + rand() % 4) {  // οι περιπτωσεις να μετακινηθει προς οποιαδήποτε κατευθυνση είναι ισοπίθανη
    case 1:
        return 1; // x++
        break;
    case 2:
        return 2; // x--
        break;
    case 3:
        return 3; // y++
        break;
    case 4:
        return 4; //y--
    default:
        break;
    }
}
int avatars:: input() {
   int i= GetKeyState(VK_NUMPAD0) & 0x8000;
   switch (i) {
   case 0x57:  //το virtual key του w
   case 0x26: //up arrow virtual key
       return 1; //x++
       break;  // 1 break γιατι εκτελουν την ίδια εντολή οπότε έχουμε 2 πανομοιοτυπα cases που λειτουργουν ως 1
   case 0x53: // virtual key "s"
   case 0x28: //down arrow virtual key
       return 2; //x--
       break;
   case 0x41: // a virtual key
   case 0x25: //left arrow virtual key
       return 3; //y++
       break;
   case 0x44: // virtual key D
   case 0x27: //virtual key right arrow key
       return 4; //y--
   default:
       break;
    }
}
void graphics::health_decrease(int i) {}
void graphics::health_increase(int i) {}

void werewolves::health_decrease(int i) { this->health -= i;}
void werewolves::health_increase(int i) { this->health += i; }

void vampires::health_decrease(int i) { this->health -= i; }
void vampires::health_increase(int i) { this->health += i; }

void werewolves::printstats_w()const {
    cout << "the power, the defense and the health are:" << getpower() << "," << getdefense() << "," << gethealth() << endl;
}

void vampires::printstats()const {
    cout << "the power, the defense and the health are:" << getpower() << "," << getdefense() << "," << gethealth() << endl;
}

int vampires::move() {
    switch (1 + rand() % 8) {  // οι περιπτωσεις να μετακινηθει προς οποιαδήποτε κατευθυνση είναι ισοπίθανη
    case 1:
        return 1; // x++
        break;
    case 2:
        return 2; //x--
        break;
    case 3:
        return 3; // y++
        break;
    case 4:
        return 4; // y--
        break;
    case 5:
        return 5; // x++ and y++
        break;
    case 6:
        return 6; // x++ and y-- 
        break;
    case 7:
        return 7; // x-- and y++
        break;
    case 8:
        return 8; // x-- and y--
    default:
        break;
    }
}


#include <cstring>
#include <iostream>
#include "game_state.h"
#include "graphics.h"
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

string** create_array_for_map(unsigned  short int x, unsigned short y) {
    string** array_for_map = new string * [x];
        for (int i = 0; i < y; i++) {
            array_for_map[i] = new string[y];
        }
        for (int i = 0; i < x; i++) {
            for (int n = 1; n < y; n++) {
                array_for_map[i][n] = ":__:";
            }
        }

        return array_for_map;
}

void printing_map(unsigned short int x, unsigned short int y, string** array_for_map) {
    cout << system("cls") << endl;

    //string** array_for_map = create_array_for_map(x, y);


    unsigned short int for_obstacles;
    for_obstacles = (x * y) / 100;
    for (int i = 0; i <= for_obstacles; i++) {
        graphics tree(rand() % x, rand() % y, TREE);
        graphics water(rand() % x, rand() % y, WATER);

        array_for_map[tree.get_x()][tree.get_y()] = " || ";
        array_for_map[water.get_x()][water.get_y()] = " ~~ ";
    }

    for (int i = 0; i < x; i++) {
        for (int n = 0; n < y; n++) {
            cout << array_for_map[i][n];
        }
        cout << endl;
    }

}


void map_create() {
    unsigned short int x=0, y=0;
    while(x* y <= 15) {
        cout << "Hello! \n Please enter the dimensions you want! \n x: " << endl;
        cin >> x;
        cout << " y: " << endl;
        cin >> y;
    };

    string** array_for_map = create_array_for_map(x, y);
    printing_map(x, y, array_for_map);
    
};
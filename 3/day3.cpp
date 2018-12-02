//  Advent of Code 2015 Day 3 Solution
//
//  Created by Jillian A. Bolton on 12/2/18.
//  Copyright © 2018 Jillian A. Bolton. All rights reserved.

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

class mover2d {
    int xpos;
    int ypos;
public:
    mover2d(int x = 0, int y = 0);

    std::pair<int, int> where();
    std::pair<int, int> move(char direction);
};

mover2d::mover2d(int x, int y) {
    xpos = x;
    ypos = y;
}

std::pair<int, int>
mover2d::where() {
    auto pair = std::make_pair(xpos, ypos);
    
    return pair;
}

std::pair<int, int>
mover2d::move(char direction) {
    
    switch (direction) {
        case '>': xpos++; break;
        case '<': xpos--; break;
        case '^': ypos++; break;
        case 'v': ypos--; break;
        default:
            cerr << "direction " << direction << " is invalid\n";
    }
    
    auto pair = std::make_pair(xpos, ypos);
    return pair;
}

int main()
{
    std::string   directions;
    ifstream      input;
    mover2d       santa_p1, santa_p2, robo_p2;
    int           turn = 0;

    map<std::pair<int, int>, int> houses_p1; // part 1 solution accumulates here
    map<std::pair<int, int>, int> houses_p2; // part 2 solution accumulates here

    input.open("input");
    if (input.fail()) {
        cerr << "input: cannot open\n";
        return 1;
    }

    // santa and robo-santa each leave a present in the starting position
    houses_p1[santa_p1.where()]++;
    houses_p2[santa_p2.where()]++;
    houses_p2[robo_p2.where()]++;

    while (input.good()) {
        input >> directions;
        if (!input.good())
            break;
        
        for (auto dir = directions.cbegin(); dir < directions.cend(); dir++, turn++) {
            houses_p1[santa_p1.move(*dir)]++;

            // first turn is zero.  they take turns, robo-santa moves on odd turns
            houses_p2[(turn % 2) ? robo_p2.move(*dir) : santa_p2.move(*dir)];
        }
    }
    
    cout << "houses part 1 " << houses_p1.size() << '\n' <<
            "houses part 2 " << houses_p2.size() << '\n';

    input.close();
    return 0;
}

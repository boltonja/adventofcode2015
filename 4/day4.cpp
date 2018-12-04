// Advent of Code 2015, day 4
//
// Copyright 2018 by Jillian A. Bolton, All Rights Reserved
//

#include <openssl/md5.h>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <unistd.h>
using namespace std;

list<string> *
readfile(string filename) {
    ifstream      input;
    list<string> *lines;

    lines = new typeof(*lines);

    input.open(filename);

    for (char buf[20]; input.getline(buf, sizeof(buf)); ) {
        string *line;
        
        line = new typeof(*line);
        if (!line) {
            delete lines;
            return NULL;
        }
        
        *line = buf;
        lines->push_back(*line);
    }

    return lines;
}

int
adventmine(string s, const char *target) {
    unsigned char md[16];
    unsigned char k[20];
    char          mdhex[33];

    for (int i = 1; i < INT_MAX; i++) {
        int   j;
        char *p;

	snprintf((char *)k, sizeof(k), "%s%d", (const char *)s.c_str(), i);
	k[sizeof(k) - 1] = 0;

        MD5((const unsigned char *)k, strlen((char *)k), md);
        
        p  = mdhex;
        for (j = 0; j < sizeof(md); p += 2)
            sprintf(p, "%02x", md[j++]);
        mdhex[32] = 0;
        
        if (!strncmp((const char *)mdhex, (const char *)target, strlen(target)))
            return i;
    }
    
    return 0;
}

int main(int argc, char *argv[]) {
    list<string> *keys;

    keys = readfile("input");
    if (keys == NULL) {
        cerr << "cannot open " << "input" << '\n';
        return 1;
    }
    
    for (auto key : *keys) {
        int i;
        
        i = adventmine(key, "00000");
        cout << "5 zeroes " << key << i << '\n';

        i = adventmine(key, "000000");
        cout << "6 zeroes " << key << i << '\n';
    }

    delete keys;
}

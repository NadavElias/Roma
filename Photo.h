//
// Created by nadav.elias on 28-Feb-19.
//

#ifndef ROMA_PHOTO_H
#define ROMA_PHOTO_H
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Photo {
    static int count = 0;
    int id;
    string hv;
    string* tags;
    int size;

    vector<string> split(string str, char delimiter) {
        vector<string> internal;
        stringstream ss(str); // Turn the string into a stream.
        string tok;

        while(getline(ss, tok, delimiter)) {
            internal.push_back(tok);
        }

        return internal;
    }

public:
    Photo(string s) {
        vector<string> sep = split(s, ' ');
        hv = sep[0];
        id = count;
        count++;
        size = stoi(sep[1]);
        tags = new string[size];
        for(int f = 2; f < sep.size(); f++)
            tags[f-2] = sep[f];
    }

    static int interestFactor(Photo p1, Photo p2){
        int same = 0;
        for (int i = 0; i < p1.size; ++i) {
            for (int j = 0; j < p2.size; ++j) {
                if (p1.tags[i] == p2.tags[j])
                    same++;
            }
        }
        return min(min(p1.size - same, p2.size - same), same);
    }
};


#endif //ROMA_PHOTO_H

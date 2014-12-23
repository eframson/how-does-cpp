//
//  main.h
//  HelloWorld
//
//  Created by Emmett Framson on 10/17/14.
//  Copyright (c) 2014 Emmett Framson. All rights reserved.
//

#ifndef HelloWorld_main_h
#define HelloWorld_main_h

using namespace std;

pair<bitset<1>, bitset<1>> simulatedFullAdder(bitset<1> a, bitset<1> b, bitset<1> carryin);
string binaryAdder(string a, string b, bool addExtraBits = false);
int integerAdd(int a, int b);
void setDefaultBoxStyle(int boxStyleNum);
void printBox(string content = "", int horizontalPadding = 2, int verticalPadding = 1, int minWidth = -1, int minHeight = -1);
string buildHorizString(int length, char horizChar);
string buildHorizString(long length, char horizChar);
void refsAndPointersAndWhatnot();

struct boxStyle{
    char corner;
    char vert;
    char horiz;
};

boxStyle boxStyleOne = {'+','|','-'};
boxStyle boxStyleTwo = {'*','|','='};
boxStyle defaultBoxStyle = boxStyleOne;

#endif

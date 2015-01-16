//
//  boxprinter.h
//  HelloWorld
//
//  Created by Emmett Framson on 10/17/14.
//  Copyright (c) 2014 Emmett Framson. All rights reserved.
//

#ifndef HelloWorld_boxprinter_h
#define HelloWorld_boxprinter_h

using namespace std;

void setDefaultBoxStyle(int boxStyleNum);
void printBox(string content = "", int horizontalPadding = 2, int verticalPadding = 1, int minWidth = -1, int minHeight = -1);
string buildHorizString(int length, char horizChar);
string buildHorizString(long length, char horizChar);

struct boxStyle{
    char corner;
    char vert;
    char horiz;
};

#endif
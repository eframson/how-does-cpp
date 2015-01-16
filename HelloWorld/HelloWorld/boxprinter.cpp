//
//  boxprinter.cpp
//  HelloWorld
//
//  Created by Emmett Framson on 10/16/14.
//  Copyright (c) 2014 Emmett Framson. All rights reserved.
//

#include <iostream>
#include <string>
#include "boxprinter.h"
using namespace std;

boxStyle boxStyleOne = {'+','|','-'};
boxStyle boxStyleTwo = {'*','|','='};
boxStyle defaultBoxStyle = boxStyleOne;

void printBox(string content, int horizontalPadding, int verticalPadding, int minWidth, int minHeight){
    long contentLength = content.length();
    long contentLengthWithPadding = contentLength + (horizontalPadding * 2);
    long totalLength = (minWidth > 0 && minWidth > contentLengthWithPadding) ? minWidth : contentLengthWithPadding;
    string contentString = "";
    
    string borderHorizString =
        defaultBoxStyle.corner +
        buildHorizString(totalLength, defaultBoxStyle.horiz) +
        defaultBoxStyle.corner +
        "\n";
    string emptyHorizString = defaultBoxStyle.vert + buildHorizString(totalLength, ' ') + defaultBoxStyle.vert + "\n";
    
    if( contentLengthWithPadding < totalLength ){
        int diff = totalLength - contentLengthWithPadding;
        int extraPadding = diff % 2;
        int padding = (diff - extraPadding) / 2;
        
        contentString =
            defaultBoxStyle.vert +
            buildHorizString( (horizontalPadding + padding), ' ') +
            content +
            buildHorizString( (horizontalPadding + padding + extraPadding), ' ') +
            defaultBoxStyle.vert +
            "\n";
        
    }else{
    
        contentString =
            defaultBoxStyle.vert +
            buildHorizString(horizontalPadding, ' ') +
            content +
            buildHorizString(horizontalPadding, ' ') +
            defaultBoxStyle.vert +
            "\n";
        
    }
    
    cout << borderHorizString;
    
    for(int i = 0; i < verticalPadding; i++){
        cout << emptyHorizString;
    }
    
    cout << contentString;
    
    for(int i = 0; i < verticalPadding; i++){
        cout << emptyHorizString;
    }
    
    cout << borderHorizString;
}

string buildHorizString(int length, char horizChar){
    string horizString = "";
    for(int i=0; i < length; i++){
        horizString += horizChar;
    }
    return horizString;
}

string buildHorizString(long length, char horizChar){
    string horizString = "";
    for(int i=0; i < length; i++){
        horizString += horizChar;
    }
    return horizString;
}

void setDefaultBoxStyle(int boxStyleNum){
    switch(boxStyleNum){
        case 1:
            defaultBoxStyle = boxStyleOne;
            break;
        case 2:
            defaultBoxStyle = boxStyleTwo;
            break;
        default:
            defaultBoxStyle = boxStyleOne;
            break;
    }
}

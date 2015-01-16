//
//  main.cpp
//  HelloWorld
//
//  Created by Emmett Framson on 10/16/14.
//  Copyright (c) 2014 Emmett Framson. All rights reserved.
//

#include <iostream>
#include <string>
#include "main.h"
#include "calculator.h"
#include "boxprinter.h"
#include "learning_references.h"
using namespace std;

int main(int argc, const char * argv[]) {

    //What arguments did we get?
    cout << argv << "\n"; //memory address of where the arguments live
    cout << *argv << "\n"; //same as argv[0];
    cout << argc << "\n";
    
    //Add some integers!
    //cout << integerAdd(4,5) << "\n";
    
    //printBox("ape", 2, 1, 15);
    //printBox("appleappleappleappleapple", 2, 1, 15);
    //setDefaultBoxStyle(2);
    //printBox("banana");
    
    refsAndPointersAndWhatnot();
    
    return 0;
}
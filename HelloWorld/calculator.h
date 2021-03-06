//
//  calculator.h
//  HelloWorld
//
//  Created by Emmett Framson on 10/17/14.
//  Copyright (c) 2014 Emmett Framson. All rights reserved.
//

#ifndef HelloWorld_calculator_h
#define HelloWorld_calculator_h

using namespace std;

pair<bitset<1>, bitset<1>> simulatedFullAdder(bitset<1> a, bitset<1> b, bitset<1> carryin);
string binaryAdder(string a, string b, bool addExtraBits = false);
int integerAdd(int a, int b);

#endif

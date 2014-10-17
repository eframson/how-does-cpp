//
//  main.cpp
//  HelloWorld
//
//  Created by Emmett Framson on 10/16/14.
//  Copyright (c) 2014 Emmett Framson. All rights reserved.
//

#include <iostream>
using namespace std;

pair<bitset<1>, bitset<1>> simulatedFullAdder(bitset<1> a, bitset<1> b, bitset<1> carryin){

    bitset<1> carryover;
    bitset<1> out;
    
    out = (a ^ b) ^ carryin;
    carryover = ( (a ^ b) & carryin) ^ (a & b);
    
    pair<bitset<1>, bitset<1>> outpair(out,carryover);
    
    return outpair;
}

string binaryAdder(string a, string b, bool addExtraBits = false){
    
    //Reverse our strings, because we're going to do our binary math from right-to-left
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    bitset<1> carryover (0);
    string outstring="";
    
    //Foreach bit in the given bit strings (based on whichever is least long)
    for(int i=0; i<min(a.length(), b.length()); i++){
        
        //Declare our bitsets
        bitset<1> ba;
        bitset<1> bb;
        bitset<1> out;
        
        //Set out bits appropriately as 1 or 0
        if(a[i]=='1'){
            ba.set();
        }
        if (b[i]=='1'){
            bb.set();
        }
        
        pair<bitset<1>, bitset<1>> outpair = simulatedFullAdder(ba, bb, carryover);
        outstring += outpair.first.to_string();
        carryover = outpair.second;
    }
    
    reverse(outstring.begin(), outstring.end());
    
    return outstring;
}

int integerAdd(int a, int b){
    const int bitsetLength = 32; //@TODO Make this dynamic?
    
    //Turn our integers into bitsets
    bitset<bitsetLength> aBitset (a);
    bitset<bitsetLength> bBitset (b);

    //Returns a string like "001100..."
    string output = binaryAdder(aBitset.to_string(), bBitset.to_string());
    
    //Convert our string into a bitset
    bitset<bitsetLength> out (output);
    
    //Finally, convert our bitset into an int
    return (int) out.to_ulong();
}

int main(int argc, const char * argv[]) {

    //Add some integers!
    cout << integerAdd(4,5) << "\n";
    
    return 0;
}
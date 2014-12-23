//
//  main.cpp
//  HelloWorld
//
//  Created by Emmett Framson on 10/16/14.
//  Copyright (c) 2014 Emmett Framson. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "main.h"
using namespace std;

pair<bitset<1>, bitset<1>> simulatedFullAdder(bitset<1> a, bitset<1> b, bitset<1> carryin){

    bitset<1> carryover;
    bitset<1> out;
    
    out = (a ^ b) ^ carryin;
    carryover = ( (a ^ b) & carryin) ^ (a & b);
    
    pair<bitset<1>, bitset<1>> outpair(out,carryover);
    
    return outpair;
}

string binaryAdder(string a, string b, bool addExtraBits){
    
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
        
        //Set our bits appropriately as 1 or 0
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
    //cout << integerAdd(4,5) << "\n";
    
    //printBox("ape", 2, 1, 15);
    //printBox("appleappleappleappleapple", 2, 1, 15);
    //setDefaultBoxStyle(2);
    //printBox("banana");
    
    refsAndPointersAndWhatnot();
    
    return 0;
}

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

void refsAndPointersAndWhatnot(){
    
    //--- POINTERS!!! ---
    
    //References:
    //http://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-int-const
        //"Read it backwards", e.g. - int const * = a pointer to a constant of type int, etc.
    //http://www.possibility.com/Cpp/const.html
        //A pointer to a const object can be initialized with a pointer to an object that is not const, but not vice versa.
        //"regular" == "mutable"
    //http://stackoverflow.com/questions/3247285/const-int-int-const
        //"const int foo" and "int const foo" are equivalent, but "const int * foo" and "int const * foo" are not
    
    //Declare an int, it gets 5
    int foo = 5;
    
    //Declare a pointer, it can only get memory addresses
    int * bar; //bar is now 0x0, and *bar is undefined and will cause an error if used
    
    //The pointer "foo" gets the address of "bar" (which represents 5 in this case)
    bar = &foo; //bar is now 0x7fff5fbff83c (or similar), and *bar is 5
    //(In this context, the asterisk is the "dereference" operator)

    int fum = 10;
    bar = &fum; //bar is now 0x7fff5fbff82c (or similar), and *bar is 10
    *bar = 7; //bar is STILL 0x7fff5fbff82c (or similar), but *bar AND fum are both 7
    
    //foo = bar; //This doesn't work, because it's trying to assign a pointer addr to an int var
    foo = *bar; //Now foo is 7
    
    
    int regular_int;
    regular_int = 3;
    const int const_int = 6; //(constants must be declared + assigned at the same time)
    
    //These are "regular" pointers, so they don't have to be declared + assigned on the same line
    int * regular_pointer_to_reg; //regular_pointer_to_reg is now 0x0, *regular_pointer_to_reg is undef
    const int * regular_pointer_to_const; //regular_pointer_to_const is now 0x0, *regular_pointer_to_const is undef
    
    regular_pointer_to_reg = &regular_int; //regular_pointer_to_reg is now 0x7fff5fbff828, *regular_pointer_to_reg is 3
    regular_pointer_to_const = &const_int; //regular_pointer_to_const is now 0x7fff5fbff824, *regular_pointer_to_const is 6
    
    //These are constant pointers, so they DO have to be declared + assigned on same line, regardless of what they point to
    int * const const_pointer_to_reg = &regular_int;
    const int * const const_pointer_to_const = &const_int;
    
    int new_reg_int = 9;
    const int new_const_int = 15;
    
    //NONE OF THESE WORK, as constant pointers cannot be reassigned, regardless of what they point to (and whether it's const or not)
    //const_pointer_to_reg = &new_reg_int;
    //const_pointer_to_const = &new_reg_int;
    //const_pointer_to_reg = &new_const_int;
    //const_pointer_to_const = &new_const_int;
    
    regular_pointer_to_reg = &new_reg_int; //regular_pointer_to_reg is now 0x7fff5fbff7fc, *regular_pointer_to_reg is 9
    *regular_pointer_to_reg = 8; //No problems here
    new_reg_int = 9; //No problem here either (let's put it back to 9 so I don't have to rewrite subsequent examples, lol)

    //This SHOULDN'T work (I think), but Xcode doesn't complain
    regular_pointer_to_const = &new_reg_int; //regular_pointer_to_reg is now 0x7fff5fbff7fc, *regular_pointer_to_reg is 9
    
    //This ACTUALLY doesn't work, because it's a const int pointer, so the deref. value can't change
    //*regular_pointer_to_const = 8;
    
    //However, this WOULD work, because you're not changing the value "through" the pointer
    //new_reg_int = 8;
    
    //This ACTUALLY doesn't work (in Xcode), because we're trying to point a regular int pointer at a constant int
    //regular_pointer_to_reg = &new_const_int;
    
    //So maybe it's legit, or maybe Xcode is just weird, but the takeaway is:
        //const int pointers CAN (but shouldn't) be pointed at regular ints
        //int pointers CANNOT be pointed at const ints
    
    regular_pointer_to_const = &new_const_int; //regular_pointer_to_const is now 0x7fff5fbff7f8, *regular_pointer_to_const is 15
    //Neither of these work, because it's declared as a pointer to a const int, and the variable itself is also const (duh)
    //*regular_pointer_to_const = 10;
    //new_const_int = 10;
    
    //Void pointers!
    int an_int = 80;
    struct my_struct {
        int my_int;
    };
    my_struct a_struct = { 75 };
    
    //All of this is valid
    void * void_pointer;
    void_pointer = &a_struct;
    void_pointer = &an_int;
    void * const const_void_pointer = &a_struct;
    
    //This doesn't work
    //int some_int = *void_pointer;
    
    //However, this does work (void pointers can't be cast + dereferenced directly into values, they must be cast as an actual pointer type, and then THAT pointer can be dereferenced into a value)
    int * actual_int_pointer = static_cast<int*>(void_pointer);
    int some_int = *actual_int_pointer;
    
    //Footnote:
    //Don't have a demo for it yet, but if you have a pointer to an object or struct or whatever, these three statements are equivalent:
        //someObj.someProp ...
        //(*pointer_to_someObj).someProp ...
        //pointer_to_someObj->someProp ...
    
    //--- REFERENCES!!! ---
    
    //This doesn't work, because references have to be declared + initialized at the same time
    //int &ref_to_int;
    
    int int_var_to_reference = 45; //&int_var_to_reference is 0x7fff5fbff7f4
    int &ref_to_var = int_var_to_reference; //ref_to_var is now 45, and &ref_to_var is also 0x7fff5fbff7f4

    const int const_int_var_to_reference = 30;
    //There's no such thing as a "constant" / "mutable" reference, as references must always be declared + init. at same time (references are always/implicitly constant)
    
    //This is actually legal (I guess), but you couldn't change the value of int_var_to_reference via ref_to_constant_var, because the reference declaration indicates it's a const int, so changing is not possible (even if it's actually pointing at a mutable int)
    //const int &ref_to_constant_var = int_var_to_reference;

    const int &ref_to_constant_var = const_int_var_to_reference;
    
    ref_to_var = 40; //ref_to_var and int_var_to_reference are now both 40
    int_var_to_reference = 45; //ref_to_var and int_var_to_reference are now both 45 again
    
    //This doesn't work, because it's declared as a reference to a constant
    //ref_to_constant_var = 55;
}

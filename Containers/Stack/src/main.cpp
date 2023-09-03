#include <iostream>
#include "../Header Files/stack.h"
#include "../Header Files/istack.h"


#define MAIN_BEGIN int main(){
#define MAIN_END }



MAIN_BEGIN

MG::stack<int> STK = { 1,2,3,4,5,6,7 };
//MG::istack<int, MG::vector<int>> STK;

STK.print();

STK = {};

STK.print();

STK.emplace(1);
STK.emplace(2);
STK.emplace(3);
STK.emplace(4);
STK.emplace(5);
STK.emplace(6);
STK.emplace(7);
STK.emplace(7);
STK.emplace(7);
STK.emplace(7);
STK.emplace(7);
STK.emplace(7);
STK.emplace(7);
STK.emplace(7);
STK.emplace(7);
STK.emplace(7);
STK.emplace(7);
STK.emplace(7);
STK.emplace(7);
STK.emplace(7);

STK.print();

STK.pop();

STK.print();

STK.pop();

STK.print();


MAIN_END
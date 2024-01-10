#include <iostream>
#include <utility>
#include "../Pair.h"


#define MAIN_BEGIN int main(){
#define MAIN_END }

#define print std::cout
#define out <<



MAIN_BEGIN

MG::pair<int, std::string> Pair1(7, "Mahmoud Gad");
MG::pair<int, std::string> Pair2(3, "Amira Gad");

print out Pair1;
print out Pair2;

print out "\n\n";
print out (Pair1 == Pair2) out "\n";
print out (Pair1 != Pair2) out "\n";
print out (Pair1 < Pair2) out "\n";
print out (Pair1 > Pair2) out "\n";
print out (Pair1 <= Pair2) out "\n";
print out (Pair1 >= Pair2) out "\n";
print out "\n\n";

Pair1.swap(Pair2);

print out Pair1;
print out Pair2;

MAIN_END
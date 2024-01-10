#include "clsString.h"

#define MAIN_BEGIN int main(){
#define MAIN_END return 0;}
#define print(x) cout << "\"" << x << "\"" << '\n'


MAIN_BEGIN


MG::String S1 = "  Mahmoud Gad  ";
S1.trim();
print(S1);

MG::String S2 = "  Amira Gad  ";
MG::String::trim(S2);
print(S2);



MAIN_END
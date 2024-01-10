#include <iostream>
#include "../MG_Utility.h"


#define MAIN_BEGIN int main(){
#define MAIN_END }

using namespace MG::algorithm;
using namespace MG::utility;
using namespace MG::utility::arr_util;


MAIN_BEGIN


std::cout << "============================================\n\n";

int n{ 4 };

while (--n) {
	std::cout << rand_util::rand_key(rand_util::en_CharType::c_alpha_digit, 4, 5) << std::endl;
}


std::cout << "\n\n============================================\n\n";

MAIN_END
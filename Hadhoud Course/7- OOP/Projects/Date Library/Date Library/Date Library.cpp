#include "clsDate.h"

#define MAIN_BEGIN int main(){
#define MAIN_END return 0;}

using namespace MG::DateLib;

MAIN_BEGIN

clsDate date1("7/3/2023");
clsDate date2("20/2/2023");
clsDate date3("1/1/2023");

date3.day = 10;
date3.month = 10;
date3.year = 2010;

date3.print();

/*date1.print();
date2.print();

date1.swap(date2);
cout << "\n\n";

date1.print();
date2.print();*/


MAIN_END


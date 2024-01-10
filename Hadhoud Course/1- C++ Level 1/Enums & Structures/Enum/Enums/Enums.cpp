
#include <iostream>
#include <string>


using namespace std;


// every part in the enum take value by defult ( 0, 1, 2, 3, 4, 5, 6, 7, 8 .......)
/*
you can choose the values by doing this:
enum colors{ Blue=100 , Red=200 , purple=300 , ..........}
*/



enum colors{ Blue, Red, Purple, Green, Black, Yellow, White };
enum car{ BMW, Mercedes_Benz, MG, Fiat ,Siat };
enum gender{ male , female };
enum status{ married , single };
enum direction{ North , south , east , west };
enum days{ sat , sun , mon , tue , wed , thu , fri };
enum sports{ football , vollyball , basketball , american_football , golf , hoky };


int main()
{
  
	
	colors mycolor = colors::Purple;
	
	car mycar;
	mycar = car::Mercedes_Benz;


	cout << "your favorite color is : " << mycolor << endl;

	cout << "your car is : " << mycar << endl;



}


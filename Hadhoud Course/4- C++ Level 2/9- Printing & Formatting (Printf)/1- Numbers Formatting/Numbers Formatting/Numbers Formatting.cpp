#include <iostream>
#include <cstdio>

using namespace std;

/*
	Look here too

	https://www.freecodecamp.org/news/format-specifiers-in-c/

	https://www.programiz.com/cpp-programming/library-function/cstdio/printf

*/

int main()
{
	// Integer


	int a = 7, b = 3;
	// Print integer Numbers
	printf("The result of: %d + %d = %d \n\n", a, b, a + b);

	
	short Sh = -561;
	// Print unsigned short
	printf("Unsigned short: %hi \n\n", Sh);
	

	unsigned short uSh = 14;
	// Print signed short
	printf("Signed short: %hu \n\n", uSh);


	unsigned int uI = 45;
	// print unsigned int 
	printf("Unsigned int: %u \n\n", uI);
	

	int I = -123;

	// Print signed int (detects the base automatically)
	printf("Signed int: %i \n\n", I);
	
	// Print signed int (assumes base 10)
	printf("Signed int: %d \n\n", I);


	// Convert int from decimal to Octal
	printf("%d in Octal is %o \n\n", I, I);


	// Convert int from decimal to Hexa
	printf("%d in Hexadecimal is %x \n\n", I, I);


	int* i = &I;
	// Print adderss or pointer of a variable
	printf("Adderss: %p \n\n", &I);
	printf("Pointer: %p \n\n", i);


	int N = 1;
	// Width specification
	cout << "Width Specification of Number:\n";
	printf("%0*d \n", 1, N); // 1
	printf("%0*d \n", 2, N); // 01
	printf("%0*d \n", 3, N); // 001
	printf("%0*d \n", 4, N); // 0001



	cout << endl << endl;
	cout << "____________________________________________________________________________" << endl << endl << endl;
	//***************************************************************************************************************
	//***************************************************************************************************************

	// Float
	

	float F = 3.4561324;
	
	// Print float number
	printf("Float: %f \n\n", F);


	// print float number in decimal exponent notation
	printf("float number in decimal exponent notation: %e \n\n", F);


	// Converts floating-point number to either decimal or decimal exponent notation
	printf("Converts floating-point number to either decimal or decimal exponent notation: %g \n\n", F);


	// Convert float from decimal to Hexa
	printf("%f in Hexadecimal is %a \n\n", F, F);


	long double Ld = 5461.46546512;

	// Print long double
	printf("long double: %Lf \n\n", Ld);


	float A = 5.154, B = 3.456;
	// Set float numbers to 3 digits after (.) using { %. }
	printf("Set float numbers to 3 digits after (.): %.3f + %.3f = %.3f \n\n", A, B, A + B);



	double PI = 3.14159265359;

	// Float Precision Specification using( %.* )
	printf("Set float numbers to 1 digits after (.): %.*f \n", 1, PI);
	printf("Set float numbers to 2 digits after (.): %.*f \n", 2, PI);
	printf("Set float numbers to 3 digits after (.): %.*f \n", 3, PI);
	printf("Set float numbers to 4 digits after (.): %.*f \n\n", 4, PI);

	// Float Precision Specification using( %. )
	printf("Set float numbers to 1 digits after (.): %.1f \n", PI);
	printf("Set float numbers to 2 digits after (.): %.2f \n", PI);
	printf("Set float numbers to 3 digits after (.): %.3f \n", PI);
	printf("Set float numbers to 4 digits after (.): %.4f \n", PI);







	return 0;
}
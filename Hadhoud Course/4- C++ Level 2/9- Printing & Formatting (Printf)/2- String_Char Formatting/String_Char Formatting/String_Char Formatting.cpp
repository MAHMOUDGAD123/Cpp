
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	char C = 'M';

	printf("One Char: %c \n\n", C);

	// Width Specification
	cout << "Width Specification: \n";
	printf("%*c \n", 1, C); // 1 space
	printf("%*c \n", 2, C); // 2 spaces
	printf("%*c \n", 3, C); // 3 spaces
	printf("%*c \n", 4, C); // 4 spaces
	printf("%*c \n", 5, C); // 5 spaces
	printf("%*c \n", 4, C);
	printf("%*c \n", 3, C);
	printf("%*c \n", 2, C);
	printf("%*c \n", 1, C);



	// Convert Char to Int & vice versa
	int a = 90;
	int b = 'M';

	printf("\nConvert Int to Char: (%d) --> (%c)", a, a);
	printf("\nConvert Char to Int: (%c) --> (%d)", b, b);




	printf("\n\n");

	//**********************************************************************************************************
	//**********************************************************************************************************

	// Printf() Don't support string but it deals with array of characters

	char Name[] = "Mahmoud Gad";
	short age = 0;

	printf("Hi %s How are you \n\n", Name);
	



	return 0;
}

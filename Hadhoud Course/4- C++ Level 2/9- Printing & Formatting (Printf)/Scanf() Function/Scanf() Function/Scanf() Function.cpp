


// you have to define the next before using scanf() function
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <iostream>
#include <cstdio>


using namespace std;


int main()
{
	char name[50];
	int age;

	printf("What Is Your Name? ");
	scanf("%s", name);
	
	printf("What Is Your Age? ");
	scanf("%d", &age);

	printf("\nHi %s, You Are (%d) Years Old.\n", name, age);


	

	return 0;
}





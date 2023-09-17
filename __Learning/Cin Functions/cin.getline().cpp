#include <iostream>

using namespace std;

int main()
{
	// cin.getline(char* buffer, int length);

	char Name[20];

	cout << "\n\nEnter Your Name:--> ";
	cin.getline(Name, 20);

	cout << "\n\nYour Name IS: \"" << Name << "\"\n\n\n";

	// cin.read(char *buffer, int n):
	// Reads n bytes (or until the end of the file) from the stream into the buffer.

	cout << "Enter Your Name:--> ";

	cin.read(Name, 20);

	cout << "\n\nYour Name IS: \"" << Name << "\"\n\n\n";

	return 0;
}
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // cout.put(char &ch);
    // Displays the character stored by ch

    char ch = 'M';

    cout.put(ch);

    cout << endl;

    // cout.write(char *str, int n);
    // Displays the first n character reading from str.

    char str[] = "Mahmoud Gad";

    cout.write(str, 7);
    cout << endl;

    // cout.precision(int n);
    // Sets the decimal precision to (n) while displaying floating-point values
    // Same as   cout << setprecision(n);

    double d = 21.45464231;

    cout.precision(7);

    cout << d << endl;

    cout << endl
        << setprecision(5) << d << endl;

    return 0;
}
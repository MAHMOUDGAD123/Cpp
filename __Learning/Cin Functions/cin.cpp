#include <iostream>
#include <string>
#include <vector>

int main()
{

    // cin >> >> >> .....  accept multiple inputs

    std::string FName, LName;

    std::cout << "Enter Your First_Name & Last_name:--> ";
    std::cin >> FName >> LName;

    std::string FullName = FName + " " + LName;

    std::cout << "Your Full Name is: " << FullName << std::endl;

    return 0;
}
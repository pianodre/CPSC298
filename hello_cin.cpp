/// @file hello_cin.cpp
/// @brief Takes a string input and outputs it after "Message:"
/// @author Dylan Ernst

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string strMessage;
    cout << "Please type a single word message" << endl;
    cin >> strMessage;
    cout << "Message: " << strMessage << endl;
    return 0;
}
/*
* Part I: Prompt the user to enter the three letter message code and display the message and Authenticator codes.
* Part II: You'll perform a character-by-character comparison of the codes. 
* Part III: you'll compare the codes using string comparison.
* Part IV: you'll characterize the received message code and display information helpful in defeating spoofing attempts.
*/


#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {

/*
* PART I
* Prompt the user to enter the three letter message code and display the message and Authenticator codes.
*/
    // Authenticator codes
    const char k_cAuthenticatorCodeCharacter1 = 'E';
    const char k_cAuthenticatorCodeCharacter2 = 'C';
    const char k_cAuthenticatorCodeCharacter3 = 'A';

    string auth;
    auth += k_cAuthenticatorCodeCharacter1;
    auth += k_cAuthenticatorCodeCharacter2;
    auth += k_cAuthenticatorCodeCharacter3;

    // User inputed message
    char c1, c2, c3;
    cout << "Enter the first character of the message code: " << endl;
    cin >> c1;
    cout << "Enter the second character of the message code: " << endl;
    cin >> c2;
    cout << "Enter the third character of the message code: " << endl;
    cin >> c3;

    // Makes the variables uppercase for readability and simplicity
    c1 = toupper(c1);
    c2 = toupper(c2);
    c3 = toupper(c3);

    string message;
    message += c1;
    message += c2;
    message += c3;

    cout << "\nAuthenticator Code: " << auth << endl;
    cout << "Message Code: " << message << "\n" << endl;
/*
* PART II
* You'll perform a character-by-character comparison of the codes. 
*/
    bool o = false; // used in part 4 to determine if any did not match
    if ((k_cAuthenticatorCodeCharacter1 == c1) && (k_cAuthenticatorCodeCharacter2 == c2) && (k_cAuthenticatorCodeCharacter3 == c3)) {
        cout << "Message is authentic." << endl;
    } else {
        cout << "Message is invalid." << endl;
        o = true;
    }

/*
* PART III
* You'll compare the codes using string comparison.
*/

    if (auth == message) {
        cout << "Concurrence: message is authentic." << "\n" << endl;
    } else {
        cout << "Concurrence: message is invalid." << "\n" << endl;
    }
/*
* PART IV: 
* You'll characterize the received message code and display information helpful in defeating spoofing attempts.
*/
    cout << "Characterization of Message Code\n------------------------------" << endl;

    int checksum = 0;
    checksum = (int(c1) + int(c2) + int(c3)) % 7;

    const int k_iValidCodeChecksum = 5;

    if (checksum == k_iValidCodeChecksum) {
        cout << "Message Code Checksum is valid: " << checksum << endl;
    } else {
        cout << "Message Code Checksum is invalid: " << checksum << "; Expected " << k_iValidCodeChecksum << endl;
    }

    cout << "ASCII Values of Message Code Characters: " << static_cast<int>(c1) << ", " << static_cast<int>(c2) << ", " << static_cast<int>(c3) << endl;
    cout << "Sum of ASCII values for Message Code Characters: " << static_cast<int>(c1) + static_cast<int>(c2) + static_cast<int>(c3) << endl;

    if (o) {
        if (c1 != k_cAuthenticatorCodeCharacter1) {
            cout << "First characters do not match: Message " << c1 << "; Authenticator: " << k_cAuthenticatorCodeCharacter1 << endl;
        }
        if (c2 != k_cAuthenticatorCodeCharacter2) {
            cout << "Second characters do not match: Message " << c2 << "; Authenticator: " << k_cAuthenticatorCodeCharacter2 << endl;
        }
        if (c3 != k_cAuthenticatorCodeCharacter3) {
            cout << "Third characters do not match: Message " << c3 << "; Authenticator: " << k_cAuthenticatorCodeCharacter3 << endl;
        }

        int messageSum = static_cast<int>(c1) + static_cast<int>(c2) + static_cast<int>(c3);
        int authSum = static_cast<int>(k_cAuthenticatorCodeCharacter1) + static_cast<int>(k_cAuthenticatorCodeCharacter2) + static_cast<int>(k_cAuthenticatorCodeCharacter3);

        if (messageSum < authSum) {
            cout << "Message code (" << message << ") is lexicographically less than Authenticator code (ECA)\n";
        } else {
            cout << "Message code (" << message << ") is lexicographically greater than Authenticator code (ECA)\n";
        }
    }

}
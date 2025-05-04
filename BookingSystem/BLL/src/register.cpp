#include "../include/register.h"
#include <conio.h>
bool checkPassword(std::string password)
{
    bool checkSize = false;
    bool checkEmpty = false;
    bool checkSpaces = false;
    bool checkUpper = false;
    bool checkSpecial = false;
    bool checkNumber = false;

    if (password.size() >= 6 && password.size() <= 16) checkSize = true;   // Check that password is the correct size

    if (!password.empty()) checkEmpty = true;

    if (password.find(' ') != std::string::npos) checkSpaces = true;

    for (unsigned int i = 0; i < password.size(); i++)      // Run until the end of password has been reached
    {
        if (password[i] >= 65 && password[i] <= 90) checkUpper = true;      // Check if there is an upper case letter
        if (password[i] >= 48 && password[i] <= 57) checkNumber = true;      // Check if there is a number
        if (!(password[i] >= 65 && password[i] <= 90) && !(password[i] >= 48 && password[i] <= 57) && !(password[i] >= 97 && password[i] <= 122)) checkSpecial = true;      // Check if there is a special character
    }

    if (checkSize && checkEmpty && checkUpper && checkNumber && checkSpecial && !checkSpaces)   // If password is inside the parameters return true
        return true;
    else
        return false;
}

bool checkUsername(std::string& username) {
    // Check if the username is non-empty and does not contain spaces
    bool checkSize = !username.empty();
    bool checkSpaces = (username.find(' ') == std::string::npos);

    return checkSize && checkSpaces;
}

bool checkEmail(std::string& email) {
    // Check if the email is non-empty and does not contain spaces
    bool checkSize = !email.empty();
    bool checkSpaces = (email.find(' ') == std::string::npos);

    bool checkAt = false;
    size_t atPosition = email.find('@');
    if (atPosition != std::string::npos && email.find('@', atPosition + 1) == std::string::npos) {
        checkAt = true; // No '@' or more than one '@'
    }

    // Check if there is at least one character before and after the '@'
    bool checkBandA = false;
    if (atPosition != 0 && atPosition != email.size() - 1) {
        checkBandA = true;
    }

    // Check if the string contains a '.' after the '@'
    bool checkDot = false;
    size_t dotPosition = email.find('.', atPosition);
    if (dotPosition != std::string::npos && dotPosition != email.size() - 1) {
        checkDot = true; // No '.' or '.' at the end
    }

    return checkSize && checkSpaces && checkAt && checkBandA && checkDot;
}

bool checkValidity(std::string& username, std::string& email, std::string& password) {
    // Check if all credentials are valid
    bool check = false;
    if (checkPassword(password) && checkUsername(username) && checkEmail(email)) check = true;
    return check;
}

void hidePassword(std::string& password) {
    char ch;
   
    password.clear();  // Clear the existing password if any
    while ((ch = _getch()) != '\r') {  // Read characters until Enter is pressed
        if (ch == 8) {  // Backspace key
            if (!password.empty()) {
                password.pop_back();
                std::cout << "\b \b";  // Remove the last '*' character on the screen
            }
        }
        else if (ch != 27) {  // Escape key
            password.push_back(ch);  // Append character to the password
            std::cout << '*';  // Print '*' for each character
        }
    }
    std::cout << std::endl;  // Print a newline after the password
}

std::string createFileLine(std::string& username, std::string& email, std::string& password)
{
    // Input all credentials in the file
    std::string inputLine;
    inputLine = username + " " + email + " " + password;
    return inputLine;
}
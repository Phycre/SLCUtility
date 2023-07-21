#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>

#ifndef SLC
#define SLC


std::string getString() {
     std::string inp;
     std::getline(std::cin, inp);
     while (inp.empty()) {
          std::cout << "\nInvalid input, please enter a valid email:";
          std::getline(std::cin, inp);
     }
     return inp;
}



bool validEmail(const std::string s) {

     bool hasSpace = s.find_first_of(" ") == std::string::npos;
     bool hasAt = s.find_first_of("@") == std::string::npos;

     if (strcmp((char *)s[s.length() - 4], (char*)"."))
          return false;

     if (!hasSpace)
          return false;
     
     return !hasAt;
}

std::string getEmail() {
     std::string inp;
     std::getline(std::cin, inp);

     while (inp.empty() || !validEmail(inp)) {
          std::cout << "\nInvalid input, please enter a valid email:";
          std::getline(std::cin, inp);
     }
     return inp;
}




bool validInt(const std::string s) {
     return s.find_first_not_of("0123456789+-") == std::string::npos;
}

//takes no value input then gives input and makes sure its an integer
int getInt() {
     int inp;
     std::string str;
     std::getline(std::cin, str);
     str.erase(remove(str.begin(), str.end(), ' '), str.end());
     while (!validInt(str) || str.empty()) {//while input is not integer
          std::cout << "\nInvalid input, please enter an integer:";
          std::getline(std::cin, str);
          str.erase(remove(str.begin(), str.end(), ' '), str.end());
     }

     try {
          return stoi(str);
     }
     catch (std::out_of_range) {
          std::cout << "\nInvalid input Integer is too large! enter new integer:";
          inp = getInt();
          return inp;
     }
}




bool validDouble(const std::string s) {
     return s.find_first_not_of("0123456789+-.") == std::string::npos;
}

double getDouble() {
     double inp;
     std::string str;
     std::getline(std::cin, str);
     str.erase(remove(str.begin(), str.end(), ' '), str.end());
     while (!validDouble(str) || str.empty()) {//while input is not integer
          std::cout << "\nInvalid input, please enter a double:";
          str.erase(remove(str.begin(), str.end(), ' '), str.end());
          std::getline(std::cin, str);
     }
     return stod(str);
}



#endif
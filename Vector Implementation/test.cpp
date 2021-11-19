#include <iostream>
#include <string>
#include "vector.h"


int main() {
    vector<std::string> vec(3);
    
    vec.push_back(std::string("One"));
    std::cout << vec[0] << "\n";


    vec.push_back(std::string("Two"));
    std::cout << vec[1] << "\n";


    vec.push_back(std::string("Three"));
    std::cout << vec[2] << "\n";


    vec.push_back(std::string("Four"));
    std::cout << vec[3] << "\n";

    return 0;
}
#include <iostream>
#include <string>
#include "vector.h"


int main() {
    vector<std::string> vec(3);
    
    vec.push_back(std::string("One"));
    vec.push_back(std::string("Two"));
    vec.push_back(std::string("Three"));
    vec.push_back(std::string("Four"));
    vec.push_back(std::string("Four"));
    vec.push_back(std::string("Four"));
    vec.push_back(std::string("Four"));
    vec.push_back(std::string("Four"));
    vec.push_back(std::string("Four"));
    vec.push_back(std::string("Four"));
    vec.push_back(std::string("Four"));
    vec.push_back(std::string("Four"));
    vec.push_back(std::string("Four"));

    return 0;
}

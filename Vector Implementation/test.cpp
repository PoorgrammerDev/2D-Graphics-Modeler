#include <iostream>
#include <string>
#include "vector.h"


int main() {
    vector<std::string> vec(3);
    vector<std::string> vec2(3);
    
    vec.push_back(std::string("Zero"));
    vec.push_back(std::string("One"));
    vec.push_back(std::string("Two"));
    vec.push_back(std::string("Three"));
    vec.push_back(std::string("Four"));
    vec.push_back(std::string("Five"));

    iterator<std::string> iter = vec2.begin();
    iter += 2;
    
    std::cout << vec;
    iter = vec.insert(iter, "ASDF");
    std::cout << vec;

    iter = vec.erase(iter);
    std::cout << vec;

    return 0;
}

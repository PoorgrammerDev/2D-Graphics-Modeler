#include <iostream>
#include "Shape.h"

using std::cout;
using std::cin;

int Shape::ChooseShape()
{
    int choice;
    cout << "What shape would you like to create\n"
         << "(1 - Line, 2 - Polyline, 3 - Polygon, 4 - Rectangle)\n"
         << "(5 - Square, 6 - Ellipse, 7 - Circle, 8 - Text)\n"
         << "Please enter a number: ";
    cin >> choice;
    return choice;
}

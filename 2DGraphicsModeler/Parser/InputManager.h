#ifndef INPUTMANAGER
#define INPUTMANAGER

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <ios>
#include <limits>
#include <QString>
#include <memory>
#include <utility>
#include "../Util/vector.h"
#include "../Shapes/Shape.h"
#include "../Util/EnumStrConv.h"

class InputManager
{
	public:
		InputManager();
		~InputManager();

        void ReadShapes(vector<std::unique_ptr<Shape>>& shapes);
	private:
        // Get Pen and Brush info is set
        void GetPenInfo (std::ifstream& in, std::unique_ptr<Shape>& shape);
        void GetBrushInfo (std::ifstream& in, std::unique_ptr<Shape>& shape);

        // Need to update
        void GetTextInfo (std::ifstream& in, std::unique_ptr<Shape>& shape);

        // Some are done, some need a little more work
        void InterpretLineDimensions (std::string lineDim, std::unique_ptr<Shape>& shape, int dimensions[]);
        void InterpretRectDimensions (std::string rectDim, std::unique_ptr<Shape>& shape, int dimensions[], std::string type);
        //void InterpretSquareDimensions (std::string squareDim, int& x, int& y, int& side);
        void InterpretPolyDimensions (std::string polyDim, std::unique_ptr<Shape>& shape, int dimensions[], int size);
};	

#endif

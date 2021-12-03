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
#include "/Util/vector.h"
#include "/Shapes/Shape.h"
#include "/Util/EnumStrConv.h"

class InputManager
{
	public:
		InputManager();
		~InputManager();

        void ReadShapes(vector<std::unique_ptr<Shape>> shapes);
	private:
        // Get Pen and Brush info is set
        void GetPenInfo (std::ifstream& in, std::unique_ptr<Shape>& shape);
        void GetBrushInfo (std::ifstream& in, std::unique_ptr<Shape>& shape);

        // Need to update
        void GetTextInfo (std::ifstream& in, std::string& text, std::string& color, std::string& alignment, int& size,
		                  std::string& fontFam, std::string& fontStyle, std::string& fontWeight);

        // Some are done, some need a little more work
		void InterpretLineDimensions (std::string lineDim, int& x1, int& x2, int& y1,int& y2);
		void InterpretRectDimensions (std::string rectDim, int& x, int& y, int& width, int&height);
		void InterpretSquareDimensions (std::string squareDim, int& x, int& y, int& side);
		void InterpretPolyDimensions (std::string polyDim, int x[], int y[]);	
};	

#endif

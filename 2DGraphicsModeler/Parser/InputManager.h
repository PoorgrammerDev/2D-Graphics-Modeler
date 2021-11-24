#ifndef INPUTMANAGER
#define INPUTMANAGER

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <ios>
#include <limits>

class InputManager
{
	public:
		InputManager();
		~InputManager();

		void ReadShapes();
	private:
		void GetPenInfo (std::ifstream& in, std::string& color, int& width, std::string& style, std::string& capStyle, std::string& joinStyle);
		void GetBrushInfo (std::ifstream& in, std::string& color, std::string& style);
		void GetTextInfo (std::ifstream& in, std::string& text, std::string& color, std::string& alignment, int& size,
		                  std::string& fontFam, std::string& fontStyle, std::string& fontWeight);
		void InterpretLineDimensions (std::string lineDim, int& x1, int& x2, int& y1,int& y2);
		void InterpretRectDimensions (std::string rectDim, int& x, int& y, int& width, int&height);
		void InterpretSquareDimensions (std::string squareDim, int& x, int& y, int& side);
		void InterpretPolyDimensions (std::string polyDim, int x[], int y[]);	
};	

#endif


#include "InputManager.h"

/**********************
 * Method Definitions *
 **********************/

// Constructor & Destructor
InputManager:: InputManager() {}
InputManager:: ~InputManager() {}

// Method to read in shapes from input file 
void InputManager:: ReadShapes()
{
	int id;
	int penWidth;
	std::string type;
	std::string dimensions;
	std::string penColor;
	std::string penStyle;
	std::string penCapStyle;
	std::string penJoinStyle;
	std::string text;
	std::string textColor;
	std::string textAlign;
	int textSize;
	std::string textFont;
	std::string textStyle;
	std::string textWeight;
	std::string brushColor;
	std::string brushStyle;
	int x1;
	int x2;
	int y1;
	int y2;
	int x[50];
	int y[50];

	std::ifstream in("shapes.txt");
	// exception??

	while(in)
	{
		in.ignore(9, ' '); // Ignoring "ShapeId: "
		in >> id;
		in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Usual ignore for >> to getline
		
		in.ignore(11, ' '); // Ignoring "ShapeType: "
		getline(in, type);

		in.ignore (17, ' '); // Ignoring "ShapeDimensions: "
		getline(in, dimensions);
		
		if(type[0] == 'L')
		{
			// Getting pen information for line or polyline
		   	GetPenInfo (in, penColor, penWidth, penStyle, penCapStyle, penJoinStyle);
			InterpretLineDimensions (dimensions, x1, x2, y1, y2);
		}	
		else if(type == "Polyline")
		{
			// Getting pen information for line or polyline
		   	GetPenInfo (in, penColor, penWidth, penStyle, penCapStyle, penJoinStyle);
			InterpretPolyDimensions (dimensions, x, y);
		}
		else if (type[0] == 'T')
		{
			// Getting text information for texts
			GetTextInfo (in, text, textColor, textAlign, textSize, textFont, textStyle, textWeight);
			InterpretRectDimensions (dimensions, x1, y1, x2, y2);
		}
		else
		{
			// Getting pen & brush information
		   	GetPenInfo (in, penColor, penWidth, penStyle, penCapStyle, penJoinStyle);
			GetBrushInfo (in, brushColor, brushStyle);

			// Ellipse and rectangle have rectnagle dimensions
			// Polygons have poly dimensions
			// Square and circle have square dimensions
			if(type[0] == 'R' || type[0] == 'E')
				InterpretRectDimensions (dimensions, x1, y1, x2, y2);
			else if(type[0] == 'P')
				InterpretPolyDimensions (dimensions, x, y);
			else
				InterpretSquareDimensions (dimensions, x1, y1, x2);
		}

		// Ignore for extra line between each shape
		in.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
	}

	in.close();
}

// Reading pen information from file
void InputManager:: GetPenInfo (std::ifstream& in, std::string& color, int& width, std::string& style, std::string& capStyle, std::string& joinStyle)
{
	in.ignore(10, ' '); // Ignoring "PenColor: "
	getline(in, color);
	in.ignore(10, ' '); // Ignoring "PenWidth: "
	in >> width;
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Usual ignore for >> to getline
	in.ignore(10, ' '); // Ignoring "PenStyle: "
	getline(in, style); 
	in.ignore(13, ' '); // Ignoring "PenCapStyle: "
	getline(in, capStyle);
	in.ignore(14, ' '); // Ignoring "PenJoinStyle: "
	getline(in, joinStyle);
}

// Reading brush information from file
void InputManager:: GetBrushInfo (std::ifstream& in, std::string& color, std::string& style)
{
	in.ignore(12, ' '); // Ignoring "BrushColor: "
	getline(in, color);
	in.ignore(12, ' '); // Ignoring "BrushStyle: "
	getline(in, style);
}

// Reading text information from file
void InputManager:: GetTextInfo (std::ifstream& in, std::string& text, std::string& color, std::string& alignment, int& size, 
		                 std::string& fontFam, std::string& fontStyle, std::string& fontWeight)
{	
	in.ignore(12, ' '); // Ignoring "TextString: "
	getline(in, text);
	in.ignore(11, ' '); // Ignoring "TextColor: "
	getline(in, color);
	in.ignore(15, ' '); // Ignoring "TextAlignment: "
	getline (in, alignment);
	in.ignore(15, ' '); // Ignoring "TextPointSize: "
	in >> size;
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Usual ignore for >> to getline
	in.ignore(16, ' '); // Ignoring "TextFontFamily: "
	getline(in, fontFam); 
	in.ignore(15, ' '); // Ignoring "TextFontStyle: "
	getline(in, fontStyle);
	in.ignore(16, ' '); // Ignoring "TextFontWeight: "
	getline(in, fontWeight);
}

// Converting string of dimensions into individual ints
void InputManager:: InterpretLineDimensions (std::string lineDim, int& x1, int& x2, int& y1,int& y2)
{
	// Using stringstream to extract integer points
	std::stringstream ss;
	
	ss << lineDim;
	ss >> x1;
	ss.ignore(2, ' '); // Ignoring ", "
	ss >> y1;
	ss.ignore(2, ' '); // Ignoring ", "
	ss >> x2;
	ss.ignore(2, ' '); // Ignoring ", "
	ss >> y2;
}

// Converting string of dimensions into individual ints
void InputManager:: InterpretPolyDimensions (std::string polyDim, int x[], int y[]) 
{
	int index = 0;

	//Using stringstream to extract integer points
	std::stringstream ss;

	ss << polyDim;
	while(index < 50 && ss)
	{
		ss >> x[index];
		ss.ignore(2, ' '); // Ignoring ", "
		ss >> y[index];
		ss.ignore(2, ' '); // Ignoring ", "

		++index;
	}
}	

// Converting string of dimensions into individual ints
void InputManager:: InterpretRectDimensions (std::string rectDim, int& x, int& y, int& width, int&height)
{
	// Using stringstream to extract integer points
	std::stringstream ss;
	
	ss << rectDim;
	ss >> x;
	ss.ignore(2, ' '); // Ignoring ", "
	ss >> y;
	ss.ignore(2, ' '); // Ignoring ", "
	ss >> width;
	ss.ignore(2, ' '); // Ignoring ", "
	ss >> height;
}

// Converting string of dimensions into individual ints
void InputManager:: InterpretSquareDimensions (std::string squareDim, int& x, int& y, int& side)
{
	// Using stringstream to extract integer points
	std::stringstream ss;
	
	ss << squareDim;
	ss >> x;
	ss.ignore(2, ' '); // Ignoring ", "
	ss >> y;
	ss.ignore(2, ' '); // Ignoring ", "
	ss >> side;
}


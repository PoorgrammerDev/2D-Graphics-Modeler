

// input stuff
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

// General Input Function that does everything atm, note will have parameters once put with class implementation
void InputShapes ();

// Lines and Shapes have pen info for the input that this function reads in, note will have dif parameters with class implementation
void GetPenInfo (std::ifstream& in, std::string& color, int& width, std::string& style, std::string& capStyle, std::string& joinStyle);

// Shapes have brush info for the input that this function reads in, note will have dif parameters with class implementation
void GetBrushInfo (std::ifstream& in, std::string& color, std::string& style);

// Texts have text info for the input that this function reads in, note will have dif paramaters with class implementation
void GetTextInfo (std::ifstream& in, std::string& text, std::string& color, std::string& alignment, int& size,
		  std::string& fontFam, std::string& fontStyle, std::string& fontWeight);

// Takes a string of dimensions for lines and seperates it into individual ints
void InterpretLineDimensions (std::string lineDim, int& x1, int& x2, int& y1,int& y2);

// Takes a string of dimensions for rectangles and seperates it into individual ints
// Rectangles, texts, and ellipses are defined with rectangle dimensions
void InterpretRectDimensions (std::string rectDim, int& x, int& y, int& width, int&height);

 
// Takes a string of dimensions for squares and seperates it into individual ints
// Squares and circles are defined with rectangle dimensions
void InterpretSqaureDimensions (std::string squareDim, int& x, int& y, int& side);

// Need to implement InterpertPolyDimensions for polylines and polygons

int main()
{
	InputShapes();
	return 0;
}

/*****************
 * Function Defs *
 *****************/

void InterpretLineDimensions (std::string lineDim, int& x1, int& x2, int& y1,int& y2)
{
	// Using stringstream to extract integer points
	std::stringstream ss;
	
	ss << lineDim;
	ss >> x1;
	ss.ignore(2, ' ');
	ss >> y1;
	ss.ignore(2, ' ');
	ss >> x2;
	ss.ignore(2, ' ');
	ss >> y2;

	// Remove testing when done
	std::cout << x1 << std::endl << y1 << std::endl << x2 << std::endl << y2 << std::endl << std::endl;

}

// InterpretPolyDimensions (std::string polyDim) // need help with class info 

void InterpretRectDimensions (std::string rectDim, int& x, int& y, int& width, int&height)
{
	std::stringstream ss;
	
	ss << rectDim;
	ss >> x;
	ss.ignore(2, ' ');
	ss >> y;
	ss.ignore(2, ' ');
	ss >> width;
	ss.ignore(2, ' ');
	ss >> height;

	std::cout << x << std::endl << y << std::endl << width << std::endl << height << std::endl << std::endl;
}

void InterpretSqaureDimensions (std::string squareDim, int& x, int& y, int& side)
{
	
	std::stringstream ss;
	
	ss << squareDim;
	ss >> x;
	ss.ignore(2, ' ');
	ss >> y;
	ss.ignore(2, ' ');
	ss >> side;

	std::cout << x1 << std::endl << y1 << std::endl << side << std::endl << std::endl;
}


void GetPenInfo (std::ifstream& in, std::string& color, int& width, std::string& style, std::string& capStyle, std::string& joinStyle)
{
	in.ignore(10, ' ');
	getline(in, color);
	in.ignore(10, ' ');
	in >> width;
	in.ignore(1000, '\n');
	in.ignore(10, ' ');
	getline(in, style);
	in.ignore(13, ' ');
	getline(in, capStyle);
	in.ignore(14, ' ');
	getline(in, joinStyle);
}

void GetBrushInfo (std::ifstream& in, std::string& color, std::string& style)
{
	in.ignore(12, ' ');
	getline(in, color);
	in.ignore(12, ' ');
	getline(in, style);
}

void GetTextInfo (std::ifstream& in, std::string& text, std::string& color, std::string& alignment, int& size, 
		  std::string& fontFam, std::string& fontStyle, std::string& fontWeight)
{	
	in.ignore(12, ' ');
	getline(in, text);
	in.ignore(11, ' ');
	getline(in, color);
	in.ignore(15, ' ');
	getline (in, alignment);
	in.ignore(15, ' ');
	in >> size;
	in.ignore(1000, '\n');
	in.ignore(16, ' ');
	getline(in, fontFam);
	in.ignore(15, ' ');
	getline(in, fontStyle);
	in.ignore(16, ' ');
	getline(in, fontWeight);
}

void InputShapes ()
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
	std::ifstream in("shapes.txt");
	// exception??

	while(in)
	{
		in.ignore(9, ' ');
		in >> id;
		in.ignore(1000, '\n');
		
		in.ignore(11, ' ');
		getline(in, type);

		in.ignore (17, ' ');
		getline(in, dimensions);
		std::cout << std::endl << dimensions << std::endl;

		if(type[0] == 'L' || type == "Polyline")
		{
			std::cout << "Line is working";
		   	GetPenInfo (in, penColor, penWidth, penStyle, penCapStyle, penJoinStyle);
			std::cout << penColor << std::endl << penWidth << std::endl << penStyle << std::endl << penCapStyle << std::endl << penJoinStyle << std::endl;	
			std::cout << std::endl;
		}
		else if (type[0] == 'T')
		{
			std::cout << "Text is working";
			GetTextInfo (in, text, textColor, textAlign, textSize, textFont, textStyle, textWeight);
			std::cout << text << std::endl << textAlign << std::endl << textSize << std::endl << textFont << std::endl << textStyle << std::endl << textWeight;
			std::cout << std::endl << std::endl;
		}
		else
		{
			std::cout << "Polygon is working";
		   	GetPenInfo (in, penColor, penWidth, penStyle, penCapStyle, penJoinStyle);
			std::cout << penColor << std::endl << penWidth << std::endl << penStyle << std::endl << penCapStyle << std::endl << penJoinStyle << std::endl;	
			GetBrushInfo (in, brushColor, brushStyle);
			std::cout << brushColor << std::endl << brushStyle << std::endl << std::endl;
		}

		in.ignore (1000, '\n');
	}

	std::cout << std::endl;
	std::cout << id << std::endl;
	std::cout << type;

}

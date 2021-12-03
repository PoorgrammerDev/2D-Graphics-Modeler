
#include "InputManager.h"
#include "/Shapes/Shape.h"
#include "/Shapes/Line.h"
#include "/Shapes/Polyline.h"



/**********************
 * Method Definitions *
 **********************/

// Constructor & Destructor
InputManager:: InputManager() {}
InputManager:: ~InputManager() {}

/*******************************************
 * Not done updating this with the classes
 * and a lot of renderarea depends on it.
 * Need to:
 * - update some interpret dimension methods
 * - update the text information
 * - assign the type (thought I did this but
 *   apprently not, will be easy with how
 *   this is formatted)
 ******************************************/

// Method to read in shapes from input file 
void InputManager:: ReadShapes(vector<std::unique_ptr<Shape>> shapes)
{
    int id;
	std::string type;
	std::string dimensions;
	std::string text;
	std::string textColor;
	std::string textAlign;
	int textSize;
	std::string textFont;
	std::string textStyle;
	std::string textWeight;
    std::unique_ptr<Shape> aShape;


    // Should go away once done
	int x1;
	int x2;
	int y1;
	int y2;
	int x[50];
	int y[50];

    // Should be kept
    int point[10];
    int index = 0;

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
		
        // Within each stmt am allocating a new object assigning all the values and pushing back *Not done with this yet!
		if(type[0] == 'L')
		{
            aShape = std::make_unique<class Line>();
            // Getting pen information for line or polyline
            InterpretLineDimensions (dimensions, point[0], point[1], point[2], point[3]);
            aShape->setDimensions(point);
            GetPenInfo (in, aShape);
            shapes.push_back(std::move(aShape));

		}	
		else if(type == "Polyline")
		{
            aShape = std::make_unique<class PolyLine>();
            // Getting pen information for line or polyline
            InterpretPolyDimensions (dimensions, point);
            // Load dimensions
            GetPenInfo (in, aShape);
		}
		else if (type[0] == 'T')
		{
            //shapes[index].setShapeType(Text);
			// Getting text information for texts
			GetTextInfo (in, text, textColor, textAlign, textSize, textFont, textStyle, textWeight);
			InterpretRectDimensions (dimensions, x1, y1, x2, y2);
		}
        else if (type[0] == 'R')
		{
            aShape = std::make_unique<class Rectangle>();
			// Getting pen & brush information
            GetPenInfo (in, aShape);
            GetBrushInfo (in, aShape);
            InterpretRectDimensions (dimensions, x1, y1, x2, y2);

        }
        else if (type[0] == 'E')
        {
            GetPenInfo (in, aShape);
            GetBrushInfo (in, aShape);
            InterpretRectDimensions (dimensions, x1, y1, x2, y2);
        }
        else if (type == "Polygon")
        {
            GetPenInfo (in, aShape);
            GetBrushInfo (in, aShape);
            InterpretPolyDimensions (dimensions, x, y);
        }

		// Ignore for extra line between each shape
		in.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
	}

	in.close();
}

// Reading pen information from file
void InputManager:: GetPenInfo (std::ifstream& in, std::unique_ptr<Shape>& shape)
{
    std::string penInfo;
    int width;

	in.ignore(10, ' '); // Ignoring "PenColor: "
    getline(in, penInfo);
    QString colorQ(penInfo.c_str());
	in.ignore(10, ' '); // Ignoring "PenWidth: "
	in >> width;
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Usual ignore for >> to getline
	in.ignore(10, ' '); // Ignoring "PenStyle: "
    getline(in, penInfo);
    QString styleQ(penInfo.c_str());
	in.ignore(13, ' '); // Ignoring "PenCapStyle: "
    getline(in, penInfo);
    QString capQ(penInfo.c_str());
	in.ignore(14, ' '); // Ignoring "PenJoinStyle: "
    getline(in, penInfo);
    QString joinQ(penInfo.c_str());
    shape->setPen(GColorFromStr(colorQ), width, PenStyleFromStr(styleQ), PenCapStyleFromStr(capQ), PenJoinStyleFromStr(joinQ));

}

// Reading brush information from file
void InputManager:: GetBrushInfo (std::ifstream& in, std::unique_ptr<Shape>& shape)
{
    std::string brushInfo;
	in.ignore(12, ' '); // Ignoring "BrushColor: "
    getline(in, brushInfo);
    QString colorQ(brushInfo.c_str());
	in.ignore(12, ' '); // Ignoring "BrushStyle: "
    getline(in, brushInfo);
    QString styleQ(brushInfo.c_str());
    shape->setBrush(GColorFromStr(colorQ), BrushStyleFromStr(styleQ));
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


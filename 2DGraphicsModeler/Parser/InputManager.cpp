
#include "InputManager.h"
#include "Shapes/Shape.h"
#include "Shapes/Ellipse.h"
#include "Shapes/Line.h"
#include "Shapes/Polygon.h"
#include "Shapes/Polyline.h"
#include "Shapes/Rectangle.h"
#include "Shapes/Text.h"


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
void InputManager:: ReadShapes(vector<std::unique_ptr<Shape>>& shapes)
{
    int id;
    std::string type;
    std::string dimensions;
    std::unique_ptr<Shape> aShape;
    int index = 0;

    // Should be kept
    int points[20];

    std::ifstream in("..\\2DGraphicsModeler\\shapes.txt");
    if (in.fail()) {
        std::cerr << "Shapes input file failed to open.\n";
        return; // Doesn't terminate the entire program - will just keep running with no starting shapes.
    }

    while(!in.eof())
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
            aShape = std::make_unique<Line>();
            aShape->SetShapeType(ShapeType::Line);
            // Getting pen information for line or polyline
            InterpretLineDimensions (dimensions, aShape, points);
            GetPenInfo (in, aShape);
        }
        else if(type == "Polyline")
        {
            aShape = std::make_unique<Polyline>();
            aShape->SetShapeType(ShapeType::Polyline);
            // Getting pen information for line or polyline
            InterpretPolyDimensions (dimensions, aShape, points, 20);
            // Load dimensions
            GetPenInfo (in, aShape);
        }
        else if (type[0] == 'T')
        {
            aShape = std::make_unique<class Text>();
            aShape->SetShapeType(ShapeType::Text);
            // Getting text information for texts
            GetTextInfo (in, aShape);
            InterpretRectDimensions (dimensions, aShape, points, type);
        }
        else if (type[0] == 'R' || type[0] == 'S')
        {
            aShape = std::make_unique<Rectangle>();
            aShape->SetShapeType(ShapeType::Rectangle);
            // Getting pen & brush information
            GetPenInfo (in, aShape);
            GetBrushInfo (in, aShape);
            InterpretRectDimensions (dimensions, aShape, points, type);

        }
        else if (type[0] == 'E' || type[0] == 'C')
        {
            aShape = std::make_unique<Ellipse>();
            aShape->SetShapeType(ShapeType::Ellipse);
            GetPenInfo (in, aShape);
            GetBrushInfo (in, aShape);
            InterpretRectDimensions (dimensions, aShape, points, type);
        }
        else if (type == "Polygon")
        {
            aShape = std::make_unique<Polygon>();
            aShape->SetShapeType(ShapeType::Polygon);
            GetPenInfo (in, aShape);
            GetBrushInfo (in, aShape);
            InterpretPolyDimensions (dimensions, aShape, points, 20);
        }

        aShape->SetShapeId(id);
        shapes.push_back(std::move(aShape));

        ++index;

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
    shape->SetPen(GColorFromStr(colorQ), width, PenStyleFromStr(styleQ), PenCapStyleFromStr(capQ), PenJoinStyleFromStr(joinQ));

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
    shape->SetBrush(GColorFromStr(colorQ), BrushStyleFromStr(styleQ));
}

// Reading text information from file
void InputManager:: GetTextInfo (std::ifstream& in, std::unique_ptr<Shape>& shape)
{
    std::string textInfo;
    int size;
    in.ignore(12, ' '); // Ignoring "TextString: "
    getline(in, textInfo);
    QString textQ(textInfo.c_str());
    shape->SetText(textQ);
    in.ignore(11, ' '); // Ignoring "TextColor: "
    getline(in, textInfo);
    QString colorQ(textInfo.c_str());
    shape->SetTextColor(GColorFromStr(colorQ));
    in.ignore(15, ' '); // Ignoring "TextAlignment: "
    getline (in, textInfo);
    QString alignQ(textInfo.c_str());
    shape->SetTextAlign(AlignFlagFromStr(alignQ));
    in.ignore(15, ' '); // Ignoring "TextPointSize: "
    in >> size;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Usual ignore for >> to getline
    in.ignore(16, ' '); // Ignoring "TextFontFamily: "
    getline(in, textInfo);
    QString fontFamQ(textInfo.c_str());
    in.ignore(15, ' '); // Ignoring "TextFontStyle: "
    getline(in, textInfo);
    QString fontStyleQ(textInfo.c_str());
    in.ignore(16, ' '); // Ignoring "TextFontWeight: "
    getline(in, textInfo);
    QString fontWeightQ(textInfo.c_str());
    shape->SetFont(size, fontFamQ, FontStyleFromStr(fontStyleQ), FontWeightFromStr(fontWeightQ));
}

// Converting string of dimensions into individual ints
void InputManager:: InterpretLineDimensions (std::string lineDim, std::unique_ptr<Shape>& shape, int dimensions[])
{
    // Using stringstream to extract integer points
    std::stringstream ss;

    ss << lineDim;
    ss >> dimensions[0];
    ss.ignore(2, ' '); // Ignoring ", "
    ss >> dimensions[2];
    ss.ignore(2, ' '); // Ignoring ", "
    ss >> dimensions[3];
    ss.ignore(2, ' '); // Ignoring ", "
    ss >> dimensions[4];
    shape->SetDimensions(dimensions);
}

// Converting string of dimensions into individual ints
void InputManager:: InterpretPolyDimensions (std::string polyDim, std::unique_ptr<Shape>& shape, int dimensions[], int size)
{
    int index = 0;

    //Using stringstream to extract integer points
    std::stringstream ss;

    ss << polyDim;
    while(index < size && ss)
    {
        ss >> dimensions[index];
        ss.ignore(2, ' '); // Ignoring ", "
        ss >> dimensions[index+1];
        ss.ignore(2, ' '); // Ignoring ", "

        ++index;
        ++index;
    }
    shape->SetDimensions(dimensions);
}

// Converting string of dimensions into individual ints
void InputManager:: InterpretRectDimensions (std::string rectDim, std::unique_ptr<Shape>& shape, int dimensions[], std::string type)
{
    // Using stringstream to extract integer points
    std::stringstream ss;

    ss << rectDim;
    ss >> dimensions[0];
    ss.ignore(2, ' '); // Ignoring ", "
    ss >> dimensions[1];
    ss.ignore(2, ' '); // Ignoring ", "
    ss >> dimensions[2];

    if(type[0] == 'S' || type[0] == 'C')
    {
        dimensions[3] = dimensions[2];
    }
    else
    {
        ss.ignore(2, ' '); // Ignoring ", "
        ss >> dimensions[3];
    }

    shape->SetDimensions(dimensions);
}

// Converting string of dimensions into individual ints
//void InputManager:: InterpretSquareDimensions (std::string squareDim, int& x, int& y, int& side)
//{
//	// Using stringstream to extract integer points
//	std::stringstream ss;

//	ss << squareDim;
//	ss >> x;
//	ss.ignore(2, ' '); // Ignoring ", "
//	ss >> y;
//	ss.ignore(2, ' '); // Ignoring ", "
//	ss >> side;
//}



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
InputManager::InputManager() {}
InputManager::~InputManager() {}

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
void InputManager::ReadShapes(vector<std::unique_ptr<Shape>>& shapes)
{
    int id;
    int points[20];
    std::string type;
    std::string dimensions;
    std::unique_ptr<Shape> aShape;

    QPen pen;
    QBrush brush;
    Qt::GlobalColor penColor;
    Qt::GlobalColor brushColor;
    TextData textData;

    std::ifstream in;

    //For some reason when I run this on my Mac, it needs a different path to get to the same place - Thomas
    //So I added some pre-processor directives that (hopefully) detect this
#if __APPLE__ && TARGET_OS_MAC
    in.open("../../../../2DGraphicsModeler/shapes.txt");
#else
    in.open("..\\2DGraphicsModeler\\shapes.txt");
#endif

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

        // Within each stmt am allocating a new object assigning all the values and pushing back
        if(type == "Line")
        {
            pen = GetPenInfo(in, penColor);
            PopulateLineDimensions(dimensions, points);
            aShape = std::make_unique<Line>(id, pen, penColor, points);
        }
        else if(type == "Polyline")
        {
            pen = GetPenInfo(in, penColor);
            PopulatePolyDimensions(dimensions, points, 20);
            aShape = std::make_unique<Polyline>(id, pen, penColor, points);
        }
        else if (type == "Text")
        {
            textData = GetTextInfo(in);
            PopulateRectDimensions(dimensions, points, ShapeType::Text);
            aShape = std::make_unique<Text>(id, textData, points);
        }
        else if (type == "Rectangle")
        {
            pen = GetPenInfo(in, penColor);
            brush = GetBrushInfo(in, brushColor);
            PopulateRectDimensions(dimensions, points, ShapeType::Rectangle);
            aShape = std::make_unique<Rectangle>(id, ShapeType::Rectangle, pen, penColor, brush, brushColor, points);
        }
        else if (type == "Square") {
            pen = GetPenInfo(in, penColor);
            brush = GetBrushInfo(in, brushColor);
            PopulateRectDimensions(dimensions, points, ShapeType::Square);
            aShape = std::make_unique<Rectangle>(id, ShapeType::Square, pen, penColor, brush, brushColor, points);
        }
        else if (type == "Ellipse")
        {
            pen = GetPenInfo(in, penColor);
            brush = GetBrushInfo(in, brushColor);
            PopulateRectDimensions(dimensions, points, ShapeType::Ellipse);
            aShape = std::make_unique<Ellipse>(id, ShapeType::Ellipse, pen, penColor, brush, brushColor, points);
        }
        else if (type == "Circle") {
            pen = GetPenInfo(in, penColor);
            brush = GetBrushInfo(in, brushColor);
            PopulateRectDimensions(dimensions, points, ShapeType::Circle);
            aShape = std::make_unique<Ellipse>(id, ShapeType::Circle, pen, penColor, brush, brushColor, points);
        }
        else if (type == "Polygon")
        {
            pen = GetPenInfo(in, penColor);
            brush = GetBrushInfo(in, brushColor);
            PopulatePolyDimensions(dimensions, points, 20); //TODO: remove magic number
            aShape = std::make_unique<Polygon>(id, pen, penColor, brush, brushColor, points);
        }

        shapes.push_back(std::move(aShape));

        // Ignore for extra line between each shape
        in.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    }
    in.close();
}

// Reading pen information from file
QPen InputManager::GetPenInfo (std::ifstream& in, Qt::GlobalColor& colorOut)
{
    QPen pen;
    std::string penInfo;
    int width;


    //Read in attributes from file
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

    //Set attributes
    colorOut = GColorFromStr(colorQ);
    pen.setColor(colorOut);
    pen.setWidth(width);
    pen.setStyle(PenStyleFromStr(styleQ));
    pen.setCapStyle(PenCapStyleFromStr(capQ));
    pen.setJoinStyle(PenJoinStyleFromStr(joinQ));
    return pen;
}

// Reading brush information from file
QBrush InputManager::GetBrushInfo (std::ifstream& in, Qt::GlobalColor& colorOut)
{
    QBrush brush;
    std::string brushInfo;

    //Read attributes in from file
    in.ignore(12, ' '); // Ignoring "BrushColor: "
    getline(in, brushInfo);
    QString colorQ(brushInfo.c_str());
    in.ignore(12, ' '); // Ignoring "BrushStyle: "
    getline(in, brushInfo);
    QString styleQ(brushInfo.c_str());

    //Set attributes
    colorOut = GColorFromStr(colorQ);
    brush.setColor(colorOut);
    brush.setStyle(BrushStyleFromStr(styleQ));
    return brush;
}

// Reading text information from file
TextData InputManager::GetTextInfo (std::ifstream& in)
{
    TextData output;
    QFont font;
    std::string textInfo;
    int size;

    //Getting attributes from file
    in.ignore(12, ' '); // Ignoring "TextString: "
    getline(in, textInfo);
    QString textQ(textInfo.c_str());

    in.ignore(11, ' '); // Ignoring "TextColor: "
    getline(in, textInfo);
    QString colorQ(textInfo.c_str());

    in.ignore(15, ' '); // Ignoring "TextAlignment: "
    getline (in, textInfo);
    QString alignQ(textInfo.c_str());

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

    //Setting attributes
    font.setPointSize(size);
    font.setFamily(fontFamQ);
    font.setStyle(FontStyleFromStr(fontStyleQ));
    font.setWeight(FontWeightFromStr(fontWeightQ));

    output.text = textQ;
    output.textColor = GColorFromStr(colorQ);
    output.textAlign = AlignFlagFromStr(alignQ);
    output.font = font;

    return output;
}

// Converting string of dimensions into individual ints
void InputManager::PopulateLineDimensions(std::string lineDim, int dimensions[])
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
}

// Converting string of dimensions into individual ints
void InputManager::PopulatePolyDimensions (std::string polyDim, int dimensions[], int size)
{
    int index = 0;

    //Using stringstream to extract integer points
    std::stringstream ss;

    ss << polyDim;
    while(index < size && ss)
    {
        ss >> dimensions[index];
        ss.ignore(2, ' '); // Ignoring ", "
        ++index;

        ss >> dimensions[index];
        ss.ignore(2, ' '); // Ignoring ", "
        ++index;
    }
}

// Converting string of dimensions into individual ints
void InputManager::PopulateRectDimensions (std::string rectDim, int dimensions[], ShapeType type)
{
    // Using stringstream to extract integer points
    std::stringstream ss;

    ss << rectDim;
    ss >> dimensions[0];
    ss.ignore(2, ' '); // Ignoring ", "
    ss >> dimensions[1];
    ss.ignore(2, ' '); // Ignoring ", "
    ss >> dimensions[2];

    if(type == ShapeType::Square || type == ShapeType::Circle)
    {
        dimensions[3] = dimensions[2];
    }
    else
    {
        ss.ignore(2, ' '); // Ignoring ", "
        ss >> dimensions[3];
    }
}

// Converting string of dimensions into individual ints
//void InputManager::InterpretSquareDimensions (std::string squareDim, int& x, int& y, int& side)
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


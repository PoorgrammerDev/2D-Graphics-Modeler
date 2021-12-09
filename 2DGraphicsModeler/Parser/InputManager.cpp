
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


// Method to read in shapes from input file
void InputManager::ReadShapes(vector<std::unique_ptr<Shape>>& shapes)
{
    int id;
    int points[20] = {};
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
        // TODO Discuss how we want to implement shape type invalid
        // 1. make an invalid type, make if statement a switch and the invalid case ignores enough lines to reset until new shape
        // 2. not have a type or method for invalid shape and instead add an else to the if stmts that ignores lines until next shape

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
QPen InputManager::GetPenInfo (std::ifstream& in, Qt::GlobalColor& colorOut) // Do we need this colorout parameter, isn't already covered in pen (same with brush)
{
    QPen pen;
    std::string penInfo;
    int width;


    //Read in and set attributes from file
    in.ignore(10, ' '); // Ignoring "PenColor: "
    getline(in, penInfo);
    pen.setColor(CheckColor(penInfo.c_str()));
    QString colorQ(penInfo.c_str()); //delete if error checking works

    in.ignore(10, ' '); // Ignoring "PenWidth: "
    in >> width;
    pen.setWidth(CheckSize(width, 0, 20));
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Usual ignore for >> to getline

    in.ignore(10, ' '); // Ignoring "PenStyle: "
    getline(in, penInfo);
    pen.setStyle(CheckPenStyle(penInfo.c_str()));

    in.ignore(13, ' '); // Ignoring "PenCapStyle: "
    getline(in, penInfo);
    pen.setCapStyle(CheckCapStyle(penInfo.c_str()));

    in.ignore(14, ' '); // Ignoring "PenJoinStyle: "
    getline(in, penInfo);
    pen.setJoinStyle(CheckJoinStyle(penInfo.c_str()));

    //Set attributes
    colorOut = GColorFromStr(colorQ);

    return pen;
}

// Reading brush information from file
QBrush InputManager::GetBrushInfo (std::ifstream& in, Qt::GlobalColor& colorOut)
{
    QBrush brush;
    std::string brushInfo;

    //Read and set attributes in from file
    in.ignore(12, ' '); // Ignoring "BrushColor: "
    getline(in, brushInfo);
    brush.setColor(CheckColor(brushInfo.c_str()));
    QString colorQ(brushInfo.c_str());

    in.ignore(12, ' '); // Ignoring "BrushStyle: "
    getline(in, brushInfo);
    brush.setStyle(CheckBrushStyle(brushInfo.c_str()));

    //Set attributes
    colorOut = GColorFromStr(colorQ);

    return brush;
}

// Reading text information from file
TextData InputManager::GetTextInfo (std::ifstream& in)
{
    TextData output;
    QFont font;
    std::string textInfo;
    int size;

    //Getting and setting attributes from file
    in.ignore(12, ' '); // Ignoring "TextString: "
    getline(in, textInfo);
    QString textQ(textInfo.c_str());

    in.ignore(11, ' '); // Ignoring "TextColor: "
    getline(in, textInfo);
    output.textColor = CheckColor(textInfo.c_str());

    in.ignore(15, ' '); // Ignoring "TextAlignment: "
    getline (in, textInfo);
    output.textAlign = CheckTextAlign(textInfo.c_str());

    in.ignore(15, ' '); // Ignoring "TextPointSize: "
    in >> size;
    font.setPointSize(CheckSize(size, -1, 50));
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Usual ignore for >> to getline

    in.ignore(16, ' '); // Ignoring "TextFontFamily: "
    getline(in, textInfo);
    QString fontFamQ(textInfo.c_str());

    in.ignore(15, ' '); // Ignoring "TextFontStyle: "
    getline(in, textInfo);
    font.setStyle(CheckFontStyle(textInfo.c_str()));

    in.ignore(16, ' '); // Ignoring "TextFontWeight: "
    getline(in, textInfo);
    font.setWeight(CheckFontWeight(textInfo.c_str()));

    //Setting attributes
    font.setFamily(fontFamQ);

    // Loading all text info into struct
    output.text = textQ;
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
    ss >> dimensions[1];
    ss.ignore(2, ' '); // Ignoring ", "
    ss >> dimensions[2];
    ss.ignore(2, ' '); // Ignoring ", "
    ss >> dimensions[3];
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

QPen InputManager::GetPenInfo(Qt::GlobalColor& colorOut, QString penColorStr, int penWidth, QString penStyleStr, QString penCapStyleStr, QString penJoinStyleStr) {
    QPen pen;

    colorOut = CheckColor(penColorStr);
    pen.setColor(colorOut);

    pen.setWidth(CheckSize(penWidth, 0, 20));
    pen.setStyle(CheckPenStyle(penStyleStr));
    pen.setCapStyle(CheckCapStyle(penCapStyleStr));
    pen.setJoinStyle(CheckJoinStyle(penJoinStyleStr));

    return pen;
}

QBrush InputManager::GetBrushInfo(Qt::GlobalColor& colorOut, QString brushColorStr, QString brushStyleStr) {
    QBrush brush;

    colorOut = CheckColor(brushColorStr);
    brush.setColor(colorOut);
    brush.setStyle(CheckBrushStyle(brushStyleStr));

    return brush;
}

TextData InputManager::GetTextData (QString textContents, QString textColorStr, QString textAlignStr, int pointSize, QString fontFamilyStr, QString fontStyleStr, QString fontWeightStr) {
    TextData data;
    QFont font;

    font.setPointSize(pointSize);
    font.setFamily(fontFamilyStr);
    font.setWeight(CheckFontWeight(fontWeightStr));
    font.setStyle(CheckFontStyle(fontStyleStr));

    data.text = textContents;
    data.textColor = CheckColor(textColorStr);
    data.textAlign = CheckTextAlign(textAlignStr);
    data.font = font;

    return data;
}

/*
ShapeType InputManager::CheckShapeType (std::string shape)
{
    try {
        return ShapeFromStr(shape.c_str());
    }  catch (std::invalid_argument) {
        // Maybe add invalid in enum and handle in switch by ignoring all the rest of the lines of that shape (skip the shape)
        // return ShapeType::Invalid;
    }
}
*/
Qt::GlobalColor InputManager::CheckColor (QString color)
{
    try {
        return GColorFromStr(color);
    }  catch (std::invalid_argument&) {
        return Qt::black;
    }
}

int InputManager::CheckSize (int size, int min, int max)
{
    if(size >= min && size <= max)
        return size;
    else
        return min;
}

Qt::PenStyle InputManager::CheckPenStyle (QString style)
{
    try {
        return PenStyleFromStr(style);
    }  catch (std::invalid_argument&) {
        return Qt::SolidLine; // maybe no pen instead? what is no pen?
    }
}

Qt::PenCapStyle InputManager::CheckCapStyle (QString style)
{
    try {
        return PenCapStyleFromStr(style);
    }  catch (std::invalid_argument&) {
        return Qt::FlatCap;
    }
}

Qt::PenJoinStyle InputManager::CheckJoinStyle (QString style)
{
    try {
        return PenJoinStyleFromStr(style);
    }  catch (std::invalid_argument&) {
        return Qt::MiterJoin;
    }
}

Qt::BrushStyle InputManager::CheckBrushStyle (QString style)
{
    try {
        return BrushStyleFromStr(style);
    }  catch (std::invalid_argument&) {
        return Qt::SolidPattern; // maybe no brush, what is no brush?
    }
}

Qt::AlignmentFlag InputManager::CheckTextAlign (QString align)
{
    try {
        return AlignFlagFromStr(align);
    }  catch (std::invalid_argument&) {
        return Qt::AlignLeft;
    }
}

QFont::Style InputManager::CheckFontStyle (QString style)
{
    try {
        return FontStyleFromStr(style);
    }  catch (std::invalid_argument&) {
        return QFont::StyleNormal;
    }
}

QFont::Weight InputManager::CheckFontWeight (QString weight)
{
    try {
        return FontWeightFromStr(weight);
    }  catch (std::invalid_argument&) {
        return QFont::Normal;
    }
}



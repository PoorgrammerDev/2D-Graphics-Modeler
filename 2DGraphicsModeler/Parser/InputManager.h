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
#include "../Shapes/Text.h"
#include "../Util/EnumStrConv.h"

class InputManager
{
	public:
		InputManager();
		~InputManager();

        void ReadShapes(vector<std::unique_ptr<Shape>>& shapes);

        //Moved these to public so RenderArea can use these methods
        void PopulateLineDimensions (std::string lineDim, int dimensions[]);
        void PopulateRectDimensions (std::string rectDim, int dimensions[], ShapeType type);
        void PopulatePolyDimensions (std::string polyDim, int dimensions[], int size);

        ShapeType CheckShapeType (std::string shape);
        Qt::GlobalColor CheckColor (std::string color);
        int CheckSize (int size, int min, int max);
        Qt::PenStyle CheckPenStyle (std::string style);
        Qt::PenCapStyle CheckCapStyle (std::string style);
        Qt::PenJoinStyle CheckJoinStyle (std::string style);
        Qt::BrushStyle CheckBrushStyle (std::string style);
        Qt::AlignmentFlag CheckTextAlign (std::string align);
        QFont::Style CheckFontStyle (std::string style);
        QFont::Weight CheckFontWeight (std::string weight);

	private:
        QPen GetPenInfo(std::ifstream& in, Qt::GlobalColor& colorOut);
        QBrush GetBrushInfo(std::ifstream& in,  Qt::GlobalColor& colorOut);
        TextData GetTextInfo(std::ifstream& in);

};	

#endif

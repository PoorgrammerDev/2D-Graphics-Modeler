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

        //This is an overload to the private methods
        //Gets QPen from individual string fields instead of a stream (used in RenderArea)
        QPen GetPenInfo(Qt::GlobalColor& colorOut, QString penColorStr, int penWidth, QString penStyleStr, QString penCapStyleStr, QString penJoinStyleStr);
        QBrush GetBrushInfo(Qt::GlobalColor& colorOut, QString brushColorStr, QString brushStyleStr);
        TextData GetTextData (QString textContents, QString textColorStr, QString textAlignStr, int pointSize, QString fontFamilyStr, QString fontStyleStr, QString fontWeightStr);

        void PopulateLineDimensions (std::string lineDim, int dimensions[]);
        void PopulateRectDimensions (std::string rectDim, int dimensions[], ShapeType type);
        int PopulatePolyDimensions (std::string polyDim, int dimensions[], int maxSize);

	private:
        QPen GetPenInfo(std::ifstream& in, Qt::GlobalColor& colorOut);
        QBrush GetBrushInfo(std::ifstream& in,  Qt::GlobalColor& colorOut);
        TextData GetTextInfo(std::ifstream& in);

        int CheckSize (int size, int min, int max);
        Qt::PenStyle CheckPenStyle (QString style);
        Qt::PenCapStyle CheckCapStyle (QString style);
        Qt::PenJoinStyle CheckJoinStyle (QString style);
        Qt::BrushStyle CheckBrushStyle (QString style);
        Qt::AlignmentFlag CheckTextAlign (QString align);
        QFont::Style CheckFontStyle (QString style);
        QFont::Weight CheckFontWeight (QString weight);
        Qt::GlobalColor CheckColor (QString color);

};	

#endif

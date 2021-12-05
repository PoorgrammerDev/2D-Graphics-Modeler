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

	private:
        QPen GetPenInfo(std::ifstream& in, Qt::GlobalColor& colorOut);
        QBrush GetBrushInfo(std::ifstream& in,  Qt::GlobalColor& colorOut);
        TextData GetTextInfo(std::ifstream& in);

        // Some are done, some need a little more work
        void PopulateLineDimensions (std::string lineDim, int dimensions[]);
        void PopulateRectDimensions (std::string rectDim, int dimensions[], ShapeType type);
        void PopulatePolyDimensions (std::string polyDim, int dimensions[], int size);
};	

#endif

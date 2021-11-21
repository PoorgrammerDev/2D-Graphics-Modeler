

// input stuff
//

#include <iostream>
#include <iomanip>
#include <fstream>


enum shapeType
{
	LINE,
	POLYGON,
	TEXT
};

void InputShapes ();
void GetPenInfo (std::ifstream& in, std::string& color, int& width, std::string& style, std::string& capStyle, std::string& joinStyle);
void GetBrushInfo (std::ifstream& in, std::string& color, std::string& style);
void GetTextInfo (std::ifstream& in, std::string& text, std::string& color, std::string& alignment, int& size,
		  std::string& fontFam, std::string& fontStyle, std::string& fontWeight);

int main()
{
	InputShapes();
	std::cout << std::endl << "Test" << std::endl;
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

/*! \file rectangle.h
	\brief Declaration of the class Rectangle

	Details.
*/


#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "polygon.h"

using namespace std;

/// @class Rectangle
/// @brief to manage an object with the shape of a rectangle
class Rectangle :public Polygon
{
private:
	float length;
	float width;
	float Area();				//If there are other subclasses	this is virtual
	float Perimeter();			//If there are other subclasses	this is virtual


public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Rectangle();
	Rectangle(float w, float l);
	Rectangle(const Rectangle& r);

	~Rectangle();			//Virtual if there are subclasses
	
	/// @}
	

	/// @name OPERATORS
	/// @{
	Rectangle& operator=(const Rectangle& r);
	bool operator==(const Rectangle& r);
	/// @}

	/// @name BASIC HANDLING
	/// @{
	void Init();
	void Init(const Rectangle& r);
	void Reset();
	/// @}


	/// @name GETTERS / SETTERS
	/// @{
	void SetDim(float w, float l);
	void SetLength(float l);
	void SetWidth(float w);

	void GetDim(float& w, float& l);
	float GetLength();
	float GetWidth();

	float GetArea();
	float GetPerimeter();
	/// @}

	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char* string);
	void WarningMessage(const char* string);
	void Dump();
	/// @}

	/// @name DRAW
	/// @{
	void Draw();
	/// @}

};

#endif

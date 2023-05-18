/*! \file rhombus.h
	\brief Declaration of the class Rhombus

	Details.
*/


#ifndef RHOMBUS_H
#define RHOMBUS_H

using namespace std;
#include "polygon.h"

/// @class Rhombus
/// @brief to manage an object with the shape of a rhombus
class Rhombus :public Polygon
{
private:
	float diagH;
	float diagV;
	float Side();
	float Area();				//If there are other subclasses	this is virtual
	float Perimeter();			//If there are other subclasses	this is virtual



public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Rhombus();
	Rhombus(float dH, float dV);
	Rhombus(const Rhombus& r);

	~Rhombus();								//Virtual if there are subclasses
	/// @}

	/// @name OPERATORS
	/// @{
	Rhombus& operator=(const Rhombus& r);
	bool operator==(const Rhombus& r);
	/// @}

	/// @name BASIC HANDLING
	/// @{
	void Init();
	void Init(const Rhombus& r);
	void Reset();
	/// @}


	/// @name GETTERS / SETTERS
	/// @{
	void SetDim(float dH, float dV);
	void SetDiagH(float dH);
	void SetDiagV(float dV);

	void GetDiagonals(float& dH, float& dV);
	float GetDiagH();
	float GetDiagV();
	float GetSide();

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
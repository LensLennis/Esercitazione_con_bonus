/*! \file polygon.h
	\brief Declaration of the general class Polygon

	Details.
*/


#ifndef POLYGON_H
#define POLYGON_H

#include<iostream>

using namespace std;

/// @class Polygon
/// @brief an abstract base class for polygons
class Polygon {
protected:
	float perimeter; 
	float area;
	
	virtual float Area()=0;
	virtual float Perimeter()=0;

public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Polygon();
	Polygon(const Polygon &p);
	virtual ~Polygon();
	/// @}
	
	/// @name OPERATORS
	/// @{
	Polygon& operator=(const Polygon &p); 
	bool operator==(const Polygon &p);
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();												
	void Init(const Polygon &r);							
	void Reset();												
	/// @}

			
	/// @name GETTERS
	/// @{
	float GetArea();
	float GetPerimeter();
	/// @}

	/// @name DRAWING
	/// @{
	virtual void Draw() = 0; 
	/// @}
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}

};

#endif
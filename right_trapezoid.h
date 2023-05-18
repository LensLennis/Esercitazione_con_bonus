/*! \file right_trapezoid.h
	\brief Declaration of the class Right_trapezoid

	Details.
*/


#ifndef RIGHT_TRAPEZOID_H
#define RIGHT_TRAPEZOID_H

#include "polygon.h"
using namespace std;

/// @class right_trapezoid
/// @brief to manage an object with the shape of a right_trapezoid
class Right_trapezoid : public Polygon
{
private:
	float top_side;
	float height;
	float bottom_side;
	float CalcSide();			//If there are other subclasses	this is virtual
	float Area();				//If there are other subclasses	this is virtual
	float Perimeter();			//If there are other subclasses	this is virtual

public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Right_trapezoid();
	Right_trapezoid(float ts, float h, float bs);
	Right_trapezoid(const Right_trapezoid& rt);

	~Right_trapezoid();			//If there are other subclasses	this is virtual
	/// @}

	/// @name OPERATORS
	/// @{
	Right_trapezoid& operator=(const Right_trapezoid& rt);
	bool operator==(const Right_trapezoid& rt);
	/// @}

	/// @name BASIC HANDLING
	/// @{
	void Init();
	void Init(const Right_trapezoid& rt);
	void Reset();
	/// @}


	/// @name GETTERS / SETTERS
	/// @{
	void SetDim(float ts, float h, float bs);
	void SetTopSide(float ts);
	void SetHeight(float h);
	void SetBottomSide(float bs);

	void GetDim(float& ts, float& h, float& bs);
	float GetTopSide();
	float GetHeight();
	float GetBottomSide();

	float GetArea();
	float GetPerimeter();

	float GetSide();
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

/// @brief defines the operator <<
/// @param out output
/// @param r right operand
/// @return output
ostream& operator<< (ostream& out, Right_trapezoid& r);

/// @brief defines the operator >>
/// @param in input
/// @param r right operand
/// @return input
istream& operator>> (istream& in, Right_trapezoid& r);

#endif
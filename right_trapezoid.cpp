/// \file right_trapezoid.cpp
///	\brief class right trapezoid: implementation of the functions
///
///	Details.
///

#include<iostream>
#include "right_trapezoid.h"

/// @brief default constructor 
Right_trapezoid::Right_trapezoid() {

	Init();
	cout << "Right trapezoid - constructor - default" << endl;
}

/// @brief constructor
/// @param ts top side
/// @param h height
/// @param bs bottom side
Right_trapezoid::Right_trapezoid(float ts, float h, float bs) {

	Init();
	SetDim(ts, h, bs);
	cout << "Right trapezoid - constructor" << endl;
}


/// @brief destructor 
Right_trapezoid::~Right_trapezoid() {
	
	Reset();
	cout << "Right trapezoid - destructor" << endl;
}

/// @brief copy constructor 
/// @param rt reference to the object that should be copied 
Right_trapezoid::Right_trapezoid(const Right_trapezoid& rt) {

	Init(rt);
	cout << "Right trapezoid - copy constructor" << endl;

}

/// @brief overload of operator = 
/// @param rt reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
Right_trapezoid& Right_trapezoid::operator=(const Right_trapezoid& rt) {

	cout << "Right trapezoid - operator =" << endl;

	Init(rt);

	return *this;

}

/// @brief overload of operator == 
/// @param rt reference to the object on the right side of the operator 
/// @return true if the two objects have the same top side, height and bottom side  
bool Right_trapezoid::operator==(const Right_trapezoid& rt) {

	if (rt.top_side == top_side && rt.height == height && rt.bottom_side == bottom_side)
		return true;

	return false;
}

/// @brief default initialization of the object
void Right_trapezoid::Init() {
	Reset();
	top_side = 0.;
	height = 0.;
	bottom_side = 0.;
}

/// @brief initialization of the object as a copy of an object 
/// @param rt reference to the object that should be copied 
void Right_trapezoid::Init(const Right_trapezoid& rt) {
	Reset();
	top_side = rt.top_side;
	height = rt.height;
	bottom_side = rt.bottom_side;
}

/// @brief total reset of the object  
void Right_trapezoid::Reset() {
	top_side = 0.;
	height = 0.;
	bottom_side = 0.;
}

/// @brief setting the top side
/// @param ts top side
void Right_trapezoid::SetTopSide(float ts) {

	if (ts <= 0.)
		ErrorMessage("constructor : top side length should be > 0");
	else
		top_side = ts;

}

/// @brief setting the height
/// @param h height
void Right_trapezoid::SetHeight(float h) {

	if (h <= 0.)
		ErrorMessage("constructor: height should be > 0");
	else
		height = h;

}

/// @brief setting bottom side
/// @param bs bottom side
void Right_trapezoid::SetBottomSide(float bs) {

	if (bs <= 0.)
		ErrorMessage("constructor: bottom side length should be > 0");
	else
		bottom_side = bs;


}

/// @brief setting all dimensions
/// @param ts top side
/// @param h height
/// @param bs bottom side
void Right_trapezoid::SetDim(float ts, float h, float bs) {

	SetTopSide(ts);
	SetHeight(h);
	SetBottomSide(bs);
}

/// @brief calculating oblique side 
/// @return side
float Right_trapezoid::CalcSide() {

	return (sqrt((top_side - bottom_side) * (top_side - bottom_side) + (height * height)));
}


/// @brief Area calculus
/// @return area
float Right_trapezoid::Area() {

	return ((top_side + bottom_side) * height / 2);

}

/// @brief Perimeter calculus
/// @return perimeter
float Right_trapezoid::Perimeter() {

	return (top_side + bottom_side + height + CalcSide());

}


/// @brief getting top side dimension
/// @return top side
float Right_trapezoid::GetTopSide() {

	return top_side;

}

/// @brief getting height dimension
/// @return height
float Right_trapezoid::GetHeight() {

	return height;

}

/// @brief getting bottom side dimension
/// @return bottom side
float Right_trapezoid::GetBottomSide() {

	return bottom_side;

}


/// @brief getting oblique side
/// @return side 
float Right_trapezoid::GetSide() {

	return CalcSide();
}




/// @brief getting all the dimensions
/// @param ts top side
/// @param h height
/// @param bs bottom side
void Right_trapezoid::GetDim(float& ts, float& h, float& bs) {

	ts = top_side;
	h = height;
	bs = bottom_side;
	return;
}

/// @brief getting area
/// @return area
float Right_trapezoid::GetArea() {

	return Area();
}

/// @brief Getting Perimeter
/// @return perimeter
float Right_trapezoid::GetPerimeter() {

	return Perimeter();

}


/// @brief write an error message 
/// @param string message to be printed
void Right_trapezoid::ErrorMessage(const char* string) {

	cout << endl << "ERROR -- Right trapezoid --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void Right_trapezoid::WarningMessage(const char* string) {

	cout << endl << "WARNING -- Right trapezoid --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void Right_trapezoid::Dump() {
	cout << endl;
	cout << "*---Right trapezoid---*" << endl;
	cout << "| " << endl;
	cout << "|Top side = " << top_side << endl;
	cout << "|Height = " << height << endl;
	cout << "|Bottom side = " << bottom_side << endl;
	cout << "|Oblique side = " << GetSide() << endl;
	cout << "*--------------------*" << endl;
	cout << endl;
	Polygon::Dump();

}

/// @brief Draws a trapezoid
void Right_trapezoid::Draw() {

	cout << "I'm drawing a right trapezoid: " << endl;
	cout << "\t      " << top_side << endl;
	cout << "\t *----------*" << endl;
	cout << "\t |           \\" << endl;
	cout << height <<"\t"<< " |            \\" << GetSide() << endl;
	cout << "\t |             \\" << endl;
	cout << "\t *--------------*" << endl;
	cout << "\t      "<<bottom_side << endl;
}

/// @brief Defining the operator <<
/// @param out the output
/// @param r right operand 
/// @return output
ostream& operator << (ostream& out, Right_trapezoid& r) {
	r.Dump();
	return out;
}

/// @brief Defining the operator >>
/// @param in the input
/// @param r right operand
/// @return input
istream& operator >> (istream& in, Right_trapezoid& r) {
	float l;
	in >> l;
	r.SetTopSide(l);
	in >> l;
	r.SetHeight(l);
	in >> l;
	r.SetBottomSide(l);
	return in;
}
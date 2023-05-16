/// \file right_trapezoid.cpp
///	\brief class right trapezoid: implementation of the functions
///
///	Details.
///

#include<iostream>
#include "right_trapezoid.h"

/// @brief default constructor 
Right_trapezoid::Right_trapezoid() {

	cout << "Right trapezoid - constructor - default" << endl;

	Init();

}

/// @brief constructor
/// @param ts top side
/// @param h height
/// @param bs bottom side
Right_trapezoid::Right_trapezoid(float ts, float h,float bs) {

	Init();

	cout << "Right trapezoid - constructor" << endl;

	if (ts <= 0.)
		cout << "WARNING: Right trapezoid - constructor: top side length should be > 0" << endl;
	else
		top_side = ts;

	if (h <= 0.)
		cout << "WARNING: Right trapezoid - constructor: height should be > 0" << endl;
	else 
		height = h;

	if (bs <= 0.)
		cout << "WARNING: Right trapezoid  - constructor: bottom side length should be > 0" << endl;
	else
		bottom_side = bs;

}


/// @brief destructor 
Right_trapezoid::~Right_trapezoid() {

	cout << "Right trapezoid - destructor" << endl;
	Reset();

}

/// @brief copy constructor 
/// @param rt reference to the object that should be copied 
Right_trapezoid::Right_trapezoid(const Right_trapezoid& rt) {

	cout << "Right trapezoid - copy constructor" << endl;

	Init(rt);

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

	if (rt.top_side == top_side && rt.height == height && rt.bottom_side== bottom_side)
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

	if (ts < 0.) {
		cout << "WARNING: Right Trapezoid - SetTopSide: top side length should be > 0" << endl;
		return;
	}

	top_side = ts;

}

/// @brief setting the height
/// @param h height
void Right_trapezoid::SetHeight(float h) {

	if (h < 0.) {
		cout << "WARNING: Right Trapezoid - SetHeight: height should be > 0" << endl;
		return;
	}

	height = h;

}

/// @brief setting bottom side
/// @param bs bottom side
void Right_trapezoid::SetBottomSide(float bs) {
	if (bs < 0.) {
		cout << "WARNING: Right Trapezoid - SetBottomSide: bottom side lenght should be > 0" << endl;
		return;
	}

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
float Right_trapezoid::CalcSide(){
	
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
float Right_trapezoid::GetSide()  {

	return CalcSide();
}




/// @brief getting all the dimensions
/// @param ts top side
/// @param h height
/// @param bs bottom side
void Right_trapezoid::GetDim(float& ts, float& h, float &bs) {

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
	cout << "|Perimeter = " << GetPerimeter() << endl;
	cout << "|Area = " << GetArea() << endl;
	cout << endl;

}


void Right_trapezoid::Draw() {


}
#include "polygon.h"




/// @brief default constructor 
Polygon::Polygon() {

	cout << "Polygon - constructor - default" << endl;

	area = 0.;
	perimeter = 0.;

}

/// @brief copy constructor 
/// @param r reference to the object that should be copied 
Polygon::Polygon(const Polygon& p) {

	cout << "Polygon - copy constructor" << endl;

	Init(p);
}

/// @brief destructor
Polygon::~Polygon() {

	cout << "Polygon - destructor" << endl;
	Reset();

}

/// @brief overload of operator = 
/// @param p reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
Polygon& Polygon::operator=(const Polygon& p) {

	return *this;

}

/// @brief overload of operator == 
/// @param p reference to the object on the right side of the operator 
/// @return true if the two objects have the same width and the same length  
bool Polygon::operator==(const Polygon& r) {
	return false;
}


/// @brief default initialization of the object
void Polygon::Init() {
	Reset();
	perimeter = 0.;
	area = 0.;
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void Polygon::Init(const Polygon& p) {
	Reset();

}

/// @brief total reset of the object  
void Polygon::Reset() {
	perimeter = 0.;
	area = 0.;
}

/// @brief get the area of the object
/// @return area 
float Polygon::GetArea() {

	area = Area();
	return area;

}

/// @brief get the perimeter of the object
/// @return perimeter 
float Polygon::GetPerimeter() {

	perimeter = Perimeter();
	return perimeter;

}

/// @brief write an error message 
/// @param string message to be printed
void Polygon::ErrorMessage(const char* string) {

	cout << endl << "ERROR -- Polygon --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void Polygon::WarningMessage(const char* string) {

	cout << endl << "WARNING -- Polygon --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void Polygon::Dump() {

	cout << endl;
	cout << "Perimeter = " << GetPerimeter() << endl;
	cout << "Area = " << GetArea() << endl;
	cout << endl << flush;

}


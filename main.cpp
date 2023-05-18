#include "rectangle.h"
#include "rhombus.h"
#include "right_trapezoid.h"
#include <iostream>

#define N 100               //dimension of polygon pointer array
/// @brief menu with choice
/// @return choice
int menu();                 

/// @brief lets you create a polygon (or more) and draw it
void main ()
{  

    Polygon* polygonarray[N] = { 0 };               //all polygon pointers array inizialized to 0 
    int index = 0;
    while (true) {
        switch (menu())

        {
        case 1:
            float l, w;
            cout << "Insert length and width: ";
            scanf_s("%f %f", &l,&w);
            cin.get();
            polygonarray[index] = new Rectangle(l,w);
            index++;
            break;

        case 2:
            float h, v;
            cout << "Insert horizontal diagonal and vertical diagonal: ";
            scanf_s("%f %f", &h, &v);
            cin.get();
            polygonarray[index] = new Rhombus(h,v);
            index++;
            break;

        case 3:
            float ts,he,bs;
            cout << "Insert top side, height and bottom side: ";
            scanf_s("%f %f %f", &ts, &he, &bs);
            cin.get();
            polygonarray[index] = new Right_trapezoid(ts,he,bs);
            index++;
            break;

        case 4:
            cout << "There are " << index << " polygons to be drawn." << endl;
            cout << "---------------------------------" << endl;
            for (int i = 0; i <= index; i++) {
                if (polygonarray[i] != NULL)
                {
                    cout << "Polygon n." << i+1 << endl;
                    polygonarray[i]->Draw();
                    cout << "Area is:" << polygonarray[i]->GetArea() << endl;
                    cout <<"Perimeter is:" << polygonarray[i]->GetPerimeter() << endl<<endl;
               
                }
            }
            break;

        case 0:
            for (int i = 0; i <= index; i++) {
                delete polygonarray[i];
            }

            cout << endl;
            cout << "Shutting down..." << endl;
            return;



        default:
            cout << "Bad choice! Please try again.\n";
        }

    }



}


int menu()
{
    int choice = 0;
    cout << "*----------------------------*"<<endl;
    cout << "| Choose an option, please:  |" << endl;
    cout << "*----------------------------*" << endl;
    cout << "| 1: Create a rectangle      |" << endl;
    cout << "| 2: Create a rhombus        |" << endl;
    cout << "| 3: Create a right trapezoid|" << endl;
    cout << "| 4: Draw all                |" << endl;
    cout << "| 0: exit                    |" << endl;
    cout << "*----------------------------*" << endl;
    cout << endl;

    scanf_s("%d", &choice);
    cin.get();
    return choice;
}
   

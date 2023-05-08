// Zlatko Markovski INKI937

#include <iostream>

#include <cmath>

using namespace std;

// Defining the class Shape to demonstrate the concept of Hierarchial Inheritence in CPP
class Shape {
    // protected member variables are only accessible within the class and its descendent classes
    protected: float width,
    height;
    // public members are accessible everywhere
    public: void setDimensions(float w, float h) {
        cout << "Setting the Dimensions using the parent Class: Shape\n";
        cout << "The dimensions are: " << w << " and " << h << "\n\n";
        width = w;
        height = h;
    }
};

// Class Rectangle inherits the Shape class
class Rectangle: public Shape {
    
    public: 
        // Method Overriding
        float area() {
            return (width * height);
        }

    float perimeter() {
        return 2 * (width + height);
    }
};

// Class Triangle inherits the Shape class
class Triangle: public Shape {
    protected: float hypotenuse;

    public: Triangle() {
        hypotenuse = 0.0;
    }

    void calculateHypotenuse() {
        hypotenuse = sqrt(width * width + height * height);
    }

    float area() {
        return (width * height / 2);
    }

    float perimeter() {
        calculateHypotenuse();
        return (width + height + hypotenuse);
    }
};

// Defining the main method to access the members of the class
int main() {
    cout << "===== Program to demonstrate the concept of Hierarchical Inheritance in CPP =====\n\n";
    // Declaring the Class objects to access the class members
    Rectangle rectangle;
    Triangle triangle;
    rectangle.setDimensions(93, 7);
    triangle.setDimensions(9, 37);
    cout << "\nArea of the Rectangle computed using Rectangle Class is: " << rectangle.area() << "\n";
    cout << "Perimeter of the Rectangle computed using Rectangle Class is: " << rectangle.perimeter() << "\n\n";
    cout << "Area of the Triangle computed using Triangle Class is: " << triangle.area() << "\n";
    cout << "Perimeter of the Triangle computed using Triangle Class is: " << triangle.perimeter() << "\n\n";
    return 0;
}
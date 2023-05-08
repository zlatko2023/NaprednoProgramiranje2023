//Zlatko Markovski INKI937

#include <iostream>
#include <cmath>

using namespace std;
class operations {
    //declaring member variables
    public: int num1,
    num2;
    //defining member function or methods
    public: void input() {
        cout << "Enter two numbers to perform operations on: \n";
        cin >> num1 >> num2;
        cout << "\n";

    }
    public: void addition() {
        cout << "Addition = " << num1 + num2;
        cout << "\n";
    }
    void subtraction() {
        cout << "Subtraction = " << num1 - num2;
        cout << "\n";
    }
    void multiplication() {
        cout << "Multiplication = " << num1 * num2;
        cout << "\n";
    }
    void division() {
        cout << "Division = " << (float) num1 / num2;
        cout << "\n";
    }
    void power() {
        int result = 1;
        for (int i = 0; i < num2; i++) {
            result *= num1;
        }
        cout << "num1^(num2) = " << result;
        cout << "\n";
    }
    void exp() {
        int sum = num1 + num2;
        double result = 1;
        double term = 1;
        int n = 1;
        while (term > 1e-8) {
            term *= (double) sum / n;
            result += term;
            n++;
        }
        cout << "e^(num1+num2) = " << result;
        cout << "\n";
    }
};
//Defining the main method to access the members of the class
int main() {
    cout << " ===== Program to perform basic operations using Class, in CPP ===== \n\n";
    //Declaring class object to access class members from outside the class
    operations op;
    cout << "\nCalling the input() function from the main() method\n";
    op.input();
    cout << "\nCalling the addition() function from the main() method\n";
    op.addition();
    cout << "\nCalling the subtraction() function from the main() method\n";
    op.subtraction();
    cout << "\nCalling the multiplication() function from the main() method\n";
    op.multiplication();
    cout << "\nCalling the power() function from the main() method\n";
    op.power();
    cout << "\nCalling the exp() function from the main() method\n";
    op.exp();
    cout << "\nExiting the main() method\n\n\n";
    return 0;
}
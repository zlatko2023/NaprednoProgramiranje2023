#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

float divide(int a, int b) {
    return (float) a / (float) b;
}

double exponentiation(int a, int b) {
    return pow(a, b);
}

int calculate(int a, int b, int (* operation)(int, int)) {
    return operation(a, b);
}

void calculate_void(int a, int b, void (* operation)(int, int)) {
    operation(a, b);
}

int main() {
    const int x = (int) 'Z';
    const int y = (int) 'M';
    int a = x, b = y;

    int sum = calculate(a, b, &add);
    cout<<"Sum of "<<a<<" and "<<b<<" is "<<sum<<endl;

    int diff = calculate(a, b, &subtract);
    cout<<"Difference between "<<a<<" and "<<b<<" is "<<diff<<endl;

    float quotient = calculate(a, b, &divide);
    cout<<"Quotient of "<<a<<" and "<<b<<" is "<<quotient<<endl;

    double power = calculate(a, b, &exponentiation);
    cout<<a<<" to the power of "<<b<<" is "<<power<<endl;

    
    cout<<"Using calculate_void function to print sum and difference:"<<endl;
    calculate_void(a, b, &print_sum);
    calculate_void(a, b, &print_diff);

    return 0;
}

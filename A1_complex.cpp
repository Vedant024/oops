  #include <iostream>
using namespace std;
class complex
{
public:
    float real, img;
    complex() // default constructor
    {
        real = 0;
        img = 0;
    }
    complex operator+(complex);                       // declaration for addition
    complex operator*(complex);                       // declaration for multiplication
    friend ostream &operator<<(ostream &, complex &); // output function//<< operator return obj of ostream class//given ostream class as a return type
    friend istream &operator>>(istream &, complex &); // input function
};
// operator overloading syntax
complex complex::operator+(complex obj) /* This is automatically called when '+' is used with between two Complex objects */
{
    complex temp;
    temp.real = real + obj.real;
    temp.img = img + obj.img;
    return (temp);
}

complex complex::operator*(complex obj)
{
    complex temp;
    temp.real = (real * obj.real) - (img * obj.img);
    temp.img = (real * obj.img) + (img + obj.img);
    return (temp);
}

istream &operator>>(istream &is, complex &obj) // defining (extraction)>> operator
{
    is >> obj.real; // accepting real part with object of istream class
    is >> obj.img;  // accepting imaginary part with object of istream class
    return is;
}

ostream &operator<<(ostream &os, complex &obj) // defining <<(insertion) operator
{
    os << obj.real;              // displaying real part with object of ostream class
    os << "+" << obj.img << "i"; // displaying imaginary part with object of ostream class
    return os;
}

int main()
{
    complex a, b, c, d;
    // Enter first complex number";
    cout << "\n Enter real and imaginary part of first complex number:";
    cin >> a;

    // Enter second complex number";
    cout << "\n Enter real and imaginary part of second complex number:";
    cin >> b;
    
    cout<<"The 1st complex number is "<<a<<endl;
    cout<<"The 2nd complex number is "<<b<<endl;

    cout << "\nArithmetic operations are :";
    c = a + b;
    cout << "\n Addition is:" << c;

    d = a * b;
    cout << "\n Multiplication is:" << d << "\n";
    return 0;
}


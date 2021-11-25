#include <iostream>
#include <cmath>

//#define STRUCT_POINT
#define CONSTRUCTORS_CHECK
//#define DISTANCE_CHECK

using namespace std;

#define tab "\t"

class Point
{

    double x;
    double y;
public:
    // get-методы должны быть константными
    // Константным называется метод, которые не изменяет объект для которого вызывается./
    // Для константного объекта могут быть только контантные методы.
    double get_x()const
    {
        return x;
    }
    double get_y()const
    {
        return y;
    }
    void set_x(double x)
    {
        this -> x = x;
    }
    
    void set_y(double y)
    {
        this -> y = y;
    }
    
    //              Constructors:
    
//    Point()
//    {
//        x = y = 0;
//        cout << "Default constructor:\t" << this << endl;
//    }
//
//    Point(double x)
//    {
//        this ->x = x;
//        this ->y = double(); //значение по умолчанию для типа double;
//        cout << "1argConstructor:\t" << this << endl;
//    }
    
    Point(double x = 0, double y = 0)
    {
        this ->x = x;
        this ->y = y;
       // cout << "Constructor:\t" << this << endl;
    }
    Point(const Point& other)
    {
        this -> x = other.x;
        this -> y = other.y;
        cout << "Copy Constructor: " << this << endl;
    }
    ~Point()
    {
        // cout << "Destructor:\t" << this << endl;
    }
    
    void operator=(const Point& other)
    {
        this -> x = other.x;
        this -> y = other.y;
        cout << "CopyAssignment:\t" << this << endl;
    }
   
    
    // Methods:
    double distance(Point other)
    {
        // other - другая точка
        double x_distance = this -> x - other.x;
        double y_distance = this -> y - other.y;
        double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
        // sqrt - square root
        return distance;
    }
    
    void print() const
    {
        cout << "X = " << x << "\t" << "Y = " << y << endl;
    }
    
};


double distance (Point A, Point B)
{
    double x_distance = A.get_x() - B.get_x();
    double y_distance = A.get_y() - B.get_y();
    return sqrt(x_distance*x_distance + y_distance * y_distance);

}

int main(int argc, const char * argv[])
{
    
#ifdef STRUCT_POINT
    // type name;
    Point A;
    A.x = 2;
    A.y = 3;
    
    cout << A.x << tab << A.y << endl;
    
    Point* pA = &A; // Объявляем указатель на point pAб и инициализируем его адресом объекта А.
    cout << pA->x << tab << pA->y << endl;
    cout << (*pA).x << tab << (*pA).y << endl;
    
#endif
    
    
#ifdef CONSTRUCTORS_CHECK
    Point A;
//    A.set_x(2);
//    A.set_y(3);
    
//    cout << A.get_x() << tab << A.get_y() << endl;
    
    A.print();
    
    Point B(4, 5);
    B.print();
    
    Point C = 5; // Single - argument constructor
    C.print();
    
    Point D(8);
    D.print();
    
    Point E = D; // Copy constructor
    E.print();
    
    Point F(B); // Copy constructor
    F.print();
    
    Point G;
    G = F; // CopyAssignment
    
    

#endif
    
#ifdef DISTANCE_CHECK

    Point A(2, 3);
    
    Point B(3, 4);
    
    cout << "Distance from A to B: " << A.distance(B) << endl;
    
    cout << "Distance from B to A: " << B.distance(A) << endl;
    
    cout << "Distance from A to B: " << distance(A, B) << endl;
    
    cout << "Distance from B to A: " << distance(B, A) << endl;
#endif
    
    
    
    return 0;
}



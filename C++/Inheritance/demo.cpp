// Ressources https://www.youtube.com/watch?v=77eueMbWI0Y&t=185s

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Shape {
	protected:
	string name;

	public:
	Shape(string _n )						{ name = _n; }

	void	setName( string _n )			{ name = _n; }
	string	getName() const					{ return name; }
	virtual double	getArea() const = 0;	// Pure virtual function
};

// Child class
class Circle : public Shape {
	double	radius;

	public:
	Circle( string _n, double _r ) : Shape( _n ) 	{ radius = _r; }
	void	setRadius( double _r) 					{ radius = _r; }
	double	getRadius() const						{ return radius; }
	double	getArea() const							{ return radius * radius * 3.14159; }

};

class Rectangle : public Shape {
	int length, width;

	public:
	Rectangle( string _n, double _l, double _w) : Shape( _n )	{ length = _l, width = _w ;}
	void	setLength( double _l )								{ length = _l; }
	void	setWidth( double _w )								{ width = _w; }
	double	getLength() const									{ return length; }
	double	getWidth() const									{ return width; }
	void	drawRectangle() const {
		int i, j;
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < width; j++) {
				if (i == 0 || i == length - 1) {
					std::cout << "-";
				} else {
					if (j == 0 || j == width - 1) {
						std::cout << "|";
					} else {
						std::cout << " ";
					}
				}
			}
			std::cout << std::endl;
		}
	}
};

int main() {
	// Shape s("Shape");
	// cout << s.getName() << endl;

	Circle c( "Circle", 2.1 );
	cout << c.getName() << " " << c.getRadius() << " " << c.getArea() << endl;

	// Rectangle r( "Rectangle", 5, 20 );
	// cout << r.getName() << " " << r.getLength() << " " << r.getWidth() << endl;
	// r.drawRectangle();
}
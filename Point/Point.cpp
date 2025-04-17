#include "Point.h"

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point Point::operator+(const Point& obj) const ///////перший операнд p1 це this, а другий операнд p2 це параметр const Point& obj      у main    p1+p2
{

	//this->x += obj.x;
	
	Point rez(this->x + obj.x, this->y + obj.y);
	return rez;
}

Point Point::operator+(int a) const////  p1+5
{
	////this 
	Point rez(this->x + a, this->y + a);
	return rez;
}

Point Point::operator+=(int rs)
{

	x += rs;
	y += rs;
	return *this;
}

bool Point::operator==(const Point& obj)////  p1==p2
{
	if (x == obj.x)
		if (y == obj.y)
			return true;


	return false;
}

bool Point::operator>(const Point& obj)////  р1>p2
{
	if (x > obj.x)
		if (y >obj.y)
			return true;


	return false;
}

void Point::Show() const///// є методом класу Point::   , ::- оператор розширення видимості
{
	cout <<"X: "<< x << " Y: " << y << endl;
}

int Point::GetX() const
{
	return x;
}

int Point::GetY() const
{
	return y;
}

///int -------> Point  explisite constructor


Point::operator int()//////  Point----->int
{

	return x + y;

}

Point& Point::operator++()////префіксна форма
{
	x++;
	y++;
	return *this;/////   (++obj)++
}

Point Point::operator++(int i)////постфіксна форма
{
	Point temp ( *this);
	x++;
	y++;
	return temp;////   (obj++)++ копія , не можна !!!! 
}








/////Глобальними функціями  2+Point
Point operator+(int number, const Point& obj)///// перегрузка глобальною функцією  int+Point
{
	
	Point res(number + obj.GetX(), number + obj.GetY());

	return res;
}
Point operator+( const Point& obj, int number)///// перегрузка глобальною функцією Point+int
{

	Point rez(number + obj.GetX(), number + obj.GetY());

	return rez;
}

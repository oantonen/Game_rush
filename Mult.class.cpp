#include "Mult.class.hpp"

Mult::Mult() : _x(10), _y(10), _x1(10), _y1(10), _type('+') {}

Mult::Mult(int x, int y) : _x(x), _y(y), _x1(x + 1), _y1(y), _type('+') {}

Mult::Mult(Mult const & rObj) : _x(rObj._x), _y(rObj._y), _type(rObj._type) {}

Mult::~Mult() {}

Mult &	Mult::operator=(Mult const & rObj) {
		_type = rObj._type;
		_x = rObj._x;
		_y = rObj._y;
	return *this;
}

int		Mult::multGetX( void ) const {
	return this->_x;
}

int		Mult::multGetY( void ) const {
	return this->_y;
}

void	Mult::multPrint() {
	init_pair(6, COLOR_BLACK, 3);
	attrset(COLOR_PAIR(6));
	mvprintw(this->_y, this->_x, &_type);
	mvprintw(this->_y1, this->_x1, &_type);
	attrset(COLOR_PAIR(3));
}

char       Mult::multGetType(void)const {

	return this->_type;
}

void		Mult::multMove(void)
{
	this->_y++;
	this->_y1++;
}

bool	Mult::multColision(AObject*& rObj) {

	return ((_x == rObj->getX() && _y == rObj->getY()) || (_x1 == rObj->getX() && _y == rObj->getY()));
}

bool	Mult::multColisionXY(int x, int y) {

	return ((_x == x && _y == y) || (_x1 == x && _y1 == y));
}
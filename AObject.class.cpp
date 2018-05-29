#include "AObject.class.hpp"

AObject::AObject() : _x(10), _y(10), _type(' ') {}

AObject::AObject(int x, int y) : _x(x), _y(y) {}

AObject::AObject(AObject const & rObj) : _x(rObj._x), _y(rObj._y), _type(rObj._type) {}

AObject::~AObject() {}

AObject &	AObject::operator=(AObject const & rObj) {
		_type = rObj._type;
		_x = rObj._x;
		_y = rObj._y;
	return *this;
}

int		AObject::getX( void ) const {
	return this->_x;
}

int		AObject::getY( void ) const {
	return this->_y;
}

void	AObject::print() {
	start_color();
	int	     random;
	random = rand() % 2;
   	init_pair(1, COLOR_BLACK, 1);
    init_pair(2, COLOR_BLACK, 2);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_RED, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    init_pair(7, 6, COLOR_BLACK);

	if (this->_type == 'T')
		attrset(COLOR_PAIR(1));
	else if (this->_type == 'X')
		attrset(COLOR_PAIR(2));
	else if (_type == 'o')
		attrset(COLOR_PAIR(4));
	else if (_type == '*')
		attrset(COLOR_PAIR(5));
	else if (_type == 'A')
		attrset(COLOR_PAIR(7));
	mvprintw(this->_y, this->_x, &_type);
	attrset(COLOR_PAIR(3));
}

char       AObject::getType(void)const {
	return this->_type;
}

bool	AObject::colision(AObject*& rObj) {
	return (_x == rObj->getX() && _y == rObj->getY());
}

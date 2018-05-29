#include "Space.class.hpp"

Space::Space() : AObject() {
	_type = '.';
}

Space::Space(int x, int y) : AObject(x, y){

	_type = '.';
}

Space::Space(Space const & src) : AObject(src.getX(), src.getY()){

}

Space  & Space::operator=(Space const & rObj)
{
	Space s = rObj;
	return *this;
}

Space::~Space() {

}

void 	Space::move( void ) {
	_y++;
}
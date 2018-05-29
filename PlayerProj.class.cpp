#include "PlayerProj.class.hpp"

PlayerProj::PlayerProj() : AObject() {
	_type = '*';
}

PlayerProj::PlayerProj(int x, int y) : AObject(x, y) {
	_type = '*';
}

PlayerProj::PlayerProj(PlayerProj const & src) : AObject(src.getX(), src.getY()) {

}

PlayerProj  & PlayerProj::operator=(PlayerProj const & rObj)
{
	PlayerProj pp = rObj;
	return *this;
}

PlayerProj::~PlayerProj() {

}

void 	PlayerProj::move() {
		_y--;
}

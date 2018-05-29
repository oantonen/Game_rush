#include "EnemyProj.class.hpp"

EnemyProj::EnemyProj() : AObject() {
	_type = 'o';
}

EnemyProj::EnemyProj(int x, int y) : AObject(x, y) {
	_type = 'o';
}

EnemyProj::EnemyProj(EnemyProj const & src) : AObject(src.getX(), src.getY()) {

}

EnemyProj  & EnemyProj::operator=(EnemyProj const & rObj)
{
	EnemyProj ep = rObj;
	return *this;
}

EnemyProj::~EnemyProj() {

}

void 	EnemyProj::move(void) {
		_y++;
}

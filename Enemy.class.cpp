#include "Enemy.class.hpp"

Enemy::Enemy() : AObject() {
	char	arr[2];
	arr[0] = 'X';
	arr[1] = 'T';
	_type = arr[rand() % 2];
}

Enemy::Enemy(int x, int y) : AObject(x, y){

	char	arr[2];
	arr[0] = 'X';
	arr[1] = 'T';
	_type = arr[rand() % 2];
}

Enemy::Enemy(Enemy const & src) : AObject(src.getX(), src.getY()){

}

Enemy &	Enemy::operator=(Enemy const & var)
{
	Enemy e = var;
	return *this;
}

Enemy::~Enemy( void ) {

}

void 	Enemy::move( void ) {
	_y++;
}

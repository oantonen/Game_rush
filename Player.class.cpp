#include "Player.class.hpp"

Player::Player() : AObject(){
	_type = 'A';
	life = 10;
}

Player::Player(int x, int y) : AObject(x, y) {
	_type = 'A';
	life = 10;
}

Player::Player(Player const & rObj) : AObject(rObj.getX(), rObj.getY()){

}

Player &	Player::operator=(Player const & var)
{
	Player p = var;
	return *this;
}

Player::~Player() {

}

void	Player::move(void)
{}

int		Player::getX() const {

	return (this->_x);
}

int		Player::getY() const {

	return (this->_y);
}

void 	Player::move_1( int const button) {
	if (button == KEY_LEFT && _x > (3))
		_x--;
	else if (button == KEY_RIGHT && _x < (82))
		_x++;
}

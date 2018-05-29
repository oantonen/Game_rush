#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

# include "AObject.class.hpp"

class Player : public AObject
{
public:
	Player();
	Player(int x, int y);
	Player(Player const & rObj);
	~Player();

	Player &	operator=(Player const & var);
	void	move_1( int const button);
	void	move(void);
	char	getForm();
	int		life;
	int		getX() const;
	int		getY() const;

};

#endif

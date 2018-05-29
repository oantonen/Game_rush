#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

# include "AObject.class.hpp"

class Enemy : public AObject
{
public:
	Enemy();
	Enemy(int x, int y);
	Enemy(Enemy const & src);
	~Enemy();
	
	Enemy &	operator=(Enemy const & var);
	void	move(void);
	bool    colision(AObject *& rObj);

};

#endif
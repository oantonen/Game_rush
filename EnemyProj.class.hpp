#ifndef ENEMYPROJ_CLASS_HPP
# define ENEMYPROJ_CLASS_HPP

# include "AObject.class.hpp"

class EnemyProj : public AObject
{
public:
	EnemyProj();
	EnemyProj(int x, int y);
	EnemyProj(EnemyProj const & src);
	EnemyProj  & operator=(EnemyProj const & rObj);
	~EnemyProj();

	void	move( void );
	bool	colision(AObject const & elem);
};

#endif
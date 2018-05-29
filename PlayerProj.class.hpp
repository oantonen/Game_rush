#ifndef PLAYERPROJ_CLASS_HPP
# define PLAYERPROJ_CLASS_HPP

# include "AObject.class.hpp"

class PlayerProj : public AObject
{
public:
	PlayerProj();
	PlayerProj(int x, int y);
	PlayerProj(PlayerProj const & src);
	PlayerProj  & operator=(PlayerProj const & rObj);
	~PlayerProj();
	
	void	move();
};

#endif
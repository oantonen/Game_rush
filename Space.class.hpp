#ifndef SPACE_CLASS_HPP
# define SPACE_CLASS_HPP

# include "AObject.class.hpp"

class Space : public AObject
{
public:
	Space();
	Space(int x, int y);
	Space(Space const & src);
	~Space();
	Space  & operator=(Space const & rObj);

	void	move(void);

};

#endif
#ifndef MULT_CLASS_HPP
# define MULT_CLASS_HPP

# include "AObject.class.hpp"

class Mult 
{
public:
	Mult();
	Mult(int x, int y);
	Mult(Mult const & rObj);
	Mult  & operator=(Mult const & rObj);
	~Mult();

	int			multGetX(void)const;
	int			multGetY(void)const;
	char		multGetType(void)const;
	void		multPrint(void);
	bool		multColisionXY(int x, int y);
	bool		multColision(AObject*& rObj);
	void		multMove(void);
	
protected:
	int			_x;
	int			_y;
	int			_x1;
	int			_y1;
	char		_type;

};

#endif
#ifndef AOBJECT_H
# define AOBJECT_H

# include <iostream>
# include <ncurses.h>

class AObject
{
public:
    AObject();
    AObject(int x, int y);
    AObject(AObject const & rObj);
    AObject  & operator=(AObject const & rObj);
    virtual ~AObject();

    int             getX(void)const;
    int             getY(void)const;
    char            getType(void)const;
    virtual void    print(void);
    bool            colision(AObject *& rObj);
    virtual void    move(void) = 0;

protected:
    int        _x;
    int        _y;
    char    _type;
    
};

#endif
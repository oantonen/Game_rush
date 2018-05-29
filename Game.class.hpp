#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

# include "Player.class.hpp"
# include "PlayerProj.class.hpp"
# include "Space.class.hpp"
# include "Mult.class.hpp"
# include "Enemy.class.hpp"
# include "EnemyProj.class.hpp"
# include "AObject.class.hpp"
# include <unistd.h>

# define STARTX 3
# define STARTY 3
# define WIDTH 80
# define HEIGHT 45
# define SPACE 32
# define ESC 27

class Game
{
public:
	Game();
	Game(Game const & var);
	~Game();
	Game &	operator=(Game const & var);

	void	refreshWin();
	void	play();

private:

	Player			_player;
	AObject*		_enemy[50];
	AObject*		_enemyProj[50];
	AObject*		_playerProj[50];
	AObject*		_space[100];
	Mult*			_mult[50];
	int				_key;
	int				_score;
	int				_l_key;
	unsigned int 	_counter;

	void	print(void);
	void	moveAll(int const key, int counter);	
	void	initArr(void);
	void	createEnemy(int _counter);
	void	createEnemyProj(int x, int y);
	void	createPlayerProj(int x);
	int		is_collide(void);
	void	createSpace(void);
	void	printInterface(void) const;
};

#endif
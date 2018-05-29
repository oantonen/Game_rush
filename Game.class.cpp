#include "Game.class.hpp"


Game::Game() : _player(Player(STARTX + (WIDTH / 2), STARTY + HEIGHT)) ,
 _key(ERR), _l_key(ERR), _counter(0) {

	initscr();
	noecho();
	curs_set(false);
	timeout(0);
	cbreak();
	keypad(stdscr, true);
	refresh();
	initArr();
	for (int i = 0; i < 50; ++i)
	{
		_enemy[i] = NULL;
		_enemyProj[i] = NULL;
		_playerProj[i] = NULL;
		_mult[i] = NULL;
	}
	for (int i = 0; i < 100; ++i)
		_space[i] = NULL;
}

Game::Game(Game const & var)
{
	*this = var;
}

Game &     Game::operator=(Game const & rObj) {
	Game g = rObj;
	return *this;
}

Game::~Game() {
	endwin();
}

void    Game::createEnemy(int _counter) {
	
	int     random;

	random = rand() % 2;
	if (_counter % 40 != 0)
		return;
	int x = (rand() % WIDTH) + 2;
	for (int i = 0; i < 50; ++i)
	{
		if (random == 1 && _mult[i] == NULL) 
		{
			_mult[i] = new Mult(x, STARTY);
			return;
		}
		else if (_enemy[i] == NULL) 
		{
			_enemy[i] = new Enemy(x, STARTY);
			return;
		}
	}
}

void    Game::createPlayerProj(int x) {

	for (int i = 0; i < 50; i++) 
	{
		if(_playerProj[i] == NULL) {
			_playerProj[i] = new PlayerProj(x, HEIGHT + STARTY);
			return;
		}
	}
}

void    Game::createSpace(void)
{
	int     random;

	random = (rand() % WIDTH) + 2;;
	for (int i = 0; i < 100; ++i)
	{
		if(_space[i] == NULL) {
			_space[i] = new Space(random, STARTY);
			return;
		}
	}
}

void     Game::createEnemyProj(int x, int y)
{
	for (int i = 0; i < 50; i++)
	{
		if(_enemyProj[i] == NULL) {
			_enemyProj[i] = new EnemyProj(x, y);
			return;
		}
	}
}

void	Game::refreshWin() {
	refresh();
	erase();
}

void    Game::printInterface(void) const
{
	static double seconds;

	seconds += 1.01;
	init_pair(12,0,6);
	attrset(COLOR_PAIR(12));
	mvhline(1, 2, '*', 82);
	mvhline(50, 2, '*', 82);
	mvvline(1, 2, '*', 50);
	mvvline(1, 83, '*', 50);
	attroff(COLOR_PAIR(12));
	init_pair(5,3,0);
	attrset(COLOR_PAIR(5));

	mvprintw(3, 4, "LIVES: %-10d SCORE: %010d       GAME TIME:%6.3f",
	_player.life, _score, seconds / 100);
	mvhline(4, 3, '_', 80);
	attroff(COLOR_PAIR(5));
}

void	Game::initArr(void)
{

}

int     Game::is_collide()
{
	static int col = 0;

	for (int i = 0; i < 50; ++i)
	{
		if (_enemy[i] && _player.colision(_enemy[i])) {
			delete _enemy[i];
			_enemy[i] = NULL;
			_player.life -= 1;
		}
		else if (_enemyProj[i] && _player.colision(_enemyProj[i])) {
			delete _enemyProj[i];
			_enemyProj[i] = NULL;
			_player.life -= 1;
		}
		else if (_mult[i] && _mult[i]->multColisionXY(_player.getX(), _player.getY())) {
			delete _mult[i];
			_mult[i] = NULL;
			_player.life -= 3;
		}
		else if (_player.life <= 0)
		{
			system("afplay sound/GO.mp3 &");
			usleep(1000000);
			return(-1);
		}
		for (int j = 0; (j < 50 && _playerProj[i]) ; ++j)
		{
			if (_enemy[j] && _playerProj[i]->colision(_enemy[j]))
			{
				delete _playerProj[i];
				_playerProj[i] = NULL;
				delete _enemy[j];
				_enemy[j] = NULL;
				_score += 100;
				system("afplay sound/boom.wav &");
			}
			else if (_mult[j] && _mult[j]->multColision(_playerProj[i]))
			{
				delete _playerProj[i];
				_playerProj[i] = NULL;
				if (col++ % 4 == 3)
				{
					delete _mult[j];
					_mult[j] = NULL;
					_score += 400;
					system("afplay sound/boom.wav &");
				}
			}
		}
	}
	return (0);
}

void    Game::print() {
	_player.print();
	for (int i = 0; i < 100; ++i)
	{
		if (_space[i])
			_space[i]->print();
	}
	for (int i = 0; i < 50; ++i)
	{
		if (_enemy[i])
			_enemy[i]->print();
		if (_playerProj[i])
			_playerProj[i]->print();
		if (_enemyProj[i])
			_enemyProj[i]->print(); 
		if (_mult[i])
			if (_mult[i] && i % 3 == 1)
			_mult[i]->multPrint();   
	}
	printInterface();
	return ;
}

void	Game::play() {

	srand(time(0));
	_key = getch();
	while (_key != ESC) {
		_key = getch();
		if (_key != ERR) 
			_l_key = _key;
		usleep(10000);
		refreshWin();
		createEnemy(_counter);
		createSpace();
		moveAll(_l_key, _counter);
		print();
		if(is_collide() == -1)
		{
			usleep(100000);
			return ;
		}
		_l_key = ERR;
		_counter++;
	}
}

void    Game::moveAll(int const key, int counter)
{
	_player.move_1(key);
	if (key == SPACE)
		createPlayerProj(_player.getX());
	for (int i = 0; i < 50; ++i)
	{
		if (counter % 20 == 0)
		{
			if (_enemy[i])
			{
				_enemy[i]->move();
				if (_enemy[i]->getY() > HEIGHT + STARTY)
				{
					delete _enemy[i];
					_enemy[i] = NULL;
				}
			}
			if (_mult[i])
			{
				_mult[i]->multMove();
				if (_mult[i]->multGetY() > HEIGHT + STARTY)
				{
					delete _mult[i];
					_mult[i] = NULL;
				}
			} 
		}
		if (_enemy[i] && (rand() % 500) == 0)
			createEnemyProj(_enemy[i]->getX(), _enemy[i]->getY());
		if (counter % 10 == 0 && _enemyProj[i])
		{
			_enemyProj[i]->move();
			if (_enemyProj[i]->getY() > STARTY + HEIGHT)
			{
				delete _enemyProj[i];
				_enemyProj[i] = NULL;
			}
		}
		if (_playerProj[i])
		{
			_playerProj[i]->move();
			if (_playerProj[i]->getY() < STARTX)
			{
				delete _playerProj[i];
				_playerProj[i] = NULL;
			}  
		}
	}
	for (int i = 0; i < 100; ++i)
	{
		if (counter % 2 == 0 && _space[i])
		{
			_space[i]->move();
			if (_space[i]->getY() > STARTY + HEIGHT)
			{
				delete _space[i];
				_space[i] = NULL;
			}  
		}
	}
}

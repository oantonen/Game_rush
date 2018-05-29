CXX = clang++
CXXFLAGS = -Wall -Werror 
CXXXFLAGS = -Wall -Werror -Wextra -lncurses -std=c++98
NAME = ft_retro

SRC = AObject.class.cpp Game.class.cpp main.cpp Player.class.cpp EnemyProj.class.cpp Enemy.class.cpp PlayerProj.class.cpp Space.class.cpp Mult.class.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
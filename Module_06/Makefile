
CXX = cpp
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = bin
SRC = ScalarConverter.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
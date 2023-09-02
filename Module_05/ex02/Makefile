
CXX	= c++
CCFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = bin
SRC = AForm.cpp Bureaucrat.cpp main.cpp ShrubberyCreationForm.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
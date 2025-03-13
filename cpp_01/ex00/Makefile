NAME := ./zombie
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := Zombie.cpp main.cpp randomChump.cpp newZombie.cpp
OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

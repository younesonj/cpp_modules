NAME := ./main
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := main.cpp Span.cpp

OBJS := $(SRCS:.cpp=.o)

Headers := Span.hpp

all: $(NAME)

$(NAME): $(OBJS) $(Headers)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

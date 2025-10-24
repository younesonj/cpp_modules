NAME := ./main
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := AForm.cpp PresidentialPardonForm.cpp main.cpp ShrubberyCreationForm.cpp Bureaucrat.cpp RobotomyRequestForm.cpp Intern.cpp

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

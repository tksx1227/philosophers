BINDIR	:= bin
SRCDIR	:= src
OBJDIR	:= obj
INCDIR	:= include

FILES	:= main.c \
			parser.c \
			philo_actions.c \
			philo_actions2.c \
			philo_observer.c \
			philo_thread.c \
			philo_utils.c \
			utils.c
SRCS	:= $(addprefix $(SRCDIR)/, $(FILES))
OBJS	:= $(addprefix $(OBJDIR)/, $(FILES:.c=.o))
DEPS	:= $(addprefix $(OBJDIR)/, $(FILES:.c=.d))

CC		:= cc
RM		:= rm -rf
NAME	:= philo
PHILO	:= $(BINDIR)/philo
CFLAGS	:= -Wall -Wextra -Werror -MMD -MP
LINKLIB	:= -pthread

ifdef DEV
	CFLAGS += -g -fsanitize=thread
endif

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(LINKLIB) $(addprefix -I, $(INCDIR)) -c $< -o $@

.PHONY: all
all: $(OBJDIR) $(BINDIR) $(PHILO)

.PHONY: $(NAME)
$(NAME): all

$(PHILO): $(OBJS)
	@echo "\033[32mGenerate binary file...\033[0m"
	$(CC) $(CFLAGS) $(LINKLIB) -o $@ $^

$(OBJDIR):
	@echo "\033[32mGenerate $(OBJDIR) directory...\033[0m"
	mkdir -p $@

$(BINDIR):
	@echo "\033[32mGenerate $(BINDIR) directory...\033[0m"
	mkdir -p $@

.PHONY: clean
clean:
	@echo "\033[31mRemove $(OBJDIR) directory...\033[0m"
	$(RM) $(OBJDIR)

.PHONY: fclean
fclean: clean
	@echo "\033[31mRemove $(BINDIR) directory...\033[0m"
	$(RM) $(BINDIR)

.PHONY: re
re: fclean all

.PHONY: dev
dev:
	@$(MAKE) DEV=1

.PHONY: test1
test1: all
	@echo "\033[33mTest with 1 800 200 200\033[0m"
	@./bin/philo 1 800 200 200

.PHONY: test2
test2: all
	@echo "\033[33mTest with 5 800 200 200\033[0m"
	@./bin/philo 5 800 200 200

.PHONY: test3
test3: all
	@echo "\033[33mTest with 5 800 200 200 7\033[0m"
	@./bin/philo 5 800 200 200 7

.PHONY: test4
test4: all
	@echo "\033[33mTest with 4 410 200 200\033[0m"
	@./bin/philo 4 410 200 200

.PHONY: test5
test5: all
	@echo "\033[33mTest with 4 310 200 100\033[0m"
	@./bin/philo 4 310 200 100

-include $(DEPS)

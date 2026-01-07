NAME      = push_swap
CC        = cc
CFLAGS    = -Wall -Wextra -Werror -MMD -g3
OBJ_DIR   = .objects
SRC_DIR   = .
INC_DIR   = .

SRCS      = ft_printf.c \
			ft_printf_utils.c \
			stack_utils.c \
			operation_1.c \
			operation_2.c \
			sort_utils.c \
			selection_sort.c
OBJS      = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
DEPS      = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.d)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
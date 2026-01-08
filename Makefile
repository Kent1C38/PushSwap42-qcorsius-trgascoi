NAME      = push_swap
CC        = cc
CFLAGS    = -Wall -Wextra -Werror -MMD -g3
OBJ_DIR   = .objects
SRC_DIR   = .
INC_DIR   = .

SRCS      = stack_utils.c \
			operation_1.c \
			operation_2.c \
			sort_utils.c \
			selection_sort.c \
			range_sort.c \
			range_sort_aux.c \
			parser.c \
			main.c
OBJS      = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
DEPS      = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.d)))

all: $(NAME)

$(NAME): libft/libft.a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

libft/libft.a:
	make -C libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -Ilibft/includes -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
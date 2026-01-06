NAME      = push_swap
CC        = cc
CFLAGS    = -Wall -Wextra -Werror -MMD
OBJ_DIR   = .objects
SRC_DIR   = src
INC_DIR   = includes

SRCS      = ...
OBJS      = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
DEPS      = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.d)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -c $(OBJS) -o $(NAME)

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
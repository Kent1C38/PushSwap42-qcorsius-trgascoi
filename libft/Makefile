NAME = libft.a

YELLOW = \033[33m
CYAN = \033[0;36m
GREEN  = \033[32m
RESET  = \033[0m

SRCDIR = src
OBJDIR = .build
INCDIR = includes
CC = cc
FLAGS = -MMD -Wall -Werror -Wextra -I$(INCDIR)

SRCS =\
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_printf/ft_printf.c \
	ft_printf/utils.c

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

BONUS_SRCS =\
	ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c 

BONUS_OBJS = $(addprefix $(OBJDIR)/, $(BONUS_SRCS:.c=.o))
BONUS_DEPS = $(BONUS_OBJS:.o=.d)


$(NAME): $(OBJS)
	@ar rcs $(NAME) $^
	@echo "$(GREEN)Build successful !$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(CYAN)Compiling $@...$(RESET)"
	@$(CC) $(FLAGS) -o $@ -c $<

-include $(DEPS)

all: $(NAME)

bonus : $(OBJS) $(BONUS_OBJS)
	@ar rcs $(NAME) $^
	@echo "$(YELLOW)[Bonus] $(GREEN)Build successful !$(RESET)"

-include $(BONUS_DEPS)

clean:
	@echo "$(YELLOW)Removing $(OBJDIR) !$(RESET)"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(YELLOW)Removing $(NAME) !$(RESET)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

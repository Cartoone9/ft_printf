CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

O_DIR = .objs

S_DIR = srcs

SRCS = ft_split_prct.c ft_itoa.c ft_strlcat.c \
	   ft_check.c ft_conv_i.c ft_conv_prct.c \
	   ft_conv_s.c ft_conv_x.c ft_printf.c \
	   ft_strdup.c ft_strlen.c ft_strchr.c \
	   ft_conv_u.c ft_free.c ft_railway.c \
	   ft_uitoa.c ft_conv_c.c ft_conv_p.c \
	   ft_hexaft.c ft_substr.c ft_strrchr.c \
	   ft_flags.c ft_strncmp.c ft_printer_di.c \
	   ft_printer_cs.c ft_printer_x.c ft_dot.c \
	   ft_annexe.c

OBJS = $(addprefix $(O_DIR)/, $(SRCS:.c=.o))

$(O_DIR)/%.o : $(S_DIR)/%.c
	@mkdir -p $(O_DIR)
	@$(CC) $(CFLAGS) -I./hdrs/ -c $< -o $@

all : $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS) 
	@ar rcs $(NAME) $(OBJS)

clean : 
	@rm -rf $(O_DIR)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re

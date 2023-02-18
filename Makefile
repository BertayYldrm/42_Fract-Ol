NAME = fractol

CC = gcc
SRCS= ./sources/controls_m_k.c \
./sources/draw.c \
./sources/fractal_man_jul.c \
./sources/init.c \
./sources/libutils.c \
./sources/utils.c \
./sources/fractol.c

BONUSSRCS= ./sources_bonus/controls_m_k_bonus.c \
./sources_bonus/draw_bonus.c \
./sources_bonus/fractal_man_jul_burn_bonus.c \
./sources_bonus/fractol_bonus.c \
./sources_bonus/init_bonus.c \
./sources_bonus/libutils_bonus.c \
./sources_bonus/utils_bonus.c \


MFLAGS=./mlxlib/libmlx.a
AFLAGS = -Wall -Werror -Wextra -O3 -I./mlxlib
RM = rm -rf
OBJS = $(SRCS:.c=.o)
BONUSOBJS = $(BONUSSRCS:.c=.o)


all: $(MFLAGS) $(NAME)

$(MFLAGS):
	make -C ./mlxlib

$(NAME):  
	$(CC) $(SRCS) $(MFLAGS) $(AFLAGS) -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(MFLAGS)
		$(CC) $(BONUSSRCS) $(MFLAGS) $(AFLAGS) -framework OpenGL -framework AppKit -o $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	make clean -C ./mlxlib
	$(RM) $(OBJS)

re: fclean all

re_bonus: fclean bonus

.PHONY : all fclean clean re re_bonus bonus

OS = MACOS
COM = fast commit
NAME = fractol

LFTDIR = ./libft/
INCDIR = ./inc/
SRCDIR = ./src/
OBJDIR = ./obj/
BINDIR = ./bin/

SRCNAME = main.c \
		rgb.c \
		complex.c \
		complex2.c \
		complex_p.c \
		grad.c \
		usage.c \
		error.c \
		functions.c \
		validator.c \
		flags.c \
		flags2.c \
		image.c \
		init.c \
		draw.c \
		fractol.c \
		newton.c \
		deal_key.c \
		deal_key2.c \
		actions.c \
		mouse.c \
		print.c \
		print_cmd.c
OBJNAME = $(SRCNAME:.c=.o)
OBJ = $(addprefix $(OBJDIR),$(OBJNAME))

LFTINIT = -I $(LFTDIR) -L $(LFTDIR) -lft
MLXINIT = -I /usr/local/include -L /usr/local/lib -lmlx

LINUX = -lXext -lX11 -lm
MACOS = -framework OpenGL -framework AppKit
WFLAGS = -Wall -Wextra -Werror

all: $(BINDIR)$(NAME)

$(BINDIR)$(NAME): $(OBJ)
	@$(MAKE) -C $(LFTDIR)
	@mkdir -p $(BINDIR)
	gcc $(WFLAGS) $(OBJ) $(MLXINIT) $($(OS)) $(LFTINIT) \
		-I $(INCDIR) -o $(BINDIR)$(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@gcc $(WFLAGS) -I $(INCDIR) -o $@ -c $<

clean:
	@$(MAKE) -C $(LFTDIR) clean
	@rm -rf $(OBJDIR)

fclean: clean
	@$(MAKE) -C $(LFTDIR) fclean
	@rm -rf $(BINDIR)

re: fclean all

git: fclean
	git status
	git add *
	git status
	git commit -m "$(COM)"
	git status
	git push

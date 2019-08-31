NAME = fractol

LFTDIR = ./libft/
INCDIR = ./inc/
SRCDIR = ./src/
OBJDIR = ./obj/
BINDIR = ./bin/

SRCNAME = main.c
OBJNAME = $(SRCNAME:.c=.o)
OBJ = $(addprefix $(OBJDIR),$(OBJNAME))

LFTINIT = -I $(LIBFTDIR) -L $(LIBFTDIR) -lft
MLXINIT = -I /usr/local/include -L /usr/local/lib -lmlx

LINUX = -lXext -lX11 -lm
MACOS = -framework OpenGL -framework AppKit
WFLAGS = -Wall -Wextra -Werror

all: $(BINDIR)$(NAME)

$(BINDIR)$(NAME): $(OBJ)
	$(MAKE) -C $(LFTDIR)
	@mkdir -p $(BINDIR)
	gcc $(WFLAGS) $(OBJ) $(MLXINIT) $(LINUX) $(LFTINIT) -I $(INCDIR) -o $(BINDIR)$(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	gcc $(WFLAGS) -I $(INCDIR) -o $@ -c $<

clean:
	$(MAKE) -C $(LFTDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LFTDIR) fclean
	rm -rf $(BINDIR)

re: fclean all

push: fclean
	git status
	git add *
	git status
	git commit -m "fast commit"
	git status
	git push

amend: fclean
	git status
	git add *
	git status
	git commit --amend "fast amend"
	git status
	git push

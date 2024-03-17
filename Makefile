NAME			:= arvore_teste
CFLAGS			:= -Wextra -Wall -Werror -g3
CC				:= cc
LIBFT			:= ./lib/lib_get_print/libft.a
PATH_MAKE_LIB	:= ./lib/lib_get_print

FILES			:=./list/create_add_back.c\
				./list/init_ast.c\
				./list_array/create_add_back_array_list.c\
				./list_array/init_array_lst.c\
				./funcoes_temporarias.c\
				./main.c\

INCLUDE			:= -I ./include -I ./lib/lib_get_print/includes
CMD_CLEAN		:= rm -Rf
CMD_FCLEAN		:= rm -rf

all: $(NAME)

$(NAME): $(LIBFT) $(FILES)

$(NAME):
	@$(CC) $(FILES) $(LIBFT) $(INCLUDE) -o $(NAME) -lreadline

$(LIBFT): libft

libft:
	@$(MAKE) -C $(PATH_MAKE_LIB) --no-print-directory

libft_clean:
	@$(MAKE) -C $(PATH_MAKE_LIB) fclean --no-print-directory

libft_re:
	@$(MAKE) -C $(PATH_MAKE_LIB) re --no-print-directory

clean:
	@$(CMD_CLEAN) $(NAME)

fclean: clean libft_clean
	@$(CMD_CLEAN) $(NAME)

re: clean, fclean, libft_re, pipex_re, $(LIBFT)
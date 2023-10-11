CLIENT	=	client

SERVER	=	server

CCFLAGS = 	-Wall -Werror -Wextra

LIBFT 	=	libft.a

INCLUDES = includes/

RED =  \033[38;5;196m
GREEN = \033[38;5;47m
YELLOW = \033[38;5;226m
CYAN = \033[0;36m
RESET = \033[0m

all: $(CLIENT) $(SERVER)

$(CLIENT): $(LIBFT)
	@cc $(CCFLAGS) -I $(INCLUDES) src/client.c $(LIBFT) -o $(CLIENT)
	@echo "[$(GREEN)compiling$(RESET)]: $(CLIENT)"

$(SERVER): $(LIBFT)
	@cc $(CCFLAGS) -I $(INCLUDES) src/server.c src/util.c $(LIBFT) -o $(SERVER)
	@echo "[$(GREEN)compiling$(RESET)]: $(SERVER)"

$(LIBFT):
	@make -C Libft
	@mv Libft/$(LIBFT) .

clean:
	@make clean -C Libft

fclean: clean
	@rm -rf $(LIBFT)
	@rm -rf $(CLIENT) $(SERVER)
	@echo "$(RED)Removing executables$(RESET)"

re: fclean all

.PHONY: all clean fclean re


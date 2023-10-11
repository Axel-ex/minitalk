CLIENT	=	client

SERVER	=	server

CCFLAGS = 	-Wall -Werror -Wextra

LIBFT 	=	libft.a

RED =  \033[38;5;196m
GREEN = \033[38;5;47m
YELLOW = \033[38;5;226m
CYAN = \033[0;36m
RESET = \033[0m

all: $(CLIENT) $(SERVER)

$(CLIENT): $(LIBFT)
	@cc $(CCFLAGS) client.c $(LIBFT) -o $(CLIENT)
	@echo "$(GREEN)$(CLIENT) compilation done$(RESET)"

$(SERVER): $(LIBFT)
	@cc $(CCFLAGS) server.c util.c $(LIBFT) -o $(SERVER)
	@echo "$(GREEN)$(SERVER) compilation done$(RESET)"

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


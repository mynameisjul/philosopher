# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 14:38:38 by jblaye            #+#    #+#              #
#    Updated: 2024/04/26 10:09:38 by jblaye           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philosopher
TEST = test_philo

CC 			:= clang
CFLAGS 		:= -Wall -Wextra -Werror -g3 -pthread
ifeq (thread, $(filter thread,$(MAKECMDGOALS)))
	CFLAGS += -fsanitize=thread
endif
ifeq (leak, $(filter leak,$(MAKECMDGOALS)))
	CFLAGS += -fsanitize=leak
endif
DEP_FLAGS	:= -MMD -MP
MAKE_FLAG 	:= --no-print-directory --silent
RM 			:= rm -rf

### DIRECTORIES ###
SRC_DIR 	:= srcs
INCLD_DIR 	:= includes
OBJS_DIR 	:= objs

### FILES ###
SRC 		:=	parsing.c \
				init.c \
				main.c
SRC_TEST	:=	parsing.c \
				init.c \
				test.c
INCLUDES	:=	$(INCLD_DIR)
INCLD_FLAG 	:= 	$(addprefix -I , $(INCLUDES))
OBJS 		:= 	$(patsubst %.c,$(OBJS_DIR)/%.o,$(SRC))
OBJS_TEST	:=	$(patsubst %.c,$(OBJS_DIR)/%.o,$(SRC_TEST))
DEPS		:= 	$(patsubst %.c,$(OBJS_DIR)/%.d,$(SRC))

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(NEW)$(PURPLE)[$(NAME)] $(UGREEN)Building:$(DEFAULT)$(BWHITE) $@$(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) $(INCLD_FLAG) -o $@
	@printf "\n"

test: $(OBJS_TEST)
	@printf "$(NEW)$(PURPLE)[$(NAME)] $(UGREEN)Building:$(DEFAULT)$(BWHITE) $@$(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJS_TEST) $(LIB) $(INCLD_FLAG) -o $@
	@printf "\n"

-include $(DEPS)
$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@printf "$(NEW)$(PURPLE)[$(NAME)] $(UGREEN)Building:$(DEFAULT) $<"
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(DEP_FLAGS) $(CFLAGS) $(INCLD_FLAG) -c $< -o $@

clean: ; @printf "$(PURPLE)[$(NAME)] $(RED)Removing $(DEFAULT)$(OBJS_DIR) files\n"
	@$(RM) $(OBJS_DIR)

fclean: clean ; @printf "$(PURPLE)[$(NAME)] $(RED)Removing $(DEFAULT)$(NAME)\n"
	@$(RM) $(NAME)

re: fclean all
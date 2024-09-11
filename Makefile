NAME		=	Map_Generator

SRC_DIR		=	srcs/

OBJ_DIR     =   objs/

SRCS		+= main.c
SRCS		+= chained_list.c
SRCS		+= close.c
SRCS		+= door.c
SRCS		+= monster.c
SRCS		+= player.c
SRCS		+= room.c
SRCS		+= room_utils.c
SRCS		+= maze.c
SRCS		+= parsing.c
SRCS		+= init.c
SRCS		+= utils.c

vpath %.c $(SRC_DIR)

OBJS		=	$(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -MMD -MP -O2 -g3 

INCLUDES 	= 	-I -I/includes/ 

LIB			=	-lm

D_FILES		=	$(OBJS:.o=.d)

RM			=	rm -f

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m
BOLD_START=\e[1m
BOLD_END=\e[0m

ifeq ($(debug), true)
	CFLAGS += -g3 -fsanitize=address,undefined
endif

ifeq ($(optimax), true)
	CFLAGS += -O3 -Ofast -ffast-math
else
	CFLAGS += -O2
endif

all: 			${NAME}
				@echo "$(GREEN)$(BOLD_START)${NAME} created$(BOLD_END)$(END)"

${NAME}: 		${OBJS}
				$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) $(LIB)

$(OBJ_DIR)%.o: %.c
				@echo "$(BLUE)Compiling: $@ $(END)"
				mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
				$(RM) -r $(OBJ_DIR)
				${RM} ${OBJS}
				${RM} ${D_FILES}
				@echo "$(GREEN)$(BOLD_START)Clean done$(BOLD_END)$(END)"

fclean: clean
				${RM} ${NAME} ${NAME_BONUS}
				@echo "$(GREEN)$(BOLD_START)Fclean done$(BOLD_END)$(END)"

re: fclean all

sinclude $(D_FILES)

.PHONY: all clean fclean re bonus libft
.SILENT:
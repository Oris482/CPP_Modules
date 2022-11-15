# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 13:30:48 by jaesjeon          #+#    #+#              #
#    Updated: 2022/11/15 19:38:23 by jaesjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rvf
NAME = megaphone

INCS_DIR = ./
INCS =

SRCS_DIR = ./
SRCS = ${notdir ${wildcard ${SRC_DIR}*.cpp}}

OBJS_DIR = objs/
OBJS = ${addprefix ${OBJS_DIR}, ${SRCS:.cpp=.o}}


${OBJS_DIR}%.o: ${SRCS_DIR}%.cpp
	@echo "# Start compling"
	mkdir -p ${dir $@}
	${CC} ${CPPFLAGS} -I${INCS_DIR} -o $@ -c $<

.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${OBJS}
	@echo "# Start Linking"
	${CC} ${CPPFLAGS} -o ${NAME} ${OBJS}

clean: 
	@echo "# Deleted files"
	@${RM} ${OBJS_DIR}

fclean: clean
	@${RM} ${NAME}

re: fclean all
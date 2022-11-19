# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 13:30:48 by jaesjeon          #+#    #+#              #
#    Updated: 2022/11/19 15:52:57 by jaesjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors
RM = rm -rvf
NAME = MyAwesomePhonebook

INCS_DIR = ./
INCS =${notdir ${wildcard ${SRC_INCS_DIR}*.hpp}}

SRCS_DIR = ./
SRCS = ${notdir ${wildcard ${SRCS_DIR}*.cpp}}

OBJS_DIR = objs/
OBJS = ${addprefix ${OBJS_DIR}, ${SRCS:.cpp=.o}}


${OBJS_DIR}%.o: ${SRCS_DIR}%.cpp
	@echo "# Start compling"
	mkdir -p ${dir $@}
	${CC} ${CPPFLAGS} -I${INCS_DIR} -o $@ -c $<

.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${OBJS} ${INCS}
	@echo "# Start Linking"
	${CC} ${CPPFLAGS} -I${INCS_DIR} -o ${NAME} ${OBJS}

clean: 
	@echo "# Deleted files"
	@${RM} ${OBJS_DIR}

fclean: clean
	@${RM} ${NAME}

re: fclean all
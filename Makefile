# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jabusson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/01 23:09:05 by jabusson          #+#    #+#              #
#    Updated: 2015/05/03 20:04:09 by clegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color
RED = \033[1;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
PURPLE = \033[1;34m
BLUE = \033[0;36m
BG_GREEN = \033[42m
BG_YELLOW = \033[43m
BG_BLUE = \033[46m
NC = \033[0m
LEFT = \033[D

# Main
NAME = arkanoid
CC = gcc
ifeq ($(DEBUG), yes)
FDEBUG = -g
export DEBUG
endif
ifneq ($(FLAG), no)
WFLAGS = -Wall -Wextra -Werror -Wno-deprecated
endif
OPTI = -I
FRAMEW = -framework
LS = ls -1
GREP = grep
MKDIR = mkdir -p
RM = rm -rf
LFLAG = "VIEW=no"

# Directory
DSRC = srcs
DINC = incs
DLIB = libft
DOBJ = objs
DLINC = $(HOME)/glfw/include/ \
		incs \
		$(DLIB)/incs_libft \
		$(DLIB)/incs_printf
DGLFW = glfw
GLFWF = Cocoa \
		OpenGL \
		IOKit \
		CoreVideo \
 		GLUT
#WGLUTFLAGS = -lGL -lGLU -lglut 

# File
SRCS := $(shell $(LS) $(DSRC) | $(GREP) \.c$)
OBJS := $(SRCS:.c=.o)
LIBA := libftprintf.a
GLFWA := libglfw3.a

# Transform
SRCS := $(addprefix $(DSRC)/, $(SRCS))
DLINC := $(addprefix $(OPTI) , $(DLINC))
OBJS := $(addprefix $(DOBJ)/, $(OBJS))
LIBA := $(addprefix $(DLIB)/, $(LIBA))
GLFWA := $(addprefix $(HOME)/glfw/lib/, $(GLFWA))
GLFWF := $(addprefix $(FRAMEW) , $(GLFWF))

# Message
ifeq ($(ASCII), yes)
MBEGIN = "[ MAKEFILE ]\> Make compil $(NAME)"
MBLOAD = "[ LOAD FILE]\> "
MCLEAN = "[CLEAR FILE]\> all objects deleted"
MFCLEA = "[CLEAR LIB ]\> $(LIBA) and $(NAME) deleted"
MNAME  = "[COMPIL OK!]\> $(NAME) created"
MALL   = "[ END MAKE ]\> $(NAME)"
MOK = "Ok !"
else
MBEGIN = "\(🎁 \)\> Make compil $(NAME)"
MBLOAD = "\(⏳ \)\> "
MCLEAN = "\(✬ \)\> all objects deleted"
MFCLEA = "\(✦ \)\> $(LIBA) and $(NAME) deleted"
MNAME  = "\(✅ \)\> $(NAME) created"
MALL   = "\(🎆 \)\> End make $(NAME)"
MOK = "☑️ "
endif

all: begin libft $(DGLFW)/Makefile $(NAME)
ifneq ($(VIEW), no)
	@echo "$(BLUE)$(MALL)$(NC)"
endif

$(NAME): $(LIBA) $(OBJS)
ifneq ($(VIEW), no)
	@echo "$(YELLOW)| $(MOK)   $(NC)"
endif
	@$(CC) $(FDEBUG) $(WFLAGS) $(OBJS) $(LIBA) $(GLFWA) $(GLFWF) -o $@
ifneq ($(VIEW), no)
	@echo "$(GREEN)$(MNAME)$(NC)"
endif

begin:
ifneq ($(VIEW), no)
	@echo "$(BLUE)$(MBEGIN)$(NC)"
	@echo "$(YELLOW)$(MBLOAD)|$(RED)\c"
endif
	@$(MKDIR) $(DOBJ)

$(DOBJ)/%.o: $(DSRC)/%.c $(DINC)
	@$(CC) $(WFLAGS) $(FDEBUG) -c $< $(DLINC) -o $@ 
ifneq ($(VIEW), no)
	@echo "$(BG_YELLOW) $(NC)$(RED)\c"
endif

libft:
ifneq ($(VIEW), no)
	@echo "$(GREEN)Wait...$(RED)\c"
endif
	@make -C $(DLIB) $(LFLAG)
ifneq ($(VIEW), no)
	@echo "$(LEFT)$(LEFT)$(LEFT)$(LEFT)$(LEFT)$(LEFT)$(LEFT)\c"
endif

$(DGLFW)/Makefile:
	@git submodule init > /dev/null 2>&1
	@echo "$(NC)\c"
	@git submodule update 2> /dev/null
ifneq ($(VIEW), no)
	@echo "$(BG_BLUE) $(NC)$(RED)\c"
endif
	@cd $(DGLFW) && cmake -DCMAKE_INSTALL_PREFIX:PATH=$(HOME)/$(DGLFW) . > /dev/null
ifneq ($(VIEW), no)
	@echo "$(BG_BLUE) $(NC)$(RED)\c"
endif
	@make -C glfw > /dev/null 2>&1
ifneq ($(VIEW), no)
	@echo "$(BG_BLUE) $(NC)$(RED)\c"
endif
	@make install -C glfw > /dev/null 2>&1
ifneq ($(VIEW), no)
	@echo "$(BG_BLUE) $(NC)$(RED)\c"
endif

clean:
	@make -C $(DLIB) clean $(LFLAG)
	@[ ! -d $(DGLFW)/Makefile ] || make -C $(DGLFW) uninstall > /dev/null
	@$(RM) $(DOBJ) $(DGLFW)/Makefile
# WARNING
	@[ ! -d $(HOME)/$(DGLFW) ] || rm -r $(HOME)/$(DGLFW)
ifneq ($(VIEW), no)
	@echo "$(PURPLE)$(MCLEAN)$(NC)"
endif

fclean: clean
	@make -C $(DLIB) fclean $(LFLAG)
	@$(RM) $(NAME)
ifneq ($(VIEW), no)
	@echo "$(PURPLE)$(MFCLEA)$(NC)"
endif

re: fclean all

.PHONY: all begin libft clean fclean re

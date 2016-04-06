# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegrand <clegrand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/14 13:29:51 by clegrand          #+#    #+#              #
#    Updated: 2015/04/05 18:54:40 by clegrand         ###   ########.fr        #
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
NC = \033[0m

# Main
NAME = libftprintf.a
AR = ar -rcs
CC = gcc
ifeq ($(DEBUG), yes)
FDEBUG = -g
endif
ifneq ($(FLAG), no)
WFLAGS = -Wall -Wextra -Werror
endif
OPTI = -I
LS = ls -1
GREP = grep
MKDIR = mkdir -p
RM = rm -rf
LFLAG = "VIEW=no"

# Directory
DSRC = srcs_printf
LDSRC = srcs_libft
ADINC = incs_printf \
	   incs_libft
DOBJ = objs_printf
LDOBJ = objs_libft

# File
SRCS := $(shell $(LS) $(DSRC) | $(GREP) \.c)
LSRCS := $(shell $(LS) $(LDSRC) | $(GREP) \.c)
OBJS := $(SRCS:.c=.o)
LOBJS := $(LSRCS:.c=.o)

# Transform
SRCS := $(addprefix $(DSRC)/, $(SRCS))
LSRCS := $(addprefix $(LDSRC)/, $(LSRCS))
AINC := $(addprefix $(OPTI) , $(ADINC))
OBJS := $(addprefix $(DOBJ)/, $(OBJS))
LOBJS := $(addprefix $(LDOBJ)/, $(LOBJS))

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
MCLEAN = "\(✳️ \)\> all objects deleted"
MFCLEA = "\(❇️ \)\> $(LIBA) and $(NAME) deleted"
MNAME  = "\(✅ \)\> $(NAME) created"
MALL   = "\(🎆 \)\> End make $(NAME)"
MOK = "☑️ "
endif

all: begin $(LOBJS) begin2 $(OBJS) $(NAME)
ifneq ($(VIEW), no)
	@echo "$(BLUE)$(MALL)$(NC)"
endif

$(NAME): $(LOBJS) $(OBJS)
ifneq ($(VIEW), no)
	@echo "$(YELLOW)| $(MOK)$(NC)"
endif
	@$(AR) $@ $(OBJS) $(LOBJS)
ifneq ($(VIEW), no)
	@echo "$(GREEN)$(MNAME)$(NC)"
endif

begin:
ifneq ($(VIEW), no)
	@echo "$(BLUE)$(MBEGIN)$(NC)"
	@echo "$(YELLOW)$(MBLOAD)|$(RED)\c"
endif
	@$(MKDIR) $(LDOBJ)

$(DOBJ)/%.o: $(DSRC)/%.c $(ADINC)
	@$(CC) $(FDEBUG) $(WFLAGS) -c $< $(AINC) -o $@
ifneq ($(VIEW), no)
	@echo "$(BG_YELLOW) $(NC)$(RED)\c"
endif

begin2:
ifneq ($(VIEW), no)
	@echo "$(YELLOW)| $(MOK)"
	@echo "$(MBLOAD)|$(RED)\c"
endif
	@$(MKDIR) $(DOBJ)

$(LDOBJ)/%.o: $(LDSRC)/%.c $(ADINC)
	@$(CC) $(FDEBUG) $(WFLAGS) -c $< $(AINC) -o $@
ifneq ($(VIEW), no)
	@echo "$(BG_GREEN) $(NC)$(RED)\c"
endif

clean:
	@$(RM) $(DOBJ) $(LDOBJ)
ifneq ($(VIEW), no)
	@echo "$(PURPLE)$(MCLEAN)$(NC)"
endif

fclean: clean
	@$(RM) $(NAME)
ifneq ($(VIEW), no)
	@echo "$(PURPLE)$(MFCLEA)$(NC)"
endif

re: fclean all

.PHONY: all begin begin2 clean fclean re

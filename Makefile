# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 01:36:34 by brda-sil          #+#    #+#              #
#    Updated: 2022/10/14 14:14:24 by brda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# config
CFLAGS			:= -Wall -Wextra -lreadline
TARGET			:= minishell
RM				:= rm -rf
CC				:= gcc
MAKE			:= make -C
VERSION			:= 4.1.2
$(eval export MAIN=1)

ifneq ($(PADDING),60)
PADDING			:= 60
endif

ifeq ($(DEBUG),)
CFLAGS			+= -Werror
else
CFLAGS			+= -g3
endif

# DIR
SRC_DIR			:= src
LIB_DIR			:= .
OBJ_DIR			:= obj
OBJ_SUBDIR		:= $(sort $(shell find $(SRC_DIR) -type d | \
											sed 's|$(SRC_DIR)|$(OBJ_DIR)|g'))
INC_TMP			:= inc \
				   $(LIB_DIR)/libft/inc
INC_DIR			:= $(addprefix -I,$(INC_TMP))

# LIB
LIBFT			:= $(LIB_DIR)/libft/libft.a

# SRC
SRC_C			:= src/builtins/cd.c \
				   src/builtins/echo.c \
				   src/builtins/env.c \
				   src/builtins/exit.c \
				   src/builtins/export.c \
				   src/builtins/pwd.c \
				   src/builtins/unset.c \
				   src/builtins/utils/args.c \
				   src/builtins/utils/do_something_with_cmd.c \
				   src/builtins/utils/env.c \
				   src/builtins/utils/env_export_utils_1.c \
				   src/builtins/utils/env_export_utils_2.c \
				   src/builtins/utils/env_export_utils_3.c \
				   src/builtins/utils/get_cwd.c \
				   src/builtins/utils/is_good_var_env.c \
				   src/builtins/utils/params.c \
				   src/dataset/free/cmds.c \
				   src/dataset/free/config.c \
				   src/dataset/free/exec.c \
				   src/dataset/free/pipes.c \
				   src/dataset/free/utils/char_pointer_pointer.c \
				   src/dataset/free/utils/list.c \
				   src/dataset/init/config.c \
				   src/dataset/init/context.c \
				   src/dataset/init/get_prompt.c \
				   src/dataset/init/redirection.c \
				   src/debug/builtin.c \
				   src/debug/init_redirection.c \
				   src/debug/parse.c \
				   src/debug/print.c \
				   src/debug/print_bool.c \
				   src/debug/print_cmd.c \
				   src/debug/prompt.c \
				   src/debug/signal.c \
				   src/minishell.c \
				   src/shell/exec_engine/exec/exec_builtin.c \
				   src/shell/exec_engine/exec/exec_prepare.c \
				   src/shell/exec_engine/exec/execute.c \
				   src/shell/exec_engine/exec/prepare_cmds.c \
				   src/shell/exec_engine/exec/prepare_cmds_error.c \
				   src/shell/exec_engine/exec/prepare_redir.c \
				   src/shell/exec_engine/exec/prepare_redir_heredoc.c \
				   src/shell/exec_engine/exec/prepare_redir_ng.c \
				   src/shell/exec_engine/exec_engine.c \
				   src/shell/exec_engine/utils/builtins.c \
				   src/shell/exec_engine/utils/path.c \
				   src/shell/exec_engine/utils/print_error.c \
				   src/shell/exec_engine/utils/utils.c \
				   src/shell/loop.c \
				   src/shell/parsing_cmd/get_block.c \
				   src/shell/parsing_cmd/identify_pipe.c \
				   src/shell/parsing_cmd/parse_entry.c \
				   src/shell/parsing_cmd/replace_dollar.c \
				   src/shell/parsing_cmd/utils/convert_list.c \
				   src/shell/prompt/get_base_prompt.c \
				   src/shell/prompt/get_prompt.c \
				   src/shell/prompt/get_status_prompt.c \
				   src/shell/signal_handling/handler.c \
				   src/shell/signal_handling/signal.c \
				   src/utils/env_to_char.c \
				   src/utils/ft_better_split.c \
				   src/utils/ft_better_strjoin.c \
				   src/utils/sh_lvl.c

# OBJ

OBJ_C			:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))

# LIB DIR
CFLAGS			+= $(INC_DIR)
LIBS			:= $(LIBFT)

#  Bash Color / unicode char

#get_random		= $(shell seq 0 256 | shuf | head -n1)
green			:= \033[38;5;82m
blue			:= \033[38;5;75m
red				:= \033[38;5;196m
orange			:= \033[38;5;214m

blinking		:= \033[5m
reset			:= \033[0m

font_color		:= $(blue)
bold			:= $(red)
ascii_color		:= $(bold)

green_plus		:= $(font_color)[$(green)+$(font_color)]
red_minus		:= $(font_color)[$(red)-$(font_color)]
orange_star		:= $(font_color)[$(orange)*$(font_color)]
blinking_arrow	:= $(blinking)$(font_color)->
#font_color		:= \033[38;5;$(get_random)m
#bold			:= \033[38;5;$(get_random)m
#ascii_color		:= \033[38;5;$(get_random)m

UL="\xe2\x95\x94"
HO="\xe2\x95\x90"
UR="\xe2\x95\x97"
VE="\xe2\x95\x91"
LL="\xe2\x95\x9a"
LR="\xe2\x95\x9d"

# **************************************************************************** #

# **************************************************************************** #
# utils

define ascii_art
 ███▄ ▄███▓ ██▓ ███▄    █  ██▓  ██████  ██░ ██ ▓█████  ██▓     ██▓
▓██▒▀█▀ ██▒▓██▒ ██ ▀█   █ ▓██▒▒██    ▒ ▓██░ ██▒▓█   ▀ ▓██▒    ▓██▒
▓██    ▓██░▒██▒▓██  ▀█ ██▒▒██▒░ ▓██▄   ▒██▀▀██░▒███   ▒██░    ▒██░
▒██    ▒██ ░██░▓██▒  ▐▌██▒░██░  ▒   ██▒░▓█ ░██ ▒▓█  ▄ ▒██░    ▒██░
▒██▒   ░██▒░██░▒██░   ▓██░░██░▒██████▒▒░▓█▒░██▓░▒████▒░██████▒░██████▒
░ ▒░   ░  ░░▓  ░ ▒░   ▒ ▒ ░▓  ▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒░▓  ░░ ▒░▓  ░
░  ░      ░ ▒ ░░ ░░   ░ ▒░ ▒ ░░ ░▒  ░ ░ ▒ ░▒░ ░ ░ ░  ░░ ░ ▒  ░░ ░ ▒  ░
░      ░    ▒ ░   ░   ░ ░  ▒ ░░  ░  ░   ░  ░░ ░   ░     ░ ░     ░ ░
       ░    ░           ░  ░        ░   ░  ░  ░   ░  ░    ░  ░    ░  ░
$(reset)
endef
export ascii_art

define print_padded
	@printf '   $(orange_star) $(font_color)Creation of $(bold)$1'
	$(eval OBJ_LEN := $(shell printf $1 | wc -c))
	$(eval PAD_LEN := $(shell expr $(PADDING) - $(OBJ_LEN)))
	@printf '%-$(PAD_LEN)s' ' '
	@printf '$(blinking_arrow) $(reset)$(bold)$2 $(reset)'
	@printf '\n'
endef

define usage
$(orange_star) $(bold)$(TARGET)$(font_color): $(bold)needed_args \
$(font_color)[$(bold)optional_args$(font_color)]$(reset)
        $(bold)arg$(font_color): eplanation
        $(bold)arg$(font_color): eplanation
        $(bold)arg$(font_color): eplanation, $(bold)WARNING$(reset)
$(font_color)Version: $(bold)$(VERSION)$(reset)

endef
export usage

define make_dir
	@if [ ! -d $1 ]; then														\
		mkdir $1;																\
		printf "$(green_plus) $(font_color)Create dir $(bold)$1$(reset)\n";		\
	fi
endef
# **************************************************************************** #

# **************************************************************************** #
# Rules

all:			setup $(TARGET)
	@printf "$$usage"

$(TARGET):				$(LIBFT) $(OBJ_C)
	@printf "$(green_plus) $(font_color)Creation of $(bold)$@$(reset)\n"
	@$(CC) -o $@ $(OBJ_C) $(LIBS) $(CFLAGS)

$(LIBFT):
	@$(MAKE) libft all

$(OBJ_SUBDIR):
	$(foreach dir,$@,$(call make_dir,$(dir)))

$(OBJ_DIR)/%.o: 		$(SRC_DIR)/%.c
	$(call print_padded,$^,$@)
	@$(CC) -o $@ -c $< $(CFLAGS)

setup:					call_logo $(OBJ_SUBDIR)

call_logo:
	@printf "$(ascii_color)$$ascii_art"

clean_all:				clean
	@$(MAKE) libft clean

clean:
	@printf "$(red_minus) $(font_color)Deleting $(bold)$(OBJ_DIR)$(reset)\n"
	@$(RM) $(OBJ_DIR)

fclean_all:				fclean
	@$(MAKE) libft fclean

fclean:					clean
	@printf "$(red_minus) $(font_color)Deleting $(bold)$(TARGET)$(reset)\n"
	@$(RM) $(TARGET)

re_lib:
	@$(MAKE) libft re all

test:					setup $(OBJ_C) $(LIBFT)
	@$(CC) $(TEST) -o ./test/$@ $(filter-out obj/minishell.o,$(OBJ_C)) $(LIBS) $(CFLAGS)

re:						fclean all

re_all:					re_lib re

.PHONY:					all clean fclean re setup lib call_logo

# **************************************************************************** #

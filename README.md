# minishell
https://cdn.intra.42.fr/pdf/pdf/58866/fr.subject.pdf

# TODO

1. suppress ^C|^\ from signal (<termios.h>)

# TIPS

## valgrind
> without vsupp work fine
`valgrind --leak-check=full <exec_path>`

> with vsupp suppress ALL leak linked to readline ...
`valgrind --leak-check=full --suppressions=vsupp <exec_path>`

## exec with log
`./minishell 3>exec.log; cat exec.log`

## AST
1. https://github.com/pmouhali/minishell_ast
	- https://ruslanspivak.com/lsbasi-part7/
	- https://unix.stackexchange.com/questions/88850/precedence-of-the-shell-logical-operators
2. https://github.com/AudeizReading/minishell/wiki/01-PARSING
	-

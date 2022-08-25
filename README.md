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

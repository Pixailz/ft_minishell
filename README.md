# minishell
https://cdn.intra.42.fr/pdf/pdf/58866/fr.subject.pdf

# TEST / TODO

1. working like the original bash
	- `ca't' -e file`
	- `ca't -e' "file.txt"`
	- `cat -e "fi"le`
	- `cat -e "fi"'le'`
	- `sleep 3 | cat file`
	- `echo pass | grep 'ass'`
	- `echo test1 | echo test2`
	- `echoo pass | cat file`
	- `cat | cat -e`
	- `cat | ls | cat`
	- `ping -c4 google.com | cat -e`
	- `grep -oE "a|b" | cat -e`
	- `cat -e | grep -o "ass"`
	- `cat | cat -e | cat -e`
	- `echo pass | grep -o ass | cat -e`
	- `echo pass | cat1 file | cat2 file`
	- `< file cat | < file cat`
	- `< file cat > outfile | < file cat`
	- `< file cat > outfile1 | < file cat >> outfile2`
	- `< file cat > file1 | < file cat -e > file2 | < file cat -e > file3 | < file cat -e >> file4`
	- `< file cat > file1 | cat >> file2`
	- `< file cat -e > file1 | < filee grep a1 > file2`
	- `< file cat -e > file1 | < file grep a1 > file2`
		- with file2 chmod 000
	- `echo "test > test"`
	- `ech$O test`
	- `echo pass1 > file pass2`
	- `echo pass >>file1 | echo pass >> file2`

1. TODO / not working
	- `cat -e "fi"le "`
	- `< file << END cat -e > file1 >> file2`<br>
	  `TEST`<br>
	  `END`
		- in this order only
	- not working multiple double in
1. exit with errno
	- implement `$?`
1. add history functionality
1. implement color prompt, with current cwd
1. implement clean debug to LOG_FD

## valgrind
> without vsupp work fine
`valgrind --leak-check=full <exec_path>`

> with vsupp suppress ALL leak linked to readline ...
`valgrind --leak-check=full --suppressions=vsupp <exec_path>`

## exec with log
`./minishell 3>exec.log; cat exec.log`

## PIPE
[PIPE](https://youtu.be/ceNaZzEoUhk?t=1576)

## AST
1. https://github.com/pmouhali/minishell_ast
	- https://ruslanspivak.com/lsbasi-part7/
	- https://unix.stackexchange.com/questions/88850/precedence-of-the-shell-logical-operators
1. https://github.com/AudeizReading/minishell/wiki/01-PARSING

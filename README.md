# minishell
https://cdn.intra.42.fr/pdf/pdf/58866/fr.subject.pdf

# TODO

1. fix ft_splitb
	- with last enclosed if is not enclosed

## first command to parse / exec

1. should work
	- `cat -e "file.txt"`
	- `ca't' -e "file.txt"`
	- `cat -e "file".txt`
	- `cat -e "file".'txt'`
2. shouldn't work
	- `ca't -e' "file.txt"`

# TIPS

## EXEC PART

1. working like the original bash
	- `sleep 3 | cat file`
	- `echo pass | grep 'ass'`
	- `echo test1 | echo test2`
	- `echoo pass | cat file`
	- `cat | cat -e`
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
	- `< file << END cat -e > file1 >> file2`<br>
	  `TEST`<br>
	  `END`
		- in this order only
	- partial double_in
1. TODO / not working
	- not working multiple double in
	- `< file cat -e > file1 > file2 > fileN`
	- `< file1 cat -e > file2 | << file3 echo pass1 >> file4 pass2`
	- `echo pass1 > file pass2`

1. free ALL list
1. repair command not found
1. repair file not found
	- exit with errno
	- add support in print_command_not_found (rename it print_error)
1. fix space

## PARSING PART

1. working like the original bash
	- `echo "test > test"`
	- `ech$O test`
1. TODO / not working

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

# minishell
https://cdn.intra.42.fr/pdf/pdf/58866/fr.subject.pdf

# TEST / TODO

1. TODO / not working
	- `echo pass <> file | echo pass`
		- parsing, create `file` but don't pipe output to it
1. add alias
1. add minishellrc
1. built-ins
	- [x] echo et l’option -n
	- [x] cd uniquement avec un chemin relatif ou absolu
		- CDPATH
	- [x] pwd sans aucune option
	- [x] export sans aucune option
	- [x] unset sans aucune option
	- [x] env sans aucune option ni argument
	- [x] exit sans aucune option
1. debug print
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

## DEBUG

> without vsupp work fine

`valgrind --leak-check=full <exec_path>`

> with vsupp suppress ALL leak linked to readline ...

`make re DEBUG=1 && valgrind  --leak-check=full --show-leak-kinds=all --suppressions=vsupp --trace-children=yes --track-fds=yes ./minishell 420>exec.log ; cat exec.log`

> MEGALINE

```
./scripts/ft_helper/ft_helper && make re DEBUG=1 && \
valgrind  --leak-check=full --show-leak-kinds=all --suppressions=$(pwd)/vsupp --trace-children=yes --track-fds=yes ./minishell 420>exec.log ; cat exec.log
```

> strace with ioctl

`strace -e trace=ioctl bash`

## exec with log
`./minishell 420>exec.log; echo "exit_code [$?]"; cat exec.log`

## termios
https://stackoverflow.com/a/27559151

### USAGE

> log
```h
# define DEBUG				<0|1>
# define LOG_FD				<FD_LOG_OUTPUT>
```

> prompt
```h
# define OLD_STYLE			<0|1>

# define C_PROMPT_ROOT		<COLOR_CODE>
# define C_PROMPT_BASE		<COLOR_CODE>
# define C_PROMPT_PATH		<COLOR_CODE>
# define C_PROMPT_CMD		<COLOR_CODE>

# define C_PROMPT_STATUS_1	<COLOR_CODE>
# define C_PROMPT_STATUS_2	<COLOR_CODE>
# define C_PROMPT_STATUS_0	<COLOR_CODE>
```

## TODO

1. `exit 1 1`
1. ctrl-\
1. ^C
	- forked_here_doc
	- normal command (cat | grep)
1. CDPATH
1. executable
	- fix message
	- ft_isexec
1. `echo pass '>' file`
1. cd <3
1. why without path execve check for current directory

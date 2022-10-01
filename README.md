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

### vsupp

```md
{
	readline
	Memcheck:Leak
	...
	fun:readline
	...
}
{
	readline
	Memcheck:Leak
	...
	fun:add_history
	...
}
```

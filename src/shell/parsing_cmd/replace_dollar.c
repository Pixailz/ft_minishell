/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 01:06:29 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/22 01:10:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_key_2(int i, char **input, char **key, t_lst_env *env)
{
	while (--i >= 0)
		(*input)++;
	free(*key);
	if (env)
		return (ft_strdup(env->value));
	return (ft_strdup("\0"));
}

char	*find_key(t_main *config, char **input, t_lst_env *env)
{
	char	*key;
	int		i;

	i = 0;
	if (**input != '$')
		return (ft_strdup("\0"));
	(*input)++;
	if (**input == '?')
		return (replace_question_mark(config, input));
	while ((*input)[i] && (ft_isalnum((*input)[i]) || (*input)[i] == '_'))
		i++;
	if (i == 0)
		return (ft_strdup("$"));
	key = ft_substr(*input, 0, i);
	while (env)
	{
		if (!ft_strcmp_env(key, env->key))
			break ;
		env = env->next;
	}
	return (find_key_2(i, input, &key, env));
}

char	*replace_question_mark(t_main *config, char **input)
{
	(*input)++;
	return (ft_itoa(config->last_return_value));
}

char	*replace_key(t_main *config, char *input, t_lst_env *env)
{
	int		i;
	char	*str;

	i = 0;
	if (!input || ft_strcchr(" '|<>", input[0]))
		return (ft_strdup(input));
	str = ft_strdup("\0");
	while (input[i])
	{
		while (input[i] && input[i] != '$')
			i++;
		str = ft_better_strjoin(str, ft_substr(input, 0, i));
		while (i > 0)
		{
			i--;
			input++;
		}
		str = ft_better_strjoin(str, find_key(config, &input, env));
	}
	return (str);
}

void	parse_replace_dollar(t_main *config, t_lst_env *env)
{
	char		*str;
	t_list		*tmp;

	tmp = config->line_splitted;
	while (tmp)
	{
		str = replace_key(config, tmp->content, env);
		free(tmp->content);
		tmp->content = str;
		tmp = tmp->next;
	}
}

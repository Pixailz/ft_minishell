/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:19:40 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/20 02:01:44 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_prompt_tilde(t_main *config)
{
	char	*prompt_tmp_1;
	char	*prompt_tmp_2;
	char	*path;
	int		len_home;
	int		len_other;

	prompt_tmp_1 = ft_strjoin(BASE_PROMPT_C2, "~");
	len_home = ft_strlen(config->home);
	len_other = ft_strlen(config->cwd) - len_home;
	if (!len_other)
		return (prompt_tmp_1);
	path = ft_substr(config->cwd, len_home, len_other);
	prompt_tmp_2 = ft_strjoin(prompt_tmp_1, path);
	free(path);
	path = FT_NULL;
	free(prompt_tmp_1);
	prompt_tmp_1 = ft_strjoin(prompt_tmp_2, RESET_C);
	free(prompt_tmp_2);
	prompt_tmp_2 = FT_NULL;
	return (prompt_tmp_1);
}

char	*get_prompt_no_tilde(t_main *config)
{
	char	*prompt_tmp_1;
	char	*prompt_tmp_2;

	prompt_tmp_1 = ft_strjoin(BASE_PROMPT_C2, config->cwd);
	prompt_tmp_2 = ft_strjoin(prompt_tmp_1, RESET_C);
	free(prompt_tmp_1);
	prompt_tmp_1 = FT_NULL;
	return (prompt_tmp_2);
}

char	*get_prompt_2(t_main *config, char *tmp_1)
{
	char	*tmp_3;
	char	*tmp_2;

	tmp_3 = get_status_prompt(config);
	tmp_2 = ft_strjoin(tmp_3, " ");
	free(tmp_3);
	tmp_3 = ft_strjoin(tmp_2, tmp_1);
	free(tmp_2);
	free(tmp_1);
	return (tmp_3);
}

void	get_prompt(t_main *config)
{
	char	*prompt_tmp_1;
	char	*prompt_tmp_2;

	config->home = get_env("HOME", config->env);
	if (ft_strncmp(config->cwd, config->home, ft_strlen(config->home)))
		prompt_tmp_1 = get_prompt_no_tilde(config);
	else
		prompt_tmp_1 = get_prompt_tilde(config);
	if (ft_strncmp(config->user, "root", 4))
		prompt_tmp_2 = ft_strjoin(prompt_tmp_1, "$ ");
	else
		prompt_tmp_2 = ft_strjoin(prompt_tmp_1, "# ");
	free(prompt_tmp_1);
	prompt_tmp_1 = ft_strjoin(config->prompt_base, prompt_tmp_2);
	free(prompt_tmp_2);
	if (config->prompt)
		free(config->prompt);
	if (DEBUG)
		config->prompt = get_prompt_2(config, prompt_tmp_1);
	else
		config->prompt = prompt_tmp_1;
	debug_prompt(config);
}

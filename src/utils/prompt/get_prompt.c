/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:19:40 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/21 20:06:43 by brda-sil         ###   ########.fr       */
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

	prompt_tmp_1 = ft_strjoin(C_PROMPT_PATH, "~");
	len_home = ft_strlen(config->home);
	len_other = ft_strlen(config->cwd) - len_home;
	if (!len_other)
	{
		prompt_tmp_2 = ft_strjoin(prompt_tmp_1, C_RESET);
		free(prompt_tmp_1);
		return (prompt_tmp_2);
	}
	path = ft_substr(config->cwd, len_home, len_other);
	prompt_tmp_2 = ft_strjoin(prompt_tmp_1, path);
	free(path);
	path = FT_NULL;
	free(prompt_tmp_1);
	prompt_tmp_1 = ft_strjoin(prompt_tmp_2, C_RESET);
	free(prompt_tmp_2);
	prompt_tmp_2 = FT_NULL;
	return (prompt_tmp_1);
}

char	*get_prompt_no_tilde(t_main *config)
{
	char	*prompt_tmp_1;
	char	*prompt_tmp_2;

	prompt_tmp_1 = ft_strjoin(C_PROMPT_PATH, config->cwd);
	prompt_tmp_2 = ft_strjoin(prompt_tmp_1, C_RESET);
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
	return (tmp_3);
}

void	get_prompt_init(t_main *config)
{
	free(config->cwd);
	config->cwd = get_cwd();
	config->home = get_env("HOME", config->env);
}

void	get_prompt(t_main *config)
{
	char	*prompt_tmp_1;
	char	*prompt_tmp_2;

	get_prompt_init(config);
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
	if (DEBUG)
		prompt_tmp_2 = get_prompt_2(config, prompt_tmp_1);
	else
		prompt_tmp_2 = ft_strdup(prompt_tmp_1);
	free(prompt_tmp_1);
	if (config->prompt)
		free(config->prompt);
	config->prompt = ft_strjoin(prompt_tmp_2, C_PROMPT_CMD);
	free(prompt_tmp_2);
	debug_prompt(config);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_base_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:19:40 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/20 19:19:58 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_hostname(void)
{
	int		file;
	char	buff[0xff];
	int		len;
	char	*tmp;
	char	**hostnames;

	if (access("/etc/hostname", F_OK | R_OK) != 0)
		return (ft_strdup("localhost"));
	file = open("/etc/hostname", O_RDONLY);
	read(file, buff, 0xff);
	tmp = ft_strchr(buff, '\n');
	len = tmp - buff;
	while (len <= 0xff)
		buff[len++] = 0;
	close(file);
	if (ft_strcchr(buff, '.'))
	{
		hostnames = ft_split(buff, '.');
		tmp = ft_strdup(hostnames[0]);
		free_char_pointer_pointer(hostnames);
	}
	tmp = ft_strdup(buff);
	return (tmp);
}

char	*assemble_base_prompt(char *user, char **hostname)
{
	char	*prompt_tmp_1;
	char	*prompt_tmp_2;

	if (!ft_strncmp(user, "root", 4))
		prompt_tmp_1 = ft_strjoin(C_PROMPT_ROOT, user);
	else
		prompt_tmp_1 = ft_strjoin(C_PROMPT_BASE, user);
	prompt_tmp_2 = ft_strjoin(prompt_tmp_1, "@");
	free(prompt_tmp_1);
	prompt_tmp_1 = ft_strjoin(prompt_tmp_2, *hostname);
	free(*hostname);
	*hostname = FT_NULL;
	free(prompt_tmp_2);
	prompt_tmp_2 = ft_strjoin(prompt_tmp_1, C_RESET);
	free(prompt_tmp_1);
	prompt_tmp_1 = ft_strjoin(prompt_tmp_2, ":");
	free(prompt_tmp_2);
	return (prompt_tmp_1);
}

char	*get_base_prompt(t_main *config)
{
	char	*hostname;
	char	*prompt;

	config->user = getenv("LOGNAME");
	hostname = get_hostname();
	prompt = assemble_base_prompt(config->user, &hostname);
	return (prompt);
}

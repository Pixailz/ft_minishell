/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 00:19:40 by brda-sil          #+#    #+#             */
/*   Updated: 2022/09/19 16:44:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_hostname(void)
{
	int		file;
	int		len;
	char	buff[0x100];
	char	*hostname;

	file = open("/etc/hostname", O_RDONLY);
	read(file, buff, 0x100);
	len = ft_strlen(buff);
	hostname = (char *)malloc(sizeof(char) * len - 2);
	ft_strcpy(hostname, buff);
	hostname[len - 1] = FT_NULL;
	return (hostname);
}

void	get_base_prompt_assemble(t_main *config, t_list *prompt)
{

}

char	*get_base_prompt(t_main *config)
{
	t_list	*prompt;

	prompt = ft_lstnew(ft_strdup(getenv("USER")));
	ft_lstadd_back(prompt, ft_lstnew(get_hostname()));
	get_base_prompt_assemble(config, prompt);
	exit(1);
	return (ft_strdup("minishell@hostname:~/Documents$ "));
}

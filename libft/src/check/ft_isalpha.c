/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:31:21 by pix               #+#    #+#             */
/*   Updated: 2022/09/28 17:56:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief			Checks if c is an alphabetic character.
 *
 * @param c			Character value to check
 *
 * @return (int)	Nonzero if character is alphabetic and zero if not
 */
int	ft_isalpha(const char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z' ));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:32:17 by napark            #+#    #+#             */
/*   Updated: 2021/06/30 12:32:19 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	nlen(int n)
{
	if (n < 0)
	{
		if (n > -10 && n < 0)
			return (2);
		else
			return (nlen(n / 10 * (-1)) + 2);
	}
	if (n < 10)
		return (1);
	return (nlen(n / 10) + 1);
}

char	*ft_itoa(int n)
{
	char	*dst;
	int		i;

	i = nlen(n);
	dst = (char *)malloc((i + 1) * sizeof(char));
	if (dst == 0)
		return (0);
	dst[i--] = 0;
	if (n < 0)
	{
		dst[0] = 45;
		dst[i] = (n % 10) * (-1) + 48;
		n = (n / 10) * (-1);
		if (n == 0)
			return (dst);
		i--;
	}
	while ((n / 10) > 0)
	{
		dst[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	dst[i] = n + 48;
	return (dst);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd != 0 && s != 0)
	{
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}

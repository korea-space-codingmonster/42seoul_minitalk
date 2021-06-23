/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:44:42 by napark            #+#    #+#             */
/*   Updated: 2021/06/23 14:54:40 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int     ft_check_argv(char *str)//포인터 주소
{
    int	i;
	int	num;

	i = 0;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num *= 10;
		num += str[i] - 48;
		i++;
		if (str[i] != 0)
		{
			if ((num == 214748364 && str[i] - 48 > 7) || num > 214748364)
				return (-1);//숫자가 아닌 문자값 return
		}
	}
	return (1);
}

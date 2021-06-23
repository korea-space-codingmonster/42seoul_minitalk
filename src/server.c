/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:24:06 by napark            #+#    #+#             */
/*   Updated: 2021/06/23 16:50:12 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_create_string(char carattere, char *string)
{
	char	*temp;
	char	*temp2;

	temp = malloc(2);
	if (temp == 0)
		exit(0);
	temp[0] = carattere;
	temp[1] = 0;
	if (string == 0)
	{
		string = malloc(2);
		if (string == 0)
			exit(0);
		ft_strlcpy(string, temp, 2);
	}
	else
	{
		temp2 = string;
		string = ft_strjoin(string, temp);
		if (string == 0)
			exit (0);
		free(temp2);
	}
	free(temp);
	return (string);
}

void    ft_count(int sign)
{
    static int	cont;
	static int	carattere;
	static char	*string;

	cont++;
	if (sign == SIGUSR2)
	{
		carattere = carattere << 1;
		carattere += 1;
	}
	else
		carattere = carattere << 1;
	if (cont == 7)
	{
		string = ft_create_string(carattere, string);
		if (carattere == 0)
		{
			ft_putstr_fd(string, 1);
			write(1, "\n", 1);
			free(string);
			string = 0;
		}
		cont = 0;
		carattere = 0;
	}
}

int     main(void)
{
    int pid;
    char *pidnum;

    pid = getpid();//프로세스의 번호(pid)를 받는다.
    pidnum = ft_itoa(pid);//받은 pid를 char로 변환(client에게 알려주기 위해서)
    if (pidnum == 0)//pid값이 0이면 즉, 받지 못하면
        exit(0);//바로 종료
    ft_putstr_fd(pidnum, 1);//피드 넘버를 출력
    write(1, "\n", 1);//한줄 뛰어넘고
    //여기서 부터 client가 보낸 메세지를 받고 출력할 것
    signal(SIGUSR1, ft_count);//SIGUSR1 = 받은 시그넘버()
    signal(SIGUSR2, ft_count);
    while (1)
        pause();
}
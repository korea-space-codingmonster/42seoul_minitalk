/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:37:40 by napark            #+#    #+#             */
/*   Updated: 2021/06/23 16:31:34 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char    *ft_cutobit(char str)//비트로 보내기 위한 비트 전환
{
    char    *ret;
    int     i;

    ret = malloc(sizeof(8));//8바이트 확보
    if (ret == 0)
        exit(0);
    ret[7] == 0;//kill로 보내고 받을 떄 null을 중심으로 어디까지 받고 끊을지 결정
    
    i = 6;
    while (str > 1)
    {
        ret[i] = (str % 2) + 48;
        str /= 2;
        i--;
    }
    ret[i] = (str % 2) + 48;
    i--;
    while (i >= 0)
    {
        ret[i] = 48;
        i--;
    }
    return (ret);
}

void ft_send_term(int pid)
{
    int i;

    i = 0;
    while (i < 7)
    {
        kill(pid, SIGUSR1);
        i++;
        usleep(50);
    }
}

static void     ft_send_signal(int pid, char *string)
{
    int i;
    int j;
    char *tmp;
    
    i = 0;
    j = 0;
    while (string[i])
    {
        tmp = ft_cutobit(string[i]);//보내기 위해 잘라줘
        j = 0;
        while (tmp[j])
        {
            if (tmp[j] == '0')
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            j++;
            usleep(50);
        }
        free(tmp);//하나한 보내면서 다보내면 해제
        i++;
    }
    ft_send_term(pid);
}

int     main(int argc, char *argv[])
{
    int     i;
    int     pid;
    char    *string;

    if (argc != 3)
        exit(0);

    i = 0;
    if (ft_check_argv(argv[1]) < 0)
        exit(0);
    pid = ft_atoi(argv[1]);//보낼 피드 값 정수 변환
    string = argv[2];//보낼 data
    ft_send_signal(pid, string);
}

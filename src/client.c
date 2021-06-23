/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:37:40 by napark            #+#    #+#             */
/*   Updated: 2021/06/23 15:33:03 by napark           ###   ########.fr       */
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

static void     ft_send_signal(int pid, char *string)
{
    int i;
    char *tmp;
    
    i = 0;
    while (string[i])
    {
        tmp = ft_cutobit(string[i]);//보내기 위해 잘라줘
    }
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

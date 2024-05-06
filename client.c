/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:22:51 by tjehaes           #+#    #+#             */
/*   Updated: 2024/05/06 10:19:54 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/*
void	send_bits(char *str, int pid)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			if (((str[i] >> j) & 1) == 0)
				kill(pid, SIGUSR1);
			else if (((str[i] >> j) & 1) == 1)
				kill(pid, SIGUSR2);
			usleep(42);
			j--;
		}
		i++;
	}
	while (++j < 8)
	{
		kill(pid, SIGUSR1);
		usleep(42);
	}
}
*/

void    send_bits(char c, int pid)
{
        int     i;

        i = 0;
	while (i < 8)
	{
		if ((c & (0x01 << i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(60);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		send_bits('\n', server_pid);
		while (argv[2][i] != '\0')
		{
			send_bits(argv[2][i], server_pid);
			i++;
		}
	}
	else
		ft_printf("Number of argument not valid\n");
	return (0);
}

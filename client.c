/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:22:51 by tjehaes           #+#    #+#             */
/*   Updated: 2024/05/03 13:56:46 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(char *str, int pid)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (j < 8)
		{
			if (((str[i] >> j) & 1) == 0)
				kill(pid, SIGUSR1);
			else if (((str[i] >> j) & 1) == 1)
				kill(pid, SIGUSR2);
			usleep(42);
			j++;
		}
		i++;
	}
	while (j >= 0)
	{
		kill(pid, SIGUSR1);
		usleep(42);
		j--;
	}
}

int	main(int argc, char **argv)
{
	char	*msg;
	int		server_pid;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (!server_pid)
		{
			ft_printf("Error : wrong pid\n");
			return (0);
		}
		msg = argv[2];
		if (!msg)
		{
			ft_printf("Error : message not valid\n");
			return (0);
		}
		else
			send_bits(msg, server_pid);
	}
	else
		ft_printf("Number of argument not valid\n");
	return (0);
}

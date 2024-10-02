/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:22:51 by tjehaes           #+#    #+#             */
/*   Updated: 2024/10/02 14:36:50 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & (0x01 << i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(450);
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

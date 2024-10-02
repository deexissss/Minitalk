/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:22:42 by tjehaes           #+#    #+#             */
/*   Updated: 2024/10/01 10:39:39 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	manage_signal(int signal)
{
	static int	bit_received;
	static int	i;

	if (signal == SIGUSR1)
		i = i | (1 << bit_received);
	bit_received++;
	if (bit_received == 8)
	{
		ft_printf("%c", i);
		bit_received = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 1)
		ft_printf("Don't need other arguments");
	else
		ft_printf("The pid is %i", getpid());
	(void)argv;
	while (argc == 1)
	{
		signal(SIGUSR1, manage_signal);
		signal(SIGUSR2, manage_signal);
		pause();
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:22:42 by tjehaes           #+#    #+#             */
/*   Updated: 2024/05/06 09:25:36 by tjehaes          ###   ########.fr       */
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
		ft_printf("Incorrect number of arguments");
	(void)argv;
	ft_printf("The pid is %i", getpid());
	while (argc == 1)
	{
		signal(SIGUSR1, manage_signal);
		signal(SIGUSR2, manage_signal);
		pause();
	}
	return (0);
}
/*
char	*dest = NULL;

int	find_power(int nb, int power)
{
	int	result;

	result = 0;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	else
	{
		result = nb * (find_power(nb, power - 1));
		return (result);
	}
}

char	*add_letter(char *s1, char letter)
{
	int	i;

	i = ft_strlen(s1);
	s1[i++] = letter;
	s1[i++] = '\0';
	return (s1);
}

void	manage_signal(int signal)
{
	static int	count = 0;
	static int	result = 0;
	static int	len = 0;
	char	*dest;

	dest = malloc(1);
	if (signal == SIGUSR1)
		result = result + 0;
	else if (signal == SIGUSR2)
		result = result + (1 * find_power(2, 8 - count));
	count++;
	if (count == 8)
	{
		dest = add_letter(dest, result);
		if (result == '\0')
		{
			ft_printf("%s\n", dest);
			free(dest);
		}
		count = 0;
		result = 0;
		len++;
	}
}

int	main(void)
{
	struct sigaction	signal_received;

	ft_printf("Hello, the pid is %d\n", getpid());
	signal_received.sa_handler = manage_signal;
	signal_received.sa_flags = 0;
	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);
	while (1)
		usleep(42);
}*/

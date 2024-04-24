/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:22:42 by tjehaes           #+#    #+#             */
/*   Updated: 2024/04/24 16:33:15 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

char	*letter_to_str(char *s1, char letter)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (s1[i++] != '\0')
		str[i] = s1[i];
	str[i++] = letter;
	free(s1);
	return (str);
}

void	manage_signal(int signal)
{
	static int	count = 0;
	static int	result = 0;
	static int	len = 0;
	static char	*dest;

	if (!dest)
		dest = ft_strdup("");
	if (signal == SIGUSR1)
		result = result + 0;
	else if (signal == SIGUSR2)
		result = result + (1 * find_power(2, 7 - count));
	count++;
	if (count == 8)
	{
		dest = letter_to_str(dest, result);
		if (result == '\0')
		{
			ft_printf("%s\n", dest);
			dest = NULL;
		}
		count = 0;
		result = 0;
		len++;
	}
}

int	main(void)
{
	struct sigaction	signal_received;

	ft_printf("Hello, pid is %d\n", getpid());
	signal_received.sa_handler = manage_signal;
	signal_received.sa_flags = 0;
	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);
	while (1)
		usleep(42);
}

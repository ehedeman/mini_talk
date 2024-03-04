/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:41:31 by ehedeman          #+#    #+#             */
/*   Updated: 2024/01/25 12:27:23 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	fail_to_send(void)
{
	write(1, "SIGNAL ERROR.", 14);
	exit(1);
}

void	sending(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

	i = 8;
	temp_char = character;
	while (i-- > 0)
	{
		temp_char = character >> i;
		if (temp_char % 2 == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				fail_to_send();
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				fail_to_send();
		}
		usleep(35);
	}
}

int	main(int argc, char **argv)
{
	char	*to_send;
	int		pid;
	int		i;

	i = 0;
	if (argc != 3)
	{
		write(1, "Error: Number of Arguments!", 28);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(1, "PID ERROR.", 28);
		return (0);
	}
	to_send = argv[2];
	while (*to_send)
	{
		sending(pid, (unsigned)*to_send);
		to_send++;
		i++;
	}
	ft_printf("Successfully sent %i characters!", i);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:38:55 by ehedeman          #+#    #+#             */
/*   Updated: 2024/01/25 12:06:13 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	static unsigned char	to_print;
	static int				bit_index;

	to_print |= (sig == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		ft_printf("%c", to_print);
		bit_index = 0;
		to_print = 0;
	}
	else
		to_print <<= 1;
}

int	main(void)
{
	int	i;

	i = (int)getpid();
	ft_printf("%i\nWaiting for signal..\n", i);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
		pause();
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 12:56:09 by eamielin          #+#    #+#             */
/*   Updated: 2019/03/17 18:35:04 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		sender(unsigned char ch, int server_pid)
{
	unsigned char	mask;

	mask = 128;
	while (mask)
	{
		if (mask & ch)
		{
			if (kill(server_pid, SIGUSR2) == -1)
			{
				ft_putendl(UNABLE);
				exit(-1);
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR1) == -1)
			{
				ft_putendl(UNABLE);
				exit(-1);
			}
		}
		usleep(TIME_BETWEEN_SEND);
		mask = mask >> 1;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		server_pid;
	int		i;

	if (argc != 3)
	{
		ft_putendl(USAGE);
		return (-1);
	}
	i = 0;
	while (argv[1][i])
	{
		if (!(ft_isdigit(argv[1][i])))
		{
			ft_putendl(WRONG);
			return (-1);
		}
		i++;
	}
	server_pid = ft_atoi(argv[1]);
	i = -1;
	while (argv[2][++i])
		sender(argv[2][i], server_pid);
	return (0);
}

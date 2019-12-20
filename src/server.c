/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 12:56:09 by eamielin          #+#    #+#             */
/*   Updated: 2019/03/17 18:40:58 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_receive	g_receive;

void	handler_one(int a)
{
	if (g_receive.mask > 1)
		g_receive.mask = g_receive.mask >> 1;
	else
	{
		ft_lstaddend(&g_receive.end, ft_lstnew("\0", 1));
		g_receive.end = g_receive.end->next;
		g_receive.mask = 128;
	}
	(void)a;
}

void	handler_two(int a)
{
	((unsigned char *)(g_receive.end->content))[0] =
		((unsigned char *)(g_receive.end->content))[0]
		| g_receive.mask;
	if (g_receive.mask > 1)
		g_receive.mask = g_receive.mask >> 1;
	else
	{
		ft_lstaddend(&g_receive.end, ft_lstnew("\0", 1));
		g_receive.end = g_receive.end->next;
		g_receive.mask = 128;
	}
	(void)a;
}

int		main(void)
{
	ft_putstr("Server_PID: ");
	ft_putnbr(getpid());
	write(1, "\n", 1);
	ft_bzero(&g_receive, sizeof(t_receive));
	g_receive.mask = 128;
	ft_lstaddend(&g_receive.start, ft_lstnew("\0", 1));
	g_receive.end = g_receive.start;
	signal(SIGUSR1, &handler_one);
	signal(SIGUSR2, &handler_two);
	while (pause())
	{
		while (usleep(WAIT_TO_PRINT))
		{
		}
		ft_lstcat(&g_receive.start, 0, 1, 1);
		write(1, g_receive.start->content, g_receive.start->content_size);
		write(1, "\n", 1);
		ft_lstdel(&g_receive.start, &ft_contdel);
		ft_bzero(&g_receive, sizeof(t_receive));
		g_receive.mask = 128;
		ft_lstaddend(&g_receive.start, ft_lstnew("\0", 1));
		g_receive.end = g_receive.start;
	}
	return (0);
}

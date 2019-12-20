/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:59:08 by eamielin          #+#    #+#             */
/*   Updated: 2019/03/16 15:59:08 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <sys/types.h>
# include <signal.h>

# include "libft.h"
# include <stdlib.h>

# define TIME_BETWEEN_SEND 30
# define WAIT_TO_PRINT 300
# define USAGE "Usage: ./client Server_PID \"string to send\""
# define WRONG "Wrong PID!\nUsage: ./client Server_PID \"string to send\""
# define UNABLE "Unable to deliver to this PID. Use valid Server_PID!"

typedef struct				s_receive
{
	volatile unsigned char	mask;
	t_list					*start;
	t_list					*end;
}							t_receive;

#endif

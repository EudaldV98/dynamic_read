/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:25:04 by jvaquer           #+#    #+#             */
/*   Updated: 2020/10/09 13:13:29 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <termios.h>
/*
** #include <termcap.h>
** #include <term.h>
*/


typedef	struct s_term
{
	struct	termios	set;
	struct	termios	backup;
}				t_term;

typedef	struct	s_keys
{
	char		k_left[4];
	char		k_right[4];
	char		k_up[4];
	char		k_down[4];
}				t_keys;

typedef	struct	s_reader
{
	char		c;
	char		*s;
}				t_reader;


void	set_keys(t_keys	*keys)
{
	keys->k_left[0] = 27;
	keys->k_left[1] = '[';
	keys->k_left[2] = 'D';
	keys->k_left[3] = 0;
	keys->k_right[0] = 27;
	keys->k_right[1] = '[';
	keys->k_right[2] = 'C';
	keys->k_right[3] = 0;
	keys->k_up[0] = 27;
	keys->k_up[1] = '[';
	keys->k_up[2] = 'A';
	keys->k_up[3] = 0;
	keys->k_down[0] = 27;
	keys->k_down[1] = '[';
	keys->k_down[2] = 'B';
	keys->k_down[3] = 0;
}

int		main(int ac, char **av)
{
	t_term		term;
	t_keys		keys;
	t_reader	reader;
	int			enter;

	enter = 0;
	tcgetattr(0, &term.backup);
	tcgetattr(0, &term.set);
	term.set.c_cflag &= ~(ICANON | ECHO | ISIG);
	set_keys(&keys);

	while (!enter)
	{
		reader.c = 0;
		read(0, &reader.c, 1);
		if (reader.c >= ' ' && reader.c <= '~')
		{
			
		}
		if (reader.c == '\n')
			enter = 1;
	}
	
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:25:04 by jvaquer           #+#    #+#             */
/*   Updated: 2020/10/11 20:23:56 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			set_keys(t_keys	*keys)
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

void			fill_str(char *str, int	len,const char c)
{
	write(1, &c, 1);
	ft_strncat(str, c, 1);
}

int				ft_switch_keys(t_reader *reader, t_keys keys)
{
	if (reader->c == 4 && ft_strlen(reader->s) == 0)
	{
		write(1, "exit", 4);
		return (1);
	}
	else if (reader->c == 3)
	{
		printf("Ctrl c\n");
		return (1);
	}
	else if (ft_strncmp(reader->k, keys.k_left, 4) == 0)
	{
		write(1, "K_left\n", 7);
		return (0);
/*
** 		code
*/
	}
	else if (ft_strncmp(reader->k, keys.k_right, 4) == 0)
	{
		write(1, "K_right\n", 8);
		return (0);
/*
** 		code
*/
	}
	else if (ft_strncmp(reader->k, keys.k_right, 4) == 0)
	{
		write(1, "K_left\n", 7);
		return (0);
/*
** 		code
*/
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_term		term;
	t_keys		keys;
	t_reader	reader;
	int			enter;
	char		k[4];

/*
** 	set read
*/
	if (tcgetattr(0, &term.backup) == -1)
		return (0);
	if (tcgetattr(0, &term.set) == -1)
		return (0);
	term.set.c_lflag &= ~(ICANON | ECHO | ISIG);
/*
** 	set vars
*/
	enter = 0;
	reader.k = k;
	ft_memset(reader.k, 0, 4);
	set_keys(&keys);
	reader.s = ft_calloc(2, sizeof(char));
/*
** 	loop
*/
	while (!enter)
	{
		tcsetattr(0, 0, &term.set);
		reader.c = 0;
		read(0, &reader.c, 1);
		if ((reader.c >= ' ' && reader.c <= '~') && ft_strlen(reader.k) == 0)
			fill_str(reader.s, ft_strlen(reader.s), reader.c);
		if (reader.c == 27 || ft_strlen(reader.k) > 0)
		{
			//write(1, "sp_k\n", 5);
			reader.k[ft_strlen(reader.k)] = reader.c;
		}
		if (reader.c == '\n')
			enter = 1;
		else if (ft_switch_keys(&reader, keys))
			enter = 1;
		if (ft_strlen(k) >=3)
			ft_memset(k, 0, 4);
		tcsetattr(0, 0, &term.backup);
	}
	if (reader.c == '\n')
	{
		ft_strncat(reader.s, reader.c, 1);
		printf("STR: %s", reader.s);
	}
	return (0);
}

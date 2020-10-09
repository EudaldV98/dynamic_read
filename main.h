/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:03:12 by jvaquer           #+#    #+#             */
/*   Updated: 2020/10/09 16:06:57 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <stdio.h>
#include <stdlib.h>
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
	char		*tmp;
	char		*k;
	char		*hold;
}				t_reader;

void    *ft_memset(void *b, int c, size_t len);
void    *ft_calloc(size_t count, size_t size);
char    *ft_strdup(const char *s1);
size_t  ft_strlen(const char *s);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strncat(char *dest, const char c, int nb);

#endif

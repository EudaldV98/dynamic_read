/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:03:12 by jvaquer           #+#    #+#             */
/*   Updated: 2020/10/12 18:53:33 by jvaquer          ###   ########.fr       */
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
	char		k_del[5];
}				t_keys;

typedef	struct	s_reader
{
	char		c;
	char		*s;
	char		*tmp;
	char		*k;
	char		*hold;
	int			i;
	int			len;
}				t_reader;

void    *ft_memset(void *b, int c, size_t len);
void    *ft_calloc(size_t count, size_t size);
char    *ft_strdup(const char *s1);
size_t  ft_strlen(const char *s);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strncat(char *dest, const char c, int nb);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_Kleft(t_keys keys, t_reader *reader);
int		ft_Kright(t_keys keys, t_reader *reader);
void    *ft_memmove(void *dst, const void *src, size_t len);
int		ft_Kdel(t_keys keys, t_reader *reader);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:03:12 by jvaquer           #+#    #+#             */
/*   Updated: 2020/10/13 18:24:48 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define S_MAX 20
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <termios.h>
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
	char		*k;
	int			i;
	int			len;
	int			close;
}				t_reader;

typedef	struct	s_historique
{
	int			i;
	char		*tab[S_MAX];
}				t_historique;


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
void	ft_Kup(t_reader *r);
void	ft_Kdown(t_reader *r);
int		ft_Kenter(t_reader *r, t_historique *h);


#endif

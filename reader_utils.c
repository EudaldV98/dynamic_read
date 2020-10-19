/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:55:31 by jvaquer           #+#    #+#             */
/*   Updated: 2020/10/19 13:00:42 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			set_read(t_reader *r)
{
	ft_memset(r->k, 0, 4);
	r->s = ft_calloc(2, sizeof(char));
	r->i = 0;
	r->len = 0;
	r->exit = 0;
	r->ent = 0;
}
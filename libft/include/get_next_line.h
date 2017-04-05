/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:44:11 by mmatamou          #+#    #+#             */
/*   Updated: 2017/02/08 14:54:10 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 350

typedef	struct		s_fds
{
	char			*str;
	int				cfd;
	struct s_fds	*next;
	struct s_fds	*prev;
}					t_fds;

int					get_next_line(const int fd, char **line);

#endif

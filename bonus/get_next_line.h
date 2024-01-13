/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 09:51:04 by goat              #+#    #+#             */
/*   Updated: 2023/11/22 16:07:13 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 50
# endif

# include "fcntl.h"
# include "unistd.h"
# include "stdlib.h"

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
size_t	ft_strlen_to_char(char *str, char c);
int		search_char(char *str, char c);

#endif

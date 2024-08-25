/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:25:43 by afavier           #+#    #+#             */
/*   Updated: 2024/02/13 21:58:20 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "../inc/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

char	*ft_strjoin_get(char *s1, char const *s2);
char	*get_next_line(int fd);
size_t	ft_strlen_get(const char *str, int c);
char	*ft_strdup_gnl(const char *s);

#endif

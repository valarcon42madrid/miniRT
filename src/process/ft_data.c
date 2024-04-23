/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:55:03 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/04 13:45:44 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

char	*ft_data(char *argv[])
{
	int		fd;
	char	*s;
	char	*s2;
	char	*tmp;
	char	*tmp2;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	s = get_next_line(fd, 1);
	s2 = ft_sec_malloc(1);
	if (!s)
		return (0);
	while (s)
	{
		tmp = s;
		tmp2 = s2;
		s2 = ft_strjoin(s2, s);
		free(tmp2);
		free(tmp);
		s = get_next_line(fd, 1);
	}
	close(fd);
	return (s2);
}

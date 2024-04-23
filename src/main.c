/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:45:31 by sasalama          #+#    #+#             */
/*   Updated: 2023/04/04 12:53:33 by valarcon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/geometry.h"

int	ft_errors(int argc, char **argv)
{
	if (argc != 2)
	{
		perror("Error in number of arguments");
		return (1);
	}
	else if (ft_strncmp_rev(argv[1], ".rt", 3))
	{
		perror("Error: Argument must be a '.rt' file");
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int		x;
	t_conf	conf;

	x = ft_errors(argc, argv);
	if (x == 1)
		return (1);
	x = ft_parser(argv, &conf);
	if (x == 1)
		exit (1);
	else if (x == 2)
	{
		ft_all_black(&conf);
		return (0);
	}
	ft_mlx_init(&conf);
	return (0);
}

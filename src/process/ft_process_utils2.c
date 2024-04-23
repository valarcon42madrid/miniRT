/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:31:40 by sasalama          #+#    #+#             */
/*   Updated: 2023/03/29 20:59:06 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/geometry.h"

int	nbrlen(long nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					a;
	unsigned long long	num;

	i = 0;
	num = 0;
	a = 1;
	while (str[i] != '\0' && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			a = a * -1;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		if (num > __LONG_LONG_MAX__ || i >= 19)
		{
			if (a == -1)
				return (0);
			return (-1);
		}
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * a);
}

long double	ft_atod(const char *str)
{
	int			i;
	long double	intg;
	long double	dec;
	int			sign;
	int			z_len;

	i = -1;
	dec = 0;
	sign = 1;
	z_len = 0;
	while (!(ft_isdigit(str[++i])))
	{
		if (str[i] == '-')
			sign *= -1;
	}
	intg = ft_atoi(str + i);
	i += nbrlen(intg);
	if (str[i] == '.')
	{
		i++;
		dec = ft_atoi(str + i);
		while (str[i++] == '0')
			z_len++;
	}
	return (intg * sign + (dec / pow(10, nbrlen(dec) + z_len)) * sign);
}

double	*not_param(double *param)
{
	free(param);
	return (NULL);
}

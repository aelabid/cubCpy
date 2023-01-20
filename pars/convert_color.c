/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:48:01 by mabdelba          #+#    #+#             */
/*   Updated: 2023/01/20 21:30:17 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ret_function(char hexa[], int i)
{
	char	*ret;

	ret = NULL;
	if (i == 2)
	{
		ret = ft_strdup("");
		ret = ft_strjoin(ret, c_tos(hexa[1]));
		ret = ft_strjoin(ret, c_tos(hexa[0]));
	}
	else if (i == 1)
	{
		ret = ft_strdup("0");
		ret = ft_strjoin(ret, c_tos(hexa[0]));
	}
	else if (i == 0)
		ret = ft_strdup("00");
	return (ret);
}

char	*dec_to_hex(int n)
{
	char	str[2];
	int		drp;
	char	*ret;
	int		i;

	i = 0;
	while (n != 0)
	{
		drp = 0;
		drp = n % 16;
		if (drp < 10)
		{
			str[i] = drp + 48;
			i++;
		}
		else
		{
			str[i] = drp + 55;
			i++;
		}
		n = n / 16;
	}
	ret = ret_function(str, i);
	return (ret);
}

char	*convert_rgb(int r, int g, int b)
{
	char	*str;

	str = ft_strdup("");
	str = ft_strjoin(str, dec_to_hex(r));
	str = ft_strjoin(str, dec_to_hex(g));
	str = ft_strjoin(str, dec_to_hex(b));
	return (str);
}

int	hex_to_dec(char *str)
{
	int	len;
	int	var;
	int	ret;
	int	i;

	len = ft_strlen(str);
	var = 1;
	ret = 0;
	i = len - 1;
	while (i >= 0)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			ret += (str[i] - 48) * var;
			var = var * 16;
		}
		else if (str[i] >= 'A' && str[i] <= 'F')
		{
			ret += (str[i] - 55) * var;
			var = var * 16;
		}
		i--;
	}
	return (ret);
}

int	convert_color(char *str)
{
	char	**spl;
	char	*col;
	int		r;
	int		g;
	int		b;

	spl = ft_split(str, ',');
	r = ft_atoi(spl[0]);
	g = ft_atoi(spl[1]);
	b = ft_atoi(spl[2]);
	col = convert_rgb(r, g, b);
	r = hex_to_dec(col);
	ft_free(spl);
	free(col);
	return (r);
}

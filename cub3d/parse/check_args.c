/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:55:30 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/12 18:50:41 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_args_error(char **argv, int i)
{
	if (i <= 0)
	{
		ft_putstr("Error\n:Wrong File Name\n", 2);
		return (0);
	}
	if (ft_isalpha_isdigit(argv[1][i - 1]) == 0)
	{
		ft_putstr("Error\n:Wrong File Name\n", 2);
		return (0);
	}
	if (ft_strcmp(&argv[1][i], ".cub") != 0)
	{
		ft_putstr("Error\n:Wrong File Extension\n", 2);
		return (0);
	}
	else
		return (1);
}

int	check_args(int args, char **argv)
{
	int	i;
	int	len;

	if (args != 2)
	{
		ft_putstr("Error\n:Input Only One File\n", 2);
		return (0);
	}
	len = ft_strlen(argv[1]);
	if (len < 5)
	{
		ft_putstr("Error\n:Wrong File Name\n", 2);
		return (0);
	}
	i = 0;
	while (argv[1][i])
		i++;
	i -= 4;
	return (check_args_error(argv, i));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_code_int_tabs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:33:57 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/30 17:35:58 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The get_rgb_code_int_tabs.c file is where we :
	- check that the floor_rgb_str and ceiling_rgb_str
	are made of 3 components (R,G and B) separated by one comma ','.
	- split the rgb_str components at the ',' and put the result in rgb_str_tab.
	- clean each rgb_tab component, removing spaces.
	- convert rgb_str components into int, checking that
	each component is between 0 and 255.
*/

#include "main.h"

static void	check_n_comma_in_str(char *str);
static void	check_rgb_str_len(char **color_code_tab);
static char	**clean_rgb_str(char **color_code_tab);
static int	*convert_str_tab_to_int_tab(char **src);

void	get_rgb_code_int_tabs(t_config *config)
{
	char	**floor_rgb_str_tab;
	char	**ceiling_rgb_str_tab;

	check_n_comma_in_str(config->floor_rgb_str);
	check_n_comma_in_str(config->ceiling_rgb_str);
	floor_rgb_str_tab = ft_split(config->floor_rgb_str, ',');
	ceiling_rgb_str_tab = ft_split(config->ceiling_rgb_str, ',');
	check_rgb_str_len(floor_rgb_str_tab);
	check_rgb_str_len(ceiling_rgb_str_tab);
	floor_rgb_str_tab = clean_rgb_str(floor_rgb_str_tab);
	ceiling_rgb_str_tab = clean_rgb_str(ceiling_rgb_str_tab);
	config->floor_rgb_int_tab = convert_str_tab_to_int_tab(floor_rgb_str_tab);
	config->ceiling_rgb_int_tab = convert_str_tab_to_int_tab(ceiling_rgb_str_tab);
	ft_free_char_tab(floor_rgb_str_tab);
	ft_free_char_tab(ceiling_rgb_str_tab);
}

static void	check_n_comma_in_str(char *str)
{
	int n_comma;
	int i;

	n_comma = 0;
	i = -1;
	while(str[++i])
	{
		if(str[i] == ',')
			n_comma ++;
	}
	if (n_comma > 2)
		exit_with_error_message(config_err, invalid);
}

static void	check_rgb_str_len(char **color_code_tab)
{
	int i;

	i = 0;
	while (color_code_tab[i])
		i ++;
	if (i != 3)
		exit_with_error_message(config_err, invalid);
}

static char	**clean_rgb_str(char **color_code_tab)
{
	int	 i;
	char	*buffer;

	i = -1;
	while (++i < 3)
	{
		replace_spaces_in_str(color_code_tab[i], ' ');
		buffer = ft_strtrim(color_code_tab[i], " ");
		free(color_code_tab[i]);
		color_code_tab[i] = buffer;
		if (i == 3)
			color_code_tab[ft_strlen(color_code_tab[i]) - 1] = "\0";
	}
	return (color_code_tab);
}

static int	*convert_str_tab_to_int_tab(char **src)
{
	int *dest;
	int i = -1;

	dest = malloc(sizeof(int) * 3);
	if (!dest)
		exit (0);
	while (++i < 3)
	{
		dest[i] = ft_atoi(src[i]);
		if (dest[i] < 0 || dest[i] > 255 )
			exit_with_error_message(config_err, invalid);
	}
	return (dest);
}

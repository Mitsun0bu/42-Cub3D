/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:33:45 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/30 17:33:47 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The open_file.c file is where we open the '.cub' file selected by the user
	after checking if :
	- only 2 arguments have been passed to the program
	- the file has been passed as the 2nd argument to the program,
	- the file has the correct '.cub' extension,
	- the argument with a '.cub' extension is not a directory.
*/

#include "main.h"

int	open_file(int ac, char **av)
{
	int	fd;
	int	i_extension;

	i_extension = ft_strlen(av[1]) - 4;
	if (ac != 2)
		exit_with_error_message(open_err, n_arg);
	if (ft_strnstr(av[1] + i_extension, ".cub", 4) == NULL)
		exit_with_error_message(open_err, extension);
	fd = open(av[1], O_DIRECTORY);
	if (fd != -1)
		exit_with_error_message(open_err, dir);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_with_error_message(open_err, fail);
	return (fd);
}
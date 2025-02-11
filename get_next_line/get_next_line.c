/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:53:17 by mcauchy           #+#    #+#             */
/*   Updated: 2025/02/10 19:07:17 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *str, int start, int len)
{
	char	*substr;
	int		i;

	substr = malloc(len + 1);
	if (!substr || !str)
		return (NULL);
	i = 0;
	while (i < len && str[start + i])
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	int			ret;
	char		buffer[BUFFER_SIZE];
	char		*temp;

	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret == -1)
		return (NULL);
	line = ft_strdup(buffer);
	while (!ft_strchr(line, '\n') && ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
		{
			free(line);
			return (NULL);
		}
		temp = ft_strdup(line);
		if (!temp)
		{
			free(line);
			return (NULL);
		}
		free(line);
		line = ft_strjoin(temp, buffer);
		free(temp);
	}
	if (ret == 0)
	{
		temp = ft_strdup(line);
		free(line);
		line = ft_strdup(temp);
		free(temp);
	}
	
}

// int	main(int ac, char **av)
// {
// 	int		fd;
// 	char	*line;

// 	if (ac != 2)
// 		return (1);
// 	fd = open(av[1], O_RDONLY);
// 	if (fd < 0)
// 		return (1);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }

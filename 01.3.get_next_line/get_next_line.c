/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:04:48 by mbellard          #+#    #+#             */
/*   Updated: 2024/02/29 12:04:51 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_new_line(char *tank)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (tank[i] && tank[i] != '\n')
		i++;
	if (!tank[i])
	{
		free(tank);
		tank = NULL;
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(tank) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	j = 0;
	while (tank[i])
		temp[j++] = tank[i++];
	temp[j] = '\0';
	free(tank);
	return (temp);
}

char	*ft_get_line(char *tank)
{
	int		i;
	char	*temp;

	i = 0;
	if (!tank[i])
		return (NULL);
	while (tank[i] && tank[i] != '\n')
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (NULL);
	i = 0;
	while (tank[i] && tank[i] != '\n')
	{
		temp[i] = tank[i];
		i++;
	}
	if (tank[i] == '\n')
	{
		temp[i] = tank[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_read_line(int fd, char *tank)
{
	ssize_t	bytes;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(tank, '\n') && bytes != 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[bytes] = '\0';
		tank = ft_strjoin(tank, temp);
	}
	free(temp);
	return (tank);
}

char	*get_next_line(int fd)
{
	static char	*tank;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tank = ft_read_line(fd, tank);
	if (!tank)
		return (NULL);
	line = ft_get_line(tank);
	tank = ft_new_line(tank);
	return (line);
}

int	main(void)
{
	char	*line = NULL;
	int		fd;
	int		i;

	fd = open("read_error.txt", O_RDONLY);
	//fd = -1;
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	i = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("(row: %d)\n%s\n", i, line);
		free(line);
		i++;
	}
	//get_next_line(fd);
	//printf("%s\n", get_next_line(fd));
	//printf("%s\n", line);
	close(fd);
	return (0);
}

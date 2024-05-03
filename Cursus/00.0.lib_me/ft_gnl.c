/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:00:21 by mbellard          #+#    #+#             */
/*   Updated: 2024/03/06 15:00:24 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_new_line(char *tank)
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
	static char	*tank[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	tank[fd] = ft_read_line(fd, tank[fd]);
	if (!tank[fd])
		return (NULL);
	line = ft_get_line(tank[fd]);
	tank[fd] = ft_new_line(tank[fd]);
	return (line);
}

/*int	main(void)
{
	int		fd;
	int		fd_2;
	int		fd_3;
	char	*line;
	int		i;

	i = 0;
	fd = open("introLOTR_1.txt", O_RDONLY);
	fd_2 = open("introLOTR_2.txt", O_RDONLY);
	fd_3 = open("introLOTR_3.txt", O_RDONLY);
	
	if (fd == -1 || fd_2 == -1|| fd_3 == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("(file_1)(riga: %d)%s\n", i, line);
		free(line);
		i++;
	}
	i = 0;
	while ((line = get_next_line(fd_2)) != NULL)
	{
		printf("(file_2)(riga: %d)%s\n", i, line);
		free(line);
		i++;
	}
	i = 0;
	while ((line = get_next_line(fd_3)) != NULL)
	{
		printf("(file_3)(riga: %d)%s\n", i, line);
		free(line);
		i++;
	}
	close(fd);
	close(fd_2);
	close(fd_3);
	return (0);
}*/

/*int	main(void)
{
	int		fd;
	int		fd_2;
	int		fd_3;
	char	*line;
	char	*line_2;
	char	*line_3;
	int		i;

	fd = open("introLOTR_1.txt", O_RDONLY);
	fd_2 = open("introLOTR_2.txt", O_RDONLY);
	fd_3 = open("introLOTR_3.txt", O_RDONLY);
	
	if (fd == -1 || fd_2 == -1|| fd_3 == -1)
	{
		perror("Error opening file");
		return (1);
	}
	i = 0;
	line = get_next_line(fd);
	line_2 = get_next_line(fd_2);
	line_3 = get_next_line(fd_3);
	while ((line != NULL) || (line_2  != NULL) || (line_3 != NULL))
	{
		printf("(file_1)(riga: %d)%s\n", i, line);
		printf("(file_2)(riga: %d)%s\n", i, line_2);
		printf("(file_3)(riga: %d)%s\n", i, line_3);
		free(line);
		free(line_2);
		free(line_3);
		i++;
	}
	close(fd);
	close(fd_2);
	close(fd_3);
	return (0);
}*/

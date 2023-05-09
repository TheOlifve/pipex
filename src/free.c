/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:04:20 by hrahovha          #+#    #+#             */
/*   Updated: 2023/04/16 16:04:24 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	pipe_close(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (++i < pipex->pipes_cnt)
	{
		close(pipex->fd[i][0]);
		close(pipex->fd[i][1]);
		free(pipex->fd[i]);
	}
	free(pipex->fd);
	close(pipex->file1);
	close(pipex->file2);
}

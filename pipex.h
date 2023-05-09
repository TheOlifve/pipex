/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:34:27 by hrahovha          #+#    #+#             */
/*   Updated: 2023/05/09 14:34:33 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./utils/utils.h"
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_pipex
{
	pid_t	pid;
	int		**fd;
	int		file1;
	int		file2;
	int		cmd_crnt;
	int		cmd_cnt;
	int		pipes_cnt;
	int		here_doc;
	int		index;
	int		p_argc;
	char	**path;
	char	*cmd;
}t_pipex;

int		open_file2(t_pipex *pipex, char **argv, int argc);
int		open_file1(t_pipex *pipex, char **argv, int argc);
char	**path(char **envp);
int		error(char *str);
void	pipe_close(t_pipex *pipex);

#endif

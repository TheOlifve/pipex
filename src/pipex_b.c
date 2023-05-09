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

void	ft_dup2(int read, int write)
{
	if (dup2(read, 0) < 0)
		error("Error");
	if (dup2(write, 1) < 0)
		error("Error");
}

char	*get_cmd(char **str, char *cmd)
{
	char	*tmp;
	char	*str2;
	int		i;

	if (!str)
		error("Error");
	i = -1;
	while (str[++i])
	{
		tmp = ft_strjoin(str[i], "/");
		if (!tmp)
			error("Error");
		str2 = ft_strjoin(tmp, cmd);
		if (!str2)
			error("Error");
		free(tmp);
		if (access(str2, X_OK) == 0)
		{
			free(str);
			return (str2);
		}
		free(str2);
	}
	free(str);
	return (NULL);
}

void	pipe_open(t_pipex *pipex)
{
	int	i;

	i = -1;
	pipex->fd = malloc(pipex->pipes_cnt * sizeof(int *));
	if (!pipex->fd)
		error("Error");
	while (++i < pipex->pipes_cnt)
	{
		pipex->fd[i] = malloc(sizeof(int) * 2);
		if (!pipex->fd[i])
			error("Error");
	}
	i = -1;
	while (++i < pipex->pipes_cnt)
		pipe(pipex->fd[i]);
}

void	child(t_pipex *pipex, char **argv, char **envp)
{
	char	**cmd_args;

	pipex->pid = fork();
	if (pipex->pid == 0)
	{
		if (pipex->index == 0)
			ft_dup2(pipex->file1, pipex->fd[0][1]);
		else if (pipex->index == pipex->cmd_cnt - 1)
			ft_dup2(pipex->fd[pipex->index - 1][0], pipex->file2);
		else
			ft_dup2(pipex->fd[pipex->index - 1][0], pipex->fd[pipex->index][1]);
		pipe_close(pipex);
		cmd_args = ft_split(argv[pipex->cmd_crnt], ' ');
		if (!cmd_args)
			error("Error");
		if (ft_strchr(cmd_args[0], '/') == 0)
			cmd_args[0] = get_cmd(pipex->path, cmd_args[0]);
		if (!cmd_args[0])
		{
			free(cmd_args);
			error("Error");
		}
		execve(cmd_args[0], cmd_args, envp);
		error ("Error");
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		i;

	i = -1;
	if (argc < 5)
		error("Error");
	open_file1(&pipex, argv, argc);
	if (pipex.file1 < 0)
		perror("Error");
	open_file2(&pipex, argv, argc);
	if (pipex.file2 < 0)
		error("Error");
	pipex.pipes_cnt = pipex.cmd_cnt - 1;
	pipe_open(&pipex);
	pipex.path = path(envp);
	while (++i <= pipex.pipes_cnt)
	{	
		child(&pipex, argv, envp);
		pipex.cmd_crnt++;
		pipex.index += 1;
	}
	pipe_close(&pipex);
	while (wait(NULL) != -1)
		;
	return (0);
}

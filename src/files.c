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

void	here_doc(t_pipex *pipex, char **argv)
{
	int		file;
	char	*tmp;

	file = open("tmp", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (file < 0)
		error("Error");
	while (1)
	{
		write(1, "heredoc> ", 9);
		tmp = get_next_line(0);
		if (!tmp)
			break ;
		if (ft_strcmp(argv[2], tmp) == -10)
			break ;
		write(file, tmp, ft_strlen(tmp));
		free(tmp);
	}
	close(file);
	free(tmp);
	pipex->file1 = open("tmp", O_RDONLY);
	unlink("tmp");
}

char	**path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (ft_split(*envp + 5, ':'));
}

int	open_file1(t_pipex *pipex, char **argv, int argc)
{
	if (!ft_strncmp(argv[1], "here_doc", 9))
	{
		pipex->cmd_crnt = 3;
		pipex->here_doc = 1;
		here_doc(pipex, argv);
	}
	else
	{
		pipex->cmd_crnt = 2;
		pipex->here_doc = 0;
		pipex->file1 = open(argv[1], O_RDONLY);
	}
	pipex->cmd_cnt = argc - 3 - pipex->here_doc;
	pipex->index = 0;
	return (1);
}

int	open_file2(t_pipex *pipex, char **argv, int argc)
{
	if (!ft_strncmp(argv[1], "here_doc", 9))
		pipex->file2 = open(argv[--argc], O_WRONLY | O_APPEND | O_CREAT, 0644);
	else
		pipex->file2 = open(argv[--argc], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	return (1);
}

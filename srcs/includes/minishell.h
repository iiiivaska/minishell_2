/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:18:43 by eghis             #+#    #+#             */
/*   Updated: 2021/07/17 14:15:40 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define PROMPT "minishell> "

/*
	IO
*/
# define STDIN 0
# define STDOUT 1
# define STDERR 2

/*
	Global Errors
*/
# define ERROR 1
# define NOERROR 0
# define MALLOCERROR "malloc error\n"

/*
	Preparser Errors
*/
# define DOUBQUOTNI 228 //Двойные кавычки не замкнуты
# define QUOTNI 229 //Одинарные кавычки не замкнуты
# define SEMICOLON 3 // ; - не в кавычках
# define SLASH 4 // \ - не в кавычках
# define DPIPE 5 // || - ошибка
# define EPIPE 6 // Пустота после/до пайпа
# define DREDIR 7 // <</>>

/*
	Spec Symbols
*/

# define PIPE 1 // |
# define AN_BR_L 2 // <
# define AN_BR_R 3 // >
# define AN_BR_L_D 4 // <<
# define AN_BR_R_D 5 // >>

# include "readline/readline.h"
# include "readline/history.h"
# include "unistd.h"
# include "signal.h"
# include "stdlib.h"
# include "stdio.h"
# include "term.h"
# include "termcap.h"
# include "errno.h"
# include "string.h"
# include <sys/types.h>
# include <dirent.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*command;
	char			*command_2;
	int	 			sym;
	int	 			pipe;
	char			**args;
	char			*com;
	int				quot_com;
	struct s_list	*next;
}					t_list;

typedef struct s_pipe
{
	int				fdin;
	int				fdout;
	char			*heredoc;
	int				redir_error;
	t_list			**list;
	struct s_pipe	*next;
}					t_pipe;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_all
{
	int		wait;
	int		redir_error;
	char	*her_str;
	int		fd_heredoc;
	char	*heredoc;
	int		in;
	int		out;
	char	*command;
	int		error;
	char	**path;
	char	**env;
	int		pid;
	t_list	*commands;
	t_pipe	*pipe;
	t_env	*env_l;
	t_env	*hidden_env;
}				t_all;

typedef struct s_sig
{
	pid_t		pid;
	int			s_int;
	int			s_quit;
	int			exit_stat;
	int	 		dyn;
}				t_sig;

/*
	Utils
*/
size_t	ft_strlen(const char *string);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
t_list	*ft_lstnew(char *command, int sym, int pipe);
t_list	*ft_lstlast(t_list *lst);
t_pipe	*ft_lstnew_pipe(int size);
t_pipe	*ft_lstlast_2(t_pipe *lst);
t_env	*ft_lstnew_env(char *value, char *key);
t_env	*ft_lstlast_env(t_env *lst);
void	ft_lstadd_back_env(t_env **lst, t_env *new);
void	ft_lstclear_pipe(t_pipe **lst);
void	ft_lstadd_back_2(t_pipe **lst, t_pipe *new);
void	ft_putchar(char c);
void	*ft_calloc(size_t number, size_t size);
void	ft_bzero(void *s, size_t n);
void	skip_quotes(t_all *all, int *i); // Пропускаем болк с кавычками в строке
void	skip_quotes_lst(t_list *all, int *i);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_putint(int c);
int		is_escape(char *str, int num); //Проверяем экранирован ли символ
int		is_spec(char ch); //Проверка на спецсимвол
int		ft_isspace(char ch);
int		is_valid_env_name(char ch);
char	*ft_itoa(int n);
void	ft_free_path(t_all *all);
int		ft_isnum(char ch);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *s);
char	*ft_strchr(const char *string, int symbol);
void	ft_delay(int count);

/*
	Exit
*/
void	ft_exit(t_all *all, char *error);
void	clean(t_all *all);
void	del(void *str);

/*
	Signals
*/
void	ft_sigint(int sig);
void	ft_signothing(int sig);
void	init_signals(void);
void	ft_sigill(int s);

/*
	readline.h
*/
void	rl_replace_line(char *str, int i);

/*
	init
*/
void	init_term(t_all *all);
void	init_all(t_all *all);

/*
	Parser
*/
void	update_cmd(t_all *all);
void	check_quotes(t_all *all);
void	parser(t_all *all);
void	preparser(t_all *all);
void	replace_env(t_all *all);
void	cut_quot(t_all *all);
void	cut_commands(t_all *all);
void	cut_space(t_all *all);
void	cut_param(t_all *all);
void	cut_com(t_all *all);
void	parse_path(t_all *all);
void	cut_quot_args(t_all *all);
void	check_syntax(t_all *all);
void	add_list_std(t_all *all, char *str, int pipe);
int		check_sym(char *str);
char	*cut_redir_from_str(t_all *all, char *str, int *i);
char	*cut_command_from_str(t_all *all, char *str, int *i);
void	add_list_spec(t_all *all, char *str, int pipe);
void	add_commands_to_list(t_all *all, char **redir, int pipe);
void	free_redir(char **redir);
void	cut_commands(t_all *all);
void	free_pipes(char **pipes);
void	cut_redir(t_all *all, char *str, int pipe);
char	*cut_str_pipe(t_all *all, int i, int t);
char	**cut_pipes(t_all *all, int k, int t, char **pipes);
void	skip_quotes_str(char *str, int *i);
char	*cut_str_redir(t_all *all, char *str, int i, int t);
char	**cut_redir_2(t_all *all, int *z, char *str, char **redir);
void	replace_env(t_all *all);
void	replace_env_3(t_all *all, t_list *node);
void	insert_str(t_all *all, char *str, int *i, t_list *node);
char	*new_str_c(int str_s, int com_s, t_all *all);
void	cut_path(t_all *all, int i, t_list *node);
char	*get_env(t_all *all, int i, t_list *node);
int		get_env_name_lenght(t_all *all, int i, t_list *node);
char	*get_env_name(t_all *all, int i, t_list *node);
void	insert_str_2(t_all *all, char *str, int *i);
void	replace_env_2(t_all *all);
char	*new_str_o(t_all *all, int str_s, int com_s);
void	cut_path_2(t_all *all, int i);
char	*get_env_2(t_all *all, int i);
int		get_env_name_lenght_2(t_all *all, int i);
char	*get_env_name_2(t_all *all, int i);
void	cut_quot_2(t_all *all, t_list *node, int i);
void	cut_q(t_all *all, t_list *lst, int i);
void	free_pipes(char **pipes);

/*
	Executable
*/
void	executable(t_all *all);
char	*full_path(t_all *all, t_list *node);
int		build_in(t_all *all, t_list *node);
int		error_message(char *path);
int		ft_pipes_2(int *fd);
void	error_dup(int fd_old, t_pipe *node, int *fd);
void	redir(t_all *all);
void	close_wait(int status, int *fd);
void	unlink_close(t_all *all, t_pipe *node);

/*
	Redirect
*/
void	find_and_start_right_redir(t_all *all, t_pipe *node);
void	double_back_redirect(t_all *all, t_list *node, t_pipe *pipe);
int		find_and_start_doub_back_redir(t_all *all, t_pipe *node, int k);
void	find_and_start_sin_back_redir(t_all *all, t_pipe *node, int p_d);
void	err_red(t_all *all, t_pipe *node, int i);
void	out_doub_back_redir(t_all *all, t_pipe *pipe);
void	back_redir_2(int k, int p_d, int fd, t_pipe *node);
void	doub_back_2(t_all *all, t_list *node);
void	doub_back_3(t_all *all, int flag);

/*
	Enviroment
*/
void	copy_env(t_all *all, char **envp);
void	replace_env_2(t_all *all);
char	*ft_getenv(t_all *all, char *key);
char	**env_to_array(t_all *all, t_env *env);
void	copy_env_2(t_all *all, char **envp);

/*
	Pipe
*/
void	parse_pipe(t_all *all);

/*
	Buidins
*/
int		ft_echo(char **args);

/*
	SHLVL
*/
void	increment_shell_lvl(t_all *all);

extern t_sig	g_sig;

#endif
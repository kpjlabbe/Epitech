/*
** proto.h for 42sh in /media/data/all/projects/42sh-v1/include
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 11:57:53 2013 kevin labbe
** Last update Mon May 20 09:57:36 2013 kevin labbe
*/

#ifndef	 PROTO_H_
# define PROTO_H_

# define DELIM_PIPE			"|"
# define DELIM_OR			"||"
# define DELIM_AND			"&&"
# define DELIM_SEPA			";"
# define REDIR_LEFT			"<"
# define REDIR_DBL_LEFT			"<<"
# define REDIR_RIGHT			">"
# define REDIR_DBL_RIGHT		">>"
# define REDIR_RIGHT_OUT		"1>"
# define REDIR_RIGHT_ERR		"2>"
# define REDIR_DBL_RIGHT_OUT		"1>>"
# define REDIR_DBL_RIGHT_ERR		"2>>"
# define REDIR_ERR_TO_OUT		"2>&1"
# define BUILTIN_EXIT			"exit"
# define BUILTIN_SOURCE			"source"
# define BUILTIN_ALIAS			"alias"
# define BUILTIN_SETALIAS		"setalias"
# define BUILTIN_UNALIAS		"unalias"
# define BUILTIN_CD			"cd"
# define BUILTIN_ENV			"env"
# define BUILTIN_SETENV			"setenv"
# define BUILTIN_UNSETENV		"unsetenv"
# define BUILTIN_LOCAL			"local"
# define BUILTIN_SETLOCAL		"setlocal"
# define BUILTIN_UNSETLOCAL		"unsetlocal"
# define PIPE_ONE_AFTER			1
# define PIPE_BOTH_SIDES		2
# define PIPE_ONE_BEFORE		3
# define PIPE_NONE			0
# define NBR_BUILTINS			13
# define NBR_REDIR			10
# define NBR_SEPA			5
# define CONFIG_FILE			".42shrc"
# define MY_GLOB_FLAGS			GLOB_TILDE | GLOB_BRACE | GLOB_NOESCAPE
# define ENV_HOME			"/home"
# define ENV_USER			"user"
# define ENV_HOST			"host"
# define ENV_PROMPT			"($USER@$HOST:$PWD %c) "
# define REDIR_LEFT_PROMPT		"> "
# define PIPE_IN			0
# define PIPE_OUT			1
# define ID_FAIL_ALLOC			-1
# define ID_FAIL_SIGNAL			-2
# define ID_FAIL_FORK			-3
# define ID_FAIL_WAITPID		-4
# define ID_FAIL_EXEC_CMD		-5
# define ID_FAIL_PIPE			-6
# define ID_FAIL_DUP2			-7
# define ID_FAIL_NO_FILE		-8
# define ID_FAIL_PERMS_DENIED		-9
# define ID_FAIL_STAT			-10
# define ID_FAIL_FILE_IS_DIR		-11
# define ID_FAIL_OPEN			-12
# define ID_FAIL_MEMCPY			-13
# define ID_FAIL_REALLOC		-14
# define ID_FAIL_STRDUP			-15
# define ID_FAIL_MEMSET			-16
# define ID_FAIL_REDIR			-17
# define ID_FAIL_STRCAT			-18
# define ID_FAIL_STRNCAT		-19
# define MSG_FAIL_PIPE			"Can't create pipes anymore.\n"
# define MSG_FAIL_DUP2			"Can't duplicate a file descriptor.\n"
# define MSG_FILE_PERMS_DENIED		"%s: Permissions denied.\n"
# define MSG_FILE_NOT_EXISTS		"%s: No such file or directory.\n"
# define MSG_FAIL_STAT			"Can't get file status.\n"
# define MSG_FILE_IS_DIR		"%s: Is a directory.\n"
# define MSG_FAIL_OPEN			"%s: can't open this file.\n"
# define MSG_FAIL_MEMCPY		"Error while copying memory area.\n"
# define MSG_FAIL_STRDUP		"Can't duplicate strings anymore.\n"
# define MSG_FAIL_MEMSET		"Can't initialize memory.\n"
# define MSG_FAIL_STRCAT		"Can't concat strings anymore.\n"
# define MSG_FAIL_STRNCAT		"Can't concat strings anymore.\n"
# define MSG_FAIL_SIGNAL		"An error occured when catching " \
					"signals\n"
# define MSG_SOURCE_NO_FILE		"%s: this file doesn't exist.\n"
# define MSG_REDIR_ERROR		"Syntax error. Filename missing.\n"
# define MSG_CD_NO_DIR			"%s: No such file or directory.\n"
# define MSG_CD_NO_PERMS		"%s: Permission denied.\n"
# define MSG_CD_FILE			"%s: Not a directory.\n"
# define MSG_SIGSEGV			"Segmentation fault\n"
# define MSG_SIGFPE			"Floating exception\n"
# define MSG_SIGABRT			"Program aborted\n"
# define MSG_SIGILL			"Illegal instruction\n"
# define MSG_SIGBUS			"Bus error\n"
# define MSG_SIGSYS			"Bad system call\n"
# define MSG_ENV_NO_VAR			"%s: doesn't exist.\n"
# define MSG_ENV_HELP			"Print all variables: env|local\n" \
					"Print some variables: env|local " \
					"var1 var2 ...\n" \
					"Delete all variables: env|local -i\n"
# define MSG_UNSETENV_ALL		"The environment is now empty.\n"
# define MSG_UNSETENV_VAR_DELETED	"%s: deleted.\n"
# define MSG_UNSETENV_HELP		"Delete all variables: " \
					"unsetenv|unsetlocal --all\n" \
					"Delete some variables: " \
					"unsetenv|unsetlocal var1 var2 ...\n"
# define MSG_SETENV_VAR_EMPTY		"%s: invalid. Must be like " \
					"variable=value.\n"
# define MSG_SETENV_VAR_EXISTS		"%s: already exists.\n"
# define MSG_SETENV_VAR_ADDED		"%s: added.\n"
# define MSG_SETENV_VAR_UPDATED		"%s: updated. --safe not to override.\n"
# define MSG_SETENV_HELP		"Add new variables: setenv|setlocal " \
					"var1=val var2=val ...\n" \
					"Not to override existing variables: " \
					"setenv|setlocal --safe var1=val " \
					"var2=val ...\n"
# define MSG_SETENV_FAIL_USAGE		"Usage: setenv|setlocal name value\n"
# define MSG_SETENV_FAIL_ENCODING	"Encoding not valid.\n"
# define MSG_SETENV_OK_ADD		"A variable %s=%s has just been set.\n"
# define MSG_SETENV_FAIL_ALREADY	"%s: Already set.\n"

# define MSG_FAIL_FORK			"No child process could be created.\n"
# define MSG_FAIL_WAITPID		"Waitpid went wrong. It couldn't wait "\
					"any longer.\n"
# define MSG_FAIL_EXEC_CMD		"%s: command not found.\n"
# define MSG_WAITPID_CHILD_STOPPED	"The child has been stopped while "\
					"running.\n"
# define MSG_ALIAS_HELP			"Print all aliases: alias.\n" \
					"Print some aliases: alias name1 " \
					"name2 ...\n" \
					"Delete some aliases: alias -i\n"
# define MSG_ALIAS_NOT_EXISTS		"%s: this alias doesn't exist.\n"
# define MSG_SETALIAS_HELP		"Add new aliases: setalias name1=val " \
					"name2=val ...\n" \
					"Not to override existing aliases: " \
					"setalias --safe name1=val " \
					"name2=val ...\n"
# define MSG_UNALIAS_ALL		"All aliases have been removed.\n"
# define MSG_UNALIAS_NAME_DELETED	"%s: deleted.\n"
# define MSG_UNALIAS_HELP		"Delete all aliases: unalias --all\n" \
					"Delete some aliases: unalias name1 " \
					"name2 ...\n"
# define MSG_SOURCE_HELP		"Loading and parsing a config file: " \
					"source file1 file2...\n"

# include				<sys/types.h>
# include				<sys/stat.h>
# include				<fcntl.h>
# include				<sys/wait.h>
# include				<signal.h>
# include				<glob.h>
# include				<errno.h>
# include				"my.h"
# include				"t_list.h"
# include				"struct.h"

void					init_vars(t_data *, char **);
char					*get_next_delim(t_delim *, char *);
int					get_next_delim_as(char **, char *);
t_delim					*get_delimiters(void);
void					set_separators(t_delim *);
void					set_redirections(t_delim *);
char					*skip_quotes(t_delim *, char *,
						     int *, char *);
char					*cmd_lookfor_delim(t_delim *, char *,
							   int *);
t_list					*parsing_line(char *, t_delim *);
char					**cmd_get_args(char *);
void					trim_arg(char *, int *, int *, char *);
int					trim_characters(char *, int *, int *,
							char *);
int					trim_slashes(char *, int *, int *);
int					trim_quotes(char *, int *, int *,
						    char *);
void					cmd_show(t_list *);
void					cmd_del_elt(t_list *);
void					cmd_free(t_list *, char *);
void					cmd_add(t_list *, char *, char *);
void					cmd_add_after(t_list *, char *, char *);
t_list					*env_fill(char **);
int					env_load_protected_vars(t_list *);
t_vars					*vars_split_var(char *);
int					vars_add_var(t_list *, char *,
						     char *, char);
int					vars_del_var(t_list *, char *);
void					vars_del_elt(t_list *);
void					vars_free(t_list *);
t_vars					*vars_get_var(t_list *, char *);
char					*vars_get_val(t_list *, char *);
int					vars_set_val(t_list *, char *, char *,
						     char);
int					vars_rename(t_list *, char *, char *);
void					vars_show_var(t_list *);
void					throw_signals(int);
int					catch_signals(void);
int					cmd_processing(t_data *);
char					*xgetcwd(void);
int					xchdir(char *);
int					is_builtin(t_cmd *, t_data *);
int					builtin_cd(t_cmd *, t_data *);
int					create_pwd_vars(t_data *);
int					update_pwd_vars(t_data *);
int					builtin_vars(t_cmd *, t_list *);
int					builtin_vars_opt_print(t_cmd *,
							       t_list *);
int					builtin_unsetvars(t_cmd *, t_list *);
int					builtin_unsetvars_vars(t_cmd *,
							       t_list *);
int					builtin_setvars(t_cmd *, t_list *);
int					builtin_setvars_base(t_cmd *, t_list *,
							     int (*fct)
							     (t_vars *,
							      t_list *));
int					builtin_setvars_vars(t_vars *,
							     t_list *);
int					builtin_setvars_safe(t_vars *,
							     t_list *);
int					builtin_exit(t_cmd *, t_data *);
char					*get_commands(const int, t_data *);
int					print_prompt(t_data *);
char					**vars_get_array(t_list *);
int					my_execvp(t_cmd *, t_data *);
int					cmd_exec(t_cmd *, t_data *);
int					parsing_commands(t_data *);
int					waiting_child(pid_t, t_data *);
int					redir_right(char *, int);
int					redir_double_right(char *, int);
int					redir_left(char *, int);
int					redir_double_left(char *, int);
int					exec_redir(t_data *);
int					parsing_vars(t_cmd *, t_data *);
void					alias_add(t_list *, char *, char *,
						  char);
t_alias					*alias_get(t_list *, char *);
void					alias_show(t_list *);
int					alias_del_name(t_list *, char *);
void					alias_del_elt(t_list *);
void					alias_free(t_list *);
int					builtin_alias(t_cmd *, t_data *);
int					builtin_alias_opt_print(t_cmd *,
								t_list *);
int					alias_del_name(t_list *, char *);
int					builtin_setalias(t_cmd *, t_data *);
int					builtin_setalias_new(t_vars *,
							     t_list *);
int					builtin_setalias_safe(t_vars *,
							      t_list *);
int					builtin_unalias(t_cmd *, t_data *);
int					builtin_unalias_name(t_cmd *, t_list *);
int					parsing_alias(t_cmd *, t_data *);
int					parsing_file(char *, t_data *);
int					builtin_source(t_cmd *, t_data *);
int					parsing_globing(t_cmd *);
void					free_all(t_data *);
t_builtins				*get_builtins(void);
void					set_builtins_fct(t_builtins *);
void					set_builtins_idx(t_builtins *);
int					builtin_env(t_cmd *, t_data *);
int					builtin_setenv(t_cmd *, t_data *);
int					builtin_unsetenv(t_cmd *, t_data *);
int					builtin_local(t_cmd *, t_data *);
int					builtin_setlocal(t_cmd *, t_data *);
int					builtin_unsetlocal(t_cmd *, t_data *);
void					redir_add(t_list *, char *, char *);
void					redir_del_elt(t_list *);
void					redir_free(t_list *);
void					redir_show(t_list *);
int					parsing_redir(t_cmd *, t_data *);
t_redir_fct				*get_redir_fct(void);
int					redir_get_nbr_of(t_list *, char *);
char					get_pipe_case(t_cmd *);
int					pipe_create(char, t_data *);
int					redir_pipe(char, t_data *);
int					close_pipe(char, t_data *);
void					*xmemcpy(void *, const void *, size_t);
void					*xmemset(void *, int, size_t);
char					*xstrdup(const char *);
int					xdup2(int, int);
int					xopen(const char *, int, mode_t);
int					xpipe(int *);
char					*xstrcat(char *, const char *);
char					*xstrncat(char *, const char *, size_t);

#endif /* PROTO_H_ */

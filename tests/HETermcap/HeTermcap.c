#include "readline/readline.h"
#include "readline/history.h"
#include "string.h"

int main()
{
    char *command_buff;
    while(1)
    {
        command_buff = readline("minishell> ");
        if (strlen(command_buff) > 0)
            add_history(command_buff);
        if (!strcmp(command_buff, "q"))
        {
            break ;
        }
        rl_redisplay();
    }
}
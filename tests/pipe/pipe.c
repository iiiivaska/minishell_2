#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(int argc, char **argv, char **envp)
{
    int pipe_1[2];
    int pipe_2[2];
    char    *yes[3];
    char *head[2];
    char *wc[2];
    yes[0] = "/bin/echo";
    yes[1] = "fffff";
    yes[2] = 0;
    head[0] = "/bin/cat";
    head[1] = 0;
    wc[0] = "/usr/bin/wc"; 
    wc[1] = 0;
    (void)argc;
    (void)argv;
    int stat;
    pid_t fr_1;
    pid_t fr_2;
    pipe(pipe_1);
    if (!(fr_1 = fork()))
    {
        dup2(pipe_1[1], 1);
        close(pipe_1[0]);
        execve(head[0], head, envp);
        close(pipe_1[1]);
        return (1);
    }
    //wait(0);
    pipe(pipe_2);
    if (!(fr_2 = fork()))
    {
        dup2(pipe_1[0], 0);
        close(pipe_1[0]);
        execve(yes[0], yes, envp);
        close(pipe_1[0]);
        return (1);
    }
    waitpid(fr_1, &stat, 0);
    waitpid(fr_2, &stat, 0);

    // pipe(pipe_1);
    // if (!fork())
    // {
    //     dup2(pipe_1[0], 0);
    //     close(pipe_1[1]);
    //     close(pipe_1[0]);
    //     execve(wc[0], 0, envp);
    // }
    // close(pipe_1[0]);
    // pipe(pipe_2);
    // if (!fork())
    // {
    //     dup2(pipe_2[0], 0);
    //     close(pipe_2[1]);
    //     close(pipe_2[0]);
    //     // dup2(pipe_1[1], 1);
    //     // close(pipe_1[1]);
    //     // close(pipe_1[0]);
    //     execve(head[0], head, envp);
    // }
    // //close(pipe_1[1]);
    // close(pipe_2[0]);
    // if (!fork())
    // {
    //     dup2(pipe_2[1], 1);
    //     close(pipe_2[1]);
    //     close(pipe_2[0]);
    //     execve(yes[0], yes, envp);
    // }
    // close(pipe_2[1]);
    // wait(0);
    // wait(0);
    // wait(0);




    // char    **args;
    // char    **args_2;
    // char    *commands[3];
    // int r = 1;
    // int temp_0 = dup(0);
    // commands[0] = (char*)malloc(sizeof(char) * 10);
    // commands[0][0] = '/';
    // commands[0][1] = 'b';
    // commands[0][2] = 'i';
    // commands[0][3] = 'n';
    // commands[0][4] = '/';
    // commands[0][5] = 'e';
    // commands[0][6] = 'c';
    // commands[0][7] = 'h';
    // commands[0][8] = 'o';
    // commands[0][9] = '\0';
    // commands[1] = (char*)malloc(sizeof(char) * 10);
    // commands[1][0] = '/';
    // commands[1][1] = 'b';
    // commands[1][2] = 'i';
    // commands[1][3] = 'n';
    // commands[1][4] = '/';
    // commands[1][5] = 'c';
    // commands[1][6] = 'a';
    // commands[1][7] = 't';
    // commands[1][8] = '\0';
    // commands[2] = 0;
    // pid_t pid;
    // pid_t pid_2;
    // int     ret;
    // int     fd[2];
    // int stat;
    // pid = -1;
    // pid_2 = -1;
    // args = (char**)malloc(sizeof(char*) * 3);
    // args[0] = "minishell";
    // args[1] = "dasfsadfsdafsdf";
    // args[2] = 0;
    // args_2 = (char**)malloc(sizeof(char*) * 2);
    // args_2[0] = "minishell";
    // //args_2[1] = "aaaa";
    // args_2[1] = 0;
    // pipe(fd);
    // while (r >= 0)
    // {
    //     pid = fork();
    //     if (pid == 0)
    //     {
    //         dup2(fd[1], 1);
    //         close(fd[0]);
    //         if (r == 0)
    //         {
    //             stat = execve(commands[r], args, envp);
    //         }
    //         else
    //             stat = execve(commands[r], args_2, envp);
    //         close(fd[1]);
    //     }
    //     else
    //     {
    //         dup2(fd[0], 0);
    //         close(fd[1]);
    //         wait(&stat);
    //         close(fd[0]);
    //     }
    //     r--;
    // }
    // pid = fork();
    // if (pid > 0)
    //     pid_2 = fork();
    // if (pid == 0)
    // {
    //     dup2(fd[1], 1);
    //     close(fd[0]);
    //     execve("/bin/echo", args, envp);
    //     close(fd[1]);
    // }
    // if (pid_2 == 0)
    // {
    //     execve("/bin/cat", args_2, envp);
    // }
    // else
    // {
    //     waitpid(pid_2, &ret, 0);
    //     waitpid(pid, &ret, 0);
    // }

    // pid = fork();
    // pid_2 = fork();
    // if (pid == 0)
    //     execve("/bin/echo", args, envp);
    // if (pid_2 == 0)
    //     execve("/bin/echo", args_2, envp);
    // else
    // {
    //     while (1)
    //         write(1, "", 1);
    // }
}
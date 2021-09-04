#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
int main(int argc, char **argv, char **envp)
{
    if (!fork())
        execve("../a.out", 0, envp);

}

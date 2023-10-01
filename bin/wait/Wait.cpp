#include <stdlib.h>
#include "Wait.h"
#include <sys/wait.h>

Wait::Wait(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Stop executing until the end of a process");
    parser().registerPositional("PID", "Stop executing until the end of the given process");
}

Wait::~Wait()
{
}

Wait::Result Wait::exec()
{
    // Variables
    int status;
    int pid = atoi(arguments().get("PID"));

    // Wait
    waitpid(pid, &status, 0);

    // Done
    return Success;
}
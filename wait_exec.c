
#include <stdlib.h>
#include <stdbool.h>

#include "mycutils.h"
#include "timer_sec.h"

/**
 * This function prints the help menu.
 */
void print_help()
{
    fsout(
            stdout,
	        "USAGE:\n"
	        "   wait_exec [-options] <command>\n"
	        "\n"
	        "OPTIONS:\n"
	        "   -h, --help         \"Print this menu\"\n"
	        "   -t, --wait-time    \"The number of seconds to wait before executing the command. Default is 0 seconds\"\n");
}

int main(int argc, char* argv[])
{
    log* l;
    timer_sec* wait_timer;
    char* command;      /* The command to execute. */
    int i;
    int wait_time;      /* The number of seconds to wait before executing the command. */
    bool invalid_args;  /* Whether the arguments passed to main function are invalid. */

    /* Default values. */
    wait_time = 0;
    command = "";
    invalid_args = false;

    l = log_init("wait_exec-log.txt");
    l->out(l->fs, "Program start.\n");
			
    /* Check if any arguments were passed to main function. */
    if (argc == 1)
    {
        fsout(stdout, "ERROR: Please provide a command.\n");
        l->out(l->fs, "ERROR: No arguments provided.\n");
        print_help();
        exit(EXIT_FAILURE);
    }

    for (i = 1; i < argc - 1; i++)
    {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
        {
            print_help();
            exit(EXIT_FAILURE);
        }
        else if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--wait-time") == 0)
        {
            if ((wait_time = atoi(argv[i + 1])) == 0)
            {
                fsout(stdout, "ERROR: Invalid wait time argument.\n");
                l->out(l->fs, "ERROR: Invalid wait_time argument..\n");
            }
        }
    }

    command = argv[argc - 1];
    
    /* Print a status message. */
    fsout(stdout, "Executing \"%s\" in %d seconds...\n", command, wait_time);
    l->out(l->fs, "Executing \"%s\" in %d seconds...\n", command, wait_time);

    wait_timer = timer_sec_init(l);

    while (!timer_sec_elapsed(*wait_timer, wait_time, l)) {}
    
    /* Execute the command. */
    system(command);
    
    l->out(l->fs, "\"%s\" was executed. Exiting wait_exec.\n", command);
    
    exit(EXIT_SUCCESS);
}

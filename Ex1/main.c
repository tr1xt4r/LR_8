#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int signum) {
    printf("Caught SIGINT signal. Process will continue.\n");
}

void handle_sigterm(int signum) {
    printf("Caught SIGTERM signal. Process will continue.\n");
}

void handle_sigusr1(int signum) {
    printf("Caught SIGUSR1 signal. Exiting...\n");
    exit(0);
}

int main() {
    signal(SIGINT, handle_sigint);
    signal(SIGTERM, handle_sigterm);
    signal(SIGUSR1, handle_sigusr1);
    signal(SIGPROF, SIG_DFL);
    signal(SIGHUP, SIG_IGN);
    while (1) {
        pause();
    }

    return 0;
}

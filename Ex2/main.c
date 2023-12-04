#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handleAlarm(int sig) {
}

void setupAlarm(int duration, const char *text) {
    signal(SIGALRM, handleAlarm);
    alarm(duration);
    pause();
    printf("Scheduled Alarm: %s\n", text);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <duration in seconds> <message>\n", argv[0]);
        return 1;
    }

    int duration = atoi(argv[1]);
    char *message = argv[2];

    pid_t childPID = fork();

    if (childPID < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (childPID == 0) {
        setupAlarm(duration, message);
        exit(0);
    } else {
        printf("Alarm set for %d seconds. Child process PID: %d\n", duration, childPID);
        exit(0);
    }

    return 0;
}

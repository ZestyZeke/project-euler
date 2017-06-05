/*
 * p16-compare.c
 *
 * Zeke Reyna
 *
 * This C program runs the different lang solutions concurrently
 * rather than the bash script
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#define		NUM_THREADS		3

// put a mutex and stuff so that the files can individually write
// to p16-compare.txt when they finish without overwriting each other.

static void die(const char *message)
{
	perror(message);
	exit(1); // might be smarter to call pthread_exit
}

static void *thread_main(void *data)
{
	int num = *(int *)data;
	switch (num) {

	case 0 : // c++
	{

		time_t before = time(NULL);
		pid_t pid;

		pid = fork(); // vfork?
		if (pid < 0) {
			die("error forking\n");

		} else if (pid == 0) { // child
			chdir("./vers_cpp");
			execl("./runplz", "runplz", (char *)0);
			die("execl failed\n");
			// think about: getting PWD env variable, changing
			// it for this child process to vers_cpp and then
			// calling execlp or something with our env variable.
			// calling chdir is probably expensive because of COW
			//
			// ALSO: stdout might get mixed up between programs

		} else { // parent

			if (waitpid(pid, NULL, 0) != pid)
				die("waitpid failed\n");
			time_t after = time(NULL);
			double time_ran = difftime(after, before); // might be negative
			// grab mutex, and write to file with C++ time and stuff
			printf("time ran for c++ is %f\n", time_ran);

		}
		break;
	}
	case 1 : // java
	{
		time_t before = time(NULL);
		pid_t pid;

		pid = fork();
		if (pid < 0) {
			die("error forking\n");
		} else if (pid == 0) {
			chdir("./vers_java");
			execl("./runplz", "runplz", (char *)0);
			die("execl failed\n");
		} else {

			if (waitpid(pid, NULL, 0) != pid)
				die("waitpid failed\n");
			time_t after = time(NULL);
			double time_ran = difftime(after, before);
			printf("time ran for java is %f\n", time_ran);
		}
		break;
	}
	case 2 : // pyton
	{
		time_t before = time(NULL);
		pid_t pid;

		pid = fork();
		if (pid < 0) {
			die("error forking\n");
		} else if (pid == 0) {
			chdir("./vers_py");
			execl("./runplz", "runplz", (char *)0);
			die("execl failed\n");
		} else {

			if (waitpid(pid, NULL, 0) != pid)
				die("waitpid failed\n");
			time_t after = time(NULL);
			double time_ran = difftime(after, before);
			printf("time ran for python is %f\n", time_ran);
		}
		break;
	}
	default :
	{
		break;
	}

	}

	pthread_exit(NULL);
}

int main()
{
	pthread_t thread_list[NUM_THREADS];
	int nums[NUM_THREADS];

	// make threads
	for (int i = 0; i < NUM_THREADS; i++) {
		nums[i] = i;
		pthread_create(&thread_list[i], NULL, thread_main, &nums[i]);
	}

	// clean up dead threads
	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_join(thread_list[i], NULL);
	}

	return 0;
}

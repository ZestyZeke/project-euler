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
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#define		NUM_THREADS		3
#define		BILLION			1000000000L
#define		BUF_SIZE		2048 // way too large

// put a mutex and stuff so that the files can individually write
// to p16-compare.txt when they finish without overwriting each other.

struct time_and_lang {
	unsigned long long time_spent;
	char lang_dir[20];
};

// maybe use uint64_t instead?
static struct time_and_lang time_queue[NUM_THREADS];

static void die(const char *message)
{
	perror(message);
	pthread_exit(NULL);
}

static void give_dir_lang(char lang_dir[20], int num)
{
	switch (num) {
	case 0 :
		{
			strcpy(lang_dir, "./vers_cpp");
			break;
		}

	case 1 :
		{
			strcpy(lang_dir, "./vers_java");
			break;
		}
	case 2 :
		{
			strcpy(lang_dir, "./vers_py");
			break;
		}
	default :
		{
			strcpy(lang_dir, "./vers_cpp");
			break;
		}
	}
}

static void *thread_main(void *data)
{
	int num = *(int *)data;
	char lang_dir[20]; // looks hardocded, clean up later.

	give_dir_lang(lang_dir, num);

	// use clock_gettime maybe choose a diff point to be more precise
	struct timespec before, after;
	unsigned long long time_running;
	clock_gettime(CLOCK_MONOTONIC, &before); // CLOCK_PROCESS_CPUTIME_ID?

	pid_t pid;

	pid = fork(); // vfork maybe?
	if (pid < 0) {
		die("fork failed\n");
	} else if (pid == 0) {
		chdir(lang_dir);
		execl("./runplz", "runplz", (char *)0);
		die("execl failed\n");
	} else {

		// look up way to force parent to run first. just worried about
		// time keeping needing a running process or something
		// can move time_t before to over here in that case.
		if (waitpid(pid, NULL, 0) != pid)
			die("waitpid failed\n");

		clock_gettime(CLOCK_MONOTONIC, &after);
		time_running = BILLION * (after.tv_sec - before.tv_sec);
		time_running += (after.tv_nsec - before.tv_nsec);

		// now need to put into time_queue so that main can write it to
		// file, later use mutex and file I/O so they get written
		// as time passes, can just put them in orders based on
		// how much time it took, make queue dynamic or something.
		// can grab a lock and check which entries are empty, add into
		// first empty entry? maybe initially put 0's in each entry
		time_queue[num].time_spent = time_running;
		strcpy(time_queue[num].lang_dir, lang_dir);
	}

	pthread_exit(NULL);
}

int main(int argc, char **argv)
{
	pthread_t thread_list[NUM_THREADS];
	int nums[NUM_THREADS];

	// start writing file they'll write into
	char const *filename;
	char const *default_name = "thread-compare.txt";
	char buffer[BUF_SIZE];

	if (argc == 2)
		filename = argv[1];
	else
		filename = default_name;

	FILE *fp = fopen(filename, "w"); // w setting erases prev file contents
	if (!fp)
		die("fopen failed\n");

	// make threads
	for (int i = 0; i < NUM_THREADS; i++) {
		nums[i] = i;
		pthread_create(&thread_list[i], NULL, thread_main, &nums[i]);
	}

	// clean up dead threads
	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_join(thread_list[i], NULL);
	}

	// write results to file.
	for (int i = 0; i < NUM_THREADS; i++) {
		printf("%llu\n", time_queue[i].time_spent);
		sprintf(buffer, "\nThe %s solution takes %llu nanoseconds\n\n",
			time_queue[i].lang_dir, time_queue[i].time_spent);
		fwrite(buffer, sizeof(char), strlen(buffer), fp);
	}

	fclose(fp);

	return 0;
}

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

void print_usage(char** argv) {
		printf("Usage: %s [OPTIONS]\n", argv[0]);
		printf("  -s, --socket                socket name\n");
		printf("  -w, --wait-for-end          continue processing till the end of the log is reached\n");
		printf("  -h, --help                print this help and exit\n");
		printf("\n");

}

		char socketName[256];
		int waitForEnd = 0;

int command_line_option(int argc, char **argv)
{
		int c;

		struct option   long_opt[] =
		{
				{"help",          no_argument,       NULL, 'h'},
				{"socket",        required_argument, NULL, 's'},
				{"wait-for-end",  no_argument,							NULL, 'w'},
				{NULL,            0,                 NULL, 0  }
		};

		while((c = getopt_long(argc, argv, "hs:w", long_opt, NULL)) != -1)
		{
				switch(c)
				{
						case 's':
								printf("you entered \"%s\"\n", optarg);
								strncpy(socketName, optarg, 256);
								break;
						
						case 'w':
								waitForEnd = 1;
								break;

						case 'h':
								print_usage(argv);
								exit(0);

						default:
								fprintf(stderr, "Try `%s --help' for more information.\n", argv[0]);
								exit(-2);
				};
		};

}

int main(int argc, char * argv[])
{
	command_line_option(argc, argv);
	printf("socket_name : %s\n", socketName);
	printf("waitForEnd %d\n", waitForEnd);
		return(0);
}

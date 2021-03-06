#include "stdio.h"
#include "stdlib.h"
#include "dirent.h"
#include "string.h"
#include "sys/types.h"

int main (int argc, char *argv[])
{
	DIR *dir;
	struct dirent * sd;
	char mfile[127];

	if (argc < 2)
	{
		strcpy(mfile, ".");
	}
	else
        strcpy(mfile, argv[1]);

        printf("%s \n \n", mfile);
        dir = opendir(mfile);

	while((sd = readdir(dir)) != NULL)
	{
		printf("[%s] \n", sd->d_name);
		sd = readdir(dir);
	}

	closedir(dir);

	return 0;
}

/*
 * Project: Die Comparison
 * Author: Nathan Sheely
 * File: die_comp.c
 *
 * Purpose: Parse inputs and run find_comp
 *
 * Contains:
 *	err_and_quit -- Throw stderr and exit program
 *	ocmp -- compare input option to short and long options
 *	main -- Parse arguments and find_comp
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "die_comp_lib.h"

 /*
  * Throws error and exits program
  *
  * Arguments:
  *	char *err: error message
  */
void err_and_quit(char* err_msg) {
	fprintf(stderr, "%s", err_msg);
	exit(EXIT_FAILURE);
}

/*
 * Checks if input matches either s or l
 *	*used for options checking, s = short, l = long
 *
 * Arguments:
 *	char input[]: input message to compare
 *	char s[]: short option
 *	char l[]: long option
 *
 *	Returns:
 *		1 if match 0 if not
 */
int ocmp(char input[], char s[], char l[]) {
	return (strcmp(input, s) == 0 || strcmp(input, l) == 0);
}

/*
 * Main function, parse inputs and pass to dice generator
 *
 */
int main(int argc, char *argv[]) {
	int pip_num = 21; // default 21 pips
	int die_faces = 6; // default 6 faces
	char *err_chk; // for error checking string to int conversion

	//default die
	int *die = malloc(die_faces * sizeof(int));
	if (!die)
		err_and_quit("die_comp: failed to allocate memory\n");
	int i, k; // loop variables
	for (k = 0; k < die_faces; k++)
		die[k] = k + 1;

	//parse args
	for (i = 1; i < argc; i++) {
		if (argv[i][0] == '-') {
			i++;
			if (ocmp(argv[i - 1], "-p", "-pips")) {
				if (i >= argc)
					err_and_quit("die_comp: need number of pips\n");
				pip_num = strtol(argv[i], &err_chk, 10);
				if (err_chk[0] != '\0')
					err_and_quit("die_comp: pips must be a number\n");
			}
			else if (ocmp(argv[i - 1], "-f", "-faces")) {
				if (i >= argc)
					err_and_quit("die_comp: need number of faces\n");
				die_faces = strtol(argv[i], &err_chk, 10);
				if (err_chk[0] != '\0')
					err_and_quit("die_comp: faces must be a number\n");
				die = (int*)realloc(die, die_faces * sizeof(int));
				if (!die)
					err_and_quit("die_comp: failed to reallocate memory\n");
				for (k = 0; k < die_faces; k++)// default new die
					die[k] = k + 1;
			}
			else if (ocmp(argv[i - 1], "-d", "-die")) {
				for (k = 0; k < die_faces; k++, i++) {
					if (i >= argc)
						err_and_quit("die_comp: die needs atleast as many"
							" entries are there are die faces\n");
					die[k] = strtol(argv[i], &err_chk, 10);
					if (err_chk[0] != '\0')
						err_and_quit("die_comp: die entries must be numbers\n");
				}
			}
			else
				err_and_quit("Unknown entry\nUsage: ./die_comp [-pips #pips]"
					"[-faces #faces][-die {number for each die face}]");
		}
		else
			err_and_quit("Unknown entry\nUsage: ./die_comp [-pips #pips]"
				"[-faces #faces][-die {number for each die face}]");
	}
	compare_die(pip_num, die_faces, die);
	free(die);
	return EXIT_SUCCESS;
}

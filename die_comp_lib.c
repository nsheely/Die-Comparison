/*
 * Project: Die Comparison
 * Author: Nathan Sheely
 * File: die_comp_lib.c
 *
 * Purpose: generate die and print win/loss rates
 *
 * Contains:
 *	check_die -- Check generated die against sample die, print results
 *	find_comb_util -- Recursive, generate all combinations of numbers that add to #pips
 *	compare_die -- set variables, call find_comb_util
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static float curr_best = 0.1; // dont show 0 win die
static int comp_die_faces = 6;
static int *comp_die;

/*
 * Check generated die against sample die, print results
 *
 * Arguments:
 *	int arr[]: generated die numbers
 *	int index: number if numbers in arr
 */
void check_die(int arr[], int index) {
	int num_wins = 0;
	int num_loss = 0;
	int temp, i, j;
	for (i = 0; i < comp_die_faces; i++) {
		temp = (i < index) ? arr[i] : 0;
		for (j = 0; j < comp_die_faces; j++) {
			if (temp < comp_die[j])
				num_loss++;
			if (temp > comp_die[j])
				num_wins++;
		}
	}
	float wlrate = (float)num_wins / num_loss;
	if (wlrate >= curr_best) {
		for (i = 0; i < comp_die_faces; i++)
			printf("%d ", (i < index ? arr[i] : 0));
		printf("num wins: %d num loss: %d win/loss: %f\n", num_wins, num_loss, wlrate);
		curr_best = wlrate;
	}
}

/*
 * Recursively calls itself to generate every combination of numbers that adds to num
 *
 * Arguments:
 *	int arr[]: generated die numbers
 *	int index: number if numbers in arr
 *	int num: target number, number of pips
 *	int reducednum: num - total of numbers in arr
 */
void find_comb_util(int arr[], int index, int num, int reducednum) {
	if (reducednum < 0)
		return;
	if (reducednum == 0) {
		check_die(arr, index);
		return;
	}
	int prev = (index == 0) ? 1 : arr[index - 1];
	int k;
	for (k = prev; k <= num; k++) {
		arr[index] = k;
		find_comb_util(arr, index + 1, num, reducednum - k);
	}
}

/*
 * Set variables, start find_comb_util, print comp die info
 *
 * Arguments:
 *	int n: number of pips
 *	int die_faces: number of die faces
 *	int die[]: numbers on each side of sample die
 */
void compare_die(int n, int die_faces, int die[]) {
	int arr[n];
	comp_die = die;
	comp_die_faces = die_faces;
	find_comb_util(arr, 0, n, n);
	printf("comp die:");
	int i;
	for (i = 0; i < die_faces; i++)
		printf(" %d", die[i]);
	printf("\n");
}

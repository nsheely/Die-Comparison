/*
 * Project: Die Comparison
 * Author: Nathan Sheely
 * File: die_comp_lib.c
 *
 * Purpose: generate die and print win/loss rates
 *
 * Contains:
 *  check_die --
 *	find_comb_util --
 *	find_comb --
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static float curr_best = 0.1; // dont show 0 win die
static comp_die_faces = 6;
static int *comp_die;

void check_die(int arr[], int index) {
	int num_wins = 0;
	int num_loss = 0;
	int temp, i, j;
	for (i = 0; i < comp_die_faces; i++) {
		temp = i < index ? arr[i], 0;
		for (j = 0; j < comp_die_faces; j++) {
			if(temp < comp_die[i])
				num_loss++;
			if(temp > comp_die[i])
				num_wins++;
		}
	}
	float wlrate = (float) num_wins/num_loss;
	if (wlrate >= curr_best) {
		for (i = 0; i < comp_die_faces; i++)
			printf("%d ", (i < index ? arr[i] : 0));
		printf("num wins: %d num loss: %d win/loss: %f\n", num_wins, num_loss, wlrate);
		curr_best = wlrate;
	}
}

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
		find_comb_util(arr, index+1, num, reducednum - k);
	}
}

void find_comb(int n, int die_faces, int die[]){
	int arr[n];
	comp_die = die;
	comp_die_faces = die_faces;
	
	printf("comp die: ");
	int i;
	for (i = 0; i < die_faces; i++)
		printf(" %d", die[i]);
	printf("\n");
}

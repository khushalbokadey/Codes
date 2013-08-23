/*
 * Kyle Donnelly
 * MeetingPoint.c
 * InterviewStreet
 * 16 April 2012
 *
 * Finds average x and y (no overflow risk)
 * Finds closest x and y to the average
 * Adds distances from all other points to that one.
 *
 * Moving diagonally to a grid on the corner has only
 *    cost 1, not sqrt(2). This means the time to move
 *    there is the max of the d_y and d_x.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<iostream>

#define ABS(a) (a > 0 ? a : -(a))
#define MAX(a, b) (a > b ? a : b)

using namespace std;

int MeetingPoint(void) {
	long  *x, *y;
	int cases;
	long double ave_x = 0, ave_y = 0;
	long double min;
	int i;
	unsigned int min_index = 0;
	unsigned long long int sum = 0;

	scanf("%d", &cases);

	x = (long*) malloc(sizeof(long long int) * cases);
	y = (long*) malloc(sizeof(long long int) * cases);

	/* Fill in coordinate array */
	for (i=0; i<cases; i++) {
		cin>>x[i]>>y[i];
	}

	/* Average = SUM(x / total) */
	for (i=0; i<cases; i++) {
		ave_x += (long double) x[i] / cases;
		ave_y += (long double) y[i] / cases;
	}

	/* Start at 0 */
	min = sqrt((ave_x-x[0])*(ave_x-x[0]) + (ave_y-y[0])*(ave_y-y[0]));

	/* Find the point closest to the average and save its index */
	for (i=1; i<cases; i++) {
		double diff = sqrt((ave_x-x[i])*(ave_x-x[i]) + (ave_y-y[i])*(ave_y-y[i]));
		if (diff < min) {
			min = diff;
			min_index = i;
		}
	}

	/* Count up the max path lengths */
	for (i=0; i<cases; i++) {
		sum += MAX((ABS(x[min_index]-x[i])), (ABS(y[min_index]-y[i])));
	}

	printf("%llu\n", sum);

	return 0;
}

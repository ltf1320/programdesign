#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "svm.h"
#include "svmcall.h"

void exit_with_help()
{
	printf(
	"Usage: svm-scale [options] data_filename\n"
	"options:\n"
	"-l lower : x scaling lower limit (default -1)\n"
	"-u upper : x scaling upper limit (default +1)\n"
	"-y y_lower y_upper : y scaling limits (default: no y scaling)\n"
	"-s save_filename : save scaling parameters to save_filename\n"
	"-r restore_filename : restore scaling parameters from restore_filename\n"
	);
	exit(1);
}

char *line = NULL;
int max_line_len = 1024;
double lower=-1.0,upper=1.0,y_lower,y_upper;
int y_scaling = 0;
double *feature_max;
double *feature_min;
double y_max = -DBL_MAX;
double y_min = DBL_MAX;
int max_index;
int min_index;
long int num_nonzeros = 0;
long int new_num_nonzeros = 0;

#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))

void output_target(double value);
void output(int index, double value);
char* readline(FILE *input);

int main(int argc,char **argv)
{
	return mainscale(argc, argv);
}

char* readline(FILE *input)
{
	int len;
	
	if(fgets(line,max_line_len,input) == NULL)
		return NULL;

	while(strrchr(line,'\n') == NULL)
	{
		max_line_len *= 2;
		line = (char *) realloc(line, max_line_len);
		len = (int) strlen(line);
		if(fgets(line+len,max_line_len-len,input) == NULL)
			break;
	}
	return line;
}

void output_target(double value)
{
	if(y_scaling)
	{
		if(value == y_min)
			value = y_lower;
		else if(value == y_max)
			value = y_upper;
		else value = y_lower + (y_upper-y_lower) *
			     (value - y_min)/(y_max-y_min);
	}
	printf("%g ",value);
}

void output(int index, double value)
{
	/* skip single-valued attribute */
	if(feature_max[index] == feature_min[index])
		return;

	if(value == feature_min[index])
		value = lower;
	else if(value == feature_max[index])
		value = upper;
	else
		value = lower + (upper-lower) * 
			(value-feature_min[index])/
			(feature_max[index]-feature_min[index]);

	if(value != 0)
	{
		printf("%d:%g ",index, value);
		new_num_nonzeros++;
	}
}

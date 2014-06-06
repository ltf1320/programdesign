#include "mex.h"

void select_sort(const double *X, int *ind, int base, int left, int right)
{
	int i, j, min, temp;
	for (i = left; i < right; i++)
	{
		min = i;
		for (j = i + 1; j <= right; j++)
			if (X[base + ind[j]] < X[base + ind[min]])
				min = j;
		temp = ind[i]; ind[i] = ind[min]; ind[min] = temp;
	}
}

void qsort(const double *X, int *ind, int base, int left, int right)
{
	if (right - left < 8)
	{
		select_sort(X, ind, base, left, right);
		return;
	}
	int i = left, j = right;
	double ref = X[base + ind[(left + right) >> 1]];
	int temp;
	
	do
	{
		while (X[base + ind[i]] < ref) i++;
		while (ref < X[base + ind[j]]) j--;
		if (i <= j)
		{
			temp = ind[i]; ind[i] = ind[j]; ind[j] = temp;
			i++; j--;
		}
	} while (i <= j);
	
	if (left < j) qsort(X, ind, base, left, j);
	if (i < right) qsort(X, ind, base, i, right);
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if (nrhs != 3)
	{
		mexErrMsgTxt("Three inputs required.");
	}
	if (nlhs != 2)
	{
		mexErrMsgTxt("Two outputs required.");
	}
	
	int minleaf = mxGetScalar(prhs[2]);
	int n = mxGetM(prhs[1]);
	int dx = mxGetN(prhs[0]);
	int dy = mxGetN(prhs[1]);
	
	double *X = mxGetPr(prhs[0]);
	double *C = mxGetPr(prhs[1]);
	double *S = new double[n * dy];
	int *ind = new int[n];
	
	int i, j, k, p;
	double bestcut = 0, bestcrit = 0;
	int bestvar = -1, bestk = 0;
	int cnt = 0;
	double left, right, sum;
	
	for (p = 0; p < dx; p++)
	{
		// Sort X and C
		for (j = 0; j < n; j++) ind[j] = j;
		qsort(X, ind, cnt, 0, n - 1);
		
		// Find the best cut
		for (j = 0; j < dy; j++)
		{
			S[j * n] = C[j * n + ind[0]];
		}
		for (i = 1; i  < n; i++)
			for (j = 0; j < dy; j++)
			{
				S[j * n + i] = S[j * n + i - 1] + C[j * n + ind[i]];
			}
		
		for (k = minleaf; k <= n - minleaf; k++)
		{
			if (X[cnt + ind[k - 1]] == X[cnt + ind[k]])
				continue;
			left = right = 0;
			for (j = 0; j < dy; j++)
			{
				i = S[j * n + k - 1];
				sum = S[j * n + n - 1];
				left += i * i;
				right += (sum - i) * (sum - i);
			}
			left /= k;
			right /= n - k;
			if (left + right > bestcrit)
			{
				bestcrit = left + right;
				bestk = k;
				bestvar = p;
			}
		}
		 
		if (bestvar == p)
		{
			bestcut = (X[cnt + ind[bestk - 1]] + X[cnt + ind[bestk]]) / 2;
		}
		
		cnt += n;
	}
	
	delete[] S;
	plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
	plhs[1] = mxCreateDoubleMatrix(1, 1, mxREAL);
	
	*mxGetPr(plhs[0]) = bestvar + 1;
	*mxGetPr(plhs[1]) = bestcut;
}
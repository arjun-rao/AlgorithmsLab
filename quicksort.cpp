/**
 * Implementation of the quicksort algorithm
 * Author: Arjun Rao
 * Usage: 
 * Run  ./quicksort
 *
 **/

#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <sys/resource.h>
#include <sys/time.h>

using namespace std;

#undef calculate
#undef getrusage

// prototype
double calculate(const struct rusage* b, const struct rusage* a);


int partition(int *a,int low, int hi)
{
	int pivot = a[hi],temp;
	int i = low-1;
	for(int j=low;j<hi;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			
		}
	}
	temp = a[i+1];
	a[i+1] = a[hi];
	a[hi] = temp;
	return i+1;
}


void quicksort(int *a,int low,int hi)
{
	if(low<hi)
	{
		int p = partition(a,low,hi);
		quicksort(a,low,p-1);
		quicksort(a,p+1,hi);
	}
}

int main()
{

	int *a,n;

	// structs for timing data
	rusage before, after;
	// benchmarks
    double ti_sort = 0.0;


	cin>>n;
	if(n<=0) exit(0);	
	a = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	getrusage(RUSAGE_SELF, &before);
		quicksort(a,0,n-1);
	getrusage(RUSAGE_SELF, &after);
	
	for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;

	ti_sort = calculate(&before, &after);
	delete [] a;

	cout<<"TIME to sort "<<n<<" inputs: "<<std::fixed<<setprecision(6)<< ti_sort<<endl;
}

/**
 * Returns number of seconds between b and a.
 */
double calculate(const struct rusage* b, const struct rusage* a)
{
    if (b == NULL || a == NULL)
    {
        return 0.0;
    }
    else
    {
        return ((((a->ru_utime.tv_sec * 1000000 + a->ru_utime.tv_usec) -
                 (b->ru_utime.tv_sec * 1000000 + b->ru_utime.tv_usec)) +
                ((a->ru_stime.tv_sec * 1000000 + a->ru_stime.tv_usec) -
                 (b->ru_stime.tv_sec * 1000000 + b->ru_stime.tv_usec)))
                / 1000000.0);
    }
}
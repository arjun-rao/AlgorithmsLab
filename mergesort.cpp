/**
 * Implementation of the mergesort algorithm
 * Author: Arjun Rao
 * Usage: 
 * Run  ./mergesort
 *
 **/




#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <sys/resource.h>
#include <sys/time.h>

#undef calculate
#undef getrusage

using namespace std;


// prototype
double calculate(const struct rusage* b, const struct rusage* a);


void merge(int *,int, int , int );
void mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}
void merge(int *a, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = 0;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low,k=0; i <=high;k++, i++)
    {
        a[i] = c[k];
    }
}



int main()
{

	int *ptr,n,i;

	// structs for timing data
	rusage before, after;
	// benchmarks
    double ti_sort = 0.0;




	cin>>n;
	if(n<=0) exit(0);	
	ptr = new int[n];

	for(i=0;i<n;i++)
	cin>>ptr[i];

	getrusage(RUSAGE_SELF, &before);
       	mergesort(ptr,0,n-1);
	getrusage(RUSAGE_SELF, &after);
	
	for(i=0;i<n;i++)cout<<ptr[i]<<" ";cout<<endl;
	
	ti_sort = calculate(&before, &after);
	delete [] ptr;

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


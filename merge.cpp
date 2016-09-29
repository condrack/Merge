/*************************************
Name: Taylor Condrack
Course: 3110
Assignment: Program 2 merge sort
Due Date: 9/19/15
************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;
//class to store variables in file
class census
{
        public:
                string names;
                double area;
                int count;
                double density; //variable that the algrithm is using to sort
		census();

};
void mergesort(census a[],int, int,census right[], census left[]);
void merge(census a[], int, int, int, census right[], census left[]);
int main()
{
//variables used for to calculate runtime
	clock_t begin, end;
	double exectime;
	int p=0; //index of sequence beginning
        int r=74000; //index of sequence ending
	census a[74000];
	census left[75000];
        census right[74000];

	begin = clock();
	mergesort(a, p,r,right,left);
	end = clock();


//prints output to file
	ofstream sorted;
	sorted.open("mergesortoutput.txt");
	for(int i=0;i<74000;i++)
        {
                sorted<<a[i].names<<'|'<<a[i].area<<'|'<<a[i].count<<'|'<<a[i].density<<endl;
        }
	sorted.close();
	exectime = (double)(end-begin)/CLOCKS_PER_SEC;
	cout<<"Execution time = "<<exectime<<" s"<<endl;
	return 0;
}
//the constructor will read in data from the input file for each item in the array of objects
census::census()
{
		getline(cin,names,'|');
                cin>>area;
                cin.get();
                cin>>count;
                cin.get();
                cin>>density;
}
//high level mergesort function
void mergesort(census a[],int p, int r, census right[],census left[])
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		mergesort(a,p,q,right,left);
		mergesort(a,q+1,r,right,left);
		merge(a,p,q,r,right,left);
	}
}
//low level merge function arguments - original array beginning position in array, middle, and end, left and right array
void merge(census a[], int p, int q, int r,census right[], census left[])
{

	int n1= q-p+1;
	int n2= r-q;

//copies values into left and right array
	for(int i=1;i<=n1;i++)
	{
		left[i].names=a[p+i-1].names;
		left[i].area=a[p+i-1].area;
		left[i].count=a[p+i-1].count;
		left[i].density=a[p+i-1].density;
	}
	for(int j=1;j<=n2;j++)
	{
		right[j].names=a[q+j].names;
		right[j].area=a[q+j].area;
		right[j].count=a[q+j].count;
		right[j].density=a[q+j].density;
	}

//these take vare of leftover values if the sorting is uneven
	left[n1+1].density=10000000;
	right[n2+1].density=10000000;
	int w=1;
	int y=1;

//compares values and swaps
	for(int k=p;k<=r;k++)
	{
		if(left[w].density<=right[y].density)
		{
			a[k].names=left[w].names;
			a[k].area=left[w].area;
			a[k].count=left[w].count;
			a[k].density=left[w].density;
			w+=1;
		}
		else
		{
			a[k].names=right[y].names;
			a[k].area=right[y].area;
			a[k].count=right[y].count;
			a[k].density=right[y].density;
			y+=1;
		}
	}

}


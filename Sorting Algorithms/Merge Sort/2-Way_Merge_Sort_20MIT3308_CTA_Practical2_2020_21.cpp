// C++ program for Merge Sort

#include <bits/stdc++.h>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include <fstream>
#include <iostream>
#include<time.h>

using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        // Same as (l+r)/2, but avoids
        // overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
    for(int i = 0; i < size; i++)
        cout << A[i] << " ";
}
void reverseArray(int arr[], int n){
   for (int low = 0, high = n - 1; low < high; low++, high--){
      swap(arr[low], arr[high]);
   }
}
// Driver code
int main()
{
    int randomNumber_len, randomNumber;
    int len_arr[] = {10,100,1000,10000,20000,50000,80000,100000};
    //int len_arr[] = {140000};
    int debug_len = 8;

    ofstream merges;
    merges.open("merge.csv");
    merges << "Length,Random,Sorted,RandomSorted\n" ;
     for (int i = 0; i < debug_len; i++)
     {


             randomNumber_len = len_arr[i];
             int arr[randomNumber_len];

             cout << "\nLength of  random numbers = " << randomNumber_len << "\n";
             cout<< "Seq Type = Random\n";

             merges << randomNumber_len << ",";




             for (int index = 0; index < randomNumber_len; index++)
                {
                    randomNumber = (rand() % (randomNumber_len*10)) + 1;
                    arr[index]  = randomNumber;

                }

    int arr_size = sizeof(arr) / sizeof(arr[0]);
    //printArray(arr, arr_size);
    clock_t t;
    t=clock();
    mergeSort(arr, 0, arr_size - 1);
    t=clock()-t;
    double time_taken_1= ((double)t);
    cout << fixed  << time_taken_1 << setprecision(5) << "sec\t\n";
    merges << fixed << time_taken_1 << setprecision(5) << ",";
    //printArray(arr, arr_size);


    cout<< "Seq Type = Sorted\n";


    t=clock();
    mergeSort(arr, 0, arr_size - 1);
    t=clock()-t;
    double time_taken_2= ((double)t);
    cout << fixed  << time_taken_2 << setprecision(5) << "sec\t\n";
    merges << fixed << time_taken_2 << setprecision(5) << ",";


    reverseArray(arr,randomNumber_len);
    //printArray(arr, arr_size);


    cout<< "Seq Type = Reverse Sorted\n";


    t=clock();
    mergeSort(arr, 0, arr_size - 1);
    t=clock()-t;
    double time_taken_3= ((double)t);
    cout << fixed  << time_taken_3 << setprecision(5) << "sec\t\n";
    merges << fixed << time_taken_3 << setprecision(5) << ",\n";

//printArray(arr, arr_size);
     }



    //printArray(arr, arr_size);

    merges.close();

    //printArray(arr, arr_size);
    return 0;
}

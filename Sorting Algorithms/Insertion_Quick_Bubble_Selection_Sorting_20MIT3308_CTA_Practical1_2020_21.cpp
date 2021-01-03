// C++ program by Jaynil Patel 3308
#include <bits/stdc++.h>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include <fstream>
#include <iostream>
#include<time.h>
using namespace std;


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
// partition the array using last element as pivot

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        //if current element is smaller than pivot, increment the low element
        //swap elements at i and j
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

//quicksort algorithm
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        //partition the array
        int pivot = partition(arr, low, high);

        //sort the sub arrays independently
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void selectionSort(int arr[], int n,int type)
{
    int i, j, min_idx;


    for (i = 0; i < n-1; i++)
    {

        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;


        swap(&arr[min_idx], &arr[i]);
    }
}


void bubbleSort(int arr[], int n,int type)
{



    int i, j;
    for (i = 0; i < n-1; i++)


    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}

void insertionSort(int arr[], int n,int type)
{




	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void reverseArray(int arr[], int n){
   for (int low = 0, high = n - 1; low < high; low++, high--){
      swap(arr[low], arr[high]);
   }
}

int main()
{



    ofstream insertion,quick,bubble,selection;
    insertion.open("insertion1.csv");
    quick.open("quick1.csv");
    bubble.open("bubble1.csv");
    selection.open("selection1.csv");

    srand((unsigned) time(0));
    int randomNumber_len, randomNumber;
    time_t start_1, end_1,start_2, end_2,start_3, end_3,start_4, end_4;


    int len_arr[] = {20000};
    //int len_arr[] = {140000};
    int debug_len = 1;

    insertion<< "Length , Random , Sorted , Reverse Sorted\n";
    quick<< "Length , Random , Sorted , Reverse Sorted\n";
    bubble<< "Length , Random , Sorted , Reverse Sorted\n";
    selection<< "Length , Random , Sorted , Reverse Sorted\n";

     for (int i = 0; i < debug_len; i++)
     {


             randomNumber_len = len_arr[i];
             int arr[randomNumber_len],arr_s[randomNumber_len],arr_b[randomNumber_len],arr_q[randomNumber_len];

             cout << "\nLength of  random numbers = " << randomNumber_len << "\n";
             cout<< "Seq Type = Random";

             insertion << randomNumber_len << ",";
             selection << randomNumber_len << ",";
             quick << randomNumber_len << ",";
             bubble << randomNumber_len << ",";



             for (int index = 0; index < randomNumber_len; index++)
                {
                    randomNumber = (rand() % (randomNumber_len*10)) + 1;
                    arr[index]  = randomNumber;
                    arr_s[index]  = randomNumber;
                    arr_b[index]  = randomNumber;
                   arr_q[index]  = randomNumber;
                }

                cout << "(Insertion = ";
                //outfile << "(Insertion = ";
                clock_t t;
                t=clock();
                insertionSort(arr, randomNumber_len,1);
                t=clock()-t;
                double time_taken_1= ((double)t);
                cout << fixed  << time_taken_1 << setprecision(5) << "sec)\t";
                insertion << fixed << time_taken_1 << setprecision(5) << ",";

                cout << "(Selection = ";
                //outfile << "(Selection = ";
                t=clock();
                selectionSort(arr_s, randomNumber_len,4);
                t=clock()-t;
                double time_taken_2= ((double)t);
                cout << fixed << time_taken_2 << setprecision(5) << "sec)\t";
                selection << fixed << time_taken_2 << setprecision(5) << ",";

                cout << "(Quick = ";
                //outfile << "(Quick = ";
                t=clock();
                quickSort(arr_q, 0, randomNumber_len - 1);
                t=clock()-t;
                double time_taken_4= ((double)t);
                cout << fixed << time_taken_4 << setprecision(5) << "sec)\t";
                quick << fixed << time_taken_4 << setprecision(5) << ",";



                cout << "(Bubble = ";
                //outfile << "(Bubble = ";
                t=clock();
                bubbleSort(arr_b, randomNumber_len,4);
                t=clock()-t;
                double time_taken_3= ((double)t);
                cout << fixed << time_taken_3 << setprecision(5) << "sec)\t\n\n";
                bubble << fixed << time_taken_3 << setprecision(5) << ",";


                cout << "Seq Type = Sorted\n  ";



                cout << "(Insertion = ";
                //outfile << "(Insertion = ";
                t=clock();
                insertionSort(arr, randomNumber_len,1);
                t=clock()-t;
                 time_taken_1= ((double)t);
                cout << fixed << time_taken_1 << setprecision(5) << "sec)\t";
                insertion << fixed << time_taken_1 << setprecision(5) << ",";

                cout << "(Selection = ";
                //outfile << "(Selection = ";
                t=clock();
                selectionSort(arr_s, randomNumber_len,4);
                t=clock()-t;
                 time_taken_2= ((double)t);
                cout << fixed << time_taken_2 << setprecision(5) << "sec)\t";
                selection << fixed << time_taken_2 << setprecision(5) << ",";

                cout << "(Quick = ";
               // outfile << "(Quick = ";
                t=clock();
                quickSort(arr_q, 0, randomNumber_len-1);
                t=clock()-t;
                 time_taken_4= ((double)t);
                cout << fixed << time_taken_4 << setprecision(5) << "sec)\t";
                quick << fixed << time_taken_4 << setprecision(5) << ",";


                cout << "(Bubble = ";
                //outfile << "(Bubble = ";
                t=clock();
                bubbleSort(arr_b, randomNumber_len,4);
                t=clock()-t;
                 time_taken_3= ((double)t);
                cout << fixed << time_taken_3 << setprecision(5) << "sec)\t\n\n";
                bubble << fixed << time_taken_3 << setprecision(5) << ",";



                reverseArray(arr,randomNumber_len);

                copy_n(arr,randomNumber_len,arr_b);
                copy_n(arr,randomNumber_len,arr_s);
                copy_n(arr,randomNumber_len,arr_q);



                cout<< "Seq Type = Reverse Sorted\n  ";



                cout << "(Insertion = ";
                //outfile << "(Insertion = ";
                t=clock();
                insertionSort(arr, randomNumber_len,1);
                t=clock()-t;
                 time_taken_1= ((double)t);
                cout << fixed << time_taken_1 << setprecision(5) << "sec)\t";
                insertion << fixed << time_taken_1 << setprecision(5) << "\n";

                cout << "(Selection = ";
                //outfile << "(Selection = ";
                t=clock();
                selectionSort(arr_s, randomNumber_len,4);
                t=clock()-t;
                 time_taken_2= ((double)t);
                cout << fixed << time_taken_2 << setprecision(5) << "sec)\t";
                selection << fixed << time_taken_2 << setprecision(5) << "\n";

                 cout << "(Quick = ";
                //outfile << "(Quick = ";
                t=clock();
                quickSort(arr_q, 0, randomNumber_len-1);
                t=clock()-t;
                 time_taken_4= ((double)t);
                cout << fixed << time_taken_4 << setprecision(5) << "sec)\t";
                quick << fixed << time_taken_4 << setprecision(5) << "\n";

                cout << "(Bubble = ";
                //outfile << "(Bubble = ";
                t=clock();
                bubbleSort(arr_b, randomNumber_len,4);
                t=clock()-t;
                 time_taken_3= ((double)t);
                cout << fixed << time_taken_3 << setprecision(5) << "sec)\t\n\n";
                bubble << fixed << time_taken_3 << setprecision(5) << "\n";

         }


    insertion.close();
     selection.close();
      bubble.close();
       quick.close();

	return 0;
}

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

int partition (int arr[], int low, int high,int pivot_loc)
{
    int pivot;
    if(pivot_loc == 0)
    {
        //Fisrt pivot
         pivot = arr[low];
         int i = (low + 1);

    for(int j =low + 1; j <= high ; j++ )  {


          if ( arr[ j ] < pivot) {
                 swap (arr[ i ],arr [ j ]);
            i += 1;
        }
   }
   swap ( arr[ low ] ,arr[ i-1 ] ) ;  //put the pivot element in its proper place.
   return i-1;

    }
    else if (pivot_loc == 1)
    {
        //last pivot
         pivot = arr[high];
         int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }
     else if (pivot_loc == 2)
    {
       int i = low, j = high;

      int tmp;

      int pivot = arr[(low + high) / 2];



      while (i <= j) {

            while (arr[i] < pivot)

                  i++;

            while (arr[j] > pivot)

                  j--;

            if (i <= j) {

                  tmp = arr[i];

                  arr[i] = arr[j];

                  arr[j] = tmp;

                  i++;

                  j--;

            }

      };



      return i;

    }
    else if (pivot_loc = 3)
    {
        //Random pivot

        int random = low + rand( )%(high-low +1 ) ;
        swap ( arr[random] , arr[low]) ;
         pivot = arr[low];
         int i = (low + 1);

    for(int j =low + 1; j <= high ; j++ )  {


          if ( arr[ j ] < pivot) {
                 swap (arr[ i ],arr [ j ]);
            i += 1;
        }
   }
   swap ( arr[ low ] ,arr[ i-1 ] ) ;  //put the pivot element in its proper place.
   return i-1;


    }


}

//quicksort algorithm
void quickSort(int arr[], int low, int high,int pivot_loc)
{
    if (low < high)
    {
        //partition the array
        int pivot = partition(arr, low, high,pivot_loc);

        //sort the sub arrays independently
        quickSort(arr, low, pivot - 1,pivot_loc);
        quickSort(arr, pivot + 1, high,pivot_loc);
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



    ofstream quick_low,quick_last,quick_mid,quick_ran;

    quick_low.open("quick_low1.csv");
    quick_mid.open("quick_mid1.csv");
    quick_ran.open("quick_ran1.csv");
    quick_last.open("quick_last1.csv");


    srand((unsigned) time(0));
    int randomNumber_len, randomNumber;
    time_t start_1, end_1,start_2, end_2,start_3, end_3,start_4, end_4;


    int len_arr[] = {10,100,1000,10000,20000,50000,80000,100000};
    //int len_arr[] = {140000};
    int debug_len = 8;


    quick_last<< "Length , Random , Sorted , Reverse Sorted\n";
    quick_low<< "Length , Random , Sorted , Reverse Sorted\n";
    quick_mid<< "Length , Random , Sorted , Reverse Sorted\n";
    quick_ran<< "Length , Random , Sorted , Reverse Sorted\n";


     for (int i = 0; i < debug_len; i++)
     {


             randomNumber_len = len_arr[i];
             int arr[randomNumber_len],arr_q_low[randomNumber_len],arr_q_mid[randomNumber_len],arr_q_last[randomNumber_len],arr_q_ran[randomNumber_len];

             cout << "\nLength of  random numbers = " << randomNumber_len << "\n";
             cout<< "Seq Type = Random";


             quick_last << randomNumber_len << ",";
             quick_low << randomNumber_len << ",";
             quick_mid << randomNumber_len << ",";
             quick_ran << randomNumber_len << ",";




             for (int index = 0; index < randomNumber_len; index++)
                {
                    randomNumber = (rand() % (randomNumber_len*10)) + 1;

                    arr_q_low[index]  = randomNumber;
                    arr_q_last[index]  = randomNumber;
                    arr_q_mid[index]  = randomNumber;
                    arr_q_ran[index]  = randomNumber;
                }



                cout << "(Quick_low = ";
                clock_t t =clock();
                quickSort(arr_q_low, 0, randomNumber_len - 1,0);
                t=clock()-t;
                double time_taken_4= ((double)t);
                cout << fixed << time_taken_4 << setprecision(5) << "sec)\t";
                quick_low << fixed << time_taken_4 << setprecision(5) << ",";

                cout << "(Quick_mid = ";
                 t =clock();
                quickSort(arr_q_mid, 0, randomNumber_len - 1,2);
                t=clock()-t;
                 time_taken_4= ((double)t);
                cout << fixed << time_taken_4 << setprecision(5) << "sec)\t";
                quick_mid << fixed << time_taken_4 << setprecision(5) << ",";

                cout << "(Quick_last = ";
                 t =clock();
                quickSort(arr_q_last, 0, randomNumber_len - 1,1);
                t=clock()-t;
                 time_taken_4= ((double)t);
                cout << fixed << time_taken_4 << setprecision(5) << "sec)\t";
                quick_last << fixed << time_taken_4 << setprecision(5) << ",";

                cout << "(Quick_ran = ";
                 t =clock();
                quickSort(arr_q_ran, 0, randomNumber_len - 1,3);
                t=clock()-t;
                 time_taken_4= ((double)t);
                cout << fixed << time_taken_4 << setprecision(5) << "sec)\t";
                quick_ran << fixed << time_taken_4 << setprecision(5) << ",";





                cout << "Seq Type = Sorted\n  ";




                cout << "(Quick_low = ";

                t=clock();
                quickSort(arr_q_low, 0, randomNumber_len-1,0);
                t=clock()-t;
                 time_taken_4= ((double)t);
                cout << fixed << time_taken_4 << setprecision(5) << "sec)\t";
                quick_low << fixed << time_taken_4 << setprecision(5) << ",";

                cout << "(Quick_mid = ";

                t=clock();
                quickSort(arr_q_mid, 0, randomNumber_len-1,2);
                t=clock()-t;
                 time_taken_4= ((double)t);
                cout << fixed << time_taken_4 << setprecision(5) << "sec)\t";
                quick_mid << fixed << time_taken_4 << setprecision(5) << ",";

                cout << "(Quick_last = ";

                t=clock();
                quickSort(arr_q_last, 0, randomNumber_len-1,1);
                t=clock()-t;
                 time_taken_4= ((double)t);
                cout << fixed << time_taken_4 << setprecision(5) << "sec)\t";
                quick_last << fixed << time_taken_4 << setprecision(5) << ",";

                cout << "(Quick_ran = ";

                t=clock();
                quickSort(arr_q_ran, 0, randomNumber_len-1,3);
                t=clock()-t;
                 time_taken_4= ((double)t);
                cout << fixed << time_taken_4 << setprecision(5) << "sec)\t";
                quick_ran << fixed << time_taken_4 << setprecision(5) << ",";







                reverseArray(arr_q_low,randomNumber_len);
                copy_n(arr_q_low,randomNumber_len,arr_q_mid);
                copy_n(arr_q_low,randomNumber_len,arr_q_last);
                copy_n(arr_q_low,randomNumber_len,arr_q_ran);



                cout<< "Seq Type = Reverse Sorted\n  ";






                cout << "(Quick_low = ";

                t=clock();
                quickSort(arr_q_low, 0, randomNumber_len-1,0);
                t=clock()-t;
                 time_taken_4= ((double)t);
                cout << fixed << time_taken_4 << setprecision(5) << "sec)\t";
                quick_low << fixed << time_taken_4 << setprecision(5) << "\n";

                cout << "(Quick_mid = ";

                t=clock();
                quickSort(arr_q_mid, 0, randomNumber_len-1,2);
                t=clock()-t;
                 time_taken_4= ((double)t);
                cout << fixed << time_taken_4 << setprecision(5) << "sec)\t";
                quick_mid << fixed << time_taken_4 << setprecision(5) << "\n";

                cout << "(Quick_last = ";

                t=clock();
                quickSort(arr_q_last, 0, randomNumber_len-1,1);
                t=clock()-t;
                 time_taken_4= ((double)t);
                cout << fixed << time_taken_4 << setprecision(5) << "sec)\t";
                quick_last << fixed << time_taken_4 << setprecision(5) << "\n";

                cout << "(Quick_ran = ";

                t=clock();
                quickSort(arr_q_ran, 0, randomNumber_len-1,3);
                t=clock()-t;
                 time_taken_4= ((double)t);
                cout << fixed << time_taken_4 << setprecision(5) << "sec)\t";
                quick_ran << fixed << time_taken_4 << setprecision(5) << "\n";




         }



       quick_low.close();
       quick_last.close();
       quick_mid.close();
       quick_ran.close();

	return 0;
}

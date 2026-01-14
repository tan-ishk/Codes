#include <iostream>
using namespace std;

// most important function, understand carefully
int partition(int* array, int s, int e){

    // pivot declaration
    int p = array[s];

    // less than p
    int count_less_than_p = 0;

    // counting less than p
    for (int i = s+1; i <= e; i++){
        count_less_than_p++;
    }
    
    // pivot index
    int pivot_index = s+count_less_than_p;

    // give the right position
    swap(array[pivot_index],array[s]);

    //  counting greater than p
    int count_greater_than_p = e-s-count_less_than_p;

    // arrrange the array
    int i = s;
    int j = e;
    while (i<pivot_index && j>pivot_index){

    if (array[i] <= array[pivot_index]){
        i++;
    }
    else if (array[j]>array[pivot_index]){
        j--;
    }
    else if (array[i]>array[pivot_index] && array[j]<array[pivot_index]){
        swap(array[i],array[j]);
        i++;
        j--;
    }
    

    }
}

void quick_sort(int* array, int s, int e){

    // base case
    if (s >= e){
        return;
    }

    int p = partition(array, s, e);

    // left part
    quick_sort(array, s, p-1);

    // right part
    quick_sort(array, p+1, e);
}

int main(){
    cout<<"Enter the number of elements of array : ";
    int n;
    cin>>n;
    int *array = new int [n];
    cout<<"Enter the elements of the array : ";
    for (int i = 0; i < n; i++){
        cin>>array[i];
    }
    cout<<"The sorted array is : "<<endl;

    quick_sort(array, 0, n-1);

    for (int i = 0; i < n; i++){
        cout<<array[i]<<" ";
    }

    return 0;
}
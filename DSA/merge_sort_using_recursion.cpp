#include <iostream>
using namespace std;

// This function is most imiportant see this carefully
void merge (int *arr, int s, int e){

    int m = s + (e-s)/2;
    
    int length_1 = m-s+1;
    int length_2 = e-m;

    int *array_1 = new int [length_1];
    int *array_2 = new int [length_2];

    int main_array_index = s;

    for (int i = 0; i < length_1; i++){
        array_1 [i] = arr[main_array_index++]; 
    }
    
    main_array_index = m+1;
    for (int i = 0; i < length_2; i++){
        array_2 [i] = arr[main_array_index++]; 
    }
    
    int index1 = 0; 
    int index2 = 0; 
    main_array_index = s;

    // sort the array
    while (index1<length_1 && index2<length_2){
        if (array_1[index1]<array_2[index2]){
            arr[main_array_index++] = array_1[index1++];
        }
        else {
            arr[main_array_index++] = array_2[index2++];
        }
    }

    //if one array's length is larger than the other
    while (index1<length_1){
        arr[main_array_index++] = array_1[index1++];
    }

    // The second one cant be larger in length, so comment out
    // while (index2<length_2){
    //     arr[main_array_index++] = array_2[index2++];
    // }
    
    delete []array_1;
    delete []array_2;
}

void merge_sort (int *arr, int s, int e){

    int m = s + (e-s)/2;

    //base case
    if (s>=e){
        return;
    }

    // left part
    merge_sort(arr, s, m);

    // Right part
    merge_sort(arr, m+1, e);

    //function
    merge(arr, s, e);
    
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

    merge_sort(array, 0, n-1);

    for (int i = 0; i < n; i++){
        cout<<array[i]<<" ";
    }

    return 0;
}
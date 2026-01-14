#include<iostream>
using namespace std;

class Heap{
public:
    int* arr;
    int size;

    Heap(){
        size = 0;
        arr = new int [100];
        arr[0] = -1;
    }

    void insert(int val){
        
        size++;
        int index = size;
        arr[index] = val;
        
        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void remove(){
        if(size == 0){
            cout<<"fuck off! ";
            return;
        }

        arr[1] = arr[size];
        size--;

        int index = 1;
        while(index <= size/2){
            int left = index*2;
            int right = index*2 + 1;
            int largest = index;

            if(left <= size && arr[largest] < arr[left]){
                // swap(arr[left], arr[index]);
                largest = left;
            }
            if(right <= size && arr[largest] < arr[right]){
                // swap(arr[right], arr[index]);
                largest = right;
            }

            if(largest != index){
                swap(arr[largest], arr[index]);
                index = largest;
            }
            else{
                break;
            }
        }
    }

    void Display(){
        cout<<"printing the array : ";
        for (int i = 1; i <= size; i++){
            cout<<arr[i]<<" ";
        }
    }
};

void heapify(int arr[], int n, int index){
    int left = index * 2;
    int right = index * 2 + 1;
    int largest = index;

    if(left <= n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right <= n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != index){
        swap(arr[index], arr[largest]);
        heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int n){

    int size = n;

    while(size > 1){
        heapify(arr, size, 1);
        swap(arr[size], arr[1]);
        size--;
    }
}

int main(){
    // Heap* heap = new Heap();
    // heap->insert(55);
    // heap->insert(40);
    // heap->insert(50);
    // heap->insert(10);
    // heap->insert(30);

    // heap->Display();

    // heap-> remove();

    // cout<<"\n";
    // heap->Display();

    // heap-> remove();

    // cout<<"\n";
    // heap->Display();

    // int arr[] = {-1, 54, 53, 55, 52, 50};
    // int index = 2;
    // while(index > 0){
    //     heapify(arr, 5, index);
    //     index--;
    // }
    // for(int i = 1;i < 6; i++){
    //     cout<<arr[i]<<" ";
    // }

    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    HeapSort(arr, 5);

    for(int i = 1;i < 6; i++){
        cout<<arr[i]<<" ";
    }
}
#include<iostream>
using namespace std;

const int max_size = 10;

void InputArr(int arr[],int size){
    if(size > max_size){
        return;
    }
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
}

void DisplayArr(int arr[],int size){
    cout << "------------------------------\n";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << "\n------------------------------\n";
}


void SelectionSort(int arr[],int size){
    for(int i = 0; i < size-1; i++){
        int min = i;
        for(int j = i+1; j < size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }

    }
}

void InsertionSort(int arr[],int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i-1;
        while (j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void BubbleSort(int arr[],int size){
    for(int i = 0; i < size ; i++){
        bool swapped = false;
        for(int j = 0; j < size - i -1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}



int main(){
    int size;
    cout << "Enter size of array : ";
    cin >> size;


    int arr1[max_size],arr2[max_size],arr3[max_size],arr4[max_size],arr5[max_size];

    cout << "Enter Array 1" << endl;
    InputArr(arr1,size);
    cout << "Enter Array 2" << endl;
    InputArr(arr2,size);
    cout << "Enter Array 3" << endl;
    InputArr(arr3,size);
    cout << "Enter Array 4" << endl;
    InputArr(arr4,size);
    cout << "Enter Array 5" << endl;
    InputArr(arr5,size);
    
    SelectionSort(arr1,size);
    cout << "SELECTION SORT\n";
    DisplayArr(arr1,size);

    InsertionSort(arr2,size);
    cout << "INSERTION SORT\n";
    DisplayArr(arr2,size);

    BubbleSort(arr3,size);
    cout << "BUBBLE SORT\n";
    DisplayArr(arr3,size);

    MergeSortRecursive(arr4,0,size-1);
    cout << "MERGE SORT\n";
    DisplayArr(arr4,size);

    QuickSort(arr5,0,size-1);
    cout << "QUICK SORT\n";
    DisplayArr(arr5,size);

    return 0;
}

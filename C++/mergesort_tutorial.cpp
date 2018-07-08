// First attempt at merge sort
#include <iostream>
#include <vector>
using namespace std;

// Merges two sublists of data[]
// First sublist is data[left..mid]
// Second sublist is data[mid+1..right]
void merge(vector<int>& data, int left, int mid, int right)
{
    int i = 0; // initial index of the first sublist
    int j = 0; // initial index of the second sublist
    int k = left; //initial index of the third sublist
    
	int size1 = (mid - left) + 1; // size for temp list data_L[]
	int size2 = right - mid; // size for temp list data_R[]
    
	// create two temporary lists data_L[] and data_R[]
    vector<int> data_L;
    vector<int> data_R;

    // copy data into data_L[] and data_R[]
    for (int a = 0; a < size1; a++)
        data_L.push_back(data[left+a]);
    for (int b = 0; b < size2; b++)
        data_R.push_back(data[(mid+1)+b]);

    // merge the temp lists back into data[left..right]
    while (i < size1 && j < size2)
    {
        // one of these (data_L[] or data_R[]) will be exhausted before the other
        if (data_L[i] <= data_R[j])
        {
            data[k] = data_L[i];
            i++;
        }
        else
        {
            data[k] = data_R[j];
            j++;
        }

        k++;
    }

    // Copy the remaining elements, if any, of data_L[]
    while (i < size1)
    {
        data[k] = data_L[i];
        i++;
        k++;
    }

    // Copy the remaining elements, if any, of data_R[]
    while (j < size2)
    {
        data[k] = data_R[j];
        j++;
        k++;
    }
}

// Recursive Merge Sort function
void mergeSort(vector<int>& data, int left, int right)
{
    if (left < right)
    {
        // int mid = (left-right)/2;
        int mid = left + (right-left)/2; // avoids overflow when left, right are too large

        mergeSort(data, left, mid); // sort the lower part
        mergeSort(data, mid+1, right); // sort the upper part

        merge(data, left, mid, right);
    }
}

// Function to print the data
void printData(vector<int>& data)
{
    for (int i = 0; i < data.size(); i++)
        cout << "[" << i << "]\t" << data[i] << endl;
    cout << endl;
}

int main()
{
    vector<int> v {56,7,4,12,30,63,87,112,98,1,42,55,29,49,70};
    
    cout << "Given data is:" << endl;
    printData(v);

    mergeSort(v, 0, v.size()-1);

    cout << "Sorted data is:" << endl;
    printData(v);
}
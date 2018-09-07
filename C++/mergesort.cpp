// mergesort.cpp
#include <iostream>
#include <vector>

// Merges two sublists of data in ascending order
template <typename T>
void merge(std::vector<T>& data, unsigned int left, unsigned int mid, unsigned int right) {
    unsigned int i = 0; // Initial index of the first sublist
    unsigned int j = 0; // Initial index of the second sublist
    unsigned int k = left; // Initial index of the merged sublist

    unsigned int size1 = (mid - left) + 1; // Size for temp list data_L
    unsigned int size2 = right - mid; // Size for temp list data_R

    // Create two temporary lists data_L and data_R
    std::vector<T> data_L;
    std::vector<T> data_R;

    // Copy data into data_L and data_R
    for (unsigned int a = 0; a < size1; a++)
        data_L.push_back(data[left + a]);
    for (unsigned int b = 0; b < size2; b++)
        data_R.push_back(data[(mid + 1) + b]);

    // Merge the temp lists back into data
    while (i < size1 && j < size2)
    {
        // One of these (data_L or data_R) will be exhausted before the other
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

    // Copy the remaining elements, if any, of data_L
    while (i < size1)
    {
        data[k] = data_L[i];
        i++;
        k++;
    }

    // Copy the remaining elements, if any, of data_R
    while (j < size2)
    {
        data[k] = data_R[j];
        j++;
        k++;
    }
}

// Recursive Merge Sort function
template <typename T>
void mergeSort(std::vector<T>& data, unsigned int left, unsigned int right)
{
    if (left < right)
    {
        // unsigned int mid = (left - right) / 2
        unsigned int mid = left + (right - left)/2; // Avoids overflow when left or right are too large
        
        mergeSort(data, left, mid); // Sort the lower part
        mergeSort(data, mid + 1, right); // Sort the upper part

        merge(data, left, mid, right);
    }
}

// Print data list
template <typename T>
void printData(std::vector<T>& data) {
    for (unsigned int i = 0; i < data.size(); i++)
        std::cout << "[" << i << "]\t" << data[i] << "\n";
    
    std::cout << std::endl;
}



int main() {
    std::vector<int> vect{ 56,7,4,12,30,63,87,112,98,1,42,55,29,49,70 };

    std::cout << "Given data is : \n";
    printData(vect);

    mergeSort(vect, 0, vect.size() - 1);

    std::cout << "Sorted data is : \n";
    printData(vect);

    return 0;
}

#include "Quicksort.h"
#include <iostream>
#include<string>

using namespace std;

template <typename T>
void quicksort(T[], int, int);
template <typename T>
void show(T[], int,int);
template <typename T>
void swapElements(T a[], int first, int last);
template <typename T>
int partition(T a[], int first, int last);

int main()
{
    //for integer
    int a[5] = { 5,4,3,2,1 };
    cout << "Previous partition is "<<endl;
    show(a, 0, 4);
    quicksort(a, 0, 4);
    cout << "\nLater partiton is " << endl;
    show(a, 0, 4);
    cout << "\n";

    //for char
    char cha[5] = { 'B','D','F','A','C' };
    cout << "Previous partition is " << endl;
    show(cha, 0, 4);
    quicksort(cha, 0, 4);
    cout << "\nLater partiton is " << endl;
    show(cha, 0, 4);
    cout << "\n";

    //for double
    double b[5] = { 3.4,5.2,7.5,4.3,8.6 };
    cout << "Previous partition is " << endl;
    show(b, 0, 4);
    quicksort(b, 0, 4);
    cout << "\nLater partiton is " << endl;
    show(b, 0, 4);
    cout << "\n";

    //for class CStudent
    CStudent arrCstu[5] = { CStudent(5),CStudent(4),CStudent(3),CStudent(2),CStudent(1) };
    cout << "Previous partition is " << endl;
    show(arrCstu, 0, 4);
    quicksort(arrCstu, 0, 4);
    cout << "\nLater partiton is " << endl;
    show(arrCstu, 0, 4);
    cout << "\n";
}
template <typename T>
void swapElements(T a[], int first, int last) {
    T temp;
    temp = a[last];
    a[last] = a[first];
    a[first] = temp;
}

template <typename T>
void quicksort(T a[], int first, int last)
{
    if (first >= last)
        return;
    
    // Otherwise, we’re in the recursive case.
   // The partition function uses the item in a[first] as the pivot
   // and returns the position of the pivot -- split -- after the partition.
    int split(partition(a, first, last));
    
    // Recursively, sort the two partitions.
    quicksort(a, first, split - 1);
    quicksort(a, split + 1, last);
    // postcondition: a is sorted in ascending order 
    // between first and last inclusive.
}

template <typename T>
int partition(T a[], int first, int last)
{
    int lastSmall(first), i;

    for (i = first + 1; i <= last; i++)
        // loop invariant: a[first+1]...a[lastSmall] <= a[first] &&
        //    a[lastSmall+1]...a[i-1] > a[first]
        if (a[i] <= a[first]) { // key comparison
            ++lastSmall;
            swapElements(a, lastSmall, i);
        }

    swapElements(a, first, lastSmall); // put pivot into correct position
    // postcondition: a[first]...a[lastSmall-1] <= a[lastSmall] &&
    //    a[lastSmall+1]...a[last] > a[lastSmall]
    return lastSmall; // this is the final position of the pivot -- the split index
}
template <typename T>
void show(T a[], int first, int last) {
    int i;
    for (i = first;i <= last;i++) {
        cout << a[i] << " ";
    }
}

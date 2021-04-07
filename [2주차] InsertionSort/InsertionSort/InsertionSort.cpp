// InsertionSort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include <typeinfo>

using namespace std;
void insertNextItem(int a[], int i); // in cx3-6.cpp
void insertionSort(int a[], int n);
int main()
{
    //입력을 받고
    int val;
    int nSize = 0;
    cout << "Insertion sort\n";
    cout << "입력될 integer의 개수: \n";
    cin >> nSize;
    int* pa = new int[nSize];
    int nInput;
    cout << "정수 입력: ";
    
    /*for (int i = 0;i < nSize;i++) {
        cin >> nInput;
        pa[i]=nInput;
    }*/
    for (int i = 0;i < nSize;i++) {
        if (typeid(nInput) ==typeid(5)) {
            cin >> nInput;
            pa[i] = nInput;
        }
        else {
            cout << "error";
            break;
        }
    }

    for (int i = 0;i < nSize;i++) {
        cout << pa[i] << "";
    }
    //insertion sort를 부르고
    insertionSort(pa, nSize) ;
    //출력을 한다
    cout << "\nInsertion Sort is ";
    for (int i = 0;i < nSize;i++) {
        cout << pa[i];
        cout << " ";
    }
    cout << "\n\n";
    
    return 0;
}

void insertNextItem(int a[], int i)
 {
     // Precondition: array a is sorted from 0 to i-1
         int newItem(a[i]), insertPos(i);
    for (; insertPos && newItem < a[insertPos - 1]; insertPos--)
         // Loop Invariant: newItem <= a[insertPos+1] .. a[i] &&
         // a[insertPos+1] .. a[i] are sorted
         a[insertPos] = a[insertPos - 1];
    a[insertPos] = newItem;
     // Postcondition: array a is sorted from 0 to i
      
}

void insertionSort(int a[], int n)
{
    // Precondition: a is an array with subscripts ranging from 0 to n - 1
    int i;
    for (i = 1; i < n; i++)
        // Loop invariant: items in range from 0 to i-1 are sorted;
    // items from i to n-1 have not yet been examined.
        insertNextItem(a, i); // see cx3-6.cpp
    // Postcondition: array a is sorted
    
}

//for (int i = 0;i < nSize;i++) {
//    if (typeid(nInput) == "int") {
//        cin >> nInput;
//        pa[i] = nInput;
//    }
//    else {
//        cout << "error";
//        break;
//    }
//}
//for (int i = 0;i < nSize;i++) {
//    cin >> nInput;
//    pa[i] = nInput;
//}
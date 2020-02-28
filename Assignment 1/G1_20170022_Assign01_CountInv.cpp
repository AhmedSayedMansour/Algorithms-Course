// GROUP:   G1
// ID:      20170022
// Assign:  04
// Assign:  CountInv
// UVA:     10810
// Name:    Ahmed Sayed Mansour

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
long long a[500001];
long long CountInvMerge(long long* a, int n);
long long CountInv(long long* a, int n);
long long  mergeSort(long long* a,int left , int right);
void print(long long* a,int n);
long long  merge(long long *a ,int l ,int m ,int r);

////////////////////////////////////////////////////////////////////////////////////////////////////////////

long long CountInvMerge(long long* a, int n){
    return mergeSort(a,0,n-1);
}

long long CountInv(long long* a, int n){
    long long count = 0;
    for(int i=0 ;i < n-1 ;++i){
        for (int j=i+1 ; j<n;++j){
            if(a[i]>a[j])   count++;
        }
    }
    return count;
}

long long mergeSort(long long* a,int left , int right){
    long long count = 0;
    if (left<right){
        int mid = (left+right)/2;
        count +=mergeSort(a,left,mid);
        count +=mergeSort(a,mid+1,right);

        count +=merge(a,left,mid,right);
    }
    return count;
}

long long merge(long long *a ,int l ,int m ,int r){
    int size1 = m-l+1;
    int size2 = r-m;
    long long count = 0;
    long long leftArr[size1],rightArr[size2];
    for(int i=0; i<size1;i++){
        leftArr[i]=a[i+l];
    }
    for(int i=0; i<size2;i++){
        rightArr[i]=a[i+m+1];
    }
    int i=0,j=0,k=l;
    while(i<size1 && j<size2){
        if (leftArr[i] <= rightArr[j]){
            a[k] = leftArr[i];
            i++;
        }
        else{
            a[k] = rightArr[j];
            count = count + (m+1 - i-l);
            j++;
        }
        k++;
    }
    while (i < size1)
        a[k++] = leftArr[i++];
    while (j < size2)
        a[k++] = rightArr[j++];

    return count;
}

void print(long long* a,int n){
    for(int i=0;i<n;++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    while(scanf("%d", &n), n) {
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        cout<<CountInvMerge(a, n)<<endl;
        //print(a,n);
    }
//    cout<<"--------------------"<<endl;
//    long long a0[] = {9,1,0,5,4};
//    long long a1[] = {1 ,3 ,5 ,2,4,6};
//    long long a2[] = {1 ,2 ,3};
//    long long a3[] = {1,20,6,4,5};
//    cout<<CountInv(a2 ,sizeof(a2) / sizeof(a2[0]))<<endl;
//    cout<<CountInvMerge(a2,sizeof(a2)/sizeof(a2[0]))<<endl;
//    print(a2,3);
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

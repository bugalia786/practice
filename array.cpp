#include <iostream>
using namespace std;

template<class T>
class array{
private:
    T *A;
    int size;
    int length;
    void swap(T &a,T &b);
public:
    array(){
        size=10;
        length=0;
        A=new int[size];
    }
    array(int sz){
        size=sz;
        length=0;
        A=new int[size];
    }
    ~array(){
        delete []A;
    }
    void Display();
    void Append(T x);
    void Insert(int index,T x);
    int LinearSearch(T key);
    int BinarySearch(T key);
    T Get(int index);
    void set(int index,T x);
    T max();
    T min();
    T sum();
    float avg();
    void reverse();
    void reverse1();
    void Insertsort(T x);
    int issorted();
    array* Merge(array arr2);
    array* Union(array arr2);
    array* Difference(array arr2);
};
template<class T>
void array<T>::swap(T &a,T &b){
    T temp=a;
    a=b;
    b=temp;
}
template<class T>
void array<T>::Display(){
    for(int i=0;i<length;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

template<class T>
void array<T>::Append(T x){
    A[length]=x;
    length++;
}

template<class T>
void array<T>::Insert(int index,T x){
    if(index>=0 && index<=length){
    for(int i=length;i>index;i--){
        A[i]=A[i-1];
    }
    }
    A[index]=x;
    length++;
}

template<class T>
int array<T>::LinearSearch(T key){
    for(int i=0;i<length;i++){
        if(A[i]==key){
            cout<<"Yes we found it"<<endl;
            return i;
        }
    }
    cout<<"Sorry we couldn't find it"<<endl;
    return -1;
}
template<class T>
int array<T>::BinarySearch(T key){
    int l=0;
    T mid;
    int h=length;
    while(l<h){
        mid=(l+h)/2;
        if(A[mid]==key){
            cout<<"Yes we found it"<<endl;
            return mid;
        }
        else if(A[mid]>key) h=mid-1;
        else l=mid+1;
    }
    cout<<"Sorry we couldn't find it"<<endl;
    return -1;
}

template<class T>
T array<T>::Get(int index){
    if(index>=0 && index<length){
        return A[index];
    }
}

template<class T>
void array<T>::set(int index,T x){
    if(index>=0 && index<length){
        A[index]=x;
    }
}

template<class T>
T array<T>::max(){
    T max=A[0];
    for(int i=0;i<length;i++){
        if(A[i]>max)
        max=A[i];
    }
    return max;
}

template<class T>
T array<T>::min(){
    T min=A[0];
    for(int i=0;i<length;i++){
        if(A[i]<min)
        min=A[i];
    }
    return min;
}

template<class T>
T array<T>::sum(){
    T sum=0;
    for(int i=0;i<length;i++){
        sum+=A[i];
    }
    return sum;
}
template<class T>
float array<T>::avg(){
    float sum=0;
    for(int i=0;i<length;i++){
        sum+=A[i];
    }
    return sum/length;
}
template<class T>
void array<T>::reverse(){
    T B[length];
    for(int i=length-1,j=0;i>=0;i--,j++){
        B[j]=A[i];
    }
    for(int i=0;i<length;i++){
        A[i]=B[i];
    }
}

template<class T>
void array<T>::reverse1(){
    int i=0;
    int j=length-1;
    while(i<j){
        swap(A[i],A[j]);
        i++;
        j--;
    }
}

template<class T>
void array<T>::Insertsort(T x){
    int i=length-1;
    while(A[i]>x){
        A[i+1]=A[i];
        i--;
    }
    A[i+1]=x;
    length++;
}

template<class T>
int array<T>::issorted(){
    for(int i=0;i<length-1;i++){
        if(A[i+1]<A[i]){
            cout<<"it's not sorted"<<endl;
            return -1;
        }
    }
    cout<<"it's sorted"<<endl;
    return 1;
}
template<class T>
array<T>* Merge(array<T> *arr1,array<T> *arr2){
    int i,j,k;
    i=j=k=0;
    array<T> *arr3=new array<T>[arr1.length+arr2.length];
    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i]<arr2.A[j]){
            arr3->A[k++]=arr1.A[i++];
        }else{
            arr3->A[k++]=arr2.A[j++];
        }
    }
    for(;i<arr1.length;i++){
        arr3->A[k++]=arr1.A[i];
    }
    for(;j<arr2.length;j++){
        arr3->A[k++]=arr2.A[j];
    }
    return arr3;
}
template<class T>
array<T>* Union(array<T> *arr1,array<T> *arr2){
    int i,j,k;
    i=j=k=0;
    array<T> *arr3=new array<T>[arr1.length+arr2.length];
    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i]<arr2.A[j]){
            arr3->A[k++]=arr1.A[i++];
        }else if(arr1.A[i]>arr2.A[j]){
            arr3->A[k++]=arr2.A[j++];
        }else{
            arr3->A[k++]=arr1.A[i++];
            j++;
        }
    }
    for(;i<arr1.length;i++){
        arr3->A[k++]=arr1.A[i];
    }
    for(;j<arr2.length;j++){
        arr3->A[k++]=arr2.A[j];
    }
    arr3->length=k;
    return arr3;
}
template<class T>
array<T>* Difference(array<T> *arr1,array<T> *arr2){
     int i,j,k;
    i=j=k=0;
    array<T> *arr3=new array<T>[arr1.length+arr2.length];
    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i]<arr2.A[j]){
            arr3->A[k++]=arr1.A[i++];
        }else if(arr1.A[i]>arr2.A[j]){
            j++;
        }else{
            i++;
            j++;
        }
    }
    for(;i<arr1.length;i++){
        arr3->A[k++]=arr1.A[i];
    }
    arr3->length=k;
    return arr3;
}

int main() {
	array<int> arr1(5);
	int x, index;
	array<int> arr2(3);
    arr2.Append(2);
    arr2.Append(10);
    arr2.Append(11);
	arr1.Append(2);
	arr1.Append(3);
	arr1.Append(4);
	arr1.Append(7);
	arr1.Display();
	arr1.Insert(3,6);
	arr1.Display();
	arr1.LinearSearch(6);
	arr1.LinearSearch(8);
	arr1.BinarySearch(2);
	arr1.BinarySearch(8);
	cout<<arr1.Get(3)<<endl;
	arr1.set(0,1);
	arr1.Display();
	cout<<"Max = "<<arr1.max()<<endl;
	cout<<"Min = "<<arr1.min()<<endl;
	cout<<"Sum = "<<arr1.sum()<<endl;
	cout<<"Avg = "<<arr1.avg()<<endl;
	arr1.reverse();
	arr1.Display();
	arr1.reverse1();
	arr1.Display();
	arr1.Insertsort(5);
	arr1.Display();
	arr1.issorted();
	
	return 0;
}

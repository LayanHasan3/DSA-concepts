#include <iostream>
using namespace std;
struct maxheap{
    int arr[5];
    int size;
};
void heapifyup(maxheap &heap, int index)
{
    while(index>0)
    {
        int parent= (index-1)/2;
        if(heap.arr[parent]>heap.arr[index])
        {
            swap(heap.arr[parent], heap.arr[index]);
            index=parent;
        }
        else{
            break;
        }
    }
}
void insert(maxheap &heap, int value)
{
    if(heap.size>=5)
    {
        cout<<"heap is full";
        return;
    }
    heap.arr[heap.size]=value;
    heapifyup(heap, heap.size);
    heap.size++;
}
void heapifydown(maxheap &heap, int index)
{
    int lchild,rchild,maxindex;
    while(index<heap.size){
        lchild=2*index+1;
        rchild=2*index+2;
        maxindex=index;
        if(lchild<heap.size && heap.arr[lchild]< heap.arr[maxindex])
        {
            maxindex=lchild;
        }
        if(rchild<heap.size && heap.arr[rchild]< heap.arr[maxindex])
        {
              maxindex=rchild;
        }
        if(maxindex!=index)
        {
            swap(heap.arr[index], heap.arr[maxindex]);
            index=maxindex;
        }
        else
        {
            break;
        }
    }
}
void Delete(maxheap &heap, int index)
{
    if(index < 0 || index >= heap.size)
    {
        cout<<"index out of bounds "<<endl;
    }
    cout<<"deleting value: "<<heap.arr[index]<< endl;
    swap(heap.arr[index],heap.arr[heap.size-1]);
    heap.size--;
    heapifydown(heap, index);
}
void display(maxheap &heap) {
    cout << "Max Heap array: ";
    for (int i = 0; i < heap.size; i++) {
        cout << heap.arr[i] << " ";
    }
    cout << endl;
}

    int main() {
    maxheap heap;
    heap.size = 0;

    int n, val;
    cout << "Enter number of elements to insert in Max Heap: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> val;
        insert(heap, val);
    }
    display(heap);
    int delindex;
    cout<<"enter index to delete: ";
    cin>>delindex;
    Delete(heap, delindex);
    display(heap);
    return 0;
}
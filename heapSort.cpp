#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void adjust(int *a,int n);

void createHeap(int *a, int size)
{
    for(int i = (size-1)/2;i>=0;i--)
        adjust(a,i);
}

int getMax(int *a)
{
    return a[0];
}

int getMin(int *a)
{

}

void show(int *a, int n)
{
    for(int i = 0; i < (n-1)/2; i++)
    {
        cout<<a[i]<<","<<a[2*i+1]<<","<<a[2*i+2]<<endl;
    }

}

void adjust(int *a, int n)
{
    int i = n;
    for(;i >=0; i=(i-1)/2)
    {
        if(2*i+1 < n&&a[2*i+1] > a[i])
            swap(a[2*i+1],a[i]);

        if(2*i+2 < n&&a[2*i+2] > a[i])
            swap(a[2*i+2],a[i]);
        if(i==0)
            break;
    }
}

int main(void)
{
    int a[3]={4,3,7};
    adjust(a,3);
    for(int i=0;i<3;i++)
        cout<<a[i]<<endl;
    return 0;
}

int a(void)
{
    int a[10];
    srand(time(NULL));
    cout<<"Original array is : "<<endl;
    for(int i = 0; i < 10;i++)
    {
        a[i] = rand()%10+1;
        cout<<a[i]<<endl;
    }
    createHeap(a,9);
    cout<<"after adjusted:"<<endl;
    for(int i = 0; i < 10; i++)
        cout<<a[i]<<endl;
    cout<<"the max is :"<<a[0]<<endl;
    show(a,10);
    return 0;
}

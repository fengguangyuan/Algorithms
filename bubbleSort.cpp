#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void bubbleSort(int *a, int n)
{
  for(int i = 0; i < n - 1;i++)
	for(int j = 0; j < n - i - 1;j++)
		if(a[j]>a[j+1])
			swap(a[j],a[j+1]);
}

int main() {
	cout<<"Hello"<<endl;
  	int *a = new int[10];
  	srand(time(NULL));
  	for(int i = 0; i < 10;i++)
	  cout<<(a[i] = rand()%10)<<",";
  	cout<<endl;
  	bubbleSort(a,10);
  	for(int i = 0; i < 10;i++)
  	cout<<a[i]<<",";
	cout<<endl;
	return 0;
}

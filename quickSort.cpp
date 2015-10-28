#include <iostream>
using namespace std;

void quickSort(int *a, int l, int h)
{
  if(l>h) return;
  int left = l;
  int right = h;
  int temp = a[h];
  while(left < right)
  {
	while(left<right&&a[left]<=temp)
	  left++;
	if(left<right)
	  swap(a[left],a[right]);
	while(left<right&&a[right]>=temp)
	  right--;
	if(left<right)
	  swap(a[left],a[right]);
	}
   	a[left] = temp;
    quickSort(a,l,right-1);
	quickSort(a,right+1,h);
}

int main() {
  int a[]={2,5,57,23,4,6,12,46,8};
  quickSort(a,0,sizeof a/sizeof(int)-1);
	cout<<"Hello"<<endl;
  for(int i = 0; i< sizeof a/sizeof(int);i++)
	cout<<a[i]<<endl;
	return 0;
}

#include<cstdlib>
#include<iostream>
#include<ctime>


using namespace std;

//member function
void insertion_sort(int arr[],int len);
void print_array(int arr[],int len);
int * create_random_array(int number_elements);


int main()
{
// Creating a random array
int length;
cout<<"Enter the number of elements you want in the array \n";
cin>>length;
int * temp_array;
temp_array= create_random_array(length);

for (int i=0; i<length; i++)
cout<<temp_array[i]<<" ";
cout<<endl;

insertion_sort(temp_array,length);

// Free memory
delete[] temp_array;

}



// Function to create random array
int * create_random_array(int number_elements)
{
cout<<"Initialiazing array with a random seed"<<endl;
srand((unsigned)time(0));

int * temp_array;
temp_array = new int [number_elements];

for (int i=0; i<number_elements; i++)
temp_array[i] = (rand()%100)+1;

return temp_array;
}



void insertion_sort(int arr[],int length)
{

int i,j,key;
for (i=1; i<length ;i++)
{
 key = arr[i];
 j=i-1;
	 while(j>=0 && arr[j]>key)
	{
	arr[j+1]=arr[j];		
	j=j-1;
	}
arr[j+1]=key;

// Printing the sorted array at each iteration
print_array(arr,length);
}
}


void print_array(int arr[], int length)
{
cout<<"Sorting: ";

for (int i=0;i<length;i++)
{
cout<< arr[i] << " ";
}
cout<<endl;
}

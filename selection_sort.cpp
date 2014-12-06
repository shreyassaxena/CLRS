#include<cstdlib>
#include<iostream>
#include<ctime>



using namespace std;

//member function
void selection_sort(int arr[],int len);
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

	selection_sort(temp_array,length);

	// Free memory
	delete[] temp_array;

}



void selection_sort(int arr[],int length)
{
	cout<< "Performing slection sort"<<endl;

for (int i=0; i<length-1; i++)      // We donot have to check for the last element
{
    int key_min = arr[i];
    int index_min = i;

    for (int j=i+1; j<length; j++)
    {     
        if(arr[j] < arr[index_min] )
            index_min = j;
    }

    // Swaping the values
    arr[i] = arr[index_min];
    arr[index_min] = key_min;
    
    // Printing the sorted array at each iteration
    print_array(arr,length);

}






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


void print_array(int arr[], int length)
{
cout<<"Sorting: ";

for (int i=0;i<length;i++)
{
cout<< arr[i] << " ";
}
cout<<endl;
}

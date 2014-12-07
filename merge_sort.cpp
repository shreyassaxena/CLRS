#include<cstdlib>
#include<iostream>
#include<ctime>
#include<cmath>
#include<limits>

using namespace std;

//member function
void print_array(int arr[], int len);
int * create_random_array(int number_elements);
void test_merge();
void merge_sort(int arr[], int low, int high);
void merge_without_exhaustion_check(int arr[], int low, int mid, int high);
void merge(int arr[], int low, int mid, int high);

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


// Performing merge sort
cout<<"Performing Merge sort "<<endl;
merge_sort(temp_array,0,length-1);     // Indexing starts at zero

// Printing the sorted array
cout<<"The sorted array is "<<endl;
for (int i=0; i<length; i++)
cout<<temp_array[i]<<" ";
cout<<endl;

// Free memory
delete[] temp_array;

// Function to test merge
//test_merge();

}


//Merge sort definition
void merge_sort(int arr[], int low, int high)
{
if(low<high)
{
    int mid = floor((low+high)/2);         // Indexing starts at zero
    merge_sort(arr,low,mid);    
    merge_sort(arr,mid+1,high);
    // Merging the two sorted sequences
    merge(arr,low,mid,high);
}

}



// Function where we will check for array exhaustion
void merge(int arr[],int low, int mid, int high)
{
// Creating the temporary array L1 and L2
int n1 = mid-low+1;
int n2 = high-mid;

int * L1, * L2;

L1 = new int [n1];

for (int i=0; i<n1; i++)
    L1[i] = arr[low+i];        

L2 = new int [n2];
for (int j=0; j<n2; j++)
    L2[j] = arr[mid+j+1];        


// Printing the two array
cout<<"L1 is ";
print_array(L1,n1);
cout<<"L2 is ";
print_array(L2,n2);

// Comparing the two arrays and replacing the elements in the original array

int i=0;
int j=0;


for (int k=low; k<=high;k++)    // We iterate till the Rth index.
{
   if( L1[i] < L2[j] )
    {
        arr[k] = L1[i];
        i = i+1;
        
        // We can check if we have exhausted array L1
        if(i==n1)
        {
            while(j<n2)
            {
                k++;
                arr[k] = L2[j];
                j++;
            }
        }
    }
   else 
    {
        arr[k] = L2[j];
        j = j+1;

        // We can check if we have exhausted array L2
        if(j==n2)
        {
            while(i<n1)
            {
                k++;
                arr[k] = L1[i];
                i++;
            }
        }
 
    }
}

// Cleaning up memory
delete[] L1;
delete[] L2;


}

// Function to merge where we do not check for array exhaustion
void merge_without_exhaustion_check(int arr[],int low, int mid, int high)
{
// Creating the temporary array L1 and L2
int n1 = mid-low+1;
int n2 = high-mid;

int * L1, * L2;

L1 = new int [n1+1];

for (int i=0; i<n1; i++)
    L1[i] = arr[low+i];        

L2 = new int [n2+1];
for (int j=0; j<n2; j++)
    L2[j] = arr[mid+j+1];        

// Appending the big element in the end to avoid checking for array exhaustion
L1[n1] = numeric_limits<int>::max();
L2[n2] = numeric_limits<int>::max();


// Printing the two array
cout<<"L1 is ";
print_array(L1,n1+1);
cout<<"L2 is ";
print_array(L2,n2+1);

// Comparing the two arrays and replacing the elements in the original array

int i=0;
int j=0;


for (int k=low; k<=high;k++)    // We iterate till the Rth index.
{
   if( L1[i] < L2[j] )
    {
        arr[k] = L1[i];
        i = i+1;
    }
   else 
    {
        arr[k] = L2[j];
        j = j+1;
    }
}

// Cleaning up memory
delete[] L1;
delete[] L2;


}

// Function to test function merge with some predefined initializations
void test_merge()
{
int length = 5;
int temp_array [5] ={11,17,19,3,6};


for (int i=0; i<length; i++)
cout<<temp_array[i]<<" ";
cout<<endl;

int low = 0;
int high = length-1;
int mid = floor((low+high)/2);

merge_without_exhaustion_check(temp_array,low,mid,high);

print_array(temp_array,length);
}

// Function to create random array
int * create_random_array(int number_elements)
{
cout<<"Initialiazing array with fixed seed"<<endl;
// Setting seed 
srand(1);

int * temp_array;
temp_array = new int [number_elements];

for (int i=0; i<number_elements; i++)
temp_array[i] = (rand()%50)+1;

return temp_array;
}






void print_array(int arr[], int length)
{
for (int i=0;i<length;i++)
{
cout<< arr[i] << " ";
}
cout<<endl;
}

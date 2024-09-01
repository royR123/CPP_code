#include <bits/stdc++.h>
using namespace std;
void restoreUp(int arr[],int loc){
    int k = arr[loc];
    int par = loc/2;
    while(loc!=par && arr[par] < k){
        arr[loc] = arr[par];
        loc = par;
        par = loc/2;
    }
    arr[loc] = k;
}
void insert(int arr[],int el,int& cur_size){
    cur_size++;
    arr[cur_size] = el;
    restoreUp(arr,cur_size);
}
void restoreDown(int arr[],int h_size){
    int loc = 1;
    int left = 2*loc , right = 2*loc+1;
    int k = arr[loc];
    while(right <= h_size){
        if(k < arr[left] && k < arr[right]){
            if(arr[left] > arr[right]){
                arr[loc] = arr[left];
                loc = left;
            }else{
                arr[loc] = arr[right];
                loc = right;
            }
        }else if(k < arr[left]){
            arr[loc] = arr[left];
            loc = left;
        }else if(k < arr[right]){
            arr[loc] = arr[right];
            loc = right;
        }else{
            arr[loc] = k;
            return;
        }
        left = 2*loc;
        right = left+1;
    }
    if(left == h_size && k < arr[left]){
        arr[loc] = arr[left];
        loc = left;
    }
    arr[loc] = k;
}
int deleteRoot(int arr[],int& cur_size){
    int mx = arr[1];
    arr[1] = arr[cur_size];
    cur_size--;
    restoreDown(arr , cur_size);
    return mx;
}
int main()
{
    int cur_size = 0;
    int arr[100];
    while(true){
        cout << "1 for insert" << endl;
        cout << "2 for delete" << endl;
        cout << "3 for display" << endl;
        cout << "4 for build heap" << endl;
        cout << "5 for Exit" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the number to be inserted into heap" << endl;
            int num;
            cin >> num;
            insert(arr , num , cur_size);
            break;
        case 2:
            int top_num ;
            top_num = deleteRoot(arr , cur_size);
            cout << "Max element is : " << top_num << endl;
            break;
        case 3 :
            cout << "Elements in heap are : " ; 
            for(int i = 1 ; i <= cur_size ; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        case 5 :
            exit(1);
        default:
            break;
        }
    }
    return 0;
}
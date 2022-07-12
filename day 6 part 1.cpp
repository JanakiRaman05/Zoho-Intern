#include<iostream>
#include<stdexcept>
using namespace std;
void error_msg(int id){
    switch (id){
        case 0:
            cout <<"Invalid division\n"<<"Exception Handling Accomplished\n"<<endl;
            break;
        case 1:
            cout <<"Memory is compromised!\n"<<"Exception Handling Accomplished\n"<<endl;
            break;
        case 2:
            cout<<"Format mismatch\n"<<"Exception Handling Accomplished\n"<<endl;
            break;
        case 3:
            cout<<"Index is invalid\n"<<"Exception Handling Accomplished\n"<<endl;
            break;
        case 4:
            cout<<"Array index is invalid\n"<<"Exception Handling Accomplished\n"<<endl;
            break;
        default:
            cout<<"Exception encountered\n"<<"Exception Handling Accomplished"<<endl;
    }
}
//Floating Error Codes
float div(float a, float b) {
    if(b==0){
        throw 0;
    } else{
        return a/b;
    }
}
//String Error Codes
char sdata(string word,int n){
    int len = word.length();
    if(n>=len){
        throw 3;
    } else{
        return word[n];
    }
}
//Array Error Codes
int adata(int word[],int len,int n){
    if(n>=len){
        throw 4;
    } else {
        return word[n];
    }
}
int main(){
    //Divide by zero error
    float a=5,b=0,res;
    try{
        res=div(a,b);
    } catch(int n){
        error_msg(n);
    }
    //Heap memory
    try{
        int* dumpmem = new (nothrow) int [999999];
        if(!(*dumpmem)){
            throw 1;
        }
    } catch(int n){
        error_msg(n);
    }
    //String out of index
    string word="samples";
    try{
        cout<<sdata(word,7);
    } catch(int n){
        error_msg(n);
    }
    //Array out of index 
    int arr[]={1,2,3,4,5,6};
    try{
        cout<<adata(arr,6,6);
    } catch(int n){
        error_msg(n);
    }
    //char to int 
    char  letters[] ="a234";
    try{
         for(int i=0; i<4; i++){
            if((letters[i] >='a' && letters[i] <= 'z') || (letters[i] >='A' && letters[i] <= 'Z')){
                throw 2;
            } else{
                cout<<letters[i]<<endl;
            }
         }
    } catch(int n){
        error_msg(n);
    }
    return 0;
}
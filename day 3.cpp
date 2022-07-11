#include<iostream>
using namespace std;
int sum=0,reference=-1,count=0;
int ids[5][4];
int group(int** mat, int row, int col,int m,int n){
    if (mat[m][n]<=0){
        return 0;
    }
    else {
        count+=1;
        sum+=mat[m][n];
        mat[m][n]=reference;
    }
    //top
    if(m>0 && mat[m-1][n]>0){
        group(mat,row,col,m-1,n);
    }
    //bottom
    if(m<row-1 && mat[m+1][n]>0){
        group(mat,row,col,m+1,n);
    }
    //left
    if(n>0 && mat[m][n-1]>0){
        group(mat,row,col,m,n-1);
    }
    //right
    if(n<col-1 && mat[m][n+1]>0){
        group(mat,row,col,m,n+1);
    }
    return 0;
}
void traverse(int** mat, int row, int col)
{
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            if (mat[i][j]>0){
                group(mat,row,col,i,j);
                ids[(reference*-1)-1][0]=sum;
                ids[(reference*-1)-1][1]=reference;
                ids[(reference*-1)-1][2]=count;
                ids[(reference*-1)-1][3]=-1;
                reference-=1;
                sum=0;
                count=0;
            }
        }
    } 
}
int getid(int val){
    for(int i=0;i<(reference*-1);++i){
        if(val==ids[i][1]){
            return i;
        }
    }
    return 0;
}
int diff(int a, int b){
    return (a>b)?(a-b):(b-a);
}
int minimum(int** lindex, int N, int row, int col){
    int min=-1,temp;
    for(int i=0;i<N;++i){
        if((diff(lindex[i][0],row)!=0) && (diff(lindex[i][1],col)!=0)){
            temp=((lindex[i][0]-row)>(lindex[i][1]-col)!=0)?diff(lindex[i][1],col):diff(lindex[i][0],row);
        } else if(diff(lindex[i][0],row)==0){
            temp=diff(lindex[i][1],col);
        } else{
            temp=diff(lindex[i][0],row);
            if(row==3 && col==1){
            }
        }
        if(min==-1 || min>temp) min=temp;
    } 
    //cout<<"min: "<<min<<" row "<<row<<" col "<<col<<endl;
    return min;
}
int main(){
    int N=5,M=5;
    cin>>N>>M;
    int** mat = new int*[M];
    for(int i=0;i<M;i++){
        mat[i] = new int[N];
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            cin>>mat[i][j];
        }
    }/*
    mat[0]=new int[5]{0,2,0,3,1};
    mat[1]=new int[5]{4,1,2,0,0};
    mat[2]=new int[5]{2,0,0,0,0};
    mat[3]=new int[5]{0,1,0,2,3};
    mat[4]=new int[5]{0,0,1,1,0};
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            cout<<mat[i][j]<<"   ";
        }
        cout<<endl;
    } */
    traverse(mat,N,M);
    int lref=0;
    //cout<<"Groups: \n";
    // identify the leader index
    for(int i=0;i<(reference*-1)-1;++i){
        //cout<<ids[i][0]<<"  "<<ids[i][1]<<"  "<<ids[i][2]<<endl;
        if(ids[i][0]>ids[lref][0]){
            ids[lref][0]=ids[i][0];
            lref=i;
        }    
    }
    //cout<<"lref: "<<lref;
    //cout<<"\nLeader: "<<ids[lref][0]<<" max count: "<<ids[lref][2]<<endl;
    cout<<"Leader: "<<ids[lref][0]<<endl;
    //optional ans 
    int **lindex = new int*[ids[lref][2]],count=0,curid;
    for(int i=0;i<N;++i){  
        for(int j=0;j<M;++j){
            if(ids[lref][1]==mat[i][j]){
                lindex[count]= new int[2] {i,j};
                count++;
            }
        }
    } 
    /*
    cout<<"\nleader index\n";
    for(int i=0;i<ids[lref][2];++i){
        cout<<"\n Row = "<<lindex[i][0]<<" Col = "<<lindex[i][1];
    } 
    */
    for(int i=0;i<N;++i){  
        for(int j=0;j<M;++j){
            if(0==mat[i][j]||ids[lref][1]==mat[i][j]){
                continue;
            } else {
                curid=getid(mat[i][j]);
                int temp=minimum(lindex,ids[lref][2],i,j);
                if(ids[curid][3]==-1){
                    ids[curid][3]=temp;
                } else if (temp<ids[curid][3]){
                    ids[curid][3]=temp;
                }
            }
        }
    }
    cout<<"Shortest path: "<< endl; 
    for (int i=0;i<(reference*-1)-1;++i){
        //cout<<ids[i][0]<<"  "<<ids[i][1]<<"  "<<ids[i][2]<<"  "<<ids[i][3]<<endl;
        if(i!=lref)
            cout<<ids[i][0]<<"  "<<ids[i][3]<<endl;
    }
    return 0;
}

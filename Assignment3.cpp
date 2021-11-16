#include<iostream>
using namespace std;
struct Sparse{
    int row;
    int col;
    int val;

};
class Matrix{
    private:
    int row;
    int col;
    int val_count=0;
    
    
    
    public:
    void set(int r,int c){
        row=r;
        col=c;
    }
    Sparse *sparse;
    
    void input();
    void convertSparse();
    void display_simple();
    void display_sparse();
    Matrix Simple_Transpose();
    Matrix Fast_Transpose();

};

void Matrix:: input( ){
    int a[row][col];
    
    cout<<"Enter values for  matrix ";
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cin>>a[i][j];
                if(a[i][j]!=0){
                val_count++;}
            }
        }
     sparse= new Sparse[val_count+1];
     int temp=1;
     sparse[0].row=row;
     sparse[0].col=col;
     sparse[0].val=val_count;
     for(int i=0;i<row;i++){
         for(int j=0;j<col;j++){
             if(a[i][j]!=0){
               sparse[temp].row=i;
               sparse[temp].col=j;
               sparse[temp].val=a[i][j];
               temp++;
                 
             }
         }
         
         
     }   

}


void Matrix:: display_sparse(){
    cout<<"Row"<<"\t"<<"Column"<<"\t"<<"Values"<<"\t"<<endl;
    for(int i=0;i<=sparse[0].val;i++){
        cout<<sparse[i].row<<"\t"<<sparse[i].col<<"\t"<<sparse[i].val<<"\t"<<endl;
             
    }
 
}


Matrix Matrix:: Simple_Transpose(){
    
    Matrix temp;
    temp.set(row,col);
    temp.val_count-val_count;
    temp.sparse=new Sparse[val_count+1];
    temp.sparse[0].row=sparse[0].col;
    temp.sparse[0].col=sparse[0].row;
    temp.sparse[0].val=sparse[0].val;
    int next=1;
    if(sparse[0].val>0){
        for(int i=0;i<col;i++){
            for(int j=0;j<=val_count;j++){
                if(sparse[j].col==i){
                    temp.sparse[next].row=sparse[j].col;
                    temp.sparse[next].col=sparse[j].row;
                    temp.sparse[next].val=sparse[j].val;
                    next++;

                }
            }
        }
    }
    return temp; 
}

Matrix Matrix:: Fast_Transpose(){
    int row_terms[col+1],start[col+1];
    Matrix temp;
    temp.set(row,col);
    temp.val_count=val_count;
    temp.sparse=new Sparse[val_count+1];
    temp.sparse[0]=sparse[0];
    int i,j,num_col=sparse[0].col,num_terms=sparse[0].val;
    if(num_terms>0){
        for(int i=0;i<num_col;i++){
            
              row_terms[i]=0;
            }
        for(int i=0;i<num_terms;i++){
            row_terms[sparse[i].col]++;
        }
        start[0]=1;
        for(int i=1;i<num_col;i++){
           start[i]=start[i-1]+row_terms[i-1];
        }
        for(i=1;i<=num_terms;i++){
            j=start[sparse[i].col]++;
            temp.sparse[j].row=sparse[i].col;
            temp.sparse[j].col=sparse[i].row;
            temp.sparse[j].val=sparse[i].val;
        }
        
    }
    return temp;
    
}



int main(){
    int r,c;
    cout<<"Enter number of rows"<<endl;
    cin>>r;
    cout<<"Emter number of columns"<<endl;
    cin>>c;
    Matrix m;
    m.set(r,c);
    m.input();
    m.display_sparse();
    m.Simple_Transpose().display_sparse();
    m.Fast_Transpose().display_sparse();
    
    
return 0;
}
#include <iostream>

using namespace std;

const int Q_number = 8  ;//size of queen
void printBroad();
bool setQueen(int row,int column);
void solve(int row);
int queens[Q_number][Q_number] = {0};//intialize
static int q_count = 0;//record the counts

int main(){
    solve(0);
    cout<<"count:"<<q_count<<endl;
    return 0;
}


//initialize
void printBroad(){
    for(int i =0;i < Q_number;i++){
        for(int j = 0;j < Q_number;j++){
            cout<<queens[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//test is it fit the requirement
bool setQueen(int row,int column){

    if(row == 0){
        queens[row][column] = 1;
        return true;
    }

    for(int i = 0;i < row ;i++){
        if(queens[i][column] == 1)
            return false;
    }


    for(int i = row - 1,j = column - 1;i >= 0 && j >= 0;i--,j--){
        if(queens[i][j] == 1){
            return false;
        }
    }

    for(int i = row - 1,j = column + 1;j < Q_number  && i >= 0;j++,i--){
        if(queens[i][j] == 1)
            return false;
    }

    queens[row][column] = 1;
    return true;
}

void solve(int row){

    if(row == Q_number){
        q_count++;
        printBroad();
        return ;
    }

    for(int i = 0;i < Q_number;i++){
        if(setQueen(row,i)){
            solve(row +1);
        }
        queens[row][i] = 0;
    }
}



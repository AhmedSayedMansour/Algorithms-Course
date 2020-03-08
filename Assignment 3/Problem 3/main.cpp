#include <iostream>

using namespace std;

void TowerGame(int n, char A, char C, char B){
    if(n==1){
        cout<<"Disk 1 moved from "<<A<<" to "<<C<<endl;
    }
    else{
        TowerGame(n-1, A, B, C);
        cout<<"Disk "<<n<<" moved from "<<A<<" to "<<C<<endl;
        TowerGame(n-1, B, C, A);
    }
}

int main()
{
    int n;
    cin>>n;
    TowerGame(n, 'A', 'C', 'B');
    return 0;
}

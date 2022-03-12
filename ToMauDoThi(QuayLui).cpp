#include <iostream>
#include <cstring>
#include <fstream>
 
using namespace std;
 
int n, a[10][10],sm=0,m[10];
 
void docfile(){ //Dung de doc file, sau do gan vao mang a[][]
    int q,p;
    ifstream dothi ("dothi.txt");
    if (dothi.is_open())
    {
        dothi >> n;
        while (!dothi.eof()) //Doc file cho den cuoi file
        {
            dothi >> q;
            dothi >> p;
            a[q][p]=1;
            a[p][q]=1;
        }
        dothi.close();
    }
    else cout << "Khong mo duoc file";
}
 
void xuly(){ //Xu ly de cho ra ket qua vao mang m[]
    int kt;
    for(int i=1;i<=n;i++)
        if(!m[i]) {
            sm++; //Dem so mau
            m[i]=sm;
            for(int j=i+1;j<=n;j++) //Kiem tra xem nhung dinh nao co the gan bang mau sm nua khong
                if((a[i][j]==0)&&(m[j]==0)){
                    kt=1;
                    for(int k=i+1;k<j;k++)
                        if((a[k][j]==1)&&(m[i]==m[k])){
                            kt=0;
                            break;
                        }
                    if(kt==1) m[j]=sm;
                }                   
        }
}
void xuatkq(){ //In ket qua ra man hinh
    for(int i=1;i<=sm;i++){
        cout << "Mau " << i << ": ";
        for(int j=1;j<=n;j++) if(m[j]==i) cout << j << " ";
        cout << endl;
    }
}
int main(){
    docfile();
    cout << n << endl;
    for(int i=1;i<=n;i++){ //In mang ra man hinh de theo doi
        for(int j=1;j<=n;j++) cout << a[i][j] << "  ";
        cout << endl;
    }cout << endl;
    xuly();
    xuatkq();
    return 0;
}
//file dothi.txt
// 3
// 1 2
// 4 2
// 6 8 

#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main()
{
    long long int bmap[64];
    long long int tmap[64];
    vector<bitset<64>> vbmap;
    bitset<64> temp;


    for(int i=0; i<64; i++){
        cin >>bmap[i];
        vbmap.push_back(bmap[i]);
    }


    for(int i=0; i<64; i++){
        for(int j=0; j<64; j++)
            temp.set(63-j, vbmap[j][63-i]);
        tmap[i] = temp.to_ullong();
        cout <<tmap[i]<<endl;
    }


    return 0;
}

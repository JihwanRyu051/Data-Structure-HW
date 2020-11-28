#include <iostream>
#include <vector>
#include <bitset>
using namespace std;


int main()
{
    long long int bmap[64];
    long long int tmap[64];
    vector<bitset<64>> bbmap;
    vector<bitset<64>> ttmap;
    vector<bitset<64>>::iterator vbit;
    bitset<64> temp;
    for(int i=0; i<64; i++){
        cin >> bmap[i];
        bbmap.push_back(bmap[i]);
    }

    for(int i=0; i<64; i++){
        for(int j=0; j<64; j++ )
            temp[63-j] = bbmap[j][63-i];
        ttmap.push_back(temp);
        tmap[i] = ttmap[i].to_ullong();
        cout <<tmap[i]<<endl;
    }





    return 0;
}

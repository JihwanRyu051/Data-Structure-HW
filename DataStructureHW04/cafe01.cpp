#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool RangeCheck(int n, int k){
    if(n>= 10 && n <=1000000)
        return 1;
    else if(k>=5 && k<=1000)
        return 1;
    else
        return 0;

}

int main()
{
    int N, K, visitor,cnt;

    cin >> N;
    cin >> K;

    if(!RangeCheck(N, K))
        return 0;


    vector<int> vlist;
    vector<int>::iterator vi;
    vector<int>::iterator pr;
    vector<int>::iterator nx;
    vector<int>::iterator fi;

    for(int i=0; i<K; i++){
        cin >> visitor;

        if(visitor>N)
            return 0;

        vlist.push_back(visitor);

        sort(vlist.begin(), vlist.end());
        fi = find(vlist.begin(), vlist.end(), visitor);
        cnt = count(vlist.begin(), vlist.end(), visitor);

        if(cnt > 1){
            vlist.erase(fi, fi+cnt);
        }
        else{

            pr = fi -1;
            nx = fi +1;

            if(pr<vlist.begin())
                pr = vlist.end()-1;
            if(nx == vlist.end())
                nx = vlist.begin();
            cout << *fi << " "<< *pr << " " << *nx<<endl;

        }


    }




    return 0;
}

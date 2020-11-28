#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

bool RangeCheck(int n, int k){
    if((n>= 10 && n <=1000000) && (k>=5 && k<=1000))
        return 1;
    else
        return 0;

}



int main()
{
    int N, K, visitor, cnt;

    cin >> N;
    cin >> K;

    if(!RangeCheck(N, K))
        return 0;


    list<int> vlist;
    list<int>::iterator vi;
    list<int>::iterator pr;
    list<int>::iterator nx;
    list<int>::iterator fi;

    for(int i=0; i<K; i++){
        cin >> visitor;

        if(visitor>N)
            return 0;

        vlist.push_back(visitor);
        vlist.sort();
        fi = find(vlist.begin(), vlist.end(), visitor);
        cnt = count(vlist.begin(), vlist.end(), visitor);

        if(cnt > 1){
            vlist.remove(visitor);
        }
        else{
            pr = prev(fi);
            nx = next(fi);

            if(pr == prev(vlist.begin()))
                pr = prev(vlist.end());
            if(nx == vlist.end())
                nx = vlist.begin();
            cout << *fi << " "<< *pr << " " << *nx<<endl;

        }


    }




    return 0;
}







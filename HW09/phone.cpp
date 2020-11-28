#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class mob{
private:
    int idx;
    int qual;
    int price;
public:
    mob(): idx(0), qual(0), price(0) {}
    mob(int i, int q, int u) : idx(i), qual(q), price(u) {}

    int Index(){   return idx;   }
    int Qual(){  return qual; }
    int Price() {   return price;   }

    bool operator <(mob& mb2){

        return (this->Qual()<mb2.Qual());
    }
    bool Eval(mob& bnd){
        if((qual>=bnd.Qual()) || (price<=bnd.Price()))
            return 1;
        else
            return 0;
    }
};

bool cmp(mob& mb1, mob& mb2){
    return mb1.Index()>mb2.Index();
}

int main(void){
    vector<mob> vmob;
    vector<mob> smob;
    int N, q, u;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> q >> u;
        mob one(i+1, q, u);
        vmob.push_back(one);
    }

    sort(vmob.begin(),vmob.end());


    while(!vmob.empty()){
        if(smob.empty())
            smob.push_back(vmob.back());
        else{
            if(smob.back().Price()>vmob.back().Price()){
                smob.push_back(vmob.back());
            }
        }

        vmob.pop_back();

    }

    sort(smob.begin(),smob.end(), cmp);

    while(!smob.empty()){
        cout << smob.back().Index() << endl;
        smob.pop_back();

    }
    return 1;
}

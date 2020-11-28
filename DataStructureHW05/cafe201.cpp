#include <bits/stdc++.h>

#define minN    10
#define maxN    1000000
#define minK    5
#define maxK    10000
#define minID   1
#define maxID   10000
#define lvi     list<visitor>::iterator

using namespace std;

class   visitor{
private:
    int id;
    int seat;
public:
    int Seat()  {   return seat;    }
    int ID()    {   return id;      }
    bool operator ==    (const int& id){
        return (this->ID() == id);
    }
    void Set(int nid, int ns){
        id = nid;
        seat = ns;
    }
    friend ostream& operator << (ostream& os, visitor& vs);
};

ostream& operator << (ostream& os, visitor& vs){
    os << vs.ID() << " " << vs.Seat()<<endl;
    return os;
}

int nextSeat(lvi vbegin, lvi vend, lvi vi, int N){
    if(next(vi) == vend)
        return vbegin->Seat() + N;
    else
        return next(vi)->Seat();
}


int rsvSum(int reserve, int N){
    if(reserve > N)
        return reserve - N;
    else
        return reserve;
}


int rsvSeat(int sum, int N){
    if(sum % 2 == 0)
        return rsvSum(sum/2, N);
    else{
        return min(rsvSum(sum/2, N), rsvSum(sum/2+1, N));
    }
}

lvi rsvItr(lvi lsbegin, lvi nextitr, int sum, int N){
    if(sum / 2 > N)
        return lsbegin;
    else
        return nextitr;
}

bool rangeCheck(int arg, int minArg, int maxArg){
    return ( minArg <= arg ) && ( arg <= maxArg );
}

void pushrsv(pair<lvi, int>& rsv, list<pair<lvi, int>>& list_rsv){
    if(rsv.second < list_rsv.front().second)
        list_rsv.push_front(rsv);
    else
        list_rsv.push_back(rsv);
    return ;
}

int main()
{
    int N, K, id;
    int maxdis, dis;
    int nx, sum;
    visitor vst;
    pair<lvi, int> rsv;

    list<visitor> list_vst;
    list<pair<lvi, int>> list_rsv;

    lvi fnd;
    lvi vi;

    cin >> N;
    cin >> K;

    if( !rangeCheck(N, minN, maxN) || !rangeCheck(K, minK, maxK))
        return 0;

    for(int i =0; i<K; i++){
        cin >> id;
        if(!rangeCheck(id, minID, maxID))
            return 0;

        fnd = find(list_vst.begin(), list_vst.end(), id);

        if(fnd != list_vst.end()){
            list_vst.erase(fnd);
            list_rsv.clear();

        }
        else if(list_vst.size() <= N){
            if(list_vst.empty()){
                    rsv = make_pair(list_vst.begin(), 1);
                    list_rsv.push_back(rsv);
                }
            else if(list_rsv.empty()){
                    maxdis  = 0;
                    for(vi = list_vst.begin(); vi != list_vst.end(); vi++){
                        nx  = nextSeat(list_vst.begin(), list_vst.end(), vi, N);
                        dis = nx - vi->Seat();

                        if(maxdis <= dis){

                            if(maxdis < dis){
                                maxdis = dis;
                                list_rsv.clear();   }

                            sum = nx + vi->Seat();
                            rsv = make_pair( rsvItr(list_vst.begin(),next(vi),sum, N),
                                            rsvSeat(sum, N) );
                            pushrsv(rsv, list_rsv);
                        }
                    }
            }
            vst.Set(id, list_rsv.front().second);
            list_vst.insert(list_rsv.front().first, vst);
            list_rsv.pop_front();
            cout << vst;
        }
    }
    return 0;
}

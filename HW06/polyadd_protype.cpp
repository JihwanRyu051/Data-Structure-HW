#include <iostream>
#include <list>
#define maxC 100
#define minC -100
#define maxE 1000
#define minE 0
#define maxN 10
#define minN 0
#define term pair<int,int>

using namespace std;

bool rcheck(int arg, int minArg, int maxArg){
    return ( minArg <= arg ) && ( arg <= maxArg );
}

bool compTerm(term& t1, term& t2){
    if(t1.second > t2.second)
        return true;
    else
        return false;
}

bool addTermsToFunc(list<term>* ptrfunc, term& tr,int& c, int& e){
        int termN;
        cin >> termN;
        for(int i=0;i<termN;i++){
            cin>>c;
            cin>>e;
            if(!rcheck(c,minC,maxC) && !rcheck(e,minE, maxE))
                return false;
            tr = make_pair(c, e);
            ptrfunc->push_back(tr);
        }
        return true;
}

void funcSort(list<term>* ptrfunc){
    list<term>::iterator vi;
    ptrfunc->sort(compTerm);
    for(vi=ptrfunc->begin();vi != ptrfunc->end(); vi++){
            if(vi != prev(ptrfunc->end()))
                if(vi->second == next(vi)->second){
                    vi->first += next(vi)->first;
                    next(vi)->first = 0;
            }
            if(vi->first == 0){
                vi--;
                ptrfunc->erase(next(vi));
            }
        }
}



void funcPrint(list<term>* ptrfunc){
    list<term>::iterator vi;
    if(ptrfunc->size() == 0){
        cout << 1 <<endl;
        cout << 0 << " "<<0<<endl;
    }
    else{
        cout << ptrfunc->size() <<endl;
        for(vi=ptrfunc->begin(); vi != ptrfunc->end(); vi++)
            cout << vi->first<< " " << vi->second <<endl;
    }
    return;
}

int main()
{
    int N, c, e;
    term temp;
    list<term> func;

    cin >> N;
    if(!rcheck(N,minN,maxN))
        return 0;

    for(int i=0; i<N; i++)
        if(!addTermsToFunc(&func, temp, c, e))
            return 0;

    funcSort(&func);
    funcPrint(&func);

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

#define llg long long

using namespace std;


void addTermsToFunc(vector<llg>& func,llg& c, int& e){
    if( e+1 > (int)func.size())
        func.resize(e+1,0);
    func.at(e) += c;
    return ;
}

void makeFunc(vector<llg>& func, llg& c, int& e){
    int term;

    cin >> term;

    for(int i=0; i<term; i++){
        cin >> c >> e;
        addTermsToFunc(func, c, e);
    }
    return;
}

void printFunc(vector<llg>& func){
    vector<llg>::iterator vi;
    int termN = (int)func.size() - count(func.begin(), func.end(), 0);

    if(termN == 0){
        cout << termN+1<<endl;
        cout << 0 << " "<< 0<<endl;
    }
    else{
        cout << termN <<endl;
        for(vi = func.end()-1; vi >= func.begin(); vi--){
            if(*vi != 0)
                cout << *vi << " "<< vi - func.begin()<<endl;
        }
    }
    return;
}

void multiFunc(vector<llg>& func1, vector<llg>& func2, vector<llg>& result){
    llg c;
    int e, fe1 = 0, fe2;
    result.clear();
    for(auto term1 : func1){
        if(term1 != 0){
            fe2 = 0;
            for(auto term2 : func2){
                if(term2 != 0){
                    c = term1 * term2;
                    e = fe1 + fe2;
                    addTermsToFunc(result,c,e);
                }fe2++;
            }
        }fe1++;
    }
    func2 = result;
    func1.clear();
    return;
}

void makeResult(vector<vector<llg>>& vfunc, vector<llg>& result){
    vector<vector<llg>>::iterator vvi;
    if(vfunc.size() == 1)
        result = vfunc.front();

    for(vvi = vfunc.begin(); vvi < vfunc.end()-1;vvi++)
        multiFunc(*vvi, *next(vvi), result);


    return;
}

int main()
{
    int N, e;
    llg c;

    cin >> N;

    vector<llg> result;
    vector<vector<llg>> vfunc(N);

    for(int i=0; i<N; i++)
        makeFunc(vfunc.at(i), c, e);

    makeResult(vfunc, result);

    printFunc(result);

    return 0;
}

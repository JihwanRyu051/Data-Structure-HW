#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void addTermsToFunc(vector<int>& func,int& c, int& e){
    if( e+1 > (int)func.size())
        func.resize(e+1,0);

    func.at(e) += c;
    return ;
}

void makeFunc(vector<int>& func,int& c, int& e){
    int term;

    cin >> term;
    for(int i=0; i<term; i++){
        cin >> c >> e;
        addTermsToFunc(func, c, e);
    }
}

void printFunc(vector<int>& func){
    vector<int>::iterator vi;
    int termN = (int)func.size() - count(func.begin(), func.end(), 0);

    if(termN == 0){
        cout << termN+1<<endl;
        cout << 0 << " " << 0;
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

int main()
{
    int N, c, e;

    vector<int> func;

    cin >> N;

    for(int i=0; i<N; i++)
        makeFunc(func, c, e);

    printFunc(func);

    return 0;
}

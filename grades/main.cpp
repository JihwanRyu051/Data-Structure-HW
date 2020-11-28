#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;

string myid;

bool myfunc(pair<string, int> st1, pair<string, int> st2){
    return (st1.second>st2.second);
}

bool AmI(pair<string, int> st1){
    string id = st1.first;
    return (id == myid);
}

int main()
{
    string id;

    int score;
    int grade=1;
    int same=0;
    int myscore=35;
    vector<pair<string, int>> grades;
    vector<pair<string, int>>::iterator it;
    pair<string,int> student;

    while(true){
        cin >> id >> score;
        if(id == "end")
            break;
        get<0>(student) = id;
        get<1>(student) = score;
        grades.push_back(student);
    }
    cout << "reads all data" <<endl;
    cout << "본인 학번: ";
    cin >> myid;
    sort(grades.begin(), grades.end(),myfunc);


    it = find_if(grades.begin(), grades.end(), AmI);
    myscore = it->second;

    for(auto st: grades){
        if(same == 0)
            if(st.second!=myscore)
                grade++;
        if(st.second == myscore)
            same++;
    }
    cout << "등수: ";
    cout << grade<<"(" << same<<")";
    cout << "/" << grades.size()<<endl;



    system("pause");
    return 0;
}

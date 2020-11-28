#include <vector>
#include <stack>
#include <iostream>

int main()
{

    stack<int> box;
    vector<int> vcef;
    vector
    stack<vector<int>> result;
    int n,r,gift;
    int cef, index=0;

    int maxp;

    cin >> n >> r;
    for(int i=0; i<n; i++){
        cin >> cef;
        vcef.push_back(cef);
    }


    cin>>gift;


    vector<stack<int>> cart(n);
    maxp = gift/vcef.front();

    while(maxp>0){
        cart.at(index).push(maxp--);
    }

    gift -= cart.at(index).top() * vcef.at(index);

    fill_stack(cart, vcef, gift, result, index, maxp);

    int cnt=0;
    while(!result.empty()){
        cnt++;
        if(cnt==r){
            for(auto stuff: result.top())
                cout << stuff << " ";
            return 0;
        }
        result.pop();
    }

    cout <<"NONE"<<endl;


    return 0;
}

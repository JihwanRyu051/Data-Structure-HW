#include <iostream>
#include <stack>
#include <vector>

using namespace std;


int fill_stack(vector<stack<int>>& vsc, vector<int>& vcef, int& gift, int& sum,
               stack<vector<int>>& result, int& index){

    if(index != vsc.size()-1){

            if(vsc.at(index).empty()){
                if(index != 0){
                    index--;
                    int price = vsc.at(index).top()*vcef.at(index);
                    sum -= price;
                    vsc.at(index).pop();
                    int next = fill_stack(vsc, vcef, gift, sum, result, index);
                    return next;
                }
                else    return 1;
            }
            else{
                int price = vsc.at(index).top()*vcef.at(index);
                sum += price;

                index++;
                int maxp = (gift-sum) / vcef.at(index);

                if(maxp<0)
                    maxp=0;

                if(index != vsc.size()-1){
                    for(int i=0; i<=maxp; i++){
                        vsc.at(index).push(i);
                    }
                }
                else{
                    vsc.at(index).push(maxp);
                }
                int next = fill_stack(vsc, vcef, gift, sum, result, index);
                return next;
            }
        }

    else{
            int price = vsc.at(index).top()*vcef.at(index);
            sum += price;

            if(sum == gift){
                    vector<int> purchase;
                    for(auto box: vsc){
                        purchase.push_back(box.top());
                    }
                    result.push(purchase);
            }
            sum -= price;
            vsc.at(index).pop();

            index--;
            price = vsc.at(index).top()*vcef.at(index);
            sum -= price;
            vsc.at(index).pop();
            int next = fill_stack(vsc, vcef, gift, sum, result, index);
            return next;
        }

}




int main()
{

    vector<stack<int>> cart;
    stack<int> box;
    vector<int> vcef;
    stack<vector<int>> result;
    int n,r,gift;
    int cef, sum=0, index=0;

    int maxp;

    cin >> n >> r;
    for(int i=0; i<n; i++){
        cin >> cef;
        sum += cef;
        vcef.push_back(cef);
    }
    cin>>gift;

    cart.resize(n);

    gift = gift - sum;
    sum = 0;
    maxp = gift/vcef.front();

    for(int i=0; i<=maxp; i++){
        cart.at(index).push(i);
    }

    fill_stack(cart, vcef, gift, sum, result, index);

    int cnt=0;
    while(result.size()>0){
        cnt++;
        if(cnt==r){
            for(auto stuff: result.top())
                cout << stuff+1 << " ";

            return 0;
        }

        result.pop();
    }
    cout <<"NONE"<<endl;


    return 0;
}

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class stuff{
private:
    int cef;
    int price;
public:
    stuff() : cef(0), price(1) {}
    int getPrice() {    return price;   }
    int getCef()   {    return cef;     }
    int totalPrice()    {   return cef*price;   }
    void setCef(int c)      {   cef = c;    }
    void setPrice(int p)    {   price = p;  }
    int operator ++(int)   {  price +=1;  return price; }
    friend ostream& operator<<(ostream& os, stuff& stf);
};

ostream& operator<<(ostream& os, stuff& stf){
    cout << stf.getCef() << " "<<stf.getPrice()<<endl;
    return os;
}

void roundingBooks(vector<stuff>& books, vector<int>& maxprice){
    vector<stuff>::iterator vbi;
    books.back()++;
    for(vbi = books.end()-1;vbi>books.begin();vbi--){
        int index = vbi - books.begin();
        if(vbi->getPrice() > maxprice.at(index)){
            vbi->setPrice(1);

            (*prev(vbi))++;
        }


    }
    return;
}

int main()
{
    vector<stuff> books;
    stack<vector<stuff>> result;
    vector<int> maxprice;

    stuff stf;
    int n,r,C;
    int price, cef, cnt=0;


    cin >> n >> r;
    for(int i=0; i<n; i++){
        cin >> cef;
        stf.setCef(cef);
        books.push_back(stf);

    }

    cin>>C;

    for(auto& sf: books){
        maxprice.push_back(C/sf.getCef());
    }

    while(true){


        price = 0;

        for(auto& sf: books){
            price += sf.totalPrice();

        }
        if(price == C){
            result.push(books);
            cnt +=1;
        }

        roundingBooks(books, maxprice);
        if(books.front().getPrice() == maxprice.front())
            break;
    }

    if(r<cnt){
        for(int i=cnt;i>r;i--)
            result.pop();
        for(auto sf: result.top()){
            cout<< sf.getPrice() << " ";
        }
    }
    else{
        cout << "NONE";

    }






    return 0;
}

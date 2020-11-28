#include <iostream>
#include <stack>

using namespace std;

class phone{
private:
    int index;
    int qual;
    int price;
public:
    phone(): index(0), qual(0), price(0) {}
    phone(int i, int q, int p) : index(i), qual(q), price(p) {}

    int Index(){   return index;   }
    int Qual(){  return qual; }
    int Price() {   return price;   }
    void operator = (phone ph){
        qual = ph.Qual();
        price = ph.Price();
    }
    bool Eval(phone& bound){
        if((qual >= bound.Qual()) || (price <= bound.Price()))
            return 1; // inferior
        else
            return 0;
    }

};


int main()
{
    int N, qual, price;

    stack<phone> rec;
    stack<phone> tmp;
    stack<phone> ttmp;
    stack<phone> result;

    phone upperQ;
    phone lowerP;

    bool inf = false;

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> qual >> price;
        phone newone(i+1, qual, price);
        if(!rec.empty()){
            if(newone.Eval(upperQ) && newone.Eval(lowerP)){
                if(newone.Qual()>upperQ.Qual())
                    upperQ = newone;


                if(newone.Price()<lowerP.Price())
                    lowerP = newone;

              rec.push(newone);
              tmp.push(newone);
            }
        }

        else{
            upperQ = newone;
            lowerP = newone;
            rec.push(newone);
            tmp.push(newone);
        }
    }


    while(!rec.empty()){
        phone rtop = rec.top();
        while(!tmp.empty()){
            if(!rtop.Eval(tmp.top())){
                inf = true;
            }
            else if(tmp.top().Eval(rtop)){
                ttmp.push(tmp.top());
            }
            tmp.pop();
        }

        if(!inf)
            result.push(rtop);

        inf = false;
        tmp.swap(ttmp);

        rec.pop();
    }

    while(!result.empty()){
        cout << result.top().Index()<<endl;
        result.pop();
    }
    return 0;
}

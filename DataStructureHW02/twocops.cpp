#include <iostream>
#define FOR(i,a) for (int i=0; i < int(a); i++)

using namespace std;

class Point{
private:
    int x;
    int y;
public:
    Point(): x(0), y(0){}
    void Set(int px, int py);
    void Move(int mvx, int mvy);
    int Coor_x()  {   return x;   }
    int Coor_y()  {   return y;   }
    bool operator == (Point p);
};

bool Point::operator==(Point p){
    if(this->x == p.x && this->y == p.y)
        return true;
    else    return false;
}

void Point::Set(int px, int py){
    x = px;
    y = py;
}

void Point::Move(int mvx, int mvy){
    x += mvx;
    y += mvy;
}

class Robo : public Point{
private:
    Point* Target;
    Point Rador;
    int dir_x;
    int dir_y;
    int start;
    int next;
    int len;
    int vel;

public:
    Robo(Point* p, int K, int I, int V) : Target(p), dir_x(0), dir_y(0),
     start(I), next(I), len(K), vel(V) {
         Set(Target[start].Coor_x(), Target[start].Coor_y());
    }
    void SetDir();
    void Step();
    void Run(int crash);
    bool operator ==(Robo& rb);
    void Reflection();
    int Crash(Robo& rb);
    friend ostream& operator <<(ostream& os, Robo& rb);
};

bool Robo::operator==(Robo &rb){
    if(this->Coor_x()==rb.Coor_x() && this->Coor_y()==rb.Coor_y())
        return true;
    else    return false;
}

void Robo::SetDir(){
    dir_x = Target[next].Coor_x() - this->Coor_x();
    dir_y = Target[next].Coor_y() - this->Coor_y();

    if(dir_x!=0)
        dir_x /= abs(dir_x);
    else
        dir_y /= abs(dir_y);
    return;
}

void Robo::Step(){
    if(Target[next] == (Point)(*this)){
        start = next;
        next = next + vel;
        if(next < 0)
            next = len-1;
        next %= len;
        SetDir();
    }
    Rador.Set(Coor_x()+dir_x, Coor_y()+dir_y);
    return ;
}

void Robo::Run(int crash){
    switch(crash){
        case 1:
            Reflection();
            Move(dir_x, dir_y);
            break;
        case 2:
            Reflection();
            break;
        case 3:
            next=start;
            Reflection();
            Move(dir_x, dir_y);
            break;
        default:
            Move(dir_x, dir_y);

        }
    return;
}

void Robo::Reflection(){
    this->vel *= -1;
    this->next += vel;
    SetDir();
    return ;
}



int Robo::Crash(Robo& rb){
    if(this->next==rb.start){
        if(*this == rb)
            return 1;
        else if(this->Rador == (Point)rb)
            return 2;
        else
            return 0;
    }

    else if(this->start == rb.start)
        if(*this == rb)
            return 3;
        else
            return 0;

    else
        return 0;

}

ostream& operator<<(ostream&os, Robo& rb){
    os << " "<<rb.Coor_x() << "  "<< rb.Coor_y() << endl;
    return os;
}

int main(){

    int K;
    cin >> K;
    int coor[K][2];
    int time;
    int condition;

    Point* track = new Point[K];

    FOR(i,K)
        FOR(j,2)
            cin >> coor[i][j];
    cin >> time;


    FOR(i,K)
        track[i].Set(coor[i][0], coor[i][1]);

    Robo rb1(track, K, 0, 1);
    Robo rb2(track, K, K/2-1, -1);


    FOR(i,time){
        rb1.Step();
        rb2.Step();
        condition = rb1.Crash(rb2);
        rb1.Run(condition);
        rb2.Run(condition);
        }

    cout<<rb1;
    cout<<rb2;

    free(track);

    return 0;
}

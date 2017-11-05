#ifndef GAME_H
#define GAME_H

#include<cmath>

class game
{
private:
    bool a;
    int last;
    int begintime;
    int grade;

    int x1,x2,x3,y1,y2,y3,z1,z2,z3,x4,y4,z4;

    int k;
public:
    game();
    void beginGame();
    int run(int x);
    void change1(int x,int y,int z){
        x1=x;
        y1=y;
        z1=z;
    }

    void change2(int x,int y,int z){
        x2=x;
        y2=y;
        z2=z;
    }

    void change3(int x,int y,int z){
        x3=x;
        y3=y;
        z3=z;
    }
    void change4(int x,int y,int z){
        x4=x;
        y4=y;
        z4=z;
    }
    bool check1(int x,int y,int z){
        if(abs(y-y2)<k)return true;
        else return false;
    }
    bool check2(int x,int y,int z){
        if(abs(y-y1)<k)return true;
        else return false;
    }
    bool check3(int x,int y,int z){
        if(abs(z-z4)<k)return true;
        else return false;
    }
    bool check4(int x,int y,int z){
        if(abs(z-z3)<k)return true;
        else return false;
    }

};

#endif // GAME_H

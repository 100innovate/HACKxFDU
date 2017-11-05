#include "game.h"
#include "time.h"
game::game()
{

}

void game::beginGame()
{
    a=0;
    grade=0;
    begintime= time((time_t*)NULL);
    last=0;
}

int game::run(int x)
{
    if(time((time_t*)NULL)-begintime>10)return -1;
    if(x-last>0&&a){
        grade++;
        a=0;
        last=x;
        return 1;
    }else if(x-last<0&&!a){
        grade++;
        a=1;
        last=x;
        return 2;
    }
    last =x;
    return 0;
}

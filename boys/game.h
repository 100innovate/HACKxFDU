#ifndef GAME_H
#define GAME_H


class game
{
private:
    bool a;
    int last;
    int begintime;
    int grade;
public:
    game();
    void beginGame();
    int run(int x);
};

#endif // GAME_H

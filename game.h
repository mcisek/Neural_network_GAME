#ifndef GAME
#define GAME

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsView>

#include "map.h"
#include "player.h"

#define HEIGHT 15
#define WIDTH 21
#define GAME_SPEED 1 //do not change

class Game : public QGraphicsView//public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    int points;
    int restart_flag;
public:
    QGraphicsScene *scene;
//    int number_of_columns;
    Map *level_map; //to hold data about obstacles on whole level
    Object *obstacles[WIDTH][HEIGHT]; //to hold data about visible obstacles
    Player *player;

    Game();
    void keyPressEvent(QKeyEvent * event);
    void back_to_begin();
    void remove_qobjects();

    void move_obstacles_left(int how_many_px);
    void get_new_column_from_map();
    void print_obstacles_table();
    int get_obstacles_table_width();
    int get_obstacles_table_height();

    void player_right();
    void player_left();
    void player_up();
    void player_shoot();
    void game_restart();
    void set_r_flag(int i);
    int get_r_flag();
    int get_points();
};

#endif // GAME


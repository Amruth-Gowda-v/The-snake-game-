#include <stdio.h>//used for common functions like printf , scanf , file_handling etx...etc
#include <stdlib.h>// used for  fuctions like malloc ,calloc,realloc ,free(),system,srand and rant 
#include <conio.h>//to register input like kbhit()and getch()
#include <windows.h>//used for sleep() function 
#include <time.h>//used for random module in this code 

#define WIDTH 30
#define HEIGHT 20
#define MAX_SNAKE_LENGTH 100



typedef enum
{
    STOP = 0,
    LEFT,//1
    RIGHT,//2
    UP,//3
    DOWN//4
} Direction;

typedef struct
{
    int x;
    int y;
} Position;

Position snake[MAX_SNAKE_LENGTH];

Position food;

Direction direction;
// Global variable
int snakeLength;
int score;
int gameOver;
int highScore = 0;

//function prototype
void setup();
void draw();
void input();
void logic();
void generateFood();


void logic()
{
    Position previous = snake[0];
    Position previous2;

    // Move body
    for (int i = 1; i < snakeLength; i++)
    {
        previous2 = snake[i];
        snake[i] = previous;
        previous = previous2;
    }

    // Move head
    switch (direction)
    {
        case LEFT:
            snake[0].x--;
            break;

        case RIGHT:
            snake[0].x++;
            break;

        case UP:
            snake[0].y--;
            break;

        case DOWN:
            snake[0].y++;
            break;

        case STOP:
            break;
    }

    // Wall collision
    if (snake[0].x < 0 ||
        snake[0].x >= WIDTH ||
        snake[0].y < 0 ||
        snake[0].y >= HEIGHT)
    {
        gameOver = 1;
    }

    // Self collision
    for (int i = 1; i < snakeLength; i++)
    {
        if (snake[0].x == snake[i].x &&
            snake[0].y == snake[i].y)
        {
            gameOver = 1;
        }
    }

    // Food collision
    if (snake[0].x == food.x &&
        snake[0].y == food.y)
    {
        score += 10;
        if (score > highScore)
{
    highScore = score;
}

        if (snakeLength < MAX_SNAKE_LENGTH)
        {
            snakeLength++;
        }

   generateFood();
    }
}


int main()
{
    setup();

    while (!gameOver)
    {
        draw();
        input();
        logic();
        Sleep(250);
    }

    printf("\n");
    printf("Game Over!\n");
    printf("Final Score : %d\n", score);

    return 0;
}


void setup()
{
    gameOver = 0;

    direction = STOP;

    snakeLength = 1;

    score = 0;

    snake[0].x = WIDTH / 2;
    snake[0].y = HEIGHT / 2;

    srand(time(NULL));

   generateFood();
}

void draw()
{
    system("cls");

    // printf("Score      : %d\n", score);
    // printf("High Score : %d\n\n", highScore);

    for (int i = 0; i < WIDTH + 2; i++)
    {
        printf("#");
    }

    printf("\n");

    for (int y = 0; y < HEIGHT; y++)
    {
        printf("#");

        for (int x = 0; x < WIDTH; x++)
        {
int printed = 0;

if (x == snake[0].x && y == snake[0].y)
{
    printf("O");
    printed = 1;
}
else
{
    for (int k = 1; k < snakeLength; k++)
    {
        if (x == snake[k].x &&
            y == snake[k].y)
        {
            printf("o");
            printed = 1;
            break;
        }
    }
}

if (!printed)
{
    if (x == food.x &&
        y == food.y)
    {
        printf("@");
    }
    else
    {
        printf(" ");
    }
}
        }

        printf("#\n");
    }

    for (int i = 0; i < WIDTH + 2; i++)
    {
        printf("#");
    }

    printf("\n");
}

void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
            case 'a':
            case 'A':
                if (direction != RIGHT)
                    direction = LEFT;
                break;

            case 'd':
            case 'D':
                if (direction != LEFT)
                    direction = RIGHT;
                break;

            case 'w':
            case 'W':
                if (direction != DOWN)
                    direction = UP;
                break;

            case 's':
            case 'S':
                if (direction != UP)
                    direction = DOWN;
                break;

            case 'x':
            case 'X':
                gameOver = 1;
                break;
        }
    }
}

void generateFood()
{
    int valid;

    do
    {
        valid = 1;

        food.x = rand() % WIDTH;
        food.y = rand() % HEIGHT;

        for (int i = 0; i < snakeLength; i++)
        {
            if (food.x == snake[i].x &&
                food.y == snake[i].y)
            {
                valid = 0;
                break;
            }
        }

    } while (!valid);
}


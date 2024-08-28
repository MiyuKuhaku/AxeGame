#include "raylib.h"



int main()
{
    //window dimensions
    int width{1280};
    int height{720};
    InitWindow(width, height, "Axe_Game");
    
    //circle coordinates and radius
    int circle_x{400};
    int circle_y{height/2};
    int circleRadius{25};
    //circle edges
    int l_circle_x{circle_x - circleRadius};
    int r_circle_x{circle_x + circleRadius};
    int u_circle_y{circle_y - circleRadius};
    int b_circle_y{circle_y + circleRadius};


    //Rectangle dimensions
    int RectangleWidth{50};
    int RectangleHeight{50};
    int axe_x{(width/2)-(RectangleWidth/2)};
    int axe_y{0};
    int direction{10};

    //score dimensions
    int ScoreWidth{50};
    int ScoreHeight{height};
    int Score_x{(width/2)-(ScoreWidth/2)};
    int Score_y{0};

    //score edges
    int l_Score_x{Score_x};
    int r_Score_x{Score_x + ScoreWidth};
    int u_Score_y{Score_y};
    int b_Score_y{Score_y + ScoreHeight};

    //axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + RectangleWidth};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + RectangleHeight};

    //collision with score
    bool collision_with_score =
                        (l_Score_x <= r_circle_x) &&
                        (r_Score_x >= l_circle_x) &&
                        (b_Score_y >= u_circle_y) &&
                        (u_Score_y <= b_circle_y);

    //collision with axe boolean
    
    bool collision_with_axe = 
                        (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (l_axe_x <= r_circle_x) && 
                        (r_axe_x >= l_circle_x);

    //score
    int score{0};
    //window drawn
    SetTargetFPS(60);
    while(WindowShouldClose()!=true)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if(collision_with_axe)
        {
            DrawText("Game Over!", 350, 200, 100, RED);
        }
        else
        {
        //game logic begins


            //update the edges
            l_circle_x = circle_x - circleRadius;
            r_circle_x = circle_x + circleRadius;
            u_circle_y = circle_y - circleRadius;
            b_circle_y = circle_y + circleRadius;

            l_axe_x = axe_x;
            r_axe_x = axe_x + RectangleWidth;
            u_axe_y = axe_y;
            b_axe_y = axe_y + RectangleHeight;
            //update collision with axe
            collision_with_axe = 
                        (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (l_axe_x <= r_circle_x) && 
                        (r_axe_x >= l_circle_x);

            collision_with_score =
                        (l_Score_x <= r_circle_x) &&
                        (r_Score_x >= l_circle_x) &&
                        (b_Score_y >= u_circle_y) &&
                        (u_Score_y <= b_circle_y);

            DrawCircle(circle_x, circle_y, circleRadius, BLUE);
            if (IsKeyDown(KEY_D) && circle_x < width - circleRadius)
            {
                circle_x += 10;
            }
            if (IsKeyDown(KEY_A) && circle_x > 0 + circleRadius)
            {
                circle_x -= 10;
            }
            DrawRectangle(Score_x, Score_y, ScoreWidth, ScoreHeight, BLACK);
            DrawRectangle(axe_x, axe_y, RectangleWidth, RectangleHeight, RED);

        //move the rectangle
            axe_y += direction;
            if(axe_y > height - (RectangleHeight) || axe_y < 0)
            {
                direction = -direction;
            }

            

            if(collision_with_score)
            {
                score += 1;
                DrawText(TextFormat("SCORE: %i", score), 280, 130, 40, MAROON);
            }
            else
            {
               DrawText(TextFormat("SCORE: %i", score), 280, 130, 40, MAROON); 
            }
            
            
        }

        //game logic ends
        EndDrawing();
       
    }
}
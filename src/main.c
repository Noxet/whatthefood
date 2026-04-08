
#include "raylib.h"

#include "resource_dir.h" // utility header for SearchAndSetResourceDir

#define NUM_RECS 5

int main()
{
    // Tell the window to use vsync and work on high DPI displays
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

    // Create the window and OpenGL context
    InitWindow(800, 600, "Hello Raylib");

    // Utility function from resource_dir.h to find the resources folder and set it as the current
    // working directory so we can load from it
    SearchAndSetResourceDir("resources");

    // Load a texture from the resources directory
    Texture wabbit = LoadTexture("wabbit_alpha.png");
    Rectangle toggleRecs[NUM_RECS] = {0};
    int mouseHoverRec = -1;

    for (int i = 0; i < NUM_RECS; i++)
    {
        toggleRecs[i] = (Rectangle){40.f, (float)(50 + 32 * i), 150.f, 30.f};
    }

    // game loop
    while (!WindowShouldClose()) // run the loop until the user presses ESCAPE or presses the Close
                                 // button on the window
    {
        // update logic

        for (int i = 0; i < NUM_RECS; i++)
        {
            if (CheckCollisionPointRec(GetMousePosition(), toggleRecs[i]))
            {
                mouseHoverRec = i;
                break;
            }
            else
            {
                mouseHoverRec = -1;
            }
        }

        // drawing
        BeginDrawing();

        // Setup the back buffer for drawing (clear color and depth buffers)
        ClearBackground(BLACK);

        // draw some text using the default font
        DrawText("Hello Raylib", 200, 200, 20, WHITE);

        // draw our texture to the screen
        DrawTexture(wabbit, 400, 200, WHITE);

        DrawFPS(500, 100);

        for (int i = 0; i < NUM_RECS; i++)
        {
            DrawRectangleRec(toggleRecs[i], i == mouseHoverRec ? SKYBLUE : LIGHTGRAY);
        }

        // end the frame and get ready for the next one  (display frame, poll input, etc...)
        EndDrawing();
    }

    // cleanup
    // unload our texture so it can be cleaned up
    UnloadTexture(wabbit);

    // destroy the window and cleanup the OpenGL context
    CloseWindow();
    return 0;
}


#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "resource_dir.h" // utility header for SearchAndSetResourceDir

#define NUM_RECS 5

int main()
{
    // Tell the window to use vsync and work on high DPI displays
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

    // Create the window and OpenGL context
    InitWindow(800, 600, "Hello Raylib");
    GuiLoadStyle("vendor/raygui/styles/terminal/style_terminal.rgs");

    // Utility function from resource_dir.h to find the resources folder and set it as the current
    // working directory so we can load from it
    SearchAndSetResourceDir("resources");

    // Load a texture from the resources directory
    Texture wabbit = LoadTexture("wabbit_alpha.png");

    bool showMessageBox = false;

    // game loop
    while (!WindowShouldClose()) // run the loop until the user presses ESCAPE or presses the Close
                                 // button on the window
    {
        // update logic

        // drawing
        BeginDrawing();

        // Setup the back buffer for drawing (clear color and depth buffers)
        ClearBackground(BLACK);

        if (GuiButton((Rectangle){24, 24, 120, 30}, GuiIconText(ICON_RESTART, "Show Message")))
            showMessageBox = true;

        if (showMessageBox)
        {
            int res = GuiMessageBox((Rectangle){85, 70, 250, 100}, "#191#Message Box",
                                    "Hi! This is a message", "Nice;Cool");
            if (res >= 0)
                showMessageBox = false;
        }

        // draw some text using the default font
        DrawText("Hello Raylib", 200, 200, 20, WHITE);

        // draw our texture to the screen
        DrawTexture(wabbit, 400, 200, WHITE);

        DrawFPS(500, 100);

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

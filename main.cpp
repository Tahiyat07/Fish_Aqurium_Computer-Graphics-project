#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

//-------------------------- To Generate Random Bubbles ----------------------
void random_bubbles(int i, int y_start, int num_bubbles) {

    for (int j = 0; j < num_bubbles; j++) {
        int rand_x = 90 + rand() % 20;  // Bubble range near the oxygen tank
        int rand_y = y_start - (i + rand() % 200);
        // Rising bubbles
        if (rand_y > 100) {
            circle(rand_x, rand_y, 5);

        }
    }
}

//-------------------------- Sinusoidal Fish Movement ------------------------
void sinusoidal_fish1(int i) {
    int y_offset = 20 * sin(i * 3.14 / 180);  // Sinusoidal offset for vertical motion

    setcolor(LIGHTBLUE);  // Body color
    arc(400 - i, 150 + y_offset, 50, 320, 30);

    setcolor(RED);  // Tail color
    line(420 - i, 128 + y_offset, 450 - i, 160 + y_offset);
    line(420 - i, 173 + y_offset, 450 - i, 130 + y_offset);
    //line(450 - i, 160 + y_offset, 450 - i, 130 + y_offset);

    setcolor(YELLOW);  // Eye color
    circle(380 - i, 150 + y_offset, 3);  // Fish eye

    setcolor(LIGHTBLUE);  // Body arc
    arc(380 - i, 150 + y_offset, 270, 90, 20);
}

void sinusoidal_fish2(int i) {
    int y_offset = 15 * cos(i * 3.14 / 180);  // Sinusoidal offset for vertical motion

    setcolor(GREEN);  // Body color
    line(150 + i, 250 + y_offset, 190 + i, 290 + y_offset);
    line(150 + i, 250 + y_offset, 90 + i, 310 + y_offset);

    setcolor(MAGENTA);  // Tail color
    line(90 + i, 270 + y_offset, 150 + i, 330 + y_offset);
    line(190 + i, 290 + y_offset, 150 + i, 330 + y_offset);
    line(90 + i, 310 + y_offset, 90 + i, 270 + y_offset);

    setcolor(WHITE);  // Eye color
    circle(170 + i, 290 + y_offset, 3);  // Fish eye
}
void sinusoidal_fish3(int i) {
    int y_offset = 10 * sin((i + 30) * 3.14 / 180);  // Sinusoidal offset for vertical motion

    // Fish body
    setcolor(CYAN);  // Body color
    ellipse(500 - i, 200 + y_offset, 0, 360, 20, 10);  // Move from right to left

    // Fish tail
    setcolor(RED);  // Tail color
    line(520 - i, 190 + y_offset, 540 - i, 210 + y_offset);
    line(520 - i, 210 + y_offset, 540 - i, 190 + y_offset);

    // Fish eye
    setcolor(WHITE);  // Eye color
    circle(490 - i, 200 + y_offset, 3);  // Eye
}
void sinusoidal_fish4(int i) {
    int y_offset = 10 * cos((i + 45) * 3.14 / 180) + 50;  // Add 50 to shift the fish lower

    // Fish body
    setcolor(YELLOW);  // Body color
    ellipse(100 + i, 200 + y_offset, 0, 360, 20, 10);  // Move from left to right

    // Fish tail
    setcolor(RED);  // Tail color
    line(80 + i, 190 + y_offset, 60 + i, 210 + y_offset);
    line(80 + i, 210 + y_offset, 60 + i, 190 + y_offset);

    // Fish eye
    setcolor(WHITE);  // Eye color
    circle(110 + i, 200 + y_offset, 3);  // Eye
}



//-------------------------- Draw Tank and Decorations -----------------------

    // Roof
    void draw_tank() {
    // Roof
    line(50, 10, 550, 10);
    line(50, 10, 10, 100);
    line(550, 10, 590, 100);
    line(10, 100, 590, 100);

line(100, 10, 100, 100);  // Vertical line at x = 100
    line(200, 10, 200, 100);  // Vertical line at x = 200
    line(300, 10, 300, 100);  // Vertical line at x = 300
    line(400, 10, 400, 100);  // Vertical line at x = 400
    line(500, 10, 500, 100);  // Vertical line at x = 500

    // Tank Border
    line(50, 100, 50, 400);
    line(550, 100, 550, 400);
    line(50, 400, 550, 400);

    // Stones
    ellipse(100, 390, 0, 360, 20, 10);
    ellipse(125, 370, 0, 360, 25, 10);
    ellipse(150, 390, 0, 360, 25, 10);
    ellipse(170, 375, 0, 360, 15, 5);
    circle(180, 390, 10);
    ellipse(200, 380, 0, 360, 10, 15);
    circle(220, 390, 10);
    ellipse(250, 380, 0, 360, 20, 15);

    ellipse(290, 390, 0, 360, 20, 10);
    ellipse(315, 370, 0, 360, 25, 10);
    ellipse(340, 390, 0, 360, 25, 10);
    ellipse(360, 375, 0, 360, 15, 5);
    circle(370, 390, 10);
    ellipse(390, 380, 0, 360, 10, 15);
    circle(410, 390, 10);
    ellipse(440, 380, 0, 360, 20, 15);

    ellipse(480, 390, 0, 360, 20, 10);
    ellipse(505, 370, 0, 360, 25, 10);
    ellipse(530, 390, 0, 360, 21, 10);

    // Grass inside the aquarium (across the bottom)
    setcolor(GREEN);
    for (int j = 50; j < 550; j += 10) {  // Start grass from the border and place it across the tank
        for (int k = 400; k > 350; k -= 10) {  // Start from the bottom border and draw upwards
            int grassHeight = rand() % 10 + 15;  // Random height for each grass line
            line(j, k, j + rand() % 10 - 5, k - grassHeight);  // Random grass lines growing upwards
        }
    }
}



//-------------------------- Main Function -----------------------------------
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "D:\\TC\\BGI");  // Write the correct path to your BGI folder
    int i;

    for (i = 0; i < 310; i++) {  // "for loop" for animation
        // Oxygen Tank
        line(50, 300, 80, 300);
        line(80, 300, 80, 370);
        line(50, 370, 80, 370);
        line(80, 305, 90, 305);
        line(80, 310, 90, 310);
        line(90, 305, 90, 310);

        sinusoidal_fish1(i);
        sinusoidal_fish2(i);
          sinusoidal_fish3(i);
sinusoidal_fish4(i);

        random_bubbles(i, 300, 15);

        draw_tank();
        delay(50);
        cleardevice();
    }

    getch();
    closegraph();

}

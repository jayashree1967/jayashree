#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to display sorted scores
void displayScores(int scores[], int count) {
    setcolor(WHITE);
    char score_str[30];
    for (int i = 0; i < count; i++) {
        sprintf(score_str, "Score %d: %d", i + 1, scores[i]);
        outtextxy(10, 30 + i * 20, score_str);
    }
}

int main() {
    int gdriver = DETECT, gmode, err;
    int x, y, top[2], bot[2];
    int score = 0;
    int scores[10]; // Array to store scores

    initgraph(&gdriver, &gmode,(char *) "C:/TURBOC3/BGI");
    err = graphresult();

    if (err != grOk) {
        printf("Graphics Error: %s", grapherrormsg(err));
        return 0;
    }

    x = 75;
    y = getmaxy() / 2 - 100;

    for (int i = 0; i < 10; i++) {
        cleardevice();
        setcolor(YELLOW);
        setlinestyle(SOLID_LINE, 1, 3);
        setfillstyle(SOLID_FILL, YELLOW);

        // Draw shooter
        circle(x, y, 15);
        floodfill(x, y, YELLOW);
        setcolor(WHITE);
        line(x, y + 15, x, y + 80);
        line(x, y + 80, x - 25, y + 125);
        line(x, y + 80, x + 25, y + 125);
        line(x, y + 20, x - 30, y + 40);
        line(x - 30, y + 40, x - 38, y + 55);
        line(x, y + 20, x + 55, y + 5);
        rectangle(x + 45, y - 5, x + 52, y + 15);
        rectangle(x + 45, y - 5, x + 75, y + 2);
        arc(x + 52, y + 3, 270, 360, 6);
        delay(300);

        // Draw target
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        circle(getmaxx() - 70, y, 15);
        floodfill(getmaxx() - 70, y, YELLOW);
        setcolor(WHITE);
        line(getmaxx() - 70, y + 15, getmaxx() - 70, y + 80);
        line(getmaxx() - 70, y + 20, getmaxx() - 50, y + 60);
        line(getmaxx() - 70, y + 20, getmaxx() - 90, y + 60);
        line(getmaxx() - 70, y + 80, getmaxx() - 90, y + 125);
        line(getmaxx() - 70, y + 80, getmaxx() - 50, y + 125);

        top[0] = x + 78;
        top[1] = y - 3;
        bot[0] = x + 82;
        bot[1] = y;

        // Motion of bullet
        for (int j = top[0]; j < getmaxx() - 80; j += 10) {
            setcolor(LIGHTRED);
            setfillstyle(SOLID_FILL, LIGHTRED);
            rectangle(top[0], top[1], bot[0], bot[1]);
            floodfill(top[0] + 1, top[1] + 1, LIGHTRED);
            delay(10);
            setcolor(BLACK);
            setfillstyle(SOLID_FILL, BLACK);
            rectangle(top[0], top[1], bot[0], bot[1]);
            floodfill(top[0] + 1, top[1] + 1, BLACK);
            top[0] += 10;
            bot[0] += 10;
        }

        // Bullet at the top of target
        setcolor(LIGHTRED);
        setfillstyle(SOLID_FILL, LIGHTRED);
        rectangle(top[0] - 10, top[1], bot[0] - 10, bot[1]);
        floodfill(top[0] - 9, top[1] + 1, LIGHTRED);
        
        score += 10;

        // Update score
        setcolor(WHITE);
        char score_str[20];
        sprintf(score_str, "Score: %d", score);
        outtextxy(10, 10, score_str);
        delay(500); // Delay to allow score to be visible
    }

    // Store final score in the scores array
    scores[0] = score;

    // Sort the scores
    insertionSort(scores, 1);

    // Display sorted scores
    cleardevice();
    displayScores(scores, 1);

    getch();
    closegraph();

    return 0;
}


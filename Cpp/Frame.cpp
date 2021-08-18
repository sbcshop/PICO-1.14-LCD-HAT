//For now we will only work with the rgb565 format as that is what this display uses but we should be able to add more formats if needed
//TODO: Maybe make it work with other colour formats?


#include "Frame.h"
#include <cstdio>

static void SortAndCheckPoints(Point& p1, Point& p2){
    uint startX = p1.X > p2.X ? p2.X : p1.X;
    uint endX = p1.X < p2.X ? p2.X : p1.X;
    uint startY = p1.Y > p2.Y ? p2.Y : p1.Y;
    uint endY = p1.Y < p2.Y ? p2.Y : p1.Y;

    p1 = { startX, startY };
    p2 = { endX, endY };
    //TODO: Add checks if we are going over the screen
}

Frame::Frame(uint8_t* _buffer, uint width, uint height){
    buffer = _buffer;
    Width = width;
    Height = height;

    Fill(0);
}

//TODO: Add checks for x/y
COLOUR Frame::GetPixel(uint x, uint y) {
    return ((COLOUR *)buffer)[x + (y * Width)];
}
void Frame::SetPixel(uint x, uint y, COLOUR colour) {
    ((COLOUR *)buffer)[x + (y * Width)] = colour;
}

void Frame::Fill(COLOUR colour) {
    DrawFilledRect({0, 0}, { Width, Height }, colour);
}

void Frame::DrawText(const char* text, Point p, COLOUR colour){
    printf("Not added yet");
}

//TODO: See if this works
void Frame::DrawRect(Point p1, Point p2, COLOUR colour){
    SortAndCheckPoints(p1, p2);

    //We want to draw four different lines here
    uint width = p2.X - p1.X;
    DrawHorizontalLine(p1, width, colour);
    DrawHorizontalLine({ p1.X, p2.Y }, width, colour);

    uint height = p2.Y - p1.Y;
    DrawVerticalLine(p1, height, colour);
    DrawVerticalLine({ p1.X + width, p1.Y }, height, colour);
}

//TODO: See if this works
void Frame::DrawFilledRect(Point p1, Point p2, COLOUR colour){
    SortAndCheckPoints(p1, p2);

    for (int i = p1.Y; i < p2.Y; ++i) {
        for (int j = p1.X; j < p2.X; ++j) {
            SetPixel(j, i, colour);
        }
    }
}

//TODO: See if this works
void Frame::DrawLine(Point p1, Point p2, COLOUR colour) {
    //We want this to draw forward which means we need start(X/Y) to be smaller then end(X/Y)

    SortAndCheckPoints(p1, p2);

    //Get how much we move on the axis
    uint xDiff = p2.X - p1.X;
    uint yDiff = p2.Y - p1.Y;
    //TODO: Maybe add assert here to check (x/y)Diff

    //If there is no difference between the two points then just set that one pixel and call it a day
    if(xDiff == 0 && yDiff == 0) {
        SetPixel(p1.X, p2.Y, colour);
        return;
    }

    //If both of them have some kind of diff then we will want to go forward on the y axis as well the x axis
    if(xDiff > 0 && yDiff > 0){
        uint yDownCount = xDiff > yDiff ?
                yDiff / xDiff : xDiff / yDiff;

        uint yCounter = 0;
        uint yAxis = p1.Y;
        for (uint i = p1.X; i < p2.X; ++i) {
            SetPixel(i, yAxis, colour);
            yCounter++;
            if(yCounter == yDownCount){
                yAxis++;
            }
        }
        return;
    }

    //If we get here then we just got to draw on the y axis
    if(yDiff > 0) {
        DrawVerticalLine(p1, yDiff, colour);
        return;
    }

    //If we get here then we just got to draw on the x axis
    DrawHorizontalLine(p1, xDiff, colour);
}
void Frame::DrawHorizontalLine(Point p, uint width, COLOUR colour) {
    uint endX = p.X + width;
    //If we get here then we just got to draw on the x axis
    for (uint i = p.X; i < endX; ++i) {
        SetPixel(i, p.Y, colour);
    }
}
//TODO: See if this works
void Frame::DrawVerticalLine(Point p, uint height, COLOUR colour) {
    uint endY = p.Y + height;
    for (uint i = p.Y; i < endY; ++i) {
        SetPixel(p.X, i, colour);
    }
}

void Frame::Scroll(int x, int y) {
    printf("Not added yet");
}

void Frame::Blit(const Frame* otherFrame, int x, int y) {
    printf("Not added yet");
}
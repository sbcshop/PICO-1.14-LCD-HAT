// This will let us create and edit what is shown, I wasn't able to find anything that was lightweight or in a license that can be used in this project
// so this is a very simple version which should let people do the same as what's possible in the python version (hopefully in a efficient enough way)

#include <cstdint>
#define COLOUR uint16_t
typedef	unsigned int uint;

struct Point {
    uint X;
    uint Y;
};

class Frame {
private:
    uint8_t *buffer;
public:
    uint Width;
    uint Height;
    Frame(uint8_t* buffer, uint width, uint height);

    COLOUR GetPixel(uint x, uint y);
    void SetPixel(uint x, uint y, COLOUR colour);

    void Fill(COLOUR colour);

    void DrawText(const char* text, Point p, COLOUR colour);

    void DrawRect(Point p1, Point p2, COLOUR colour);
    void DrawFilledRect(Point p1, Point p2, COLOUR colour);

    void DrawLine(Point p1, Point p2, COLOUR colour);
    void DrawHorizontalLine(Point p, uint width, COLOUR colour);
    void DrawVerticalLine(Point p, uint height, COLOUR colour);

    void Scroll(int x, int y);
    void Blit(const Frame* otherFrame, int x, int y);
};
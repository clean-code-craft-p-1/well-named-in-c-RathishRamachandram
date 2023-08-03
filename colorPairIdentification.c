#include <stdbool.h>
#include "main.h"

#define isCompatible(x, type) _Generic(x, type: true, default: false)

const char* MajorColorNames[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};
int numberOfMajorColors =
sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
const char* MinorColorNames[] = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};

int numberOfMinorColors =
sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);


void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s",
        MajorColorNames[colorPair->majorColor],
        MinorColorNames[colorPair->minorColor]);
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor =
        (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor =
        (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors +
        colorPair->minorColor + 1;
}

void PrintColourCode(void) {
    for (enum MajorColor major = WHITE; major < VIOLET; major++)
    {
        for (enum MinorColor minor = BLUE; minor < SLATE; minor++)
        {
            ColorPair colorPair;
            colorPair.majorColor = major;
            colorPair.minorColor = minor;

            int pairNumber = GetPairNumberFromColor(&colorPair);
            printf("Got pair number %d\n", pairNumber);

        }
    }   
}


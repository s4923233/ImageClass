#include <iostream>
#include "Image.h"
#include <random>

int main()
{
    std::cout<<"testing image\n";
    size_t width = 200;
    size_t height = 200;

    Image test(width,height);

    std::random_device rd;
    std::default_random_engine re(rd()) ;
    std::uniform_int_distribution<> colour(0, 255);
    std::uniform_int_distribution<> posx(0, width-1);
    std::uniform_int_distribution<> posy(0, height-1);

    test.clearScreen(255,255,255);

    for(int i=0; i<123346; ++i)
    {
        test.setPixel(posx(re),posy(re),
                      (unsigned char)colour(re),
                      (unsigned char)colour(re),
                      (unsigned char)colour(re));
    }

    test.save("random.png");
    return EXIT_SUCCESS;
}

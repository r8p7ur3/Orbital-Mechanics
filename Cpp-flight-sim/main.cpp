#define FPL_IMPLEMENTATION
#include "final_platform_layer.h"

#include <iostream>
using namespace std;

class soul {
    public:
    double speed;
    double acceleration;

};
int main (int argc, char **argv) {
// initialize window with video context
    if (fplPlatformInit(fplInitFlags_Window | fplInitFlags_Video, fpl_null)) {

//loop that keeps communication between running window and application (i think)
        while(fplWindowUpdate()) {
            fplEvent ev;
            while (fplPollEvent(&ev)) {

            }
        }

        fplPlatformRelease();
        return 0;
    } else {
        return -1;

    }
}

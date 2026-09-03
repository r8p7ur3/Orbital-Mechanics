#define FPL_IMPLEMENTATION
#include "final_platform_layer.h"

#include <iostream>
using namespace std;
// soul class (using for objects that move and interact with eachother later)
class soul {
    public:
    double speed;
    double acceleration;

};

char mexico ='P';

const char* title = &mexico;


int main (int argc, char **argv) {
    fplSetWindowTitle (title);
// initialize window with video context
    if (fplPlatformInit(fplInitFlags_Window | fplInitFlags_Video, fpl_null)) {


        
//loop that keeps communication between running window and application (i think)
        while(fplWindowUpdate()) {
            fplEvent ev;
            while (fplPollEvent(&ev)) {

            }
        }

//release window
        fplPlatformRelease();
        return 0;
    } else {
        return -1;

    }
}

#define FPL_IMPLEMENTATION
#include "final_platform_layer.h"
#include <math.h>
#include <glbinding/gl/gl.h>
#include <iostream>
using namespace std;
using namespace gl;
// soul class (using for objects that move and interact with eachother later)
class soul {
    private:
    double speed;
    double acceleration;


};

class values {
    private:
    string windowtitle;

};
char mexico ='P';

const char* title = &mexico;

//testing something
fplWindowSize curSize;

int main (int argc, char **argv) {

 
fplSettings settings;
fplSetDefaultSettings(&settings);
fplVideoSettings &videoSettings = settings.video;


//Open Gl for video backend
videoSettings.backend = fplVideoBackendType_OpenGL;

// initialize window with video context
    if (fplPlatformInit(fplInitFlags_Window | fplInitFlags_Video, &settings)) {

        glClearColor(0.0,0.0,0.0,1.0);
        //setting window string (Chikun cover ist sehr gut )
        fplSetWindowTitle("MIT ALLER MACHT");
        //all main OpenGL commands here
        if (fplGetWindowSize(&curSize)){
        

        }
        // set window size to 800x600
        fplSetWindowSize(800,600);
        char titleBuffer[FPL_MAX_NAME_LENGTH];
        fplGetWindowTitle(titleBuffer, fplArrayCount(titleBuffer));


        
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

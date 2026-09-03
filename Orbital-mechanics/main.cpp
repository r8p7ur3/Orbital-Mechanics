#define FPL_IMPLEMENTATION
#include "final_platform_layer.h"
#include <math.h>
#include <glbinding/gl/gl.h>
#include <glbinding/glbinding.h>
#include <iostream>


using namespace std;
using namespace gl;

// soul class (using for objects that move and interact with eachother later) (these are doing nothing until much later)
class soul {
    private:
    double speed;
    double acceleration;


};

class values {
    private:
    string windowtitle;

};


//testing something
fplWindowSize curSize;

int main (int argc, char **argv) {

 
fplSettings settings;
fplSetDefaultSettings(&settings);
fplVideoSettings &videoSettings = settings.video;


//Open Gl for video backend
videoSettings.backend = fplVideoBackendType_OpenGL;

videoSettings.graphics.opengl.compatibilityFlags = fplOpenGLCompatibilityFlags_Legacy;

// initialize window with video context
    if (fplPlatformInit(fplInitFlags_Window | fplInitFlags_Video, &settings)) {

      //FPL does not have an native way to pass the context to glbinding. Feast your eyes on this mess

      HMODULE opengl32 =LoadLibraryA("opengl32.dll");
      auto wglGetProcAddressFunc = reinterpret_cast<PROC (WINAPI *)(LPCSTR)>(
        GetProcAddress(opengl32,"wglGetProcAddress")

      );

      glbinding::initialize([opengl32, wglGetProcAddressFunc](const char *name) -> glbinding::ProcAddress
        {
            PROC proc = wglGetProcAddressFunc(name);
            //fallback
            if (!proc)
                proc = GetProcAddress (opengl32, name);

            return reinterpret_cast<glbinding::ProcAddress>(proc);
        }
    
    );  

        
        //setting window string (Chikun cover ist verdammt gut)
        fplSetWindowTitle("MIT ALLER MACHT");
        //all main OpenGL commands here
        if (fplGetWindowSize(&curSize)){
        

        }


        // set window size to 800x600
        fplSetWindowSize(800,600);
        char titleBuffer[FPL_MAX_NAME_LENGTH];
        fplGetWindowTitle(titleBuffer, fplArrayCount(titleBuffer));
        //look at later
        glClearColor(0.0f,0.0f,0.0f,1.0f);

        
//loop that keeps communication between running window and application (i think)
        while(fplWindowUpdate()) {
            fplEvent ev;
            while (fplPollEvent(&ev)) {
                

            }
            glClear(GL_COLOR_BUFFER_BIT);
        }


//release window
        fplPlatformRelease();
        return 0;
    } else {
        return -1;

    }
}

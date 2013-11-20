#ifndef SCENE_H
#define SCENE_H


#include <glm/glm.hpp>

#include "shader.h"
#include "model.h"
#include "rendercontext.h"

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include "texture.h"
#include "skybox.h"

#include "label.h"

class Scene
{
public:
    Scene();
    ~Scene();
    int start();
    void setMinFps(float fps);
private:
    bool mRunning = true;
    SDL_GLContext mContext;
    SDL_Window *mWindow;

    RenderContext m3DRenderContext;
    RenderContext m2DRenderContext;

    int mScreenWidth;
    int mScreenHeight;

    Model *mMonkeyModel;

    Skybox *mSkybox = NULL;


    float mMaxSpf;
    float mFps;
    Label *mFpsLabel;

    std::vector<SDL_Joystick*> mJoysticks;

    glm::vec3 mCameraPosition;
    glm::vec3 mCameraUp; // direction vector
    glm::vec3 mCameraForward; // direction vector

    void flushEvents();
    void update(float dt, float dx);
    void draw();
    void initJoystick();
};

#endif // SCENE_H

#include <ui/PixelFormat.h>
#include <ui/DisplayInfo.h>

namespace android {
    class Test {
        public:
                static const sp<ISurface>& getISurface(const sp<Surface>& s) {
                            return s->getISurface();
                }
    };
};

#define SURFACE_CREATE(client,surface_ctrl,android_surface, android_isurface, win_width, win_height) \
do {                                                                    \
    android::DisplayInfo info;                                          \
    client = new SurfaceComposerClient();                               \
                                                                        \
    client->getDisplayInfo(android::DisplayID(0), &info);               \
    printf("Screen resolution %dx%d,", info.w, info.h);                 \
    switch (info.orientation) {                                         \
    case android::ISurfaceComposer::eOrientationDefault:                \
        printf("normal orientation\n");                                 \
        break;                                                          \
    case android::ISurfaceComposer::eOrientation90:                     \
        printf("90 orientation\n");                                     \
        break;                                                          \
    case android::ISurfaceComposer::eOrientation180:                    \
        printf("180 orientation\n");                                    \
        break;                                                          \
    case android::ISurfaceComposer::eOrientation270:                    \
        printf("270 orientation\n");                                    \
        break;                                                          \
    default:                                                            \
        printf("Bad orientation returned from getDisplayIndo %d\n", info.orientation); \
        break;                                                          \
    }                                                                   \
    if (win_width > info.w)                                             \
        win_width = info.w;                                             \
    if (win_height > info.h)                                            \
        win_height = info.h;                                            \
                                                                        \
    surface_ctrl = client->createSurface(getpid(), 0, win_width, win_height, PIXEL_FORMAT_RGB_565, ISurfaceComposer::ePushBuffers); \
    android_surface = surface_ctrl->getSurface();                       \
    android_isurface = Test::getISurface(android_surface);              \
                                                                        \
    client->openTransaction();                                          \
    surface_ctrl->setPosition(0, 0);                                    \
    client->closeTransaction();                                         \
                                                                        \
    client->openTransaction();                                          \
    surface_ctrl->setSize(win_width, win_height);                       \
    client->closeTransaction();                                         \
                                                                        \
    client->openTransaction();                                          \
    surface_ctrl->setLayer(0x100000);                                   \
    client->closeTransaction();                                         \
} while (0)



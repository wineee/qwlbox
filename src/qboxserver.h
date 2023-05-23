#ifndef SERVER_H
#define SERVER_H

#include "qboxdecoration.h"
#include "qboxcursor.h"
#include "qboxseat.h"
#include "qboxoutput.h"
#include "qboxxdgshell.h"

#include <QRect>

#include <qwbackend.h>
#include <qwdisplay.h>
#include <qwsignalconnector.h>
#include <qwrenderer.h>
#include <qwallocator.h>
#include <qwcompositor.h>
#include <qwsubcompositor.h>
#include <qwdatadevice.h>
#include <qwoutputlayout.h>
#include <qwoutput.h>
#include <qwscene.h>
#include <qwseat.h>
#include <qwxdgshell.h>
#include <qwcursor.h>
#include <qwxcursormanager.h>
#include <qwinputdevice.h>
#include <qwkeyboard.h>
#include <qwpointer.h>

extern "C" {
// avoid replace static
#include <wayland-server-core.h>
#define static
#include <wlr/util/log.h>
#include <wlr/util/edges.h>
#include <wlr/types/wlr_keyboard.h>
#include <wlr/types/wlr_seat.h>
#include <wlr/types/wlr_output.h>
#include <wlr/types/wlr_xdg_shell.h>
#include <wlr/types/wlr_scene.h>
#include <wlr/types/wlr_data_device.h>
#undef static
#include <wayland-server.h>
}
QW_USE_NAMESPACE

class QBoxServer : public QObject
{
    Q_OBJECT
    friend class QBoxDecoration;
    friend class QBoxCursor;
    friend class QBoxSeat;
    friend class QBoxOutPut;
    friend class QBoxXdgShell;
    using View = QBoxOutPut::View;

public:
    QBoxServer();
    ~QBoxServer();

    bool start();

private:
    QWDisplay *display;
    QWBackend *backend;
    QWRenderer *renderer;
    QWAllocator *allocator;

    QWCompositor *compositor;
    QWSubcompositor *subcompositor;
    QWDataDeviceManager *dataDeviceManager;

    QBoxOutPut *output;
    QBoxXdgShell *xdgShell;

    QBoxDecoration *decoration;

    QBoxCursor *cursor;

    QBoxSeat *seat;
    QWSignalConnector sc;
};

#endif // SERVER_H

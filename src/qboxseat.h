#ifndef QBOXSEAT_H
#define QBOXSEAT_H

#include <qwseat.h>
#include <qwkeyboard.h>
#include <qwinputdevice.h>
#include <QObject>

extern "C" {
#include <xkbcommon/xkbcommon.h>
}

using QW_NAMESPACE::QWSeat;
using QW_NAMESPACE::QWKeyboard;
using QW_NAMESPACE::QWInputDevice;

class QBoxServer;

class QBoxSeat : public QObject
{
    Q_OBJECT
    friend class QBoxServer;
    friend class QBoxCursor;
public:
    explicit QBoxSeat(QBoxServer *server = nullptr);

private:
    void onRequestSetCursor(wlr_seat_pointer_request_set_cursor_event *event);
    void onRequestSetSelection(wlr_seat_request_set_selection_event *event);

    void onNewInput(QWInputDevice *device);

    void onKeyboardModifiers();
    void onKeyboardKey(wlr_keyboard_key_event *event);
    void onKeyboardDestroy();
    bool handleKeybinding(xkb_keysym_t sym);

    QWSeat *m_seat;
    QList<QWKeyboard*> m_keyboards;

    QBoxServer *m_server;
};

#endif // QBOXSEAT_H
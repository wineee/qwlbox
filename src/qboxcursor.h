#ifndef QBOXCURSOR_H
#define QBOXCURSOR_H

#include <qwcursor.h>
#include <qwxcursormanager.h>
#include <qwseat.h>

#include <QObject>

using QW_NAMESPACE::QWCursor;
using QW_NAMESPACE::QWXCursorManager;
using QW_NAMESPACE::QWSeat;

class QBoxServer;

class QBoxCursor : public QObject
{
    Q_OBJECT
    friend class QBoxServer; // TODO : should be QBoxXdgShell
    friend class QBoxSeat;

public:
    explicit QBoxCursor(QBoxServer *parent = nullptr);

    enum class CursorState {
        Normal,
        MovingWindow,
        ResizingWindow,
    };

private Q_SLOTS:
    void onCursorMotion(wlr_pointer_motion_event *event);
    void onCursorMotionAbsolute(wlr_pointer_motion_absolute_event *event);
    void onCursorButton(wlr_pointer_button_event *event);
    void onCursorAxis(wlr_pointer_axis_event *event);
    void onCursorFrame();

private:
    void processCursorMotion(uint32_t time);
    QWSeat *getSeat();

    QWCursor *m_cursor;
    QWXCursorManager *m_cursorManager;
    CursorState cursorState = CursorState::Normal;
    QBoxServer *m_service;
};

#endif // QBOXCURSOR_H

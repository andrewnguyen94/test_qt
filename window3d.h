#ifndef WINDOW3D_H
#define WINDOW3D_H

#include <qwidget.h>
#include <qt3dwindow.h>
#include <qmouseevent.h>
#include <qscreen.h>

class Window3D : public Qt3DExtras::Qt3DWindow
{
    Q_OBJECT
public:
    explicit Window3D(Qt3DExtras::Qt3DWindow *parent = nullptr);
    ~Window3D();

    void mouseMoveEvent(QMouseEvent *ev) override;
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;

    int x_move, y_move, x_press, y_press, x_release, y_release;
};

#endif // WINDOW3D_H

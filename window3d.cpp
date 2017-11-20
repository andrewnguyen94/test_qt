#include "window3d.h"

Window3D::Window3D(Qt3DExtras::Qt3DWindow *parent) :
    Qt3DExtras::Qt3DWindow()
{

}
Window3D::~Window3D(){

}

void Window3D::mouseMoveEvent(QMouseEvent *ev)
{
    this->x_move = ev->x();
    this->y_move = ev->y();
}

void Window3D::mousePressEvent(QMouseEvent *ev)
{
    this->x_press = ev->x();
    this->y_press = ev->y();
}

void Window3D::mouseReleaseEvent(QMouseEvent *ev)
{
    this->x_release = ev->x();
    this->y_release = ev->y();
}






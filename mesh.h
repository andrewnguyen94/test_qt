#ifndef MESH_H
#define MESH_H

#include <qmesh.h>

class Mesh : public Qt3DRender::QMesh
{
public:
    explicit Mesh(Qt3DRender::QMesh *parent = nullptr);
    ~Mesh();

    QVector2D getWindowCoordinate(QMatrix projectionMatrix, QMatrix viewMatrix, QVector3D point3D, QVector2D viewSize,
                                QVector2D viewOffset);
};

#endif // MESH_H

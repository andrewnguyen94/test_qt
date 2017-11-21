#include "mesh.h"


Mesh::Mesh(Qt3DRender::QMesh *parent) :
    Qt3DRender::QMesh(parent)
{

}

Mesh::~Mesh(){

}

QVector2D Mesh::getWindowCoordinate(QMatrix projectionMatrix, QMatrix viewMatrix, QVector3D point3D, QVector2D viewSize, QVector2D viewOffset)
{
    QVector4D clipSpacePos = projectionMatrix * (viewMatrix * QVector4D(point3D, 1.0));
    QVector3D ndcSpacePos = clipSpacePos.xyz / clipSpacePos.w;
    QVector2D windowSpacePos = ((ndcSpacePos.xy + 1.0) / 2.0) * viewSize + viewOffset;
    return windowSpacePos;
}



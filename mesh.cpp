#include "mesh.h"
#include <qvector.h>
#include <qvector4d.h>
#include <qvector3d.h>
#include <qvector2d.h>
#include <qmatrix4x4.h>


Mesh::Mesh(Qt3DRender::QMesh *parent) :
    Qt3DRender::QMesh(parent)
{

}

Mesh::~Mesh(){

}

QVector2D Mesh::getWindowCoordinate(QMatrix4x4 projectionMatrix, QMatrix4x4 viewMatrix, QVector3D point3D, QVector2D viewSize, QVector2D viewOffset)
{
    QVector4D clipSpacePos = projectionMatrix * (viewMatrix * QVector4D(point3D, 1.0));
    QVector3D ndcSpacePos = QVector3D(clipSpacePos.x()/clipSpacePos.w(), clipSpacePos.y() / clipSpacePos.w(),
                                      clipSpacePos.z() / clipSpacePos.w()) ;
    QVector2D windowSpacePos = QVector2D(((ndcSpacePos.x() + 1.0) / 2.0) * viewSize.x() + viewOffset.x(),
                                         ((ndcSpacePos.y() + 1.0) / 2.0) * viewSize.y() + viewOffset.y());
    return windowSpacePos;
}



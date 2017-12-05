#include "logoone.h"
#include <qmath.h>

LogoOne::LogoOne()
    : m_count(0)
{
    m_data.resize(2500 * 6);

    const GLfloat x1 = +0.06f;
    const GLfloat y1 = -0.14f;
    const GLfloat x2 = +0.14f;
    const GLfloat y2 = -0.06f;
    const GLfloat x3 = +0.08f;
    const GLfloat y3 = +0.00f;
    const GLfloat x4 = +0.30f;
    const GLfloat y4 = +0.22f;

    quadOne(x1, y1, x2, y2, y2, x2, y1, x1);
    quadOne(x3, y3, x4, y4, y4, x4, y3, x3);

    extrudeOne(x1, y1, x2, y2);
    extrudeOne(x2, y2, y2, x2);
    extrudeOne(y2, x2, y1, x1);
    extrudeOne(y1, x1, x1, y1);
    extrudeOne(x3, y3, x4, y4);
    extrudeOne(x4, y4, y4, x4);
    extrudeOne(y4, x4, y3, x3);

    const int NumSectors = 10;

    for (int i = 0; i < NumSectors; ++i) {
        GLfloat angle = (i * 2 * M_PI) / NumSectors;
        GLfloat angleSin = qSin(angle);
        GLfloat angleCos = qCos(angle);
        const GLfloat x5 = 0.30f * angleSin;
        const GLfloat y5 = 0.30f * angleCos;
        const GLfloat x6 = 0.20f * angleSin;
        const GLfloat y6 = 0.20f * angleCos;

        angle = ((i + 1) * 2 * M_PI) / NumSectors;
        angleSin = qSin(angle);
        angleCos = qCos(angle);
        const GLfloat x7 = 0.20f * angleSin;
        const GLfloat y7 = 0.20f * angleCos;
        const GLfloat x8 = 0.30f * angleSin;
        const GLfloat y8 = 0.30f * angleCos;

        quadOne(x5, y5, x6, y6, x7, y7, x8, y8);

        extrudeOne(x6, y6, x7, y7);
        extrudeOne(x8, y8, x5, y5);
    }
}

void LogoOne::addOne(const QVector3D &v, const QVector3D &n)
{
    GLfloat *p = m_data.data() + m_count;
    *p++ = v.x();
    *p++ = v.y();
    *p++ = v.z();
    *p++ = n.x();
    *p++ = n.y();
    *p++ = n.z();
    m_count += 6;
}

void LogoOne::quadOne(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4)
{
    QVector3D n = QVector3D::normal(QVector3D(x4 - x1, 0.0f, y4 - y1), QVector3D(x2 - x1, 0.0f, y2 - y1));

    addOne(QVector3D(x1, -0.05f, y1), n);
    addOne(QVector3D(x4, -0.05f, y4), n);
    addOne(QVector3D(x2, -0.05f, y2), n);

    addOne(QVector3D(x3, -0.05f, y3), n);
    addOne(QVector3D(x2, -0.05f, y2), n);
    addOne(QVector3D(x4, -0.05f, y4), n);

    n = QVector3D::normal(QVector3D(x1 - x4, 0.0f, y1 - y4), QVector3D(x2 - x4, 0.0f,y2 - y4));

    addOne(QVector3D(x4, 0.05f, y4), n);
    addOne(QVector3D(x1, 0.05f, y1), n);
    addOne(QVector3D(x2, 0.05f, y2), n);

    addOne(QVector3D(x2, 0.05f, y2), n);
    addOne(QVector3D(x3, 0.05f, y3), n);
    addOne(QVector3D(x4, 0.05f, y4), n);

}

void LogoOne::extrudeOne(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
    QVector3D n = QVector3D::normal(QVector3D(0.0f, -0.05f, 0.0f), QVector3D(x2 - x1, 0.0f, y2 - y1));

    addOne(QVector3D(x1, +0.05f, y1), n);
    addOne(QVector3D(x1, -0.05f, y1), n);
    addOne(QVector3D(x2, +0.05f, y2), n);

    addOne(QVector3D(x2,-0.05f, y2), n);
    addOne(QVector3D(x2, +0.05f, y2), n);
    addOne(QVector3D(x1, -0.05f, y1), n);
}

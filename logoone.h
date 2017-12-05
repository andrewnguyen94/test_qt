#ifndef LOGOONE_H
#define LOGOONE_H

#include <qopengl.h>
#include <QVector>
#include <QVector3D>

class LogoOne
{
public:
    LogoOne();
    const GLfloat *constDataOne() const { return m_data.constData(); }
    int countOne() const { return m_count; }
    int vertexCountOne() const { return m_count / 6; }
private:
    void quadOne(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4);
    void extrudeOne(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
    void addOne(const QVector3D &v, const QVector3D &n);

    QVector<GLfloat> m_data;
    int m_count;
};

#endif // LOGOONE_H

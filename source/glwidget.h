#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QMouseEvent>
#include <QtGui/QOpenGLWindow>
#include <QtGui/QOpenGLBuffer>
#include <QtGui/QOpenGLFunctions>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QOpenGLVertexArrayObject>
#include <modelloader.h>
class GLWidget : public QGLWidget, QOpenGLFunctions
{
public:
    GLWidget(QWidget *parent = nullptr,QString geometrypath="");
    /*!
     * \brief initializeGL
     */
    QString                  geometryName;
    void createShaderProgram();
    void createGeometry();
    void initializeGL();
    void mouseMoveEvent(QMouseEvent *event);
    void normalizeAngle(int *angle);
    void setRotationX(int angle);
    void setRotationY(int angle);
    void setRotationZ(int angle);
    void paintGL();
    void drawNode(const QMatrix4x4& model, const Node *node, QMatrix4x4 parent);
    void draw();
    void resizeGL(int w, int h);

    QPoint lastPos;
    int xRot=0,yRot=0,zRot=0;
    ModelLoader              m_loader;
    QMatrix4x4 m_projection, m_view;
    QOpenGLShaderProgram     m_pgm;
    QOpenGLVertexArrayObject m_vao;
    QOpenGLBuffer            m_vbo, m_nbo;
    QOpenGLBuffer            m_ibo;
    GLsizei                  m_cnt;

};

#endif // GLWIDGET_H

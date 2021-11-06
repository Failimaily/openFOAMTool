#include "glwidget.h"

static QString vertexShader =
        "#version 330 core \n"
        "\n"
        "layout(location = 0) in vec3 vertexPosition;\n"
        "layout(location = 1) in vec3 vertexNormal;\n"
        "\n"
        "out vec3 normal;\n"
        "out vec3 position;\n"
        "\n"
        "uniform mat4 MV;\n"
        "uniform mat3 N;\n"
        "uniform mat4 MVP;\n"
        " \n"
        "void main()\n"
        "{\n"
        "    normal = normalize( N * vertexNormal );\n"
        "    position = vec3( MV * vec4( vertexPosition, 1.0 ) );\n"
        "    gl_Position = MVP * vec4( vertexPosition, 1.0 );\n"
        "}\n"
        ;

static QString fragmentShader =
        "#version 330 core \n"
        "\n"
        "in vec3 normal;\n"
        "in vec3 position;\n"
        "\n"
        "layout (location = 0) out vec4 fragColor;\n"
        "\n"
        "struct Light\n"
        "{\n"
        "    vec4 position;\n"
        "    vec3 intensity;\n"
        "};\n"
        "uniform Light light;\n"
        "\n"
        "struct Material {\n"
        "    vec3 Ka;\n"
        "    vec3 Kd;\n"
        "    vec3 Ks;\n"
        "    float shininess;\n"
        "};\n"
        "uniform Material material;\n"
        "\n"
        "void main()\n"
        "{\n"
        "    vec3 n = normalize( normal);\n"
        "    vec3 s = normalize( light.position.xyz - position);\n"
        "    vec3 v = normalize( -position.xyz);\n"
        "    vec3 h = normalize( v + s);\n"
        "    float sdn = dot( s, n);\n"
        "    vec3 ambient = material.Ka;\n"
        "    vec3 diffuse = material.Kd * max( sdn, 0.0);\n"
        "    vec3 specular = material.Ks * mix( 0.0, pow( dot(h, n), material.shininess), step( 0.0, sdn));\n"
        "    fragColor = vec4(light.intensity * (ambient + diffuse + specular), 1);\n"
        "}\n"
        ;

GLWidget::GLWidget(QWidget* parent,QString geometryPath):
    QGLWidget(parent),
    m_vbo(QOpenGLBuffer::VertexBuffer),
    m_nbo(QOpenGLBuffer::VertexBuffer),
    m_ibo(QOpenGLBuffer::IndexBuffer)
{
    qDebug() << g_pprojectsettings->modelName << "constructor";
     g_pprojectsettings->modelName = QString(geometryPath.toUtf8());
    qDebug() << g_pprojectsettings->modelName << "constructor";
}

void GLWidget::createShaderProgram()
{
    if ( !m_pgm.addShaderFromSourceCode( QOpenGLShader::Vertex, vertexShader)) {
        qDebug() << "Error in vertex shader:" << m_pgm.log();
        //exit(1);
    }
    if ( !m_pgm.addShaderFromSourceCode( QOpenGLShader::Fragment, fragmentShader)) {
        qDebug() << "Error in fragment shader:" << m_pgm.log();
        //exit(1);
    }
    if ( !m_pgm.link() ) {
        qDebug() << "Error linking shader program:" << m_pgm.log();
        //exit(1);
    }
}

void GLWidget::createGeometry()
{
    //TODO Load Specified File from MainWindow
qDebug() <<  g_pprojectsettings->modelName << "createGeometry";
    if(!m_loader.Load( g_pprojectsettings->modelName)) {
        qDebug() << "ModelLoader failed to load model" << m_pgm.log();
        //exit(1);
    }
    else
    {
        // Get the loaded model data from the model-loader: (v)ertices, (n)ormals, and (i)ndices
        QVector<float> *v, *n; QVector<unsigned int> *i; m_loader.getBufferData(&v, &n, &i);

        // Initialize and bind the VAO that's going to capture all this vertex state
        m_vao.create();
        m_vao.bind();

        // Put all the vertex data in a FBO
        m_vbo.create();
        m_vbo.setUsagePattern( QOpenGLBuffer::StaticDraw );
        m_vbo.bind();
        m_vbo.allocate(&(*v)[0], v->size() * sizeof((*v)[0]));

        // Configure the attribute stream
        m_pgm.enableAttributeArray(0);
        m_pgm.setAttributeBuffer(0, GL_FLOAT, 0, 3);

        // Put all the normal data in a FBO
        m_nbo.create();
        m_nbo.setUsagePattern( QOpenGLBuffer::StaticDraw );
        m_nbo.bind();
        m_nbo.allocate(&(*n)[0], n->size() * sizeof((*n)[0]));

        // Configure the attribute stream
        m_pgm.enableAttributeArray(1);
        m_pgm.setAttributeBuffer(1, GL_FLOAT, 0, 3);

        // Put all the index data in a IBO
        m_ibo.create();
        m_ibo.setUsagePattern( QOpenGLBuffer::StaticDraw );
        m_ibo.bind();
        m_ibo.allocate(&(*i)[0], i->size() * sizeof((*i)[0]));

        // Okay, we've finished setting up the vao
        m_vao.release();
    }
}

void GLWidget::initializeGL()
{
    qDebug() <<  g_pprojectsettings->modelName << " initializeGL";
    QOpenGLFunctions::initializeOpenGLFunctions();
    createShaderProgram(); m_pgm.bind();

    m_pgm.setUniformValue("light.position",   QVector4D( -1.0f,  1.0f, 1.0f, 1.0f ));
    m_pgm.setUniformValue("light.intensity",  QVector3D(  1.0f,  1.0f, 1.0f  ));

    createGeometry();
    m_view.setToIdentity();
    m_view.lookAt(QVector3D(0.0f, 0.0f, 5.0f),    // Camera Position
                  QVector3D(0.0f, 0.0f, 0.0f),    // Point camera looks towards
                  QVector3D(0.0f, 1.0f, 0.0f));   // Up vector

    glEnable(GL_DEPTH_TEST);

    glClearColor(.9f, .9f, .93f ,1.0f);
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

     if (event->buttons() & Qt::LeftButton) {
         setRotationX(xRot + 2 * dy);
         setRotationY(yRot + 2 * dx);
     } else if (event->buttons() & Qt::RightButton) {
         setRotationX(xRot + 2 * dy);
         setRotationZ(zRot + 2 * dx);
     }
     lastPos = event->pos();
}

void GLWidget::normalizeAngle(int *angle)
{
    while (*angle < 0)
             *angle += 360 * 16;
         while (*angle > 360 * 16)
             *angle -= 360 * 16;
}

void GLWidget::setRotationX(int angle)
{
    normalizeAngle(&angle);
    if (angle != xRot)
    {
             xRot = angle;
             //emit xRotationChanged(angle);
             updateGL();
    }
}

void GLWidget::setRotationY(int angle)
{
    normalizeAngle(&angle);
    if (angle != yRot)
    {
             yRot = angle;
             //emit xRotationChanged(angle);
             updateGL();
    }
}

void GLWidget::setRotationZ(int angle)
{
    normalizeAngle(&angle);
    if (angle != zRot)
    {
             zRot = angle;
             //emit xRotationChanged(angle);
             updateGL();
    }
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    qDebug()<< g_pprojectsettings->modelName << "paintGL";
    if(m_vbo.isCreated())
    {
        m_pgm.bind();
        m_vao.bind();
        draw();
        m_vao.release();
        update();
    }
}

void GLWidget::drawNode(const QMatrix4x4& model, const Node *node, QMatrix4x4 parent)
{
    QMatrix4x4 local = parent * node->transformation;
            QMatrix4x4 mv = m_view * model; //* local;

            m_pgm.setUniformValue("MV",  mv);
            m_pgm.setUniformValue("N",   mv.normalMatrix());
            m_pgm.setUniformValue("MVP", m_projection * mv);
            //qDebug() << node->transformation;
            // Draw each mesh in this node
            // TODO Implement Coloration acording to patch type (wall, inlet ,etc)
            for(int i = 0; i<node->meshes.size(); ++i)
            {
                const Mesh& m = *node->meshes[i];
                qDebug() << m.indexOffset;
                if (m.material->Name == QString("DefaultMaterial")) {
                    m_pgm.setUniformValue("material.Ka",        QVector3D(  0.05f, 0.2f, 0.05f ));
                    m_pgm.setUniformValue("material.Kd",        QVector3D(  0.3f,  0.5f, 0.3f  ));
                    m_pgm.setUniformValue("material.Ks",        QVector3D(  0.6f,  0.6f, 0.6f  ));
                    m_pgm.setUniformValue("material.shininess", 50.f);
                } else {
                    m_pgm.setUniformValue("material.Ka",        m.material->Ambient);
                    m_pgm.setUniformValue("material.Kd",        m.material->Diffuse);
                    m_pgm.setUniformValue("material.Ks",        m.material->Specular);
                    m_pgm.setUniformValue("material.shininess", m.material->Shininess);
                }

                glDrawElements(GL_TRIANGLES, m.indexCount, GL_UNSIGNED_INT, (const GLvoid*)(m.indexOffset * sizeof(GLuint)));
            }

            // Recursively draw this nodes children nodes
            for(int i = 0; i < node->nodes.size(); ++i)
                drawNode(model, &node->nodes[i], local);
}

void GLWidget::draw()
{
    QMatrix4x4 model;
    model.translate(-0.2f, 0.0f, .5f);
    model.rotate(zRot/16.0, 0.0f, 0.0f, 1.0f);
    model.rotate(xRot/16.0, 1.0f, 0.0f, 0.0f);
    model.rotate(yRot/16.0, 0.0f, 1.0f, 0.0f);

    drawNode(model, m_loader.getNodeData().data(), QMatrix4x4());
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    m_projection.setToIdentity();
    m_projection.perspective(60.0f, (float)w/h, .3f, 1000);
    update();
}

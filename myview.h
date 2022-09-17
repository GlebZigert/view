#ifndef MYVIEW_H
#define MYVIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QSharedPointer>
#include <QWheelEvent>

class MyView : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene* scene;

    QGraphicsRectItem *area;

    QGraphicsItem *rect;

    QPointF prev;

    int area_h;
    int area_w;

    int rect_h;
    int rect_w;

    bool flag;

    qreal scale;

    void zoomIn();
    void zoomOut();

    void scaleView(qreal scaleFactor);

public:
    MyView(QWidget *parent = 0);
    ~MyView();

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void wheelEvent(QWheelEvent *event) override;
signals:

};

#endif // MYVIEW_H

#ifndef MYVIEW_H
#define MYVIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QSharedPointer>
#include <QWheelEvent>
#include <myitem.h>
#include <QGraphicsItemGroup>

class MyView : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene* scene;

    QGraphicsRectItem *area;

      QGraphicsItemGroup  *points;

    MyItem *rect;

    QPointF prev;
    int n;
    int area_h;
    int area_w;

    int rect_h;
    int rect_w;

    bool flag;

    qreal scale;
     QList<QPointF> list;
    void zoomIn();
    void zoomOut();
    void deleteItemsFromGroup(QGraphicsItemGroup *group);
     void update_meta();

    bool scaleView(qreal scaleFactor);

public:
    MyView(QWidget *parent = 0);
    ~MyView();
    void update_ladmarks( QList<QPointF> list);
    void load(QString filapath);

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void wheelEvent(QWheelEvent *event) override;
signals:

};

#endif // MYVIEW_H

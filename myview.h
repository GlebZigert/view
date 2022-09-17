#ifndef MYVIEW_H
#define MYVIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QSharedPointer>

class MyView : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene* scene;

    QGraphicsItem *area;

    QGraphicsItem *rect;

    QPointF prev;

    int area_h;
    int area_w;

    int rect_h;
    int rect_w;

    bool flag;

public:
    MyView(QWidget *parent = 0);
    ~MyView();

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
signals:

};

#endif // MYVIEW_H

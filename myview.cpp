#include "myview.h"
#include <QGraphicsRectItem>
#include <QDebug>
#include <QTime>

MyView::MyView(QWidget *parent)
    : QGraphicsView(parent)
{
    scene = new QGraphicsScene();
    setScene(scene);

    scene->addEllipse(0,0,1,1);

     area_h=100;
     area_w=100;

     rect_h=180;
     rect_w=180;


flag = false;

    area = new QGraphicsRectItem(0,0,area_w,area_h);
    area->setFlag(QGraphicsItem::ItemIsMovable,false);
    scene->addItem(area);

    rect = new QGraphicsRectItem(0,0,rect_w,rect_h);
    rect->setFlag(QGraphicsItem::ItemIsMovable,true);
    scene->addItem(rect);

    qDebug()<<"1: "<<rect->x()<<" "<<rect->y();
    rect->moveBy(-10,-10);
    qDebug()<<"2: "<<rect->x()<<" "<<rect->y();
}

MyView::~MyView()
{

}

void MyView::mouseMoveEvent(QMouseEvent *event)
{
     QPointF f =mapToScene(viewport()->mapFromGlobal(QCursor::pos()));

     int x = -(prev.x()-f.x());
     int y = -(prev.y()-f.y());

  //   qDebug()<<x<<" "<<y;

     if(flag==true){

         qDebug()<<rect->mapToScene(0,0).x()<<" "<<area->mapToScene(0,0).x();

        if(rect->mapToScene(0,0).x()+x<area->mapToScene(0,0).x())
        if(rect->mapToScene(rect_w,0).x()+x>area->mapToScene(area_w,0).x())

        if(rect->mapToScene(0,0).y()+y<area->mapToScene(0,0).y())
        if(rect->mapToScene(0,rect_h).y()+y>area->mapToScene(0,area_h).y())
         rect->moveBy(x,y);
     }

     prev=f;


}

void MyView::mousePressEvent(QMouseEvent *event)
{

     QPointF f =mapToScene(viewport()->mapFromGlobal(QCursor::pos()));

     QPointF ff=rect->mapFromScene(f);

    auto res = rect->contains(ff);

    if(res==true)
        flag=true;

    qDebug()<<res;

    prev=f;

}

void MyView::mouseReleaseEvent(QMouseEvent *event)
{
flag=false;
}

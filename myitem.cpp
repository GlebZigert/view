// myitem.cpp

#include "myitem.h"
#include <QImageReader>

MyItem::MyItem()
{
    load("/home/administrator/8299.jpg");
    this->width=pxm.width();
    this->height=pxm.height();

    setFlag(ItemIsMovable);
}

QRectF MyItem::boundingRect() const
{
    // outer most edges
    return QRectF(0,0,1920,1080);
   // return QRectF(0,0,100,100);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    qDebug()<<"paint";
    QRectF rect = boundingRect();


        painter->drawEllipse(-1,-1,1,1);
        painter->drawPixmap(0,0,1920,1080,pxm);

        foreach(QPointF point, list){
            painter->drawEllipse(point.x(),
                                 point.y(),
                                 1,
                                 1);
        }

}

void MyItem::load(QString qStrFilePath)
{

        if (qStrFilePath.isEmpty())
            return;

        QImageReader reader(qStrFilePath);
        if (!reader.canRead())
        {

            qDebug()<<"Cannot read file";

            return;
        }

        QImage qimg = reader.read();

        pxm = QPixmap::fromImage(qimg);

        this->width=pxm.width();
        this->height=pxm.height();



        update();
}

void MyItem::addPoint(QPointF point)
{
    list.append(point);
}



void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    update();
    QGraphicsItem::mousePressEvent(event);
}

void MyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

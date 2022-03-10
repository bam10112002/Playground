#ifndef MYGRAPHICVIEW_H
#define MYGRAPHICVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QWidget>

#include <string>
#include <fstream>
#include "../json/single_include/nlohmann/json.hpp"
#include "v_map.h"

class MyGraphicView : public QGraphicsView
{
    Q_OBJECT;

public:
    MyGraphicView(QWidget *parent);

    V_Map mp;

private:
    QGraphicsScene          *scene;     // сцена для отрисовки
    QGraphicsItemGroup      *mapGroup;  // группа клеток карты
    QGraphicsItemGroup      *SFGroup;   // группа для отрисовки старта и финиша
    QGraphicsItemGroup      *arrowGroup; // группа отрисовки стрелочек

    int sceneWidth;
    int sceneHeight;

    void resizeEvent(QResizeEvent *event) override; // перегрузка ивента изменения размера


private:
    void createMapView(std::string mapName);

};

#endif // MYGRAPHICVIEW_H

#include "mygraphicview.h"


MyGraphicView::MyGraphicView(QWidget *parent):QGraphicsView(parent)
{
    // отключаем скроллбар
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setAlignment(Qt::AlignCenter);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    sceneWidth = parent->width()*0.8;
    sceneHeight = parent->height()*0.9;


    // задаем сцену
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0, sceneWidth, sceneHeight);
    this->setScene(scene);

    // задаем группы объектов
    mapGroup = new QGraphicsItemGroup();
    arrowGroup = new QGraphicsItemGroup();
    SFGroup = new QGraphicsItemGroup();

    scene->addItem(mapGroup);
    scene->addItem(arrowGroup);
    scene->addItem(SFGroup);


    // Задаем грацицы сцены
    QGraphicsRectItem* it = new QGraphicsRectItem(0, 0, parent->width()*0.8, parent->height()*0.9);
    it->setPos(0,0);
    scene->addItem(it);


    mp = V_Map(mapGroup,std::string("C:/Users/Artem/Documents/test/map_1.json"),std::string("C:/Users/Artem/Documents/test/Cells.json"));

//    std::vector<std::vector<std::string>> vector_matrix = JSON["matrix"].get<std::vector<std::vector<std::string>>>();
//	int height = vector_matrix.size();
//	int width = vector_matrix[0].size();

//	for (int i = 0; i < height; i++)
//	{
//		for (int j = 0; j < width; j++)
//		{
//            if (vector_matrix[i][j] == "EMPTY"){}
//            else if (vector_matrix[i][j] == "WALL"){}
//            else if (vector_matrix[i][j] == "FOREST"){}

//		}
//	}


    // Задаем картинку

//    for (int i = 0; i < sceneWidth;i += 120)
//    {
//        QGraphicsPixmapItem *item = new QGraphicsPixmapItem();
//        item->setPixmap(QPixmap("forest.jpg"));
//        item->setPos(i,0);
//        scene->addItem(item);
//    }
}

void MyGraphicView::resizeEvent(QResizeEvent *event)
{

    //перерисовка элементов
    QGraphicsView::resizeEvent(event);
}

void MyGraphicView::createMapView(std::string mapName)
{
    std::ifstream f(mapName);


}


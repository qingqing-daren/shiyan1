#include "qipan.h"
#include <QPainter>
#include <QDebug>
//构造函数
qipan::qipan(QWidget *parent) : QWidget(parent),row1(-1),col1(-1),flag(false)
{
    //初始化数组为空
    for(int i=0;i<bsize;i++)
    {
        for(int j=0;j<bsize;j++)
        {
            m_board[i][j]=EMPTY;
        }
    }

    //设置鼠标追踪
    setMouseTracking(true);
}
//绘画事件
void qipan::paintEvent(QPaintEvent *event)
{
    //创建画家类
    QPainter painter(this);

    //去除毛刺-抗锯齿
    painter.setRenderHint(QPainter::Antialiasing);

    //设置棋盘背景颜色
    QColor background=QColor(227, 235, 205);//青草绿
    painter.fillRect(rect(),background);//填充颜色

    //绘制棋盘
    for(int i=0;i<bsize;i++)
    {
        //画竖线
    painter.drawLine(margin+i*cellsize,margin,
                     margin+i*cellsize,margin+cellsize*(bsize-1));
        //画横线
    painter.drawLine(margin,margin+i*cellsize,
                     margin+cellsize*(bsize-1),margin+i*cellsize);

    }
    //绘制悬停点坐标
    if((flag=true)&&(row1>=0&&row1<bsize)&&(col1>=0&&col1<bsize)&&m_board[row1][col1]==EMPTY)
    {
        //设置笔刷
    painter.setBrush(Qt::black);

    painter.drawEllipse(QPoint(margin+cellsize*row1,margin+cellsize*col1),
                        cellsize/6,cellsize/6);
    }


    //绘制棋子
    for(int i=0;i<bsize;i++)
    {
        for(int j=0;j<bsize;j++)
        {
            if(m_board[i][j]==PLAYER)
            {
                setBrush//未完
            }
        }

    }

}
//判断坐标以及悬停点
void qipan::mouseMoveEvent(QMouseEvent *event)
{
    //打印x，y坐标
    int row = (event->x()-margin+cellsize/2)/cellsize ;
    int col = (event->y()-margin+cellsize/2)/cellsize ;
    qDebug() << "row=" << row << endl;
    qDebug() << "col=" << col << endl;

    if((row>=0&&row<bsize)&&(col>=0&&col<bsize))
    {
        if(row1!=row||col1!=col)
        {
            row1=row;
            col1=col;
            flag=true;

            //手动触发绘画事件，让函数qipan再触发一次
            update();
        }
    }
    else
    {
        flag=false;
        //鼠标在棋盘外时，清空悬浮点
        row1=-1;
        col1=-1;
        //手动触发绘画事件
        update();
    }

    //鼠标点击事件

}

//鼠标点击事件
void qipan::mousePressEvent(QMouseEvent *event)
{
    int row = (event->x()-margin+cellsize/2)/cellsize ;
    int col = (event->y()-margin+cellsize/2)/cellsize ;

    //判断鼠标是否在棋盘内
    if((row>=0&&row<bsize)&&(col>=0&&col<bsize)&&m_board[row][col]==EMPTY)
    {
      m_board[row][col]==PLAYER;
      //手动触发绘画事件
      update();
    }

}

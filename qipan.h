#ifndef QIPAN_H
#define QIPAN_H

#include <QWidget>
#include<QMouseEvent>
#include "stdshared.h"

class qipan : public QWidget
{
    Q_OBJECT
public:
    explicit qipan(QWidget *parent = nullptr);

private:
    //绘画事件
    void paintEvent(QPaintEvent *event) override;
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event) override;
    //鼠标点击事件
    void mousePressEvent(QMouseEvent *event) override;
signals:

public slots:

private:
    static const int bsize=15;//棋盘规格;
    static const int cellsize=60;//方块格尺寸；
    static const int margin=40;//棋盘距离边缘距离;

    //数组：棋盘上的点
    ROLE m_board[bsize][bsize];
    //悬停点
    int row1;
    int col1;
    //是否需要绘制悬停点
    bool flag;

};

#endif // QIPAN_H

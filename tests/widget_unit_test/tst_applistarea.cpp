#include <gtest/gtest.h>

#include <QApplication>
#include <QWheelEvent>

#include "applistarea.h"


class Tst_Applistarea : public testing::Test
{
public:
    void SetUp() override
    {
        widget = new AppListArea;
    }

    void TearDown() override
    {
        widget = nullptr;
        delete widget;
    }

public:
    AppListArea* widget = nullptr;
};

TEST_F(Tst_Applistarea, appListArea_test)
{
    QWidget *view = new QWidget;
    widget->addWidget(view);

    QWheelEvent event(QPointF(0, 0), 0, Qt::MiddleButton, Qt::ControlModifier);
    QApplication::sendEvent(widget, &event);

    QEvent event1(QEvent::Enter);
    QApplication::sendEvent(widget, &event1);

    QMouseEvent event2(QEvent::MouseButtonPress, QPointF(0, 0), QPointF(0, 1), QPointF(1, 1), Qt::LeftButton, Qt::LeftButton, Qt::NoModifier, Qt::MouseEventSynthesizedByQt);
    QApplication::sendEvent(widget, &event2);

    QMouseEvent event3(QEvent::MouseButtonRelease, QPointF(0, 0), QPointF(0, 1), QPointF(1, 1), Qt::LeftButton, Qt::LeftButton, Qt::NoModifier, Qt::MouseEventSynthesizedByQt);
    QApplication::sendEvent(widget, &event3);

}


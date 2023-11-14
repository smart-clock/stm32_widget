#ifndef ROBOTVIEW_HPP
#define ROBOTVIEW_HPP

#include <gui_generated/robot_screen/RobotViewBase.hpp>
#include <gui/robot_screen/RobotPresenter.hpp>

class RobotView : public RobotViewBase
{
public:
    RobotView();
    virtual ~RobotView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ROBOTVIEW_HPP

/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef USERVIEWBASE_HPP
#define USERVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/user_screen/UserPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/containers/SwipeContainer.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class UserViewBase : public touchgfx::View<UserPresenter>
{
public:
    UserViewBase();
    virtual ~UserViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::SwipeContainer swipeContainer1;
    touchgfx::Container home;
    touchgfx::Image image1;
    touchgfx::TextArea textArea3;
    touchgfx::TextArea textArea4;
    touchgfx::Container Weather;
    touchgfx::Image image2;
    touchgfx::Container Clock;
    touchgfx::Box box2_2;
    touchgfx::Container swipeContainer1Page4;
    touchgfx::Box box2_3;
    touchgfx::Container swipeContainer1Page5;
    touchgfx::Box box2_4;
    touchgfx::TextArea battery;
    touchgfx::TextArea time;

private:

};

#endif // USERVIEWBASE_HPP
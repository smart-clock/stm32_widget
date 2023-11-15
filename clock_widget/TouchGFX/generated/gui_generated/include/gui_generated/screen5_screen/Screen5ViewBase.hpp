/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREEN5VIEWBASE_HPP
#define SCREEN5VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen5_screen/Screen5Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/VideoWidget.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class Screen5ViewBase : public touchgfx::View<Screen5Presenter>
{
public:
    Screen5ViewBase();
    virtual ~Screen5ViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::VideoWidget videoHappy;
    touchgfx::Button buttonPrev;
    touchgfx::Button buttonNext;
    touchgfx::TextArea textVideo;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Screen5ViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // SCREEN5VIEWBASE_HPP

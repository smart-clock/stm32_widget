/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREEN7VIEWBASE_HPP
#define SCREEN7VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen7_screen/Screen7Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/VideoWidget.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>

class Screen7ViewBase : public touchgfx::View<Screen7Presenter>
{
public:
    Screen7ViewBase();
    virtual ~Screen7ViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::VideoWidget videoSad;
    touchgfx::TextArea textVideo;
    touchgfx::ButtonWithLabel buttonPrev;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Screen7ViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // SCREEN7VIEWBASE_HPP

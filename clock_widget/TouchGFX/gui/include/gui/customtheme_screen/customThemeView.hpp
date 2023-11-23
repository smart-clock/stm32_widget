#ifndef CUSTOMTHEMEVIEW_HPP
#define CUSTOMTHEMEVIEW_HPP

#include <gui_generated/customtheme_screen/customThemeViewBase.hpp>
#include <gui/customtheme_screen/customThemePresenter.hpp>

class customThemeView : public customThemeViewBase
{
public:
    customThemeView();
    virtual ~customThemeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CUSTOMTHEMEVIEW_HPP

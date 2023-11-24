#ifndef CUSTOMTHEMEPRESENTER_HPP
#define CUSTOMTHEMEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class customThemeView;

class customThemePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    customThemePresenter(customThemeView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~customThemePresenter() {}

private:
    customThemePresenter();

    customThemeView& view;
};

#endif // CUSTOMTHEMEPRESENTER_HPP

#ifndef ROBOTTHEMEPRESENTER_HPP
#define ROBOTTHEMEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class robotThemeView;

class robotThemePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    robotThemePresenter(robotThemeView& v);

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

    virtual ~robotThemePresenter() {}

private:
    robotThemePresenter();

    robotThemeView& view;
};

#endif // ROBOTTHEMEPRESENTER_HPP

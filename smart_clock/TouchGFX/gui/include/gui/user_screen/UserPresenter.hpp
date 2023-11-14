#ifndef USERPRESENTER_HPP
#define USERPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class UserView;

class UserPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    UserPresenter(UserView& v);

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

    virtual ~UserPresenter() {}

private:
    UserPresenter();

    UserView& view;
};

#endif // USERPRESENTER_HPP

#ifndef USERVIEW_HPP
#define USERVIEW_HPP

#include <gui_generated/user_screen/UserViewBase.hpp>
#include <gui/user_screen/UserPresenter.hpp>

class UserView : public UserViewBase
{
public:
    UserView();
    virtual ~UserView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // USERVIEW_HPP

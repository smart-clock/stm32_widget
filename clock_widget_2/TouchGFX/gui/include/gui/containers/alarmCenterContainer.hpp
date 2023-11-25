#ifndef ALARMCENTERCONTAINER_HPP
#define ALARMCENTERCONTAINER_HPP

#include <gui_generated/containers/alarmCenterContainerBase.hpp>

class alarmCenterContainer : public alarmCenterContainerBase
{
public:
    alarmCenterContainer();
    virtual ~alarmCenterContainer() {}

    virtual void initialize();
protected:
};

#endif // ALARMCENTERCONTAINER_HPP

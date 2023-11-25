#ifndef ALARMCONTAINER_HPP
#define ALARMCONTAINER_HPP

#include <gui_generated/containers/alarmContainerBase.hpp>

class alarmContainer : public alarmContainerBase
{
public:
    alarmContainer();
    virtual ~alarmContainer() {}

    virtual void initialize();
protected:
};

#endif // ALARMCONTAINER_HPP

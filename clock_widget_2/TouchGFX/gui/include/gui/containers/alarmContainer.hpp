#ifndef ALARMCONTAINER_HPP
#define ALARMCONTAINER_HPP

#include <gui_generated/containers/alarmContainerBase.hpp>

class alarmContainer : public alarmContainerBase
{
public:
    alarmContainer();
    virtual ~alarmContainer() {}

    virtual void initialize();

    void setText(int time);
protected:
};

#endif // ALARMCONTAINER_HPP

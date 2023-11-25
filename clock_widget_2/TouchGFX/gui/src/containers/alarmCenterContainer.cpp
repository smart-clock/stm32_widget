#include <gui/containers/alarmCenterContainer.hpp>

alarmCenterContainer::alarmCenterContainer()
{

}

void alarmCenterContainer::initialize()
{
    alarmCenterContainerBase::initialize();
}

void alarmCenterContainer::setText(int time)
{
    Unicode::snprintf(textAreaBuffer, TEXTAREA_SIZE, "%02d", time);
    textArea.invalidate();
}
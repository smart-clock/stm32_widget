#include <gui/containers/alarmContainer.hpp>

alarmContainer::alarmContainer()
{

}

void alarmContainer::initialize()
{
    alarmContainerBase::initialize();
}

void alarmContainer::setText(int time)
{
    Unicode::snprintf(textAreaBuffer, TEXTAREA_SIZE, "%02d", time);
    textArea.invalidate();
}
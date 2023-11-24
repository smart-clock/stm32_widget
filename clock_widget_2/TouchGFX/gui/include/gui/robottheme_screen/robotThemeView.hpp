#ifndef ROBOTTHEMEVIEW_HPP
#define ROBOTTHEMEVIEW_HPP

#include <gui_generated/robottheme_screen/robotThemeViewBase.hpp>
#include <gui/robottheme_screen/robotThemePresenter.hpp>

class robotThemeView : public robotThemeViewBase
{
public:
    robotThemeView();
    virtual ~robotThemeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleTickEvent();
    
    virtual void buttonPlayClicked();
    virtual void buttonStopClicked();
    virtual void buttonResetClicked();

    virtual void buttonTimerMaxClicked();
    virtual void bottonTimerMinClicked();

    virtual void handleDragEvent(const DragEvent& Event);
protected:
    int tickCounter;
    int stopWatchHours;
    int stopWatchMinutes;
    int stopWatchSeconds;

    bool isStopWatchPlay = false;
    
    static const uint32_t TICK_BLINK_INTERVAL = 180;
    uint32_t frameCountBlinkInterval;

    bool timerWidgetDrag; // Issue #18
    int8_t timerMinute; // display value
    int8_t timerSecond; // display value
    int timerOfCurAng; // current angle
    int timerOfPreAng; // previous angle
    bool timerMax; // max drag limit
    bool timerMin; // min drag limit
    bool timerStart; // timer start flag
    int timerCounter;

    Callback<robotThemeView, const Gauge&, const ClickEvent&> gaugeClickCallback;
    void gaugeClickHandler(const Gauge& g, const ClickEvent& e);
};

#endif // ROBOTTHEMEVIEW_HPP

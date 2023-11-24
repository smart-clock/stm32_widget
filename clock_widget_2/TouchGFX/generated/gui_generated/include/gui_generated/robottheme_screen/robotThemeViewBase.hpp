/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef ROBOTTHEMEVIEWBASE_HPP
#define ROBOTTHEMEVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/robottheme_screen/robotThemePresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/containers/SwipeContainer.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/VideoWidget.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/containers/clock/DigitalClock.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/canvas/Circle.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/widgets/Gauge.hpp>
#include <touchgfx/mixins/ClickListener.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/containers/scrollers/ScrollList.hpp>
#include <gui/containers/CustomContainer1.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/graph/GraphWrapAndClear.hpp>
#include <touchgfx/widgets/graph/GraphElements.hpp>

class robotThemeViewBase : public touchgfx::View<robotThemePresenter>
{
public:
    robotThemeViewBase();
    virtual ~robotThemeViewBase();
    virtual void setupScreen();

    virtual void scrollList1UpdateItem(CustomContainer1& item, int16_t itemIndex)
    {
        // Override and implement this function in robotTheme
    }
    virtual void handleTickEvent();

    /*
     * Virtual Action Handlers
     */
    virtual void buttonPlayClicked()
    {
        // Override and implement this function in robotTheme
    }
    virtual void buttonStopClicked()
    {
        // Override and implement this function in robotTheme
    }
    virtual void buttonResetClicked()
    {
        // Override and implement this function in robotTheme
    }
    virtual void buttonTimerMaxClicked()
    {
        // Override and implement this function in robotTheme
    }
    virtual void bottonTimerMinClicked()
    {
        // Override and implement this function in robotTheme
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box whiteBackground;
    touchgfx::SwipeContainer swipeContainerWidget;
    touchgfx::Container homePage1;
    touchgfx::VideoWidget videoBlink;
    touchgfx::Container whetherPage2;
    touchgfx::Box background2;
    touchgfx::Image imageRaining;
    touchgfx::Box box1;
    touchgfx::TextArea textDegree;
    touchgfx::TextArea textWhether;
    touchgfx::Container stopWatchPage3;
    touchgfx::Box background3;
    touchgfx::DigitalClock digitalClock;
    touchgfx::Button buttonReset;
    touchgfx::Button buttonStop;
    touchgfx::Button buttonPlay;
    touchgfx::Container timerPage4;
    touchgfx::Box boxTimerBackground;
    touchgfx::Button buttonTimerMax;
    touchgfx::Button buttonTimerMin;
    touchgfx::Circle circleGaugeBackground;
    touchgfx::PainterRGB565 circleGaugeBackgroundPainter;
    touchgfx::ClickListener< touchgfx::Gauge > gaugeTimer;
    touchgfx::PainterRGB565 gaugeTimerPainter;
    touchgfx::TextAreaWithTwoWildcards textTimer;
    touchgfx::Container SchedulePage4;
    touchgfx::Box background4;
    touchgfx::ScrollList scrollList1;
    touchgfx::DrawableListItems<CustomContainer1, 6> scrollList1ListItems;
    touchgfx::Box boxScheduleBack;
    touchgfx::TextArea textScheduleTime;
    touchgfx::TextArea textSchedule;
    touchgfx::Container BusPage5;
    touchgfx::Box background5;
    touchgfx::Circle circleFill1;
    touchgfx::PainterRGB565 circleFill1Painter;
    touchgfx::Circle circleOutLine1;
    touchgfx::PainterRGB565 circleOutLine1Painter;
    touchgfx::Line lineUp1;
    touchgfx::PainterRGB565 lineUp1Painter;
    touchgfx::Line lineDown1;
    touchgfx::PainterRGB565 lineDown1Painter;
    touchgfx::Image bus1;
    touchgfx::Image bus2;
    touchgfx::Circle circleFill2;
    touchgfx::PainterRGB565 circleFill2Painter;
    touchgfx::Circle circleOutLine2;
    touchgfx::PainterRGB565 circleOutLine2Painter;
    touchgfx::Line lineDown2;
    touchgfx::PainterRGB565 lineDown2Painter;
    touchgfx::Line lineUp2;
    touchgfx::PainterRGB565 lineUp2Painter;
    touchgfx::Circle circleFill3;
    touchgfx::PainterRGB565 circleFill3Painter;
    touchgfx::Circle circleFill3_1;
    touchgfx::PainterRGB565 circleFill3_1Painter;
    touchgfx::Circle circleOutLine3;
    touchgfx::PainterRGB565 circleOutLine3Painter;
    touchgfx::TextArea busTime1;
    touchgfx::TextArea busTime2;
    touchgfx::Container StockPage6;
    touchgfx::Box background6;
    touchgfx::GraphWrapAndClear<100> dynamicGraph1;
    touchgfx::GraphElementLine dynamicGraph1Line1;
    touchgfx::PainterRGB565 dynamicGraph1Line1Painter;
    touchgfx::GraphElementArea dynamicGraph1Area1;
    touchgfx::PainterRGB565 dynamicGraph1Area1Painter;
    touchgfx::TextArea textStock;
    touchgfx::TextArea textStockValue;
    touchgfx::TextArea textBattery;
    touchgfx::TextArea textClock;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTTIMERBUFFER1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTimerBuffer1[TEXTTIMERBUFFER1_SIZE];
    static const uint16_t TEXTTIMERBUFFER2_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textTimerBuffer2[TEXTTIMERBUFFER2_SIZE];

private:

    /*
     * Canvas Buffer Size
     */
    static const uint32_t CANVAS_BUFFER_SIZE = 7200;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];

    /*
     * Callback Declarations
     */
    touchgfx::Callback<robotThemeViewBase, touchgfx::DrawableListItemsInterface*, int16_t, int16_t> updateItemCallback;
    touchgfx::Callback<robotThemeViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex);
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

    /*
     * Tick Counter Declarations
     */
    static const uint32_t TICK_BLINK_INTERVAL = 180;
    uint32_t frameCountBlinkInterval;

};

#endif // ROBOTTHEMEVIEWBASE_HPP

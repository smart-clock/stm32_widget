/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef PACKETVIEWBASE_HPP
#define PACKETVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/packet_screen/PacketPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class PacketViewBase : public touchgfx::View<PacketPresenter>
{
public:
    PacketViewBase();
    virtual ~PacketViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box box1;
    touchgfx::TextAreaWithOneWildcard textArea1;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTAREA1_SIZE = 257;
    touchgfx::Unicode::UnicodeChar textArea1Buffer[TEXTAREA1_SIZE];

private:

};

#endif // PACKETVIEWBASE_HPP

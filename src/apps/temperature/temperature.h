#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "../app.h"

class TemperatureApp : public App {
   public:
    TemperatureApp() {
        name = "Temperature";
        description = "Displays the current temperature and humidity.";
        icon = {
            {CRGB::Red, CRGB::Green, CRGB::Blue},
            {CRGB::Yellow, CRGB::Magenta, CRGB::Cyan},
            {CRGB::White, CRGB::Black, CRGB::Gray},
            {CRGB::Pink, CRGB::Aqua, CRGB::Orange}};
    }

    void tick() override ;

    void handleButtonPressed(int button, ClickType clickType) override;
};

#endif  // TEMPERATURE_H

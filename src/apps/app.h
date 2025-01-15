#ifndef APP_H
#define APP_H

#include <string>
#include <vector>

#include "../graphics/screen/screen.h"
#include "../modules/buttons/buttons.h"
#include "../graphics/utils/graphics_utils.h"

class App;

extern std::vector<App*> apps;
extern App* activeApp;

class App {
   protected:
    std::string name;
    std::string description;
    std::vector<std::vector<CRGB>> icon;
    Screen screen;

   public:
    virtual ~App() {}

    virtual void setup() {};

    virtual std::string getName() {
        return name;
    }

    virtual std::string getDescription() {
        return description;
    }

    virtual std::vector<std::vector<CRGB>> getIcon() {
        return icon;
    }

    virtual Screen& getScreen() {
        return screen;
    }

    virtual void tick() = 0;
    virtual void handleButtonPressed(int button, ClickType clickType) = 0;
};

#endif  // APP_H

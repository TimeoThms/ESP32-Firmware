# Files structure
```graphql
esp32_firmware_project/
│
├── src/                            # Main source code
│   ├── main.cpp                    # Main entry point of the firmware
│   ├── configs/
│   │   ├── config.h                # Global configuration (WiFi, pins, etc.)
│   │   ├── chars.h                 # Characters BitMaps
│   │   └── settings.h              # Default settings
│   ├── utils/                      # Utility functions
│   │   ├── logger/                 # Logging module
│   │   │   ├── logger.cpp          # Logging implementation
│   │   │   └── logger.h            # Logging header
│   ├── modules/                    # Functional modules (separated by functionality)
│   │   ├── dht22/                  # DHT22 sensor management
│   │   │   ├── dht22.cpp           # DHT22 implementation
│   │   │   └── dht22.h             # DHT22 header
│   │   ├── bh1750/                 # Light sensor management
│   │   │   ├── bh1750.cpp          # BH1750 implementation
│   │   │   └── bh1750.h            # BH1750 header
│   │   ├── ds3231/                 # Real-time clock (RTC) module
│   │   │   ├── ds3231.cpp          # DS3231 implementation
│   │   │   └── ds3231.h            # DS3231 header
│   │   ├── inmp441/                # INMP441 microphone management
│   │   │   ├── inmp441.cpp         # INMP441 implementation
│   │   │   └── inmp441.h           # INMP441 header
│   │   ├── max98357a/              # Amplifier and speaker control module
│   │   │   ├── max98357a.cpp       # MAX98357A implementation
│   │   │   └── max98357a.h         # MAX98357A header
│   │   ├── ws2812b/                # LED matrix control module
│   │   │   ├── ws2812b.cpp         # WS2812B implementation
│   │   │   └── ws2812b.h           # WS2812B header
│   ├── graphics/                   # Graphics-related functionalities
│   │   ├── screen/                 # Screen object
│   │   │   ├── screen.cpp          # Screen object implementation
│   │   │   ├── screen.h            # Screen class definition
│   │   ├── utils/                  # Screen utilities
│   │   │   ├── graphics_utils.cpp  # Utility functions for creating/displaying elements on the screen
│   │   │   └── graphics_utils.h    # Header for the graphics utility functions
│   └── apps/                       # Applications for FreeRTOS
│       ├── settings/               # Settings-related apps
│       │   ├── settings.cpp        # Settings app
│       │   └── settings.h
│       ├── bluetooth/              # Bluetooth functionality | Sub app of settings ?
│       │   ├── bluetooth.cpp       # Bluetooth functionality
│       │   └── bluetooth.h
│       ├── clock/                  # Clock display app | Create sub app for alarm configuration ?
│       │   ├── clock.cpp           # Clock display app
│       │   └── clock.h
│       ├── date/                   # Date display app
│       │   ├── date.cpp            # Date display app
│       │   └── date.h
│       ├── temperature/            # Temperature/Humidity app (indoor sensors)
│       │   ├── temperature.cpp     # Temperature sensor app
│       │   └── temperature.h
│       ├── weather/                # Weather forecast app
│       │   ├── weather.cpp         # Weather forecast app
│       │   └── weather.h
│       ├── timer/                  # Timer app
│       │   ├── timer.cpp           # Timer app
│       │   └── timer.h
│       ├── app_slider/             # Slider for enabled apps
│       │   ├── app_slider.cpp      # Slider for enabled apps
│       │   └── app_slider.h
│       ├── mini_games/             # Games app
│       │   ├── mini_games.cpp      # Games app
│       │   └── mini_games.h
│       ├── led_animations/         # LED Animations app
│       │   ├── led_animations.cpp  # LED Animations app
│       │   └── led_animations.h
├── .gitignore                      # Files to ignore for Git
├── LICENSE                         # Project license
└── README.md                       # Main documentation
```

Each app must have the following methods :
- `setup()` : Initialization of the app when app is enabled
- `getName()` : Returns the name of the app
- `getDescription()` : Returns the description of the app
- `getIcon()` : Returns a bitmap image with the 8*8 icon
- `getScreen()` : Returns the screen to display
- `tick()` : Update variables, states, etc of the app. Implement in getScreen ???
- `handleButtonPressed(button)` : Called when a button is pressed

Make sure that screen is not displayed if screen at previous tick (10TPS) has not changed

`src/graphics/screen.cpp`
Screen class.
Attributes:
- `pixels` : BitMap of 32x8 pixels
Methods:
- `getPixels()` : Returns this.pixels
- `place(std::tuple<int, int> coords, const std::vector<uint32_t>& bitmap, int bitmap_width, int bitmap_height)` : Places an element on the screen
  
`src/graphics/utils/graphics_utils.cpp`
Contains static functions:
- `join(Bitmap bitmap1, Bitmap bitmap2, int offsetX = widht_of_bitmap1, int offsetY = 0) ` : Concatenate two elements into one (optional offset, default x offset is the bitmap1 widht)
- `text(const std::string& text, const RGBColor& color)` : Creates an element from a text with the given color


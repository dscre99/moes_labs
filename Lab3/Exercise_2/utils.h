#if !defined(LIGHTS_COLORS)
#define LIGHTS_COLORS

enum color
    {
        RED,
        YELLOW,
        GREEN
    };

// 'inline' needed to avoid multiple definition of global variable
inline const char* COLORS[3] = {"RED", "YELLOW", "GREEN"};

#endif // LIGHTS_COLORS

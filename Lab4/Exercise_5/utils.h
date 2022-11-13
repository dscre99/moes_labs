#ifndef UTILS_H
#define UTILS_H

#define CLK_PER_SEC 1000000 // 1MHz clock
#define TIMER_COUNTER_ADDR 100
#define TIMER_MAX_VALUE_ADDR 104
#define TIMER_CONTROL_ADDR 108
#define PIO_DIR_ADDR 112
#define PIO_DATA_ADDR 116

enum color {RED, YELLOW, GREEN};
inline const char *COLORS[] = {"RED", "YELLOW", "GREEN"};
inline const sc_time BUS_DELAY(1, SC_US);   // 1MHz BUS clock

#endif
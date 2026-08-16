STM32F103RB Timer-Based 8-LED Running Light
📌 Description

A timer-based LED running light project using the STM32F103RB and STM32 HAL Library. Eight LEDs run sequentially from left to right and right to left with a 100 ms delay using TIM2 interrupts.

🔧 Hardware
STM32F103RB
8 × LEDs
8 × 220Ω–330Ω resistors
ST-Link Programmer/Debugger
Breadboard and jumper wires
📍 GPIO Configuration
LED	GPIO Pin
LED1	PA5
LED2	PA6
LED3	PA7
LED4	PB0
LED5	PB1
LED6	PB2
LED7	PB10
LED8	PB11
⚙️ Working
Initialize all 8 GPIO pins as outputs.
Initialize the TIM2 timer.
Start the timer in interrupt mode.
Turn ON one LED at a time.
Maintain a 100 ms delay between transitions.
Run the sequence from LED1 → LED8.
Reverse the sequence from LED8 → LED1.
Repeat the process continuously.
🧩 Timer HAL

The project uses a custom TIMER_HAL module with:

TIMER_Init()
TIMER_Start()
TIMER_Stop()
TIMER_GetTick()
TIMER_IsElapsed()
🎯 Result

The LEDs successfully produce a continuous left-to-right and right-to-left running-light effect with accurate timing.

🛠️ Tools
STM32CubeIDE
STM32 HAL Library
STM32F103RB
TIM2
GPIO
👨‍💻 Author

Ahsan Basharat Ali

For any queries or suggestions, contact:
ahsanbasharatali38@gmail.com

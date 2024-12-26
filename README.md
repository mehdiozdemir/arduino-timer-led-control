# Arduino Timer Interrupt LED Control

Arduino project demonstrating multiple interrupt types (Timer and External) to control three LEDs with different timing patterns.

## 🛠️ Components Used

- 1x Arduino Uno
- 1x Green LED
- 1x Orange LED
- 1x Red LED
- 1x Push Button
- 4x Resistors (220Ω)
- Jumper Wires
- 1x Breadboard

## 📋 Features

- Timer1 CTC mode interrupt
- Timer2 overflow interrupt
- External interrupt on button
- Three independent LED control
- Different timing patterns
- Non-blocking operation

## ⚡ Pin Configuration

### LED Connections
 - Green LED: Pin 3
 - Orange LED: Pin 4
 - Red LED: Pin 5
 - Button: Pin 2 (Interrupt)

## 🎮 Interrupt Configuration

### Timer1 (CTC Mode)
1 Second Interval
 - OCR1A = 7812
 - Prescaler = 1024
 - Mode = CTC (Clear Timer on Compare Match)

### Timer2 (Overflow Mode)
2 Second Interval (152 overflows)
 - Prescaler = 1024
 - Mode = Normal
 - Overflow Count = 152

## 💡 LED Patterns

1. **Green LED**
   - Timer1 controlled
   - 1 second toggle
   - CTC mode interrupt

2. **Orange LED**
   - Timer2 controlled
   - 2 second toggle
   - Overflow interrupt

3. **Red LED**
   - Button controlled
   - Toggle on press
   - External interrupt

## 📺 Circuit Diagram

![Ödev 4](https://github.com/user-attachments/assets/4c103d50-a259-4dfc-8295-1be437e34153)


## ⚠️ Important Notes

- Interrupt priorities matter
- Use volatile for shared variables
- Minimize ISR execution time
- Verify timer calculations
- Check button debouncing
- Ground connections critical

## 🔧 Timer Calculations

### Timer1 (CTC Mode)
 - OCR1A = 16MHz/(210241Hz) - 1 = 7812

### Timer2 (Overflow)
 - Overflow Time = 256 1024 / 16MHz = 0.016384s
 - Required Overflows = 2s / 0.016384s = 152

## 🔍 Troubleshooting

| Problem | Possible Solution |
|---------|------------------|
| LEDs not blinking | Check timer settings |
| Irregular timing | Verify calculations |
| Button bouncing | Add debounce code |
| Multiple triggers | Check interrupt flags |

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

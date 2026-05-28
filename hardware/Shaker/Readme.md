# AccessLabs Incubator Shaker

<p align="center">
  <img src="https://github.com/Fadanka/AccessLabs-Resources-Version.20/blob/81ab827224bcf39b26bfc94a89ca09642e70fcd8/hardware/Shaker/Images/Assmebled1.jpg" alt="Assembled shaker" width="72%">
</p>

<p align="center">
  <strong>3D-printed incubator shaker</strong><br>
  ESP32-S3 controlled, motor-driven, modular, and designed for interchangeable lab vessel adapters.
</p>

<p align="center">
  <em>Prototype hardware documented for replication, testing, and further improvement.</em>
</p>

---

## Overview

This repository documents the design and construction of a compact incubator shaker built around:

- a **3D-printed mechanical assembly**
- an **ESP32-S3 DevKitC-1** controller
- a **DC gear motor**
- a **DRV8871 motor driver**
- interchangeable adapters for **flasks**, **tubes**, and **plates**

The aim of the project is to provide a reproducible open-hardware shaker that is easy to print, assemble, adapt, and improve for different laboratory applications. The shaker was designed with a compact footprint to fit inside small laboratory incubators and operate as a shaking incubator.

---

## Features

- Modular 3D-printed design
- Interchangeable tray adapters
- ESP32-S3 based control
- PWM motor speed control
- LCD and RGB LED feedback
- Open documentation for replication and customization

---

## Bill of Materials

### 3D-printed parts

| Part name | Qty |
|---|---:|
| `Tray_Main Platform` | 1 |
| `Tray_Screws and nuts` | 2 |
| `Flask adapter_Lid` | 2 |
| `Flask adapter_Lid retainer` | 2 |
| `Plate adapter` | 1 |
| `Tube adapter_15 mL and 50 mL` | 1 |
| `Motion Mechanism_Tray Support Bracket` | 1 |
| `Motion Mechanism_Motor motion linker (6mm Shaft)` | 1 |
| `Motion Mechanism_Connecting Link` | 2 |
| `Motion Mechanism_Nut holders` | 2 |
| `Motion Mechanism_Screw holders` | 1 set |
| `Enclosure_Main Housing` | 1 |
| `Enclosure_Gear Motor Mount` | 1 |
| `Enclosure_Top Cover` | 1 |
| `Enclosure_Base Cover` | 1 |
| `Enclosure_Feet` | 1 set |

### Purchased parts

#### Enclosure and mechanism

| Item | Qty | Cost | Supplier | Notes |
|---|---:|---:|---|---|
| 608ZZ miniature double-protection metal ball bearings (`8 mm x 22 mm x 7 mm`) | 1 | €10.99 | Amazon | / |
| M3 screws, bolts, nuts, and washers kit (`870 pcs`) | 1 | €14.98 | Amazon | / |

#### Electronics

| Item | Qty | Cost | Supplier | Notes |
|---|---:|---:|---|---|
| ESP32-S3 DevKitC-1 microcontroller | 1 | €22.99 | Amazon | Used due to availability. Offers potential for future upgrades. |
| DRV8871 DC motor driver board (`3.6 A`, PWM control) | 2 | €9.99 | Amazon | MOSFET-based H-bridge with lower power loss, higher current handling, wider voltage range, and built-in protection features for improved reliability during prolonged operation. |
| 10K rotary potentiometer with cap and washer | 1 | €8.99 | Amazon | Input device for speed control. |
| 12 V DC worm geared motor (`370WG`, `375 RPM`) | 2 | €18.99 | Amazon | Preferred choice for cost effectiveness. Recommended to use similar motor with high torque and biuilt with better materials for prolonged use. |
| DC barrel power connector / jack adapter set | 1 | €7.99 | Amazon | Includes multiple connectors and inline rocker switches; useful for other projects as well. |
| 12 V power cable / adapter | 2 | €12.90 | Amazon | Portable design with multi-project adapter compatibility reduces future tooling costs. |
| LM2596 step-down DC-DC buck converter module | 1 | €11.19 | Amazon | Required to safely power the full circuit from a single 12 V external adapter via the DC jack. |
| ARCELI 20x4 2004 5 V DC LCD display module with TWI/IIC I2C interface adapter (`Blue/2004`) | 1 | €10.77 | Amazon | Used for system status display, speed display, and approximate RPM readout. I2C interface simplifies wiring to the ESP32-S3. |

### Tools and consumables

- Strong instant glue
- Screwdriver set
- Soldering station
- Jumper wires
- Double sided tape
---

## Printing recommendations

For the **critical structural and motion parts**, use **PETG** or a similar durable filament.

### Recommended print settings
- **Infill:** at least **50%**
- **Supports:** use where needed
- **Brim:** use where needed for better bed adhesion

### Critical parts
- `Enclosure_Main Housing`
- `Enclosure_Feet`
- all motion mechanism parts
- `Tray_Main Platform`
- `Tray_Screws and nuts`

### Notes
- Remove supports and brims carefully after printing.
- Clean mating surfaces and holes before assembly.
- Check bearing and nut pockets before gluing.

---

## Parts Gallery

The images below are arranged by function and labeled with the current filenames in the repository.

### 1. Tray and adapters

<table>
  <tr>
    <td align="center" width="33%">
      <strong>Tray_Main Platform.jpg</strong><br><br>
      <img src="https://raw.githubusercontent.com/Fadanka/AccessLabs-Resources-Version.20/baf2fe9cfbb54dcbefb2e4a2180c2807738f8826/hardware/Shaker/Images/Tray_Main%20Platform.jpg" alt="Tray_Main Platform.jpg" width="100%">
    </td>
    <td align="center" width="33%">
      <strong>Tray_Screws and nuts.jpg</strong><br><br>
      <img src="https://raw.githubusercontent.com/Fadanka/AccessLabs-Resources-Version.20/baf2fe9cfbb54dcbefb2e4a2180c2807738f8826/hardware/Shaker/Images/Tray_Screws%20and%20nuts.jpg" alt="Tray_Screws and nuts.jpg" width="100%">
    </td>
    <td align="center" width="33%">
      <strong>Plate adapter.jpg</strong><br><br>
      <img src="https://raw.githubusercontent.com/Fadanka/AccessLabs-Resources-Version.20/baf2fe9cfbb54dcbefb2e4a2180c2807738f8826/hardware/Shaker/Images/Plate%20adapter.jpg" alt="Plate adapter.jpg" width="100%">
    </td>
  </tr>
  <tr>
    <td align="center" width="33%">
      <strong>Tube adapter_15 mL and 50 mL.jpg</strong><br><br>
      <img src="https://raw.githubusercontent.com/Fadanka/AccessLabs-Resources-Version.20/baf2fe9cfbb54dcbefb2e4a2180c2807738f8826/hardware/Shaker/Images/Tube%20adapter_15%20mL%20and%2050%20mL.jpg" alt="Tube adapter_15 mL and 50 mL.jpg" width="100%">
    </td>
    <td align="center" width="33%">
      <strong>Flask adapter_Lids .jpg</strong><br><br>
      <img src="https://raw.githubusercontent.com/Fadanka/AccessLabs-Resources-Version.20/baf2fe9cfbb54dcbefb2e4a2180c2807738f8826/hardware/Shaker/Images/Flask%20adapter_Lids%20.jpg" alt="Flask adapter_Lids .jpg" width="100%">
    </td>
    <td align="center" width="33%">
      <strong>Flask adapter_Lid retainers.jpg</strong><br><br>
      <img src="https://raw.githubusercontent.com/Fadanka/AccessLabs-Resources-Version.20/baf2fe9cfbb54dcbefb2e4a2180c2807738f8826/hardware/Shaker/Images/Flask%20adapter_Lid%20retainers.jpg" alt="Flask adapter_Lid retainers.jpg" width="100%">
    </td>
  </tr>
</table>

### 2. Motion assembly

<table>
  <tr>
    <td align="center" width="100%">
      <strong>Motion Mechanism parts.jpg</strong><br><br>
      <img src="https://raw.githubusercontent.com/Fadanka/AccessLabs-Resources-Version.20/baf2fe9cfbb54dcbefb2e4a2180c2807738f8826/hardware/Shaker/Images/Motion%20Mechanism%20parts.jpg" alt="Motion Mechanism parts.jpg" width="60%">
    </td>
  </tr>
</table>

### 3. Enclosure

<table>
  <tr>
    <td align="center" width="33%">
      <strong>Enclosure_Main Housing.jpg</strong><br><br>
      <img src="https://raw.githubusercontent.com/Fadanka/AccessLabs-Resources-Version.20/baf2fe9cfbb54dcbefb2e4a2180c2807738f8826/hardware/Shaker/Images/Enclosure_Main%20Housing.jpg" alt="Enclosure_Main Housing.jpg" width="100%">
    </td>
    <td align="center" width="33%">
      <strong>Enclosure_Top Cover.jpg</strong><br><br>
      <img src="https://raw.githubusercontent.com/Fadanka/AccessLabs-Resources-Version.20/baf2fe9cfbb54dcbefb2e4a2180c2807738f8826/hardware/Shaker/Images/Enclosure_Top%20Cover.jpg" alt="Enclosure_Top Cover.jpg" width="100%">
    </td>
    <td align="center" width="33%">
      <strong>Enclosure_Base Cover.jpg</strong><br><br>
      <img src="https://raw.githubusercontent.com/Fadanka/AccessLabs-Resources-Version.20/baf2fe9cfbb54dcbefb2e4a2180c2807738f8826/hardware/Shaker/Images/Enclosure_Base%20Cover.jpg" alt="Enclosure_Base Cover.jpg" width="100%">
    </td>
  </tr>
</table>

---

## Assembly

### A. Print and sort all parts

Download the 3D models and print all required parts.

After printing:
1. Remove all supports and brims.
2. Clean all holes and mating surfaces.
3. Sort the parts before starting assembly.

Recommended first check:
- verify that all bearings fit correctly
- verify that all nut pockets are clean
- verify that moving parts rotate freely

---

### B. Prepare the motion mechanism

#### Parts involved
- `Motion Mechanism_Motor motion linker (6mm Shaft)`
- `Motion Mechanism_Connecting Link`
- `Motion Mechanism_Nut holders`
- `Motion Mechanism_Screw holders`
- `Motion Mechanism_Tray Support Bracket`

#### Instructions
1. Dry-fit each M3 nut and 608ZZ bearing before gluing.
2. Apply a small amount of strong liquid glue around the nut or bearing pocket.
3. Insert the nut or bearing carefully.
4. Do **not** let glue enter:
   - threaded areas
   - the inner bearing race
   - rotating contact surfaces
5. Let the glue set for about **30 minutes**.
6. Add a small finishing layer at the interstices if needed.
7. Allow full curing according to the glue manufacturer's recommendations.

> **Note:** For the motor linker, the nut located around the shaft should remain unglued if required for fit and rotation.

---

### C. Prepare the enclosure

#### Parts involved
- `Enclosure_Main Housing`
- `Enclosure_Gear Motor Mount`
- `Enclosure_Top Cover`
- `Enclosure_Base Cover`
- `Enclosure_Feet`

#### Instructions
1. Install bearings in their dedicated holes where applicable.
2. Mount the gear motor in the motor holder.
3. Check shaft alignment before tightening hardware.
4. Test fit the top and base covers before the final electronics closure.

---

### D. Electronics assembly

#### Main electronics

- ESP32-S3 DevKitC-1
- DRV8871 motor driver
- 10K rotary potentiometer
- ARCELI 20x4 2004 LCD display module with TWI/IIC I2C interface (`5 V`, `Blue/2004`)
- LM2596 step-down DC-DC buck converter
- 12 V DC worm geared motor (`370WG`, `375 RPM`)
- 12 V DC input connector

#### Electronics overview

<p align="center">
  <img src="https://raw.githubusercontent.com/Reclone-org/AccessLabs-Resources/a3064f7d6fa062d5c8d652163d7769e257eb15cf/hardware/Shaker/Images/Electrionics%20parts%20.jpg" alt="Electronics parts overview" width="60%">
</p>

<p align="center">
  <em>Electronics parts used for the shaker build.</em>
</p>

#### Instructions

1. **Prepare the motor driver**  
   Solder the DRV8871 motor driver board according to the manufacturer's instructions.

2. **Connect the power input**  
   Connect the DC barrel power connector to the **input** of the LM2596 buck converter.

3. **Set the regulated output**  
   Power the LM2596 from the 12 V input.  
   Adjust the onboard potentiometer until the output is **5 V**.

4. **Wire the low-voltage electronics**  
   Connect the regulated **5 V** output and **GND** from the LM2596 to the ESP32-S3 and the LCD power lines.

5. **Connect the LCD**  
   Wire the LCD I2C backpack to:
   - **5 V**
   - **GND**
   - **SDA** on the ESP32-S3 (pin 21)
   - **SCL** on the ESP32-S3 (pin 17)

6. **Connect the control circuit**  
   Wire the potentiometer, DRV8871, ESP32-S3, and motor according to the wiring diagram.

7. **Check the wiring**  
   Before powering the full circuit, confirm that:
   - all grounds are shared
   - the LM2596 output is set to **5 V**
   - the LCD is powered from **5 V**
   - the correct pins are used for **SDA** and **SCL**
   - the ESP32-S3 pins match the firmware
   - wires are secure and clear of moving parts

#### Wiring diagram

<p align="center">
  <img src="https://raw.githubusercontent.com/Reclone-org/AccessLabs-Resources/a3064f7d6fa062d5c8d652163d7769e257eb15cf/hardware/Shaker/Images/Circuit_Design.jpg" alt="Wiring diagram" width="70%">
</p>

<p align="center">
  <em>Wiring diagram for the shaker electronics assembly.</em>
</p>

#### Electronic assembly overview
<p align="center">
  <img src="https://github.com/Reclone-org/AccessLabs-Resources/blob/146c8ff39164a329773417a12c168016dd412f1f/hardware/Shaker/Electronics/Electronics_Assembly_overview_1.jpg" alt="Electronic assembly overview" width="70%">
</p>

<p align="center">
  <em>Electronic assembly overview.</em>
</p>

8. **Run a bench test**  
   Power the circuit and confirm that:
   - the ESP32-S3 starts correctly
   - the LCD initializes correctly (If needed, adjust the screen brightness by turning the contrast knob.)
   - the potentiometer input responds correctly
   - the motor driver powers on
   - the motor runs as expected

> **Important:** If you use a different ESP32 board, LCD backpack, or pin mapping, check the pinout and update the wiring and firmware as needed.

#### Circuit assembly and bench testing 
<p align="center">
  <img src="https://github.com/Reclone-org/AccessLabs-Resources/blob/6352cc1aba1e1877ab49168ca83a83deffa42aae/hardware/Shaker/Electronics/Assembled%20Circuit.jpg" alt="Electronic circuit assembly" width="70%">
</p>

<p align="center">
  <em>Electronic circuit assembly.</em>
</p>

<p align="center">
  <img src="https://github.com/Reclone-org/AccessLabs-Resources/blob/6352cc1aba1e1877ab49168ca83a83deffa42aae/hardware/Shaker/Electronics/Testing%20the%20Circuit.jpg" alt="Bench testing" width="70%">
</p>

<p align="center">
  <em>Bench testing.</em>
</p>
---

### E. Firmware

The firmware acts as the control system for the shaker.

#### Main behavior
- scans the I2C bus at startup
- initializes the LCD
- runs a short boot animation
- reads and averages potentiometer values
- maps the input to PWM motor speed
- estimates RPM for display
- updates the LCD with:
  - speed percentage
  - approximate RPM
  - raw potentiometer value

#### Speed control logic
A dead zone is used so the shaker remains reliably off at low potentiometer values.

- `0` to about `1264` → motor off
- above `1264` → mapped linearly to PWM output
- the displayed RPM is an approximation and not encoder measured

---

### F. Software installation

#### Prerequisites

Before uploading the firmware:

1. Make sure the circuit is **not powered on**.
2. Connect the **ESP32-S3 DevKitC-1** to the computer using the board programming/COM port.
3. Install **Arduino IDE**.
4. Download the firmware from the software folder:

   [Shaker software folder](https://github.com/Reclone-org/AccessLabs-Resources/tree/841adbdfd7efff96190e474088e382160f662ce2/hardware/Shaker/Software)

5. Open the firmware file:

   **`Shaker 2.0_Program_DRV8871.ino`**

#### Using Arduino IDE

1. Open **Arduino IDE**.
2. Open the shaker firmware sketch:

   **`Shaker 2.0_Program_DRV8871.ino`**

3. Go to **Tools**.
4. Go to **Board**.
5. Select **ESP32S3 Dev Module**.

   Board selection reference:

   ![Board selection in Arduino IDE](https://github.com/Reclone-org/AccessLabs-Resources/blob/c56b7725d194fec7f952a9e6bda650d4a0742f8c/hardware/Shaker/Images/Board%20selection.png?raw=true)

6. Select the correct serial **Port**.
7. Click **Verify** to compile the firmware.

   Compile sketch reference:

   ![Compile sketch in Arduino IDE](https://github.com/Reclone-org/AccessLabs-Resources/blob/c56b7725d194fec7f952a9e6bda650d4a0742f8c/hardware/Shaker/Images/Compile%20sketch_2026-05-12%20054341.jpg?raw=true)

   > **Note:** It is acceptable to ignore the warning message shown during compilation, as long as the sketch compiles successfully and no upload-blocking error is reported.

8. Click **Upload** to upload the firmware to the ESP32-S3.
9. Once the upload is complete, unplug the cable from the programming/COM port.
10. Power the circuit and confirm that the shaker circuit behaves as expected.
---

### G. Testing

Before final assembly, perform a bench test to confirm that the electronics and firmware behave as expected.

#### Bench test video

<video src="https://github.com/Reclone-org/AccessLabs-Resources/blob/08afdaf5fe64cb9ac954e42d3c4990fea31591c5/hardware/Shaker/Electronics/Bench%20Test.mp4?raw=true" controls width="100%">
</video>

#### Test checklist

1. Power the system.
2. Confirm that the **ESP32-S3** starts correctly.
3. Confirm that the LCD initializes correctly. If needed, adjust the screen brightness by turning the contrast knob.
4. Confirm that the potentiometer changes the displayed value.
5. Confirm that the motor responds smoothly to PWM control.

---

### H. Final assembly

1. Install the tray support and motion mechanism.
2. Attach the tray platform.
3. Fit the required vessel adapter:
   - flask adapter
   - tube adapter
   - plate adapter
4. Route and secure all wiring.
5. Close the enclosure with the top and base covers.
6. Add the feet.
7. Run a final low-speed test before regular operation.

---

### I. Operation

1. Power the shaker.
2. Place the correct adapter on the tray.
3. Load vessels symmetrically.
4. Increase speed gradually using the potentiometer.
5. Monitor for:
   - vibration
   - imbalance
   - slipping vessels
   - overheating

For best results:
- balance the load evenly
- avoid overloading one side
- start at low speed after every configuration change

---

## Safety

- Use the device on a stable, level surface.
- Do not operate with loose hardware.
- Do not touch moving parts during operation.
- Keep liquids away from exposed electronics.
- Verify adapter fit before placing samples.
- Disconnect power before maintenance or rewiring.
- Inspect glued nuts, bearings, and fasteners regularly.

---

## Known limitations

- RPM is estimated, not encoder measured
- assembly photos and wiring diagrams can still be expanded
- documentation may evolve as the mechanical design is refined

---

## Contributing

Improvements are welcome.

Useful contributions include:
- better assembly photos
- wiring diagrams
- firmware improvements
- adapter variants
- validation tests
- print optimization notes

---

## Project note

If you use or adapt this design, consider linking back to the original repository and documenting your modifications.

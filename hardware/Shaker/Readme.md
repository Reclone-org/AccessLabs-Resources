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

This project is a compact incubator shaker built around:

- a **3D-printed mechanical assembly**
- an **ESP32-S3 DevKitC-1** controller
- a **DC gear motor**
- a **DRV8871 motor driver**
- interchangeable adapters for **flasks**, **tubes**, and **plates**

The aim of the project is to provide a reproducible open-hardware shaker that is easy to print, assemble, adapt, and improve.

---

## Features

- Modular 3D-printed design
- Interchangeable tray adapters
- ESP32-S3 based control
- PWM motor speed control
- Potentiometer-based user input
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
- 10K potentiometer
- LM2596 buck converter
- DC motor
- 12V DC input connector

#### Suggested workflow
1. Mount the motor and controller hardware inside the enclosure.
2. Install the DC power input.
3. Wire the motor to the motor driver.
4. Wire the motor driver control lines to the ESP32-S3.
5. Wire the potentiometer to an ESP32-S3 analog input.
6. Add the buck converter if voltage regulation is required for logic electronics.
7. Confirm that all grounds are shared correctly.

> Add a wiring diagram here when available.

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
- periodically displays a shaker activity message
- uses RGB LED feedback for status indication

#### Speed control logic
A dead zone is used so the shaker remains reliably off at low potentiometer values.

- `0` to about `1264` → motor off
- above `1264` → mapped linearly to PWM output
- the displayed RPM is an approximation and not encoder measured

---

### F. Software installation

#### Using Arduino IDE
1. Open **Arduino IDE**
2. Go to **Tools**
3. Go to **Board**
4. Select **ESP32S3 Dev Module**
5. Select the correct serial **Port**
6. Open the shaker firmware sketch
7. Click **Verify**
8. Click **Upload**

You can later add a direct link to the firmware sketch once it is committed in the repository.

---

### G. Testing

Before final assembly:

1. Power the system without load.
2. Confirm that the ESP32-S3 starts correctly.
3. Confirm that the LCD initializes.
4. Confirm that the potentiometer changes the displayed value.
5. Confirm that the motor responds smoothly to PWM control.
6. Check for wobble, friction, or mechanical interference.
7. Stop immediately if:
   - bearings bind
   - parts rub against the enclosure
   - the motor mount shifts
   - the tray becomes unstable

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

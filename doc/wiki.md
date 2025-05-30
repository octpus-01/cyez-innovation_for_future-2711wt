# Boat Technical Report
## I. Introduction
The combination of carbon fiber keel and acrylic boat plate ensures the strength and rigidity of the hull while having both transparency and beauty, with chip ESP32C3 as the central control, integrated electromagnetic cannon system, so that it has unique power and attack capability.
## II Boat design and material selection
### (1) Keel and support
The carbon fiber tube was selected as the keel material due to its high strength and low density, and the central vertical support of the hull was constructed by cutting. Its special features let us place it higher through the whole boat, which plays a stable supporting role in the pitching axis. We chose MDF as the material for the horizontal support, and the timber provided a solid frame base for the ship model, while providing good machinability for us to perforate as threading and joining components. These ensure the stability of the hull and resistance to deformation during navigation.
### (2) Acrylic boat plates
Acrylic ship plates have good transparency and mechanical properties, and are used for the fabrication of hull shells. It is lightburned according to the design size and tightly fitted to the keel to form a complete hull structure, which is not only convenient to observe the internal situation, but also effectively protects the internal components from the worse condition on the water.
### (3) Connecting and gluing
- Epoxy resin: mainly to complete the gluing of acrylic sheets and the filling of waterproofing
- Hot melt adhesives: waterproof filling
- White glue: used in all types of installations to connect different materials
- 502 Glue: Used for rapid positioning and structural verification testing, and to a certain extent for waterproofing
- Answer sheet: used for waterproof joints, it is the last line of defense to protect electronic components.
## III the control system
As the central control core, ESP32 - C3 has powerful processing power and rich interface resources, and is responsible for the overall control and coordination of the ship model.
1. Power management: 18650 batteries are connected in series and parallel and model airplanes to form different battery pack systems, providing stable 5v, 12v, 24v power supply circuits, providing reliable power supply for ESP32-C3, power system, electromagnetic gun system and other electronic components to ensure the stable operation of the system.
2. Communication interface: The built-in antenna Wi-Fi function of ESP32-C3 can realize wireless communication between the model ship and the remote control, which is convenient for remote control and data transmission. The interior uses Dupont wire as the power supply and signal transmission in the ship.
3. Sensor integration: It can access various sensors (such as heading sensor, speed sensor, etc.) to obtain the navigation status information of the ship model in real time, and accurately control the sailing direction and speed of the ship model after being processed by ESP32 - C3.
## IV electromagnetic gun system
1. Principle: Based on the principle of electromagnetic induction, a magnetic field is generated by an electric current entering the coil, and then a magnetic force is applied to the steel ball projectile to realize the accelerated launch of the projectile.
2. Construction: The primary coil for the electromagnetic gun is wound and encapsulated with suitable enameled wire, installed above the power supply area in the middle of the hull, and connected to the power supply and control circuit to ensure that the electromagnetic cannon can be reliably fired under the control of ESP32 - C3.

## V the production process
1. 3D modeling: SOLIDWORKS is used to model and digitally 3D manual drawings to calculate the data dimensions of each plate.
2. Keel production: cut the carbon fiber tube according to the design drawings, and use glue and answer sheet to bond, fill and fix to form the overall structure of the hull keel and ensure the smooth interface.
3. Hull assembly: Install the supporting wooden board on the keel, use laser cutting and processing the acrylic plate into the corresponding shape according to the 3D modeling data, and install it on the wooden board through glue bonding and hinge fixing, and assemble it into a complete hull shell.
4. Use foam padding pads to form an internal watertight compartment, and use hot melt adhesive, 502 glue, and answer sheet for waterproof sealing after the general structure of the internal structure is formed. After the assembly is completed, check the tightness and overall rigidity of the hull.
5. Control system installation: The ESP32-C3 control board is fixed in the bow to prevent the electromagnetic gun power supply from interfering with the control signal. Thread and connect power supplies, communication modules and various sensor lines, fix the wires, and debug functions to ensure the normal operation of the control system.
6. Installation and debugging of the electromagnetic gun: fix the made electromagnetic gun in the predetermined position of the hull, connect the power supply, control signal line, and debug it with the ESP32 - C3 control system to test the firing effect and stability of the electromagnetic gun, and optimize the firing parameters.
## VI Testing and debugging (on-site)
- Navigation test: Conduct navigation test of the ship model in the pool or open water, control the sailing direction and speed of the ship model through remote control or preset program, observe the stability, maneuverability and wind and wave resistance of the hull, and adjust and optimize the hull structure and propeller speed according to the test results.
- Electromagnetic gun testing: In a safe environment, the electromagnetic gun system is tested individually, the projectile is fired and its speed, range and other parameters are measured, the performance of the electromagnetic gun is evaluated, and the coordination with the ESP32 - C3 control system is checked to ensure accurate firing in practical applications.
## VII. Summary
The production of this powered ship model has successfully integrated advanced materials such as carbon fiber and acrylic, as well as ESP32 - C3 control and electromagnetic gun technology, with good sailing performance and unique attack ability, and has accumulated rich experience in the production process, which provides a valuable technical foundation and reference case for the subsequent production of more complex ship models or related projects, and can be further expanded and improved in the follow-up to continue to optimize the hull design and improve the system performance.

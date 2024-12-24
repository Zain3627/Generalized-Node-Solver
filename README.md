# Generalized-Node-Solver

## Overview
This program calculates the node voltages in an electrical circuit using the generalized node method. It takes the number of nodes, resistances, and current sources in the circuit as input, formulates the conductance matrix, solves the resulting equations, and displays the voltages at each node.

---

## Features
- Allows input of resistances and current sources for each node.
- Forms a conductance matrix dynamically based on input.
- Solves the resulting system of linear equations using Gaussian elimination.
- Displays the calculated voltages at each node.

---

## Prerequisites
- A C++ compiler that supports C++11 or later (e.g., GCC, Clang, or MSVC).

---

## Input Format
1. **Number of Nodes**: Enter the number of nodes in the circuit.
2. **For Each Node**:
   - Enter the number of resistances connected directly to the node.
   - For each resistance, specify its value.
   - Specify resistances between the current node and other nodes, if any.
   - Enter the number of current sources connected to the node.
   - For each current source, specify its current value (positive if entering the node, negative otherwise).

---

## Output
1. Conductance Matrix: Displays the conductance matrix formed based on the input.
2. Node Voltages: Displays the calculated voltage at each node.

---


## Limitations
- The program is limited to a maximum of 10 nodes.
- Assumes no voltage sources for simplicity (commented-out voltage source handling code).

---

## Future Improvements
- Extend support for voltage sources.
- Implement user-friendly error handling.
- Optimize matrix-solving algorithms for larger circuits.

---


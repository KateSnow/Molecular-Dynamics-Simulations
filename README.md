## Learning Molecular Dynamical with C++ Simulations

A training module to teach molecular dynamics and C++
This code has been developed and incorporated as a new module to be used by students in the third year Physics laboratory courses at the University of Wollongong.

### Introduction

Molecular Dynamical simulations provide models of the motion of individual or groups of molecules in a solid, liquid or gaseous region. Various forms of simulation can be performed, from 2D to 3D and involving different interactions and potentials. Two of the simplest potentials is the hard sphere and Lennard Jones potentials. 

To simulate molecular interactions, knowledge of computing and a relevant programming language is necessary. Using C++ vector and matrix knowledge along with fundamental laws (e.g. Newton’s Laws of motion, energy conservation, etc) simulations of particle position, momentum and energy changes are observed over time as forces and interactions between the particles are modelled given a set of boundary and initial conditions. Boundary conditions are important and these can include periodic and reflective boundary conditions depending on the situation. Periodic boundary conditions are advantageous for removing “wall effects” while reflective boundary conditions are advantageous for dense fluids where the periodic boundary conditions may lead to overlap of particles.

### Molecular Simulation FCC

The FCC (Face-Centred-Cubic) module is a toy example of producing an FCC structure with a user input N particles and variable density (volume). The resultant output gives the positions of the particles in units of the FCC cell width.

The second part of the code calculates the total potential energy in the system, assuming a Lennard-Jones interaction and applying the nearest image convention.

Users may adjust the number of particles, atomic weight, and energy parameters to observes the effects on atom positions, density and the total potential energy of the system.

Additionally, a subroutine is provided in which particles are selected at random and displaced slightly with periodic boundary conditions applied. Here Monte Carlo methods are chosen as it provides a numerical method that is not defined by taking regular points along an interval. The Metropolis Monet Carlo method is able to sample values with the approximate probability density. Using this technique to displace a particle in the FCC structure with Lennard-Jones potential the new potential after displacement is calculated and may be observed by users. 

### Molecular Dynamical Spin

This module describes the interaction of molecules located on the vertices of a 2D square lattice and incorporating the effects of spin (set to positive or negative 1). Spin interaction is another important molecular potential interaction. Periodic boundary conditions are applied to calculate the potential using nearest neighbour configuration. Initially with 0 potential, a Monte Carlo random walk is performed changing one of the spin configurations and the final state may be determined. Users can investigate and observe how the potential energy changes over time from the initial state to the final state. Different cofigurations may be explored and analysed.

### Molecular Hard Spheres

The Hard Spheres section looks more closely at molecular dynamical methods. For this case a hard sphere approach is required. N spheres are given an initial lattice configuration and a random spread of initial velocities, noting the constraint that the kinetic energy must be constant over time (as there is no other energy source), and total momentum zero.

The variables that may be adjusted to observe the hard sphere collisions are N number of particles and T temperature. At the first collision, particle velocities and vector paths are updated via vector calculus while all other particle positions are incremented according to the free flight law. This process is repeated incrementally as each new collision occurs.

Note that periodic boundary conditions can cause problems at low densities when a particle can suddenly appear on the other side of the box and possibly overlap a particle already there. Hence reflective boundary conditions have been used here instead. 

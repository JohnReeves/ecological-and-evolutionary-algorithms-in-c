# introduction

## theory, numerical methods, and simulations

deterministic .. stochastic
--------------|-----------
numerical     .. simulation

## introduction to c

`imageNoise.c` shows how to:   
* read & write to image files;   
* use to random numbers.   

each of these will be used in the simulations

## preditor-prey models

Lotka-Volterra ODEs from 1924 .  

```
dV/dt = aV - b/N*PV .  
dP/dt = e*b/N*PV - dP .  

V == victim population .  
P == prey population .  

divide equ 1 by equ 2:   

dV/dP = V(aN - bP)/P(e*bV - dN) .  

aN lnP/P0 + d lnV/V0 
= eb(V - V0) + b(P - P0) .  
```
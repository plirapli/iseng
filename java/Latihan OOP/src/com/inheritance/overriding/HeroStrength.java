package com.inheritance.overriding;

class HeroStrength extends Hero {
  int strength;

  // Meng-override parent method
  void display() {
    System.out.println("Hero Strength: " + this.name);
    System.out.println("Strength: " + this.strength);
    System.out.println();
  }
}

package com.inheritance.subclass_constructor;

// Subclass
class HeroStrength extends Hero {
  int strength;

  HeroStrength(String name, int strength) {
    super(name); // Memanggil super constructor
    this.strength = strength;
  }

  void display() {
    System.out.println("Hero Strength");
    System.out.println("Name: " + super.name);
    System.out.println("Strength: " + this.strength);
    System.out.println();
  }
}

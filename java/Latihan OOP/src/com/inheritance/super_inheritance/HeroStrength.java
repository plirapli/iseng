package com.inheritance.super_inheritance;

class HeroStrength extends Hero {
  int strength;

  /*
   * this akan mendahulukan atribute dari kelas ini
   * sebelum mencari ke kelas parent/super.
   * Sedanglan, super selalu memanggil parent attribute/method
   */
  void display() {
    System.out.println("Hero Strength: " + super.name);
    System.out.println("Strength: " + this.strength);
    this.dummyMethod();
    System.out.println();
  }

  void displaySuper() {
    System.out.println("Memanggil method di Super Class");
    super.dummyMethod();
  }

  void dummyMethod() {
    System.out.println("Ini adalah method di Subclass");
  }
}

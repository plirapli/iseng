package com.inheritance.super_inheritance;

public class App {
  public static void main(String[] args) {
    Hero hero1 = new Hero();
    hero1.name = "Seva";
    hero1.display();

    HeroStrength hero2 = new HeroStrength();
    hero2.name = "Hekal";
    hero2.strength = 10;
    hero2.display();
    hero2.displaySuper();
  }
}

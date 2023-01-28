package com.inheritance.subclass_constructor;

public class App {
  public static void main(String[] args) {
    Hero hero1 = new Hero("Hekal");
    hero1.display();

    HeroStrength hero2 = new HeroStrength("Seva", 12);
    hero2.display();
  }
}

package com.latihan_tiga;

public class App {
  public static void main(String[] args) {
    Hero hero1 = new Hero("Hekal", 10, 100);
    HeroStrength hero2 = new HeroStrength("Seva", 12.8, 100);

    hero1.display();
    hero2.display();

    hero1.attack(hero2);
    hero2.attack(hero1);

    hero1.display();
    hero2.display();
  }
}

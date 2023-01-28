package com.inheritance.introduction;

// Inheritance adalah hubungan "is a"
class Hero {
  String name;

  void display() {
    System.out.println("Name: " + this.name);
  }
}

class HeroStrength extends Hero {

}

public class App {
  public static void main(String[] args) {
    Hero hero1 = new Hero();
    hero1.name = "Seva";
    hero1.display();

    HeroStrength hero2 = new HeroStrength();
    hero2.name = "Hekal";
    hero2.display();
  }
}

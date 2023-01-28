package com.latihan_tiga;

public class HeroStrength extends Hero {
  private String type = "Strength";

  HeroStrength(String name, double attack, double hp) {
    super(name, attack, hp);
  }

  @Override
  void display() {
    System.out.println("Type: " + this.type);
    super.display();
  }

  @Override
  void defend(double damage) {
    damage *= 0.5;
    this.hp -= damage;

    System.out.println(this.name + " receive " + damage + " damage!");
    System.out.println();
  }
}

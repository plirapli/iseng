package com.latihan_tiga;

public class Hero {
  // Attribute
  String name;
  double attack, hp;

  // Constructor
  Hero(String name, double attack, double hp) {
    this.name = name;
    this.attack = attack;
    this.hp = hp;
  }

  // Method
  void attack(Hero enemy) {
    System.out.println(
        this.name + " is attacking " + enemy.name + "!");

    enemy.defend(this.attack);
  }

  void defend(double damage) {
    this.hp -= damage;

    System.out.println(this.name + " receive " + damage + " damage!");
    System.out.println();
  }

  void display() {
    System.out.println("Name: " + this.name);
    System.out.println("HP: " + this.hp + "%");
    System.out.println("Attack: " + this.attack);
    System.out.println();
  }
}
